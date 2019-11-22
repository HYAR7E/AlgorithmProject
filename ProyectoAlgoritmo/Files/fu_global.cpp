// Global User Functions
#ifndef FU_GLOBAL
#define FU_GLOBAL
/*** FUNCTIONS PROTOTYPE ***/
// Capa Usuario
void myData(int _userid, int _printtype); // Print specific user(guest/worker/enterprise) data, with possibility of modify
void myJobOffer(int _jobid, int _userid); // Print specific job offer data, with possibility of modify
void printWorkers(string **data=NULL, int _length=0); // Recursive function, double default value cuz we'll call it without arguments from the menu
void printEnterprises(string **data=NULL, int _length=0); // Recursive function
void printJobOffers(int _entid=-1, string **data=NULL, int _length=0); // Print all job offers, owned by enterprise with id = _entid
void printApplications(int _userid);

// Capa Logica
bool mll_changeData(int _actype, string _code, string _value); // Change user data
bool mll_getWorkers(); // Get workers data
bool mll_getEnterprises(); // Get enterprises data
bool mll_getJobOffers(int _entid); // Get request data
int genUniqueRandId(int _idtype); // Generate a random number and check if it is already taken
Person *getPersonStructAddress(int _userid); // Get user struct address from accounts array and return it to store in 'user' global pointer variable
bool userIdExists(int _userid); // We can't mix the functions getPersonStruct with userIdExists for security good practices
Request *getRequestStructAddress(int _jobid); // Get job offer structure address
bool jobOfferExists(int _offerid); // Job offer exists?
#ifndef PROTO_APPLYOFFER // If applyForJobOffer prototype function hasn't been declared yet
#define PROTO_APPLYOFFER // Define applyForJobOffer prototype function
bool applyForJobOffer(int _idjob); // Apply to job offer function
#endif

// Capa Servidor
// bool pullChangesInUser(int _userid);


