// Program functions
#ifndef PROGRAM_FILE
#define PROGRAM_FILE
// Functions declaration
int _login();
int _register();
bool _userExist(string _n, string _ln, string pw="");
int _getUserId(string _n, string _ln, string pw);
int addNewWorker();
int addNewEnterprise();
int addNewOffer();
int checkForMatch();

// Functions explanation
int _login(){
    string _name, _lastname, _password;

    cout<<"Nombre: "; cin>>_name;
    if( !isString(_name) ) return -1;
    cout<<"Primer Apellido: "; cin>>_lastname;
    if( !isString(_lastname) ) return -1;
    if( !_userExist(_name,_lastname) ) return -2; // User don't exists

    inputpass:
    int _ipass=1;
    cout<<"Contrasena: "; cin>>_password;
    if( !_userExist(_name,_lastname,_password) ){
        cout<<"Contraseña incorrecta";
        if(_ipass>=3) return -0; // Password incorrect
        _ipass++;
        goto inputpass;
    }

    // Show guest menu
    _accountID = _getUserId(_name,_lastname,_password); // Add account id to global variable
    return 1;
}
int _register(){
    string _name, _lastname, _telf, _password;
    short _age;

    // Ask personal data
    cout<<"Edad: "; cin>>_age;
    if( _age<16||_age>65 ) return -2; // Verify age range

    cout<<"Nombre: "; cin>>_name;
    if( !isString(_name) ) return -1;
    cout<<"Primer apellido: "; cin>>_lastname;
    if( !isString(_lastname) ) return -1;

    // Verify user already exist
    if( _userExist(_name,_lastname) ) return 0; // User already exists

    cout<<"Telefono de contacto: "; cin>>_telf;
    if( !isNumber(_telf) ) return -1;

    int _ipass=1;
    inputpass:
    cout<<"Contraseña: "; cin>>_password;
    if( _password.length()<6 || _password.length()>15 ){ // Amount of characters in password
        if( _ipass >= 3) return -3;
        cout<<"La contraseña debe tener entre 6 a 15 caracteres"<<endl;
        _ipass++;
        goto inputpass;
    }

    // Add to array
    srand(time(NULL)); // Initialize random seed
    int _id = rand()%8999 + 1000; // Generate random number from 1000 - 9999
    Person _new = {_id, _name, _lastname, _age, _telf, _password, 0}; // Create person
    accounts[_iac] = _new; // Add person to accounts array
    _iac++; // Iterate account array variable
    return 1; // Everything alright
}
bool _userExist(string _n, string _ln, string _pw){
    for(int i=0; i<_iac; i++){
        if( accounts[i].name == _n && accounts[i].lastname == _ln ){ // Account exists
            if(_pw != ""){ // Password check
                if( accounts[i].password == _pw ) return true; // Password is correct
                return false; // Password is incorrect
            }
            return true;
        }
    }
    return false;
}
int _getUserId(string _n, string _ln, string _pw){
    for(int i=0; i<_iac; i++){
        if( accounts[i].name == _n && accounts[i].lastname == _ln && accounts[i].password == _pw){ // Account verification
            return accounts[i].id; // Return account id
        }
    }
    return -1;
}
#endif
