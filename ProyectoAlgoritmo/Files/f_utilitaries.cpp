// Utilitary functions
#ifndef UTILITARIES_FILE
#define UTILITARIES_FILE
// Functions declaration
void clear(int n=5, char m='\n');
void pause();
void printMMLog(int ,int );
bool isString(string txt);
bool isNumber(string num);
void printMenu(int _actype);

// Functions explanation
void clear(int n, char m){ // n=30
    cout<<string(n,m);
}
void pause(){
    cin.ignore(30,'\n'); // Ignore newline in stream
    cin.get(); // Actually waits for an input character
}
void printMMLog(int _case,int _res){
    if(_case==1){
        switch(_res){
            case -2: cout<<"El usuario no existe."; break;
            case -1: cout<<"La informacion introducida no es valida."; break;
            case 0: cout<<"Contrasena incorrecta."; break;
            case 1: cout<<"Inicio de sesion exitoso."; break;
        }
    }
    if(_case==2){
        switch(_res){
            case -3: cout<<"Tercer error, intente registrarse nuevamente."; break;
            case -2: cout<<"No tiene edad suficiente para usar nuestra plataforma."; break;
            case -1: cout<<"La informacion introducida no es valida."; break;
            case 0: cout<<"Usuario ya registrado."; break;
            case 1: cout<<"Cuenta creada exitosamente."; break;
        }
    }
    cout<<endl;
    pause();
}
bool isString(string txt){
    char word;
    for(int i=0; i<txt.length(); i++){
        word = txt.at(i);
        if( !((word >= 'a' && word <= 'z') || (word >= 'A' && word <= 'Z')) ){
            return false;
        }
    }
    return true;
}
bool isNumber(string num){
    char n;
    for(int i=0; i<num.length(); i++){
        n = num.at(i);
        if( n!='0' &&
            n!='1' &&
            n!='2' &&
            n!='3' &&
            n!='4' &&
            n!='5' &&
            n!='6' &&
            n!='7' &&
            n!='8' &&
            n!='9' ){
            return false;
        }
    }
    return true;
}

#include "../Header/menudata.h"
void printMenu(int _actype){
    clear();
    int opc=0;
    do{
        cout<<"1. Agregar Trabajador"<<endl;
        cout<<"2. Agregar Empresa"<<endl;
        cout<<"3. Nueva Oferta"<<endl;
        cout<<"4. Ver anuncios de trabajo"<<endl;
        cout<<"5. Ver trabajadores"<<endl;
        cout<<"Opc: "; cin>>opc;
    }while(opc<1||opc>5);
    cout<<opc;
}
#endif

