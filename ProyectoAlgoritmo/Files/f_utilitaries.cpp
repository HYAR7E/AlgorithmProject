// Utilitary functions
#ifndef UTILITARIES_FILE
#define UTILITARIES_FILE
// Functions declaration
void clear(int n=5, char m='\n');
void pause();
void printMMLog(int ,int );
void printErrorLog();
bool isString(string txt);
bool isNumber(string num);
int printMenu();

// Functions explanation
void clear(int n, char m){ // n=30
    cout<<string(n,m);
}
void printMMLog(int _case,int _res){
    if(_case==1){
    }
    if(_case==2){
        switch(_res){
            case -3: cout<<"Tercer error, intente registrarse nuevamente."<<endl; break;
            case -2: cout<<"No tiene edad suficiente para usar nuestra plataforma"<<endl; break;
            case -1: cout<<"La informacion introducida no es valida"<<endl; break;
            case 0: cout<<"Usuario ya registrado"<<endl; break;
            case 1: cout<<"Cuenta creada exitosamente"<<endl; break;
        }
    }
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
int printMenu(){
    clear();
    int opc=0;
    do{
        cout<<"1. Agregar Trabajador"<<endl;
        cout<<"2. Agregar Empresa"<<endl;
        cout<<"3. Nueva Oferta"<<endl;
        cout<<"4. Ver anuncios de trabajo"<<endl;
        cout<<"4. Ver trabajadores"<<endl;
        cout<<"Opc: "; cin>>opc;
    }while(opc<1||opc>4);
    return opc;
}
#endif

