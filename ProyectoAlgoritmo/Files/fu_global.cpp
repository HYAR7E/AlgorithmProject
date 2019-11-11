// Global User Functions
#ifndef FU_GLOBAL
#define FU_GLOBAL
/*** FUNCTIONS PROTOTYPE ***/
// Capa Usuario
void myData(int _userid, int _actype); // Print specific user(guest/worker/enterprise) data, with possibility of modify
void printWorkers(string **data=NULL, int _length=0); // Recursive function, double default value cuz we'll call it without arguments from the menu
void printEnterprises(string **data=NULL, int _length=0); // Recursive function
void printJobOffers(int _entid=-1, string **data=NULL, int _length=0); // Print all job offers, owned by enterprise with id = _entid

// Capa Logica
bool mll_changeData(int _actype, string _code, string _value); // Change user data
bool mll_getWorkers(); // Get workers data
bool mll_getEnterprises(); // Get enterprises data
bool mll_getJobOffers(); // Get request data
Person *getPersonStructAddress(int _userid); // Get user struct direction from accounts array and return it to store in 'user' global pointer variable
bool userIdExists(int _userid); // We can't mix the functions getPersonStruct with userIdExists for security good practices
bool jobOfferExists(int _offerid); // Job offer exists?
int genUniqueRandId(int _idtype); // Generate a random number and check if it is already taken

// Capa Servidor
// bool pullChangesInUser(int _userid);


