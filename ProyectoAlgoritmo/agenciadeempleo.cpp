// Proyecto del curso Algoritmo
/*
    Proyect Especifications
        Struct data Profession is added as keywords like enginner, nurse, assassin, etc.

    To do
        Make menu from data array
*/

#include <iostream>
using namespace std;

// Structs file
#include "Files/structs.cpp"

// Global variable
#include "Files/database.cpp"

// Functions
#include "Files/f_utilitaries.cpp"
#include "Files/f_program.cpp"
void printWelcomeMenu();

// Main Function
int main(){
    printWelcomeMenu();
    return 0;
}

void printWelcomeMenu(){
    int opc=0;
    int i_log=0;

    // Main menu
    mainmenu:
    clear();
    cout<<"1. Iniciar sesion"<<endl;
    cout<<"2. Registrarse"<<endl;
    cout<<"3. Salir"<<endl;
    cout<<"Opc: "; cin>>opc;
    switch(opc){
        case 1:
            i_log = _login();
            printMMLog(opc, i_log);
            break;
        case 2:
            i_log = _register();
            printMMLog(opc, i_log);
            break;
        case 3:
            clear();
            exit(0);
            break;
    }
    goto mainmenu;
}
