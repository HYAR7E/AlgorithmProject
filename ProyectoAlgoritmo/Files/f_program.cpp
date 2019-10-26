// Program functions
#ifndef PROGRAM_FILE
#define PROGRAM_FILE
/*** FUNCTIONS DECLARATION **/

// Capa Usuario
int _login();
int _register(); // Register a new user with account type unespecified
int addNewWorker();
int addNewEnterprise();
int addNewOffer();

// Capa Logica
bool _userExist(string _dni, string _pw=""); // Check if exist a user with the given data
int _getUserId(string _dni, string pw);
int checkForMatch(); // Job offer match with job applicant


/*** FUNCTIONS EXPLANATION ***/

int _login(){
    string _name, _dni, _password;

    cout<<"DNI: "; cin>>_dni;
    if( !isNumber(_dni) || _dni.length() != 8 ) return -1;

    if( !_userExist(_dni) ) return -2; // User don't exists

    inputpass:
    int i_pass=1;
    cout<<"Contrasena: "; cin>>_password;
    if( !_userExist(_dni,_password) ){
        cout<<"Contraseña incorrecta"<<endl;
        if(i_pass>=3) return -0; // Password incorrect
        i_pass++;
        goto inputpass;
    }

    // Add account id to global variable
    _accountID = _getUserId(_dni,_password);
    return 1;
}
int _register(){
    string _name, _lastname, _dni, _password, _borndate;

    // Ask personal data
    cout<<"Nombre: "; cin>>_name;
    if( !isString(_name) ) return -1;
    cout<<"Primer apellido: "; cin>>_lastname;
    if( !isString(_lastname) ) return -1;

    // BornDate
    cout<<"Fecha de nacimiento DD/MM/AAAA :"; cin>>_borndate;
    if( !isValidDate(_borndate) ) return -1; // Check date
    if( !isValidDate(_borndate, true) ) return -2; // Check age

    // Ask and check dni
    cout<<"DNI: "; cin>>_dni;
    if( !isNumber(_dni) || _dni.length() != 8 ) return -1;

    // Verify dni already exist
    if( _userExist(_dni) ) return 0; // User already exists

    int i_pass=1;
    inputpass:
    cout<<"Contraseña: "; cin>>_password; // We can't use isString or isInt function cuz this could be any character or number
    if( _password.length()<6 || _password.length()>15 ){ // Amount of characters in password
        if( i_pass >= 3) return -3;
        cout<<"La contraseña debe tener entre 6 a 15 caracteres"<<endl;
        i_pass++;
        goto inputpass;
    }

    // Add to array
    srand(time(NULL)); // Initialize random seed
    int _id = ( rand()%8999 ) + 1000; // Generate random number from 1000 - 9999
    Person _new = Person{_id, _name, _lastname, _borndate, _dni, _password, 0, ""}; // Create person
    // We don't want to declare contactinfo yet so we initialize it as an empty string cuz its first element is string type variable
    accounts[_iac] = _new; // Add person to accounts array
    _iac++; // Iterate account array variable
    return 1; // Everything alright
}
bool _userExist(string _dni, string _pw){
    for(int i=0; i<_iac; i++){
        if( accounts[i].dni == _dni ){ // Account exists
            if(_pw != ""){ // Password check
                if( accounts[i].password == _pw ) return true; // Password is correct
                return false; // Password is incorrect
            }
            return true;
        }
    }
    return false;
}
int _getUserId(string _dni, string _pw){
    for(int i=0; i<_iac; i++){
        if( accounts[i].dni == _dni && accounts[i].password == _pw){ // Account verification
            return accounts[i].id; // Return account id
        }
    }
    return -1;
}
#endif
