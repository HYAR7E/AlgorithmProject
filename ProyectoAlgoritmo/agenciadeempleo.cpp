// Proyecto del curso Algoritmo
/*
    Proyect Especifications
        Struct data Profession is added as keywords like enginner, nurse, assassin, etc.

    *Main Menu
        *Register
        *Login
        *Exit

        Guest menu
            Choose accoun type
            Change data
        Worker menu
            Publish cv (add to workers)
            Look announcements
            Apply for work (show announcements paginated)
            return main menu / exit
        Enterprise menu
            Publish job offer (add to enterprise and request)
            Check out applicants
            return main menu / exit
        Admin menu
            Look databases
            New activities
            return main menu / exit
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

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
    cout<<"Opc: "; cin>>opc;
    clear();
    switch(opc){
        case 1:
            i_log = _login();
            printMMLog(opc, i_log);
            printMenu(0);
            break;
        case 2:
            i_log = _register();
            printMMLog(opc, i_log);
            break;
        case 3:
            exit(0);
            break;
    }
    goto mainmenu;
}
