// Global User Functions
#ifndef FU_GLOBAL
#define FU_GLOBAL
/*** FUNCTIONS PROTOTYPE ***/
// Capa Usuario
void myData(Person *_user); // Print user data
// Capa Logica
bool changeData(int _actype, string _code, string _value); // Change user data
// Capa Servidor


/*** FUNCTIONS DECLARATION ***/
/* ### USER LAYER ### */
void myData(Person *_user){ // _user is memory address of Person structure
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
    if( !_same ) return; // Don't allow to change data if the given user is not the logged in user
    pauseClear(); // Pause for watch printed data

    // Change data
    string _opc = "f";
    string _code="",_value=""; // Empty code and value
    cout<<"Desea realizar cambios en sus datos? (y/n): "; cin>>_opc;
    pauseClear(); // Earse remaining stream data
    if( !isString(_opc,1,1) || (_opc!="y" && _opc!="Y") ) return; // User don't want to change his data

    cout<<"Que dato desea cambiar? (code): "; cin>>_code; // Get only three characters
    pauseClear(); // Earse remaining stream data
    if( _code.length() != 3 ) return; // Failed at enter code

    cout<<"Introduzca el valor a asignar: ";
    getline(cin,_value); // Get the full line with all spaces
    // pauseClear(); // We don't pause after getline(cin,_var) cuz getline does not remain any data

    // Why to send accounttype too? cuz '_changeData' function is gonna be used by admin too, so if we don't send account type parameter he'll can not make changes
    if( !changeData(_user->accounttype,_code,_value) ){ // Send account_type, code, value
        cout<<"\nHa ocurrido un error y los datos no han podido ser procesados."<<endl;
    }else{ // Changed correctly
        cout<<"\nSe ha modificado correctamente."<<endl;
    }
    return;
}

/* ### LOGIC LAYER ### */
bool changeData(int _actype, string _code, string _value){
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
            if( !isString(_value,8) ) return false;
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
            if( !isString(_value,8) ) return false;
            _user->description = _value;

        }else if(_code == "cem"){
            if( !isMail(_value) ) return false;            _user->one.contact.email = _value;

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

/* ### SERVER LAYER ### */

#endif
