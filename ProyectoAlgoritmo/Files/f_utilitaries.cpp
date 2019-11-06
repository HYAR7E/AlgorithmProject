// Utilitary functions
#ifndef UTILITARIES_FILE
#define UTILITARIES_FILE

/*** FUNCTIONS PROTOTYPE **/

// Capa Usuario
void clear(int n=st_clearlines, char m='\n'); // For our program code to be compilable in other operating systems we should create our own functions of cleaning and pausing cuz these come from libraries which often depends on it
void pause(); // Getch's imitation but available independent of OS
void printInformation(int _actype); // Print user information according to their account type

// Capa Logica
bool isString(string txt, int minlength=-1, int maxlength=-1); // Is it a string value?
bool isNumber(string num); // Is it a number value?
int convertToInt(string num); // Convert a string value to int value
int getValidIntInput(string x_Ask, string x_Error); // Avoid program error when introducing string values into int variable input
int getCurrentTime(char f); // Gets current time _f: Y,M,D,h,m,s
bool isDate(string date); // Is it a date value?
bool isValidDate(string date, bool _checkage=false); // Is it a correct date value?

// Capa Servidor
void serverConection(){}


/*** FUNCTIONS DECLARATION ***/
/* ### USER LAYER ### */
void clear(int n, char m){ // n=30 m='\'
    cout<<string(n,m);
}
void pause(){
    // Right after a input is readed there left newlines in stream which could cause the pause to be skipped instantly, so we ignore those  inputs left
    cin.ignore(st_clearlines,'\n'); // Ignore newline in stream
    cin.get(); // Actually waits for an input character
}
void printInformation(int _actype){
    // They all but enterprise have person information
    if(_actype!=3){ // Print Person struct information
        cout<<"ID: "<<user->id<<endl;
        cout<<"Nombre completo: "<<user->name<<" "<<user->lastname<<endl;
        cout<<"Fecha de nacimiento: "<<user->borndate<<endl;
        cout<<"DNI: "<<user->dni<<endl;
        cout<<"Información de contacto: "<<endl;
        cout<<"\t Email: "<<user->contact.email<<endl;
        cout<<"\t Telefono 1: "<<user->contact.telf1<<endl;
        cout<<"\t Telefono 2: "<<user->contact.telf2<<endl;
        cout<<"\t Direccion: "<<user->contact.address<<endl;
    }
    switch(_actype){ /*** ERROR USER VARIABLE TYPE IS PERSON, NOT WORKER OR ENTERPRISE ***/
        case 1: // Worker
            // cout<<"Profesion: "<<user->wProfession<<endl;
            // cout<<""<<user->A<<endl;
            break;
        case 2: // Enterprise
            break;
        case 3: // Admin
            break;
        default: return;
    }
}


/* ### LOGIC LAYER ### */
bool isString(string txt, int minlength, int maxlength){
    if( minlength!=-1) if( txt.length() <= minlength ) return false;
    if( maxlength!=-1) if( txt.length() >= maxlength ) return false;

    char letter;
    for(int i=0; i<txt.length(); i++){
        letter = txt.at(i);
        if( !((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')) ){
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
int convertToInt(string x_num){
    if( !isNumber(x_num) ) return 0;
    stringstream _num(x_num); // Create stringstream object with x_num value
    int _n = 0; // Declarate int variable
    _num>>_n; // Pass value of _num (stringstream object) to int variable
    return _n;
}
int getValidIntInput(string x_Ask, string x_Error){
    string x_n = "";
    int i_n = 0;
    cout<<x_Ask; cin>>x_n;
    while( !isNumber(x_n) ){ // If it's invalid input show error message
        cout<<x_Error<<endl;
        cout<<x_Ask; cin>>x_n;
    }
    i_n = convertToInt(x_n);
    return i_n;
}
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
bool isDate(string date){ // date = "11/22/3333"
    if( !isNumber( date.substr(0,2) ) ) return false;
    if( !isNumber( date.substr(3,2) ) ) return false;
    if( !isNumber( date.substr(6,4) ) ) return false;
    if( date[2] != st_dateseparator ) return false;
    if( date[5] != st_dateseparator ) return false;
    return true;
}
bool isValidDate(string date, bool checkage){ // date = "11/22/3333"
    if( !isDate(date) ) return false;
    int day, month, year;
    day = convertToInt( date.substr(0,2) );
    month = convertToInt( date.substr(3,2) );
    year = convertToInt( date.substr(6,4) );
    // Check year
    int now_year = getCurrentTime('Y');
    if( checkage ) if( year < (now_year-65) || year > (now_year-18) ) return false; // Max age 65 and min age 18
    // Check month
    if( month < 1 || month > 12 ) return false;
    // Calc max day
    int maxday = 30;
    if( month==2 ){ // April
        maxday = 28;
        if( year%4==0 && year%100!=0 ) maxday = 29;
    }else if( month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12 ){ // 31
        maxday = 31;
    }
    // Check day
    if( day < 1 || day > maxday ) return false;

    return true;
}
#endif
