#include<iostream>
#include<sstream>
#include<time.h>
using namespace std;
int getCurrentTime(char _f){
    time_t _now = time(0); // Gets current system time
    tm* now = localtime(&_now); // Convert to tm structure for local time
    int f = -1;
    // Use -> to indicate structs members and plus 1900 to actual year
    switch(_f){
        case 'Y': f = now->tm_year + 1900;
            break;
        case 'M': f = now->tm_mon + 1;
            break;
        case 'D': f = now->tm_mday + 1900;
            break;
        case 'h': f = now->tm_hour;
            break;
        case 'm': f = now->tm_min - 3;
            break;
        case 's': f = now->tm_sec;
            break;
        default: f = -1;
            break;
    }
    return f;
}
/*** STRUCTS ***/
struct foo{
    // foo() : bar(3), var(5) {};   // Constructor
    // or
    foo(int _bar=3, int _var=5){
        bar=_bar; var=_var;
    }
    /**/
    int bar;
    int var;
    int getBar(int i=1){ // Function
        return (bar+var+i);
    }
}y; // y.getBar() == 9

int avg(int *array, int length){
    cout<<"Last element: "<<array[length-1]<<endl;
    cout<<"Memory position: "<<array<<endl;
    return array[0];
};
void sum(foo *f){
    cout<<"foo.var: "<<f->var<<endl;
};
int main(){

    /*** Sending arrays to as function parameter ***/
    int notes[4] = {15,16,17,18};
    int notes_length = 4;
    cout<<"avg(notes,notes_length): "<<avg(notes,notes_length)<<endl;
    // Explanation: sending just 'notes' without any index sends the memory direction, and the function receive it as the value with '*array', then use it as if the value itself was sended
    // In other words to receive a memory direction and play it as the value u have to receive it like (int *direction)
    sum(&y);

    /*** Pointer to struct ***/
    foo *pointer = NULL;
    pointer = &y;
    // pointer->struct_element or
    cout<<"pointer: "<<pointer->getBar(2)<<endl;
    // (*pointer).struct_element
    cout<<"pointer: "<<(*pointer).getBar()<<endl;

    /*** Declare an struct variable empty ***/
    // To initialize the value of a struct as empty we should declare empty its first element
    struct numeros{
        int n;
        char l;
    };
    numeros nuevonumero = {0};
    struct letras{
        char l;
        string k;
    };
    letras nuevaletra = {'0'}; // A constant char can't be declared empty so we initialize it with the value '0'
    struct palabras{
        string l;
        int age;
        char nothing;
    };
    palabras nuevapalabra = {""}; // In case of 


    /*** If allows only one sentence when no curly braces ***/
    int i=1;
    int ra=5;
    if(i==0)
        if(ra>10) cout<<"SI"<<endl;
        else cout<<"NO"<<endl;
    else cout<<"!= 0"<<endl;

    /*** getCurrentTime from declared function ***/
    int rightnow = getCurrentTime('Y');
    cout<<rightnow<<endl;

    /*** string can be taken as an array ***/
    string k = "aa/bb/cc";
    cout<<"string k: "<<k<<endl;
    cout<<"k[0]: "<<k[0]<<endl;
    cout<<"k.substr(0,2): "<<k.substr(0,2)<<endl;
    cout<<"k.substr(3,2): "<<k.substr(3,2)<<endl;
    cout<<"k.substr(6,2): "<<k.substr(6,4)<<endl;

    /*** POINTERS ***/
    // declare pointer variable with NULL
    int *p = NULL;
    // or
    int* r = NULL;
    // Explanation
        // 'p' by itself is the memory direction
        // '*p' is the value
        // &age returns the memory direction of age
        // dni returns memory direction of array dni
        // p->a gets the a value of p structure pointer
        //  same as (*p).a
    int age = 19;
    int dni[8] = {1,5,7,4,2,6,3,8}; // declare array variable to test

    r = &age; // r gets memory direction of age
    p = dni; // p gets memory direction of first element of dni such as &dni[0]

    cout<<"*r: "<<*r<<endl; // print value of age
    cout<<"r: "<<r<<endl; // print direction of age

    cout<<"dni[0]: "<<*p<<endl;
    p += 1; // 
    cout<<"dni[1]: "<<*p<<endl;
    p += 1;
    cout<<"dni[2]: "<<*p<<endl;
    p += 1;
    cout<<"dni[3]: "<<*p<<endl;
    p += 1;
    cout<<"dni[4]: "<<*p<<endl;
    p += 1;
    cout<<"dni[5]: "<<*p<<endl;
    p += 1;
    cout<<"dni[6]: "<<*p<<endl;
    p += 1;
    cout<<"dni[7]: "<<*p<<endl;

    /*** String to int convertion ***/
    string x_age = "18"; // Only the first integer value found will be converted
        // if there is no number value at the beginning it return 0
        // "a15"->0 && "1b3c"->1 && "123abc"->123
    stringstream _converter(x_age); // Create stringstream object with x_age value
    int i_age; // Create a int variable
    _converter>>i_age; // Pass the value to a int variable
    cout<<"Converted integer value: "<<i_age<<endl;

}
