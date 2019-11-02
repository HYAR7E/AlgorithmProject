// Proyecto del curso Algoritmo - Agencia de empleo
/*
    TO DO
    Check accounttype at show function printMenu
    Show menu depending of account type
    Status online, offline
*/

#include <iostream> // Basic language library
#include <stdlib.h> // Rand number generation
#include <sstream> // Convert string to int
#include <typeinfo> // Get variable type
using namespace std; // Allow to avoid std:: prefix

// Structs file
#include "Files/structs.cpp"

// Global variable
#include "Files/database.cpp"

// Functions
#include "Files/f_utilitaries.cpp"
#include "Files/f_program.cpp"
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
    cout<<"1. Iniciar sesion"<<endl;
    cout<<"2. Registrarse"<<endl;
    cout<<"3. Salir"<<endl;
    opc = getValidIntInput("Opc: ", "Introduzca una opcion valida");
    clear();
    switch(opc){
        case 1:
            i_log = _login();
            printMMLog(opc, i_log); // Print result message with code i_log
            if(i_log == 1) printMenu( user.accounttype ); // Send current user accounttype
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