/*** FUNCTIONS DECLARATION ***/
/* ### USER LAYER ### */
void myData(int _userid, int _printtype){ // _printtype is the acount type of the print
    string x_opc = "f";
    // Get user struct
    // _user is memory address of Person structure
    Person* _user = NULL;
    _user = getPersonStructAddress(_userid); // Get user person struct by id
    // Prevent of choosing a id that exists but is from another account type
    if( _user->accounttype != _printtype ){ // If the given user id is for another account type
        cout<<"El ID no existe"<<endl;
        return;
    }

    bool _same = false;
    /* ERROR: The pointer parameter doesn't have the same memory address than the original pointer, so we can't compare 'em, instead we compare the user->id*/
    if( user->id == _user->id ) _same=true; // If logged in user is the given user
    clear();


    if(_same) cout<<"cod\tDato: valor\n\n"; // Title (?)
    // Get user account type and create a _u variable of the account type indicated
    void *_u = NULL; // Void type pointer variable, we use this to store the variable memory address of any data type
    /* ERROR: doesn't allow to use 'switch' statement cuz variables declared within 'switch' overpass 'break' sentences so we would get a same name variable multiple declaration error so we opted for 'if' statement */
    // _u.printData(_same); // Recursively print data
    // printData(_same) when _same is true should print all data recursively (worker/enterprise, person, contact)
        // When _same is false, should print only general data
    if(_user->accounttype == 0){ // Guest
        _u = _user; // Get the Person memory address
        ((Person*) _u)->printData(_same);
    }
    if(_user->accounttype == 1){ // Worker
        _u = (_user->w_ma); // Get the Worker memory address
        ((Worker*) _u)->printData(_same);
    }
    if(_user->accounttype == 2){
         _u = (_user->e_ma); // Get the Enterprise memory address
        ((Enterprise*) _u)->printData(_same);
    }
    cout<<endl;

    // PRINT ENTERPRISE'S JOB OFFERS WHEN IT'S NOT THE SAME
    if( !_same && user->accounttype!=2){
        if( x_opc=="y" || x_opc=="Y" ) printJobOffers(_userid); // Print job offers
        cout<<"Ver ofertas de trabajo? (y/n): "; cin>>x_opc;
    }

    // CHANGE DATA
    if( !_same ) return; // Don't allow to change data if the given user is not the logged in user
    // pauseClear(); // Pause for watch printed data

    string _code="",_value=""; // Empty code and value
    cout<<"Desea realizar cambios en sus datos? (y/n): "; cin>>x_opc;
    if( !isString(x_opc,1,1) || (x_opc!="y" && x_opc!="Y") ) return; // User don't want to change his data

    cout<<"Que dato desea cambiar? (code): "; cin>>_code; // Get only three characters
    pauseClear(); // Earse remaining stream data
    if( _code.length() != 3 ){ // Failed at enter code
        cout<<"Formato de codigo incorrecto"<<endl;
        return;
    }

    cout<<"Introduzca el valor a asignar: ";
    getline(cin,_value); // Get the full line with all spaces
    // pauseClear(); // We don't pause after getline(cin,_var) cuz getline does not remain any data

    // Why to send accounttype too? cuz 'mll_changeData' function is gonna be used by admin too, so if we don't send account type parameter he'll can not make changes
    if( !mll_changeData(_user->accounttype,_code,_value) ){ // Send account_type, code, value
        cout<<"\nEl codigo o formato de dato no ha podido ser procesado."<<endl;
    }else{ // Changed correctly
        cout<<"\nSe ha modificado correctamente."<<endl;
    }
    // pauseClear(); // Pause to watch output
    return;
}
void myJobOffer(int _idjob){ // Print a specific job offer
    // Get request struct
    Request* _job = NULL;
    // We should check if the jobIdExists() before calling this function
    _job = getRequestStructAddress(_idjob); // Get request struct by id

    // cout<<"user->accounttype: "<< user->accounttype <<endl;
    bool _same = false;
    if( user->accounttype == 2 ){ // If the logged in user is enterprise
        // cout<<"user->e_ma->getRequest(_idjob): "<<user->e_ma->getRequest(_idjob)<<endl;
        if( user->e_ma->getRequest(_idjob) != NULL ) // Is owner of the job
            _same = true;
    }
    // cout<<"_same: "<<_same<<endl;
    clear();


    if(_same) cout<<"cod\tDato: valor\n\n"; // Title (?)
    _job->printRequest(_same); // Print request data
    if( user->accounttype == 3) cout<< (_same? "   \t":"") <<"Cantidad de postulantes: "<<_job->countApplicants()<<endl; // Show applicants amount when user is admin
    cout<<endl;


    // APPLY FOR JOB OFFER
    if( user->accounttype == 1 ){ // User gotta be worker
        string _opc = "f";
        cout<<"Desea postular a este trabajo? (y/n): "; cin>>_opc;
        if( !(_opc!="y" && _opc!="Y") ){ // User want to apply for this job
            if( applyForJobOffer(_idjob) ) cout<<"Se ha postulado correctamente."<<endl;
            else cout<<"Trabajador ya postulando o no vacantes disponibles."<<endl; // This could be cuz enterprise earse the job offer right before worker applies
            pauseClear();
        }
        return;
    }

    // Watch appliers (enterprise and admin only)
    if( !_same && user->accounttype!=3 ) return; // Don't allow watch appliers if it is not the given enterprise or admin
    if( _job->countApplicants() == 0 ) return; // Do not allow to watch if there is no applicant
    string _opc = "f";
    cout<<"Desea ver los postulantes? (y/n): "; cin>>_opc;
    if( !isString(_opc,1,1) || (_opc!="y" && _opc!="Y") ) return; // Enterprise do not want to watch appliers
    pauseClear();
    _job->printApplications();
    /**/
}
void printWorkers(string **data, int _length){ // Print '_length' workers
    if(data==NULL){ // First execution it will receive no data, so by default data=NULL
        // Get the data and send it to this function by recursively calling this, do note that it's calling this function again, so this execution does not have the data
        if( !mll_getWorkers() ){
            cout<<"No hay trabajadores registrados."<<endl;
        }else{ // This will be executed when data is already printed
            int _id;
            cout<<"\nSeleccionar trabajador (0: salir)"<<endl;
            _id = getValidIntInput("ID: ","Formato incorrecto");

            if( _id==0 ) return; // Return before pause if 0 is selected
            pauseClear();
            if( _id==-1 ){ // Max amount of errors
                cout<<"Maxima cantidad de errores, regresando.."<<endl;
                return; // End function cuz too many errors
            }
            if( !userIdExists(_id) ){ // Id
                cout<<"El ID indicado no existe"<<endl;
                return;
            }
            myData(_id,1); // Print specific user's data
        }
        return; // In the second executation we will exit
    }
    // data == &_pointerworker == &&workersinfo; // Print the memory address // iterate to change worker
    // *data == _pointerworker == &workersinfo; // Print each worker // iterate to change data
    // **data == *_pointerworker == workersinfo; // Print each data // never iterate
    clear(); // Clear screen
    // Print the received data
    cout<<"TRABAJADORES REGISTRADOS"<<endl;
    cout<<" ID\t\tProfesion\t\tNombre\t\tApellido"<<endl;
    for(int i=0; i<_length; i++){
        for(int j=0; j<4; j++){
            cout<< **data <<"\t\t";
            (*data)++; // Iterate data element
        }
        cout<<endl;
        data++; // Iterate worker
    }
}
void printEnterprises(string **data, int _length){
    if(data==NULL){
        if( !mll_getEnterprises() ){
            cout<<"No hay empresas registradas"<<endl;
        }else{
            int _id;
            cout<<"\nSeleccionar trabajador (0: salir)"<<endl;
            _id = getValidIntInput("ID: ","Formato incorrecto");

            if( _id == 0 ) return; // Return before pause if 0 is selected
            pauseClear();
            if( !userIdExists(_id) ){
                cout<<"El ID indicado no existe"<<endl;
                return;
            }
            myData(_id,2);
        }
        return;
    }
    clear();
    cout<<"EMPRESAS REGISTRADAS"<<endl;
    cout<<" ID\t\tNombre\t\t\tTrabajos disponibles"<<endl;
    for(int i=0; i<_length; i++){
        for(int j=0; j<3; j++){
            cout<< **data <<"\t\t";
            (*data)++;
        }
        cout<<endl;
        data++;
    }
}
void printJobOffers(int _entid, string **data, int _length){
    if(data==NULL){
        if( !mll_getJobOffers(_entid) ){ // There is no requests
            if( _entid != -1 ) cout<<"Ud no ha publicado ningun trabajo"<<endl;
            else cout<<"No hay ofertas de trabajo disponibles"<<endl; // Worker
        }else{
            int _id;
            cout<<"\nSeleccionar trabajo (0: salir)"<<endl;
            _id = getValidIntInput("ID: ","Formato incorrecto");

            if( _id == 0 ) return; // Return before pause if 0 is selected
            pauseClear();
            if( !jobOfferExists(_id) ){ // Job offer with id = _id exists
                cout<<"El ID indicado no existe"<<endl;
                return;
            }
            myJobOffer(_id); // Print specific job offer's information
        }
        return;
    }
    clear();
    cout<<"OFERTAS DE TRABAJO"<<endl;
    cout<<"Total ofertas: "<<_length<<endl;
    cout<<" ID\t\tProfesion\t\tSalario\t\t";
    // Enterprises can't see each other
    cout<< (user->accounttype!=2 ?"Empresa":"Solicitantes") <<endl; // Show enterprise or applicants
    for(int i=0; i<_length; i++){
        // cout<<"i: "<<i<<endl;
        for(int j=0; j<4; j++){ // The last element is whether or enterprisename or applicantsamount
            // cout<<"j: "<<j<<endl;
            // cout<<"data: "<<data<<endl;
            // cout<<"*data: "<<*data<<endl;
            // Print enterprise name(j=2) or amount of applicants
            if( user->accounttype==2 && j==3 ){ // If account type is not worker show amount of applicants
                (*data)++; // Pass to index=4 (applicants amount)
            }
            cout<< **data <<"\t\t";
            (*data)++;
        }
        cout<<endl;
        data++;
    }
}
void printApplications(int _userid){
    Person *_p = NULL;
    if( !userIdExists(_userid) ){ // User don't exists
        cout<<"El usuario indicado no existe";
        return;
    }
    _p = getPersonStructAddress(_userid); // Pass the person owner of the id
    _p->w_ma->printApplications(); // Print applications info

    // DELETE OPTION
}


