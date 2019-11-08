// Proyecto del curso Algoritmo - Agencia de empleo
/*
    TO DO
    Add default admin account accounttype=3
    Add print database error in user layer functions
    Delete variables after usage
    Status online, offline
*/

#include <iostream> // Basic language library
#include <stdlib.h> // Rand number generation
#include <sstream> // Convert string to int
using namespace std; // Allow to avoid std:: prefix

// Structs file
#include "Files/structs.cpp" // Structures declaration

// Global variable
#include "Files/database.cpp" // Global and static variables

// Functions
#include "Files/f_utilitaries.cpp" // Utilitaries functions to suport other functions
#include "Files/fu_global.cpp" // Global user suport functions
#include "Files/fu_guest.cpp" // Guest User Functions
#include "Files/fu_worker.cpp" // Worker User Functions
#include "Files/fu_enterprise.cpp" // Enterprise User Functions
#include "Files/fu_admin.cpp" // Admin User Functions
#include "Files/f_menu.cpp" // Menu Functions
#include "Files/f_reglog.cpp" // Register-Login Functions
void printMainMenu();

// Main Function
int main(){
    if( !preload() ) return 0; // Problem declaring to global variables
    printMainMenu();
    return 0;
}

void printMainMenu(){
    int opc=0;
    int i_log=0;

    // Main menu
    mainmenu:
    clear();
// cout<<"mainmenu: id: "<<user->id<<endl;
// cout<<"mainmenu: ac: "<<user->accounttype<<endl;
    cout<<"1. Iniciar sesion"<<endl;
    cout<<"2. Registrarse"<<endl;
    cout<<"3. Salir"<<endl;
    opc = getValidIntInput("Opc: ", "Introduzca una opcion valida");
    clear();
    switch(opc){
        case 1:
        // cout<<"mainmenu: "<<user->accounttype<<endl;
            i_log = _login();
        // cout<<"mainmenu: "<<user->accounttype<<endl;
            printMMLog(opc, i_log); // Print result message with code i_log
        // cout<<"mainmenu: "<<user->accounttype<<endl;
            if(i_log == 1) printMenu( user->accounttype ); // Send current user accounttype
        // cout<<"mainmenu: "<<user->accounttype<<endl;
            break;
        case 2:
            i_log = _register();
            printMMLog(opc, i_log); // Print result message with code i_log
            break;
        case 3:
            exit(0);
            break;
    }
    goto mainmenu;
}
