// Program functions
#ifndef PROGRAM_FILE
#define PROGRAM_FILE
// Functions declaration
int _login();
int _register();
bool _userExist(string _n, string _ln);
int addNewWorker();
int addNewEnterprise();
int addNewOffer();
int checkForMatch();

// Functions explanation
int _login(){
    return 0;
}
int _register(){
    string _name, _lastname, _telf, _password;
    short _age;
    clear();

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
    Person _new = {_name, _lastname, _age, _telf, _password};
    accounts[_iac] = _new;
    _iac++;
    return 1; // Everything alright
}
bool _userExist(string _n, string _ln){
    for(int i=0; i<_iac; i++){
        if( accounts[i].name == _n && accounts[i].lastname == _ln ) return true;
    }
    return false;
}
#endif