/* ### LOGIC LAYER ### */
bool mll_changeData(int _actype, string _code, string _value){
    /*
    // Logic layer functions does not interact with user, so we only receive parameters and work with 'em
    // Person* _user = NULL;  // Auxiliar pointer which will allow us to write alright code regardless the account type
    if( _code[0]=='c' || _code[0]=='p') // Is gonna use a person struct element
        if( _actype!=0 ) // Is not guest so we should use user->one.element
            _user = &(user->one); // Pointer to one(Person) element in worker/enterprise
        else // Is guest
            _user = user; // Pointer to global user variable just to be the same variable with other account type cases
    else // Is not gonna use a guest element
        if( _actype==0 ) // Is guest
            return false; // Is guest but is not gonna use a guest element
        else // Is not guest
            _user = user;
    */

    // We can't use switch with non integer variables so we lead to use if statement instead
    // We could have used maps instead but it's way more work and probably errors too
    if(_actype == 0){ // Is person(guest)
        // Person cases
        if(      _code == "cem"){
            if( !isMail(_value) ) return false;
            user->contact.email = _value;

        }else if(_code == "ct1"){
            if( !isNumber(_value) || _value.length() < 7 ) return false;
            user->contact.telf1 = _value;

        }else if(_code == "ct2"){
            if( !isNumber(_value) || _value.length() < 7 ) return false;
            user->contact.telf2 = _value;

        }else if(_code == "cad"){
            if( _value.length() < 6 ) return false;
            user->contact.address = _value;

        }else if(_code == "pnm"){
            if( !isString(_value,3) ) return false;
            user->name = _value;

        }else if(_code == "pln"){
            if( !isString(_value,4) ) return false;
            user->lastname = _value;

        }else if(_code == "pwd"){
            if( _value.length()<6 || _value.length()>15 ) return false;
            user->password = _value;

        }else{ // Code does not exists
            return false;
        }
    }else if(_actype == 1){ // Is worker
        Worker *_user = NULL;
        _user = user->w_ma;

        if(      _code == "wpf"){
            if( !isString(_value,4) ) return false;
            _user->profession = _value;

        }else if(_code == "wdc"){
            // We don't use isString function cuz there can be anything as ',.$+-*' etc
            _user->description = _value;

        }else if(_code == "cem"){
            if( !isMail(_value) ) return false;
            _user->one->contact.email = _value;

        }else if(_code == "ct1"){
            if( !isNumber(_value) || _value.length() < 7 ) return false;
            _user->one->contact.telf1 = _value;

        }else if(_code == "ct2"){
            if( !isNumber(_value) || _value.length() < 7 ) return false;
            _user->one->contact.telf2 = _value;

        }else if(_code == "cad"){
            if( _value.length() < 6 ) return false;
            _user->one->contact.address = _value;

        }else if(_code == "pnm"){
            if( !isString(_value,3) ) return false;
            _user->one->name = _value;

        }else if(_code == "pln"){
            if( !isString(_value,4) ) return false;
            _user->one->lastname = _value;

        }else if(_code == "pwd"){
            if( _value.length()<6 || _value.length()>15 ) return false;
            _user->one->password = _value;
            cout<<"_user->one.password: "<<_user->one->password<<endl;
            cout<<"user->password: "<<user->password<<endl;

        }else{ // Code does not exists
            return false;
        }
        user->setWorker(_user); // Pass all changes done to user
    }else if(_actype == 2){ // Is enterprise
        Enterprise* _user = user->e_ma;

        if(      _code == "enm"){
            if( !isString(_value,5) ) return false;
            _user->name = _value;

        }else if(_code == "edc"){
            // Description is not necessarily string type
            _user->description = _value;

        }else if(_code == "cem"){
            if( !isMail(_value) ) return false;
            _user->one->contact.email = _value;

        }else if(_code == "ct1"){
            if( !isNumber(_value) || _value.length() < 7 ) return false;
            _user->one->contact.telf1 = _value;

        }else if(_code == "ct2"){
            if( !isNumber(_value) || _value.length() < 7 ) return false;
            _user->one->contact.telf2 = _value;

        }else if(_code == "cad"){
            if( _value.length() < 6 ) return false;
            _user->one->contact.address = _value;

        }else if(_code == "pnm"){
            if( !isString(_value,3) ) return false;
            _user->one->name = _value;

        }else if(_code == "pln"){
            if( !isString(_value,4) ) return false;
            _user->one->lastname = _value;

        }else if(_code == "pwd"){
            if( _value.length()<6 || _value.length()>15 ) return false;
            _user->one->password = _value;

        }else{ // Code does not exists
            return false;
        }
    }
    return true;
}
bool mll_getWorkers(){ // Get a workers info array
    _iwk; // Workers array iterator
    workers; // Workers array

    if( _iwk==0 ) return false; // There is no worker register yet

    string _workersinfo[_iwk][4]; // Create array to store id, name, lastname, profession for each worker
    string* _pointerworker[ _iwk ]; // One pointer to each array element

    // Get worker's id, name, lastname, profession and add to the void array
    for(int i=0; i<_iwk; i++){ // Elements of Worker array
        // cout<<"str: "<<to_string( workers[i].one.id )<<endl;
        // cout<<"workers[i].one.id: "<< workers[i].one.id <<endl;
        // For good practices we should convert all data to string, regardless if it is string by default or other. But the to_string function does not allow string type parameters
        _workersinfo[i][0] = to_string( workers[i].one->id );
        _workersinfo[i][1] = workers[i].profession;
        _workersinfo[i][2] = workers[i].one->name;
        _workersinfo[i][3] = workers[i].one->lastname;
        _pointerworker[i] = _workersinfo[i]; // Pass ma of this worker
    }

    /* Returns void ar[]={name,lastname,profession,&(worker->one)} => afterwards will be displayed(name, lastname and profession), enumerated, selected(by enumeration) and enter to the user's profile by the myData(&(worker->one)) */
    // Returns the memory address to the pointer of array data
    printWorkers( _pointerworker,_iwk );
    return true;
}
bool mll_getEnterprises(){
    _iet; // Enterprise global array iterator
    enterprises; // Enterprises array

    if( _iet==0 ) return false; // There is no enterprise register yet

    string _enterprisesinfo[_iet][3];
    string* _pointerenterprises[_iet];

    for(int i=0; i<_iet; i++){
        _enterprisesinfo[i][0] = to_string( enterprises[i].one->id ); // Get enterprise id
        _enterprisesinfo[i][1] = enterprises[i].name; // Get enterprise name
        _enterprisesinfo[i][2] = to_string( enterprises[i].countRequests() ); // Get enterprises's requests amount
        _pointerenterprises[i] = _enterprisesinfo[i]; // Pass data to enterprises pointer
    }

    printEnterprises( _pointerenterprises,_iet );
    return true;
}
bool mll_getJobOffers(int _entid){
    int _length = _irq; // Request global array iterator
    requests; // Requests array

    if( _length==0 ) return false; // There is no job offer posted yet

    // cout<<"1: "<<_entid<<endl;
    if( _entid != -1 ){ // Check if the given enterprises have at least one requests
        Person *_entp = NULL; // Initialize to NULL
        _entp = getPersonStructAddress( _entid ); // Get enterprise's director Person structure
        // cout<<"2"<<endl;
        Enterprise* _ent = NULL; // Initializeto NULL
        _ent = _entp->e_ma; // Pass the enterprise ma to enterprise pointer
        // cout<<"3"<<endl;
        // Set array length
        _length = _ent->countRequests(); // Get this enterprise's number of requests
        // Print this enterprise's requests
        if( _length == 0 ) return false; // Check, if it has no requests then exit
        // cout<<"4"<<endl;
    }

    string _rqinfo[_length][5]; // Request's info
    string* _pointerrq[_length]; // Pointer to request info
    // cout<<"5"<<endl;

    // ERROR //
    int _aux=0; // Auxiliar iterator for enterprise specific data store
    // cout<<"length: "<<_length<<" - irq: "<<_irq<<endl;
    for(int i=0; i<_irq; i++){ // ID, profession, salary, enterprise
        if( _entid != -1 ){ // If there is a specific enterprise
            // cout<<requests[i].rEnterprise->one->id <<" - "<< _entid<<endl;
            if( requests[i].rEnterprise->one->id != _entid ){ // If this requests is not from our specific enterprise
                // cout<<"i: "<<i<<" - skip"<<endl;
                continue; // Skip to next requests
            }
        }
        // cout<<"i: "<<i<<" - aux:"<<_aux<<endl;
        _rqinfo[_aux][0] = to_string( requests[i].id ); // Get request's id
        _rqinfo[_aux][1] = requests[i].rProfession; // Get request's profession required
        _rqinfo[_aux][2] = to_string( requests[i].rSalary ); // Get request's salary offered
        _rqinfo[_aux][3] = requests[i].rEnterprise->name; // Get request's enterprise
        _rqinfo[_aux][4] = to_string( requests[i].countApplicants() ); // Get request's enterprise
        _pointerrq[_aux] = _rqinfo[_aux]; // Pass data to requests pointer
        _aux++;
    }
    // cout<<"res: "<<_rqinfo[0][0]<<endl;
    // cout<<"res: "<<_rqinfo[0][1]<<endl;
    // cout<<"res: "<<_rqinfo[0][2]<<endl;
    // cout<<"res: "<<_rqinfo[0][3]<<endl;
    // cout<<"res: "<<_rqinfo[0][4]<<endl;
    // cout<<"_rqinfo[0]: "<<_rqinfo[0]<<endl;
    // cout<<"_pointerrq: "<<_pointerrq<<endl;
    // cout<<"7"<<endl;

    printJobOffers( -1,_pointerrq,_length );
    return true;
}
Person *getPersonStructAddress(int _userid){
    for(int i=0; i<_iac; i++){
        if( accounts[i].id == _userid ){
            return &accounts[i]; // Return account's pointer
        }
    }
    // Always check first if userIdExists()
    return NULL; // There is no way a person can't be found, otherwise it would lead to an error
}
Request *getRequestStructAddress(int _jobid){
    for(int i=0; i<_irq; i++){
        if( requests[i].id == _jobid ){
            return &requests[i]; // Return request's pointer
        }
    }
    return NULL; // There is no way a person can't be found, otherwise it would lead to an error
}
bool userIdExists(int _userid){
    for(int i=0; i<_iac; i++){
        if( accounts[i].id == _userid ){ // Check if it is the same user id
            return true; // User exists
        }
    }
    return false; // User does not exists
}
bool jobOfferExists(int _offerid){
    for(int i=0; i<_irq; i++){
        if( requests[i].id == _offerid ){ // Check if it is the same job offer id
            return true; // Job offer exists
        }
    }
    return false; // Job offer does not exists
}
int genUniqueRandId(int _idtype){
   int _rd = -1;
   bool _r = false;
   srand(time(NULL)); // Initialize random seed
   /* SERVER FUNCTION */
   // Check if it is already taken
   do{
       _rd = ( rand()%8999 ) + 1000; // Generate random number from 1000 - 9999
       switch(_idtype){
           case 1: // User id type
               _r = userIdExists(_rd); // Is it already taken?
               break;
         case 2: // Request id type
             _r = jobOfferExists(_rd); // Is it already taken?
             break;
       }
   }while( _r ); // Repeat if it is already taken
   return _rd; // Return rand number generated
}

/* ### SERVER LAYER ### */

#endif













