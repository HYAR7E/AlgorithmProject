// Menu Functions
#ifndef F_MENU
#define F_MENU
/*** FUNCTIONS PROTOTYPE ***/
// Capa Usuario
void printMMLog(int _case,int _res); // Main menu log
void printMenu(int _actype); // Menu function, changes depend of account type
void printGuestMenu(); // Print guest menu
void printWorkerMenu();
void printEnterpriseMenu();
void printAdminMenu();
// Capa Logica
// Capa Servidor

/*** FUNCTIONS DECLARATION ***/
/* ### USER LAYER ### */
void printMMLog(int _case,int _res){
    if(_case==1){
        switch(_res){
            case -2: cout<<"El usuario no existe."; break;
            case -1: cout<<"La informacion introducida no es valida."; break;
            case 0: cout<<"Contraseña incorrecta\nMaximo numero de errores permitidos, saliendo..."; break;
            case 1: cout<<"Inicio de sesion exitoso."; break;
        }
    }
    if(_case==2){
        switch(_res){
            case -3: cout<<"Tercer error, intente registrarse nuevamente."; break;
            case -2: cout<<"Debe tener entre 18 y 65 años para usar nuestra plataforma."; break;
            case -1: cout<<"La informacion introducida no es valida."; break;
            case 0: cout<<"Usuario ya registrado."; break;
            case 1: cout<<"Cuenta creada exitosamente."; break;
        }
    }
    cout<<endl;
    pauseClear(); // Pause
}
void printMenu(int _actype){ /**/
    user->online = true; // Only change this value when user enter into menu
    switch(_actype){
        case 0: printGuestMenu();
            break;
        case 1: printWorkerMenu();
            break;
        case 2: printEnterpriseMenu();
            break;
        case 3: printAdminMenu();
            break;
    }
    // Logout
    user = &noone;
    user->online = false; // Only change this value when user exit from menu
}
void printGuestMenu(){
    int opc=0;
    do{ // Repeat menu
        do{
            clear();
            cout<<"1. Escoger tipo de cuenta"<<endl;
            cout<<"2. Mis datos"<<endl;
            cout<<"3. Salir"<<endl;
            opc = getValidIntInput("Opc: ", "Introduzca una opcion valida");
        }while(opc<1||opc>3);
        clear();
        pauseClear(); // Clear data stream remaining from previous cin input
        switch(opc){
            case 1: if( ac0_chooseAccountType() ) return; // If account type changed
                break;
            case 2: myData(user->id, user->accounttype); break; // Global user function
            case 3: return; // Exit
        }
    pauseClear(); // Pause
    }while(true); // Infinite bucle
}
void printWorkerMenu(){
    int opc=0;
    do{ // Repeat menu
        do{
            clear();
            // cout<<"ID: "<<user->id<<endl;
            // cout<<"AC: "<<user->accounttype<<endl;
            // cout<<"MA: "<<user->w_ma<<endl;
            // cout<<"1. CV"<<endl;
            cout<<"1. Ver anuncios"<<endl; // And apply
            cout<<"2. Ver empresas"<<endl;
            cout<<"3. Estado de postulaciones"<<endl;
            cout<<"4. Mi cuenta"<<endl;
            cout<<"5. Salir"<<endl;
            opc = getValidIntInput("Opc: ", "Introduzca una opcion valida");
        }while(opc<1||opc>5);
        clear();
        pauseClear(); // Clear data stream remaining from previous cin input
        switch(opc){
            // case 1: ac1_cvStatus(); break; // CV is showing?
            case 1: printJobOffers(); break; // Print all job offers
            case 2: printEnterprises(); break;
            case 3: printApplications(user->id); break;
            case 4: myData(user->id, user->accounttype); break;
            case 5: return; // Exit
        }
    pauseClear();
    }while(true); // Infinite bucle
}
void printEnterpriseMenu(){
    int opc=0;
    do{ // Repeat menu
        do{
            clear();
            cout<<"1. Nueva oferta de trabajo"<<endl;
            cout<<"2. Mis ofertas de trabajo"<<endl;
            cout<<"3. Mi cuenta"<<endl;
            cout<<"4. Salir"<<endl;
            opc = getValidIntInput("Opc: ", "Introduzca una opcion valida");
        }while(opc<1||opc>4);
        clear();
        pauseClear(); // Clear data stream remaining from previous cin input
        switch(opc){
            case 1: ac2_postJobOffers(); break;
            case 2: printJobOffers(user->id); break; // Print all job offers owned by logged in enterprise
            case 3: myData(user->id, user->accounttype); break;
            case 4: return; // Exit
        }
    pauseClear();
    }while(true); // Infinite bucle
}
void printAdminMenu(){
    int opc=0;
    do{ // Repeat menu
        do{
            clear();
            cout<<"1. Ver anuncios"<<endl; // Delete
            cout<<"2. Ver trabajadores"<<endl; // Ban
            cout<<"3. Ver empresa"<<endl; // Ban
            cout<<"4. Salir"<<endl;
            opc = getValidIntInput("Opc: ", "Introduzca una opcion valida");
        }while(opc<1||opc>4);
        clear();
        pauseClear(); // Clear data stream remaining from previous cin input
        switch(opc){
            case 1: printJobOffers(); break; // Print all job offers
            case 2: printWorkers(); break; // Print all workers
            case 3: printEnterprises(); break; // Print all enterprises
            case 4: return; // Exit
        }
    pauseClear();
    }while(true); // Infinite bucle
}

/* ### LOGIC LAYER ### */

/* ### SERVER LAYER ### */

#endif
