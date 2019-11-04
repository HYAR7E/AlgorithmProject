// Guest User Functions
#ifndef FU_GUEST
#define FU_GUEST
/*** FUNCTIONS PROTOTYPE ***/
// Capa Usuario
bool ac0_chooseAccountType();
void ac0_changeData();

// Capa Logica
bool _chooseAccountType(int _actype); // Change user's account type
bool _changeData();

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
    return _r;
}
void ac0_changeData(){
    return;
}

/* ### LOGIC LAYER ### */
bool _chooseAccountType(int _actype){
    user->accounttype = _actype;
    // Add to workers
    // Send to servidor and return true/false
    return true;
}
bool _changeData(){
    return false;
}

/* ### SERVER LAYER ### */

#endif
