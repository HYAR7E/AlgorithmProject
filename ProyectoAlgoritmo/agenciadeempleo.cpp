// Proyecto del curso Algoritmo - Agencia de empleo
/*
    PROYECT ESPECIFICATIONS
        Struct data Profession is added as keywords like enginner, nurse, assassin, etc.

    *Main Menu
        *Register
        *Login
        *Exit
    Guest menu
        Choose accoun type
        Add contact info
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
        Delete accounts
        return main menu / exit
    Enterprise sheet
        Show
            Information and contact
            Job vacancies
        Options
            Apply
    Worker sheet
        Show
            Information and contact
        Send job offer


    TO DO

    Check if id person is already taken
    Add value to control account type
    Show menu depending of account type

    DONE CHANGES
        Separate functions into User, Logic and Server layer
        Added function to get date number (Y,M,D,h,m,s)
        Added function to calc valid date
        Changed Person.age to Person.borndate wich allows calculate age anytime
        Person.dni changed to string type for easier comparison
        Added check for valid F_Register->dni
        Added check for valid age in F_Register
        Added check min/max string length in function F_isString
        Removed name input of _login function (unnecessary)
        ERROR FIXED:
            ERROR: We can't declarate null contactinfo in _register function
            SOLUTION: We don't want to declare contactinfo yet so we initialize it as an empty string cuz its first element is string type variable. In f_program.cpp _register()
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
    printMainMenu();
    return 0;
}

void printMainMenu(){
    int opc=0;
    int i_log=0;
    string x_aux = "";

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
            printMMLog(opc, i_log);
            if(i_log == 1) printMenu(0);
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