/*** FUNCTIONS DECLARATION ***/
/* ### USER LAYER ### */
void myData(int _userid, int _actype){ // _user is memory address of Person structure
    // Get user struct
    Person* _user = NULL;
    _user = getPersonStructAddress(_userid); // Get user person struct by id
    if( _user->accounttype != _actype ){
        cout<<"El ID no existe"<<endl;
        return;
    }

    bool _same;
    /* ERROR: The pointer parameter doesn't have the same memory address than the original pointer, so we can't compare 'em, instead we compare the user->id*/
    if( user->id == _user->id ) _same=true; // If logged in user is the given user
    // Get user account type and create a _u variable of the account type indicated
    clear();


    if(_same) cout<<"cod\tDato: valor\n\n"; // Title (?)
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


    // CHANGE DATA
    if( !_same ) return; // Don't allow to change data if the given user is not the logged in user
    // pauseClear(); // Pause for watch printed data

    string _opc = "f";
    string _code="",_value=""; // Empty code and value
    cout<<"Desea realizar cambios en sus datos? (y/n): "; cin>>_opc;
    // pauseClear(); // Earse remaining stream data
    if( !isString(_opc,1,1) || (_opc!="y" && _opc!="Y") ) return; // User don't want to change his data

    cout<<"Que dato desea cambiar? (code): "; cin>>_code; // Get only three characters
    pauseClear(); // Earse remaining stream data
    if( _code.length() != 3 ) return; // Failed at enter code

    cout<<"Introduzca el valor a asignar: ";
    getline(cin,_value); // Get the full line with all spaces
    // pauseClear(); // We don't pause after getline(cin,_var) cuz getline does not remain any data

    // Why to send accounttype too? cuz 'mll__changeData' function is gonna be used by admin too, so if we don't send account type parameter he'll can not make changes
    if( !mll_changeData(_user->accounttype,_code,_value) ){ // Send account_type, code, value
        cout<<"\nHa ocurrido un error y los datos no han podido ser procesados."<<endl;
    }else{ // Changed correctly
        cout<<"\nSe ha modificado correctamente."<<endl;
    }
    // pauseClear(); // Pause to watch output
    return;
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
            if( _id == 0 ) return; // Return before pause if 0 is selected
            pauseClear(); // Clear stream of previous cin
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
         if( !mll_getJobOffers() ){ // There is no requests
             cout<<"No hay ofertas de trabajo disponibles"<<endl;
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
             // myJobOffer(_id); // Print specific job offer's information
         }
         return;
     }
     clear();
     cout<<"OFERTAS DE TRABAJO"<<endl;
     cout<<" ID\t\tProfesion\tSalario\t\tEmpresa"<<endl;
     for(int i=0; i<_length; i++){
         for(int j=0; j<4; j++){
             cout<< **data <<"\t\t";
             (*data)++;
         }
         cout<<endl;
         data++;
     }
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
            if( !isString(_value,6) ) return false;
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
        Worker* _user = user->w_ma;

        if(      _code == "wpf"){
            if( !isString(_value,4) ) return false;
            _user->profession = _value;

        }else if(_code == "wdc"){
            if( _value.length() < 8 ) return false; // We don't use isString function cuz there can be anything as ',.$+-*' etc
            _user->description = _value;

        }else if(_code == "cem"){
            if( !isMail(_value) ) return false;
            _user->one.contact.email = _value;

        }else if(_code == "ct1"){
            if( !isNumber(_value) || _value.length() < 7 ) return false;
            _user->one.contact.telf1 = _value;

        }else if(_code == "ct2"){
            if( !isNumber(_value) || _value.length() < 7 ) return false;
            _user->one.contact.telf2 = _value;

        }else if(_code == "cad"){
            if( !isString(_value,6) ) return false;
            _user->one.contact.address = _value;

        }else if(_code == "pnm"){
            if( !isString(_value,3) ) return false;
            _user->one.name = _value;

        }else if(_code == "pln"){
            if( !isString(_value,4) ) return false;
            _user->one.lastname = _value;

        }else if(_code == "pwd"){
            if( _value.length()<6 || _value.length()>15 ) return false;
            _user->one.password = _value;

        }else{ // Code does not exists
            return false;
        }
    }else if(_actype == 2){ // Is enterprise
        Enterprise* _user = user->e_ma;

        if(      _code == "enm"){
            if( !isString(_value,5) ) return false;
            _user->name = _value;

        }else if(_code == "edc"){
            if( _value.length() < 8 ) return false; // Description is not necessarily string type
            _user->description = _value;

        }else if(_code == "cem"){
            if( !isMail(_value) ) return false;
            _user->one.contact.email = _value;

        }else if(_code == "ct1"){
            if( !isNumber(_value) || _value.length() < 7 ) return false;
            _user->one.contact.telf1 = _value;

        }else if(_code == "ct2"){
            if( !isNumber(_value) || _value.length() < 7 ) return false;
            _user->one.contact.telf2 = _value;

        }else if(_code == "cad"){
            if( !isString(_value,6) ) return false;
            _user->one.contact.address = _value;

        }else if(_code == "pnm"){
            if( !isString(_value,3) ) return false;
            _user->one.name = _value;

        }else if(_code == "pln"){
            if( !isString(_value,4) ) return false;
            _user->one.lastname = _value;

        }else if(_code == "pwd"){
            if( _value.length()<6 || _value.length()>15 ) return false;
            _user->one.password = _value;

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
        _workersinfo[i][0] = to_string( workers[i].one.id );
        _workersinfo[i][1] = workers[i].profession;
        _workersinfo[i][2] = workers[i].one.name;
        _workersinfo[i][3] = workers[i].one.lastname;
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
        _enterprisesinfo[i][0] = to_string( enterprises[i].one.id ); // Get enterprise id
        _enterprisesinfo[i][1] = enterprises[i].name; // Get enterprise name
        _enterprisesinfo[i][2] = to_string( enterprises[i].countRequests() ); // Get enterprises's requests amount
        _pointerenterprises[i] = _enterprisesinfo[i]; // Pass data to enterprises pointer
    }

    printEnterprises( _pointerenterprises,_iet );
    return true;
}
bool mll_getJobOffers(){
    _irq; // Request global array iterator
    requests; // Requests array

    if( _irq==0 ) return false; // There is no job offer posted yet

    string _rqinfo[_irq][3]; // Request's info
    string* _pointerrq[_irq]; // Pointer to request info

    for(int i=0; i<_irq; i++){ // ID, profession, salary, enterprise
        _rqinfo[i][0] = to_string( requests[i].id ); // Get request's id
        _rqinfo[i][1] = requests[i].rProfession; // Get request's profession required
        _rqinfo[i][2] = to_string( requests[i].rSalary ); // Get request's salary offered
        _rqinfo[i][3] = requests[i].rEnterprise.name; // Get request's enterprise
        _pointerrq[i] = _rqinfo[i]; // Pass data to requests pointer
    }

    printJobOffers( -1,_pointerrq,_irq );
    return true;
}
Person *getPersonStructAddress(int _userid){
    for(int i=0; i<_iac; i++){
        if( accounts[i].id == _userid ){
            return &accounts[i]; // Return account pointer
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













