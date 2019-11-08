// Guest User Functions
#ifndef FU_GUEST
#define FU_GUEST
/*** FUNCTIONS PROTOTYPE ***/
// Capa Usuario
bool ac0_chooseAccountType();

// Capa Logica
bool _chooseAccountType(int _actype); // Change user's account type

// Capa Servidor


/*** FUNCTIONS DECLARATION ***/
/* ### USER LAYER ### */
bool ac0_chooseAccountType(){
    int opc=0;
    do{
        clear();
        cout<<"\t Escoja el tipo de cuenta que desea"<<endl;
        cout<<"El tipo de cuenta no se puede cambiar una vez seleccionado \n";
        cout<<"Por favor verifique que todos sus datos sean correctos antes de seleccionar un tipo de cuenta \n\n";
        cout<<"1. Trabajador"<<endl;
        cout<<"2. Empresa"<<endl;
        cout<<"3. Regresar"<<endl;
        opc = getValidIntInput("Opc: ", "Introduzca una opcion valida");
    }while(opc<1||opc>3);
    if( opc==3 ) return false; // Exit

    bool _r = _chooseAccountType(opc);
    if( !_r ) cout<<"Un error ha ocurrido y los cambios no han podido ser realizados";
    else cout<<"Se ha seleccionado el tipo de cuenta correctamente";
    cout<<endl;
    pause();
    return _r;
}

/* ### LOGIC LAYER ### */
bool _chooseAccountType(int _actype){
    if( !user->setAccountType(_actype) ) return false; // Operation failed, maybe the user has already picked his account type
    switch(_actype){ // Add to global array
        case 1:
            workers[_iwk].setPerson(*user); // Send user value to 'setPerson' function
            if( !user->setWorker( &workers[_iwk] ) ) return false; // Send new worker element and return false if failed
            _iwk++; // Iterate variable
            break;
        case 2:
            enterprises[_iet].setPerson(*user); // Send user value to 'setPerson' function
            if( !user->setEnterprise( &enterprises[_iet] ) ) return false; // Send new enterprise element and return false if failed
            _iet++; // Iterate variable
            break;
    }
    // Send to servidor and return true/false
    return true;
}

/* ### SERVER LAYER ### */

#endif
