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
*//*
Especificaciones del proyecto
         Estructura de datos Profesión se agrega con palabras clave como ingeniero, enfermero, asesino, etc.

    *Menú principal
        *Registro
        *Iniciar sesión
        *Salida

    Menú de invitado
        Elegir tipo de cuenta (trabajador/empresa/administrador)
        Cambiar datos
    Menú trabajador
        Publicar CV
        Mira anuncios
        Solicitar trabajo (mostrar anuncios)
        volver al menú principal / salir
    Menú de empresa
        Publicar oferta de trabajo
        Ver solicitantes al trabajo
        Aceptar/rechazar solicitante
            Abrir chat
        volver al menú principal / salir
    Menú de administrador
        Mira bases de datos
        Eliminar cuentas
        volver al menú principal / salir

    Hoja de empresa
        Mostrar
            Información y contacto
            Trabajos vacantes
        Opción
            Postular
    Hoja de trabajador
        Mostrar
            Información y contacto
        Enviar oferta de trabajo
*/

#include <iostream> // Basic language library
#include <stdlib.h> // Rand number generation
#include <sstream> // Convert string to int
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
