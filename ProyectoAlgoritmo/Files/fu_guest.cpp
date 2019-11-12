// Guest User Functions
#ifndef FU_GUEST
#define FU_GUEST
/*** FUNCTIONS PROTOTYPE ***/
// Capa Usuario
bool ac0_chooseAccountType();

// Capa Logica
bool _chooseAccountType(int _actype); // Change user's account type
bool _isDataFilled(); // Has user filled all person data elements?

// Capa Servidor


/*** FUNCTIONS DECLARATION ***/
/* ### USER LAYER ### */
bool ac0_chooseAccountType(){
    // User has filled all data elements?
    if( !_isDataFilled() ){ // User hasn't filled all person elements
        cout<<"Debe de llenar sus datos personales y al menos un numero de telefono antes de escoger un tipo de cuenta"<<endl;
        return false;
    }

    int opc=0;
    do{
        clear();
        cout<<"Escoja el tipo de cuenta que desea"<<endl;
        cout<<"El tipo de cuenta no se puede cambiar una vez seleccionado \n";
        cout<<"Por favor verifique que todos sus datos sean correctos antes de seleccionar un tipo de cuenta \n\n";
        cout<<"1. Trabajador"<<endl;
        cout<<"2. Empresa"<<endl;
        cout<<"3. Regresar"<<endl;
        opc = getValidIntInput("Opc: ", "Introduzca una opcion valida");
    }while(opc<1||opc>3);
    pauseClear(); // Ignore cin remaining data so the next pauseClear function will pause
    if( opc==3 ) return false; // Exit

    bool _r = _chooseAccountType(opc);
    if( !_r ) cout<<"Un error ha ocurrido y los cambios no han podido ser realizados";
    else cout<<"Se ha seleccionado el tipo de cuenta correctamente, por favor inicie sesion nuevamente";
    cout<<endl;
    pauseClear();
    return _r;
}

/* ### LOGIC LAYER ### */
bool _chooseAccountType(int _actype){
    if( !user->setAccountType(_actype) ) return false; // Operation failed, maybe the user has already picked his account type
    switch(_actype){ // Add to global array
        case 1:
            workers[_iwk].setPerson(user); // Send user value to 'setPerson' function
            if( !user->setWorker( &workers[_iwk] ) ) return false; // Send new worker element and return false if failed
            _iwk++; // Iterate variable
            break;
        case 2:
            enterprises[_iet].setPerson(user); // Send user value to 'setPerson' function
            if( !user->setEnterprise( &enterprises[_iet] ) ) return false; // Send new enterprise element and return false if failed
            _iet++; // Iterate variable
            break;
    }
    // Send to servidor and return true/false
    return true;
}
bool _isDataFilled(){ // Check if user's person data is filled
    // Global variable user is Person type, with memory address of it's account, but since this function is executed before choosing an account type there will only be person data elements
    // Filled in register but modifiable later, anyways there is restriction to do not allow set empty values to this field
    if( user->name == "" ) return false;
    if( user->lastname == "" ) return false;
    if( user->password == "" ) return false;
    // User should enter this elements
    if( user->contact.email == "" ) return false;
    if( user->contact.telf1 == "" && user->contact.telf2 == "" ) return false;
    if( user->contact.address == "" ) return false;
    return true;
}

/* ### SERVER LAYER ### */

#endif
