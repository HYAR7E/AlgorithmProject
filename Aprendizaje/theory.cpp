#include <iostream>
#include <string.h>
#include <typeinfo> // Get variable type
using namespace std;
int main(){

    //** To reproduce getch() function of conio.h library in linux (cuz conio.h library doesn't exist in linux based operative systems)
    cin.ignore(120,'\n'); // Ignores the next 120 characters input till \n is readed
    cin.get(); // Gets any next character wether it is a space or not

    // For reading lines i would recommend string type variables
    string name;
    getline(cin, name, '\n'); // use de cin method, store value in 'name' variable, end when '\n' is read

    // Get variable type
    int edad = 20;
    char sexo = 'M';
    cout << typeid(edad).name() << endl; // type: i -> int
    cout << typeid(sexo).name() << endl; // type: c -> char


    return 0;
}
