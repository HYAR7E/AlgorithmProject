// Utilitary functions
#ifndef UTILITARIES_FILE
#define UTILITARIES_FILE

/*** FUNCTIONS PROTOTYPE **/

// Capa Usuario
void clear(int n=st_clearlines, char m='\n'); // For our program code to be compilable in other operating systems we should create our own functions of cleaning and pausing cuz these come from libraries which often depends on it
void pauseClear(); // Getch's imitation but available independent of OS

// Capa Logica
bool isString(string txt, int minlength=-1, int maxlength=-1); // Is it a string value?
bool isNumber(string num); // Is it a number value?
bool isMail(string mail); // Is it a mail value?
int convertToInt(string num); // Convert a string value to int value
int getValidIntInput(string x_Ask, string x_Error, int i_min=-1, int i_max=-1, int maxerror=st_maxerror); // Avoid program error when introducing string values into int variable input
int getCurrentTime(char f); // Gets current time _f: Y,M,D,h,m,s
bool isDate(string date); // Is it a date value?
bool isValidDate(string date, bool _checkage=false); // Is it a correct date value?
#ifndef PROTO_CURDATE
#define PROTO_CURDATE
string getCurrentDate(); // Returns a string with the current date (no time)
#endif


// Capa Servidor
void serverConection(){}


/*** FUNCTIONS DECLARATION ***/
/* ### USER LAYER ### */
void clear(int n, char m){ // n=30 m='\n'
    cout<<string(n,m);
}
void pauseClear(){
    // Right after a input is readed there left newlines in stream which could cause the pause to be skipped instantly, so we ignore those inputs left
    // cout<<"pause"<<endl;
    cin.ignore(30,'\n'); // Ignore characteres left from stream
}


/* ### LOGIC LAYER ### */
bool isString(string txt, int minlength, int maxlength){
    if( minlength!=-1) if( txt.length() < minlength ) return false;
    if( maxlength!=-1) if( txt.length() > maxlength ) return false;

    char letter;
    for(int i=0; i<txt.length(); i++){
        letter = txt.at(i);
        // Allow lowercase, uppercase and spaces
        if( !((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z') || letter==' ') ){
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
bool isMail(string mail){
    char letter;
    bool _arroba = false;
    bool _dot = false;
    for(int i=0; i<mail.length(); i++){
        letter = mail[i];
        if(letter=='@'){
            _arroba = true;
            _dot = false;
            continue;
        }
        if(letter=='.'){
            _dot = true;
            continue;
        }
    }
    return (_arroba && _dot);
}
int convertToInt(string x_num){
    if( !isNumber(x_num) ) return 0;
    stringstream _num(x_num); // Create stringstream object with x_num value
    int _n = 0; // Declarate int variable
    _num>>_n; // Pass value of _num (stringstream object) to int variable
    return _n;
}
int getValidIntInput(string x_Ask, string x_Error, int i_min, int i_max, int maxerror){
    string x_n = "";
    int i_n = 0;
    int errorcount=0;

    do{
        cout<<x_Ask; cin>>x_n;
        if( !isNumber(x_n) || (i_min!=-1 && convertToInt(x_n)<i_min) || (i_max!=-1 && convertToInt(x_n)>i_max) ){
            cout<<x_Error<<endl; // Print error
            errorcount++; // Iterate error count
            if( errorcount == maxerror ) return -1; // Condition of fail
        }
        else break; // It is alright
    }while( true ); // Infinite bucle

    return convertToInt(x_n);
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
        case 'D': f = now->tm_mday;
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
string getCurrentDate(){
    string _date = "";
    int _d = getCurrentTime('D');
    _date +=  to_string(_d) + st_dateseparator;
    int _m = getCurrentTime('M');
    _date += to_string(_m) + st_dateseparator;
    int _y = getCurrentTime('Y');
    _date += to_string(_y);
    return _date; // return date
}
#endif
