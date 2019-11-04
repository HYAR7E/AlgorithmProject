// Register-Login functions
#ifndef REGLOG_FILE
#define REGLOG_FILE
/*** FUNCTIONS PROTOTYPE ***/

// Capa Usuario
int _login();
int _register(); // Register is named with '_' prefix cuz 'register' is a keyword

// Capa Logica
bool userExists(string _dni, string _pw=""); // Check if exists a user with the given data
int getUserId(string _dni, string _pw); // We can't mix the functions getUserId with userExist for security good practices
Person *getPersonStructDirection(int _userid); // Get user struct direction from accounts array and return it to store in 'user' global pointer variable
bool userIdExists(int _userid); // We can't mix the functions getPersonStruct with userIdExists for security good practices
int genUniqueRandId(); // Generate a random number and check if it is already taken

// Capa Servidor
bool pullChangesInUser(); // Send changes in user account to database
// bool pushChanges(); // Get changes in user account to database


/*** FUNCTIONS DECLARATION ***/
/* ### USER LAYER ### */
int _login(){
    string _name, _dni, _password;

    cout<<"DNI: "; cin>>_dni;
    if( !isNumber(_dni) || _dni.length() != 8 ) return -1;

    if( !userExists(_dni) ) return -2; // User don't exists

    int i_pass=1;
    inputpass:
    cout<<"Contrasena: "; cin>>_password;
    if( !userExists(_dni,_password) ){
        if(i_pass==3) return 0; // Password incorrect
        cout<<"Contraseña incorrecta"<<endl;
        i_pass++;
        goto inputpass;
    }

    // Get logged user struct direction
    user = getPersonStructDirection( getUserId(_dni,_password) );
    // For security and scalability reasons we should get the user structure variable through the user id
// cout<<user->id<<" - "<<user->accounttype<<endl; cin.ignore(3);
    return 1;
}
int _register(){
    string _name, _lastname, _dni, _password, _borndate;

    // Ask personal data
    cout<<"Nombre: "; cin>>_name;
    if( !isString(_name,3) ) return -1;
    cout<<"Primer apellido: "; cin>>_lastname;
    if( !isString(_lastname,4) ) return -1;

    // BornDate
    cout<<"Fecha de nacimiento DD/MM/AAAA :"; cin>>_borndate;
    if( !isValidDate(_borndate) ) return -1; // Check date
    if( !isValidDate(_borndate, true) ) return -2; // Check age

    // Ask and check dni
    cout<<"DNI: "; cin>>_dni;
    if( !isNumber(_dni) || _dni.length() != 8 ) return -1;

    // Verify dni already exist
    if( userExists(_dni) ) return 0; // User already exists

    int i_pass=1;
    inputpass:
    cout<<"Contraseña: "; cin>>_password; // We can't use isString or isInt function cuz this could be any character or number
    if( _password.length()<6 || _password.length()>15 ){ // Amount of characters in password
        if( i_pass >= 3) return -3;
        cout<<"La contraseña debe tener entre 6 a 15 caracteres, y debe contener solo numeros o letras"<<endl;
        i_pass++;
        goto inputpass;
    }

    // For security reasons we can't have the dni as the id of person, so we create a random number
    int _id = genUniqueRandId(); // Generate a random number and check if it is not taken
// cout<<_id<<endl; cin.ignore(1);

    Person _new = Person{0}; // Create empty Person structure
    _new.set(_id, _name, _lastname, _borndate, _dni, _password); // Add data to Person structure of user
    accounts[_iac] = _new; // Add person to accounts array
// cout<<accounts[_iac].id<<" - "<<accounts[_iac].accounttype<<endl; cin.ignore(1);
    _iac++; // Iterate account array variable
    return 1; // Everything alright
}


/* ### LOGIC LAYER ### */
bool userExists(string _dni, string _pw){
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
int getUserId(string _dni, string _pw){
    for(int i=0; i<_iac; i++){
        if( accounts[i].dni == _dni && accounts[i].password == _pw){ // Account verification
            return accounts[i].id; // Return account id
        }
    }
    return -1;
}
Person *getPersonStructDirection(int _userid){
    for(int i=0; i<_iac; i++){
        if( accounts[i].id == _userid ){
            return &accounts[i]; // Return account pointer
        }
    }
    return 0; // There is no way a person can't be found, otherwise it would lead to an error
};
bool userIdExists(int _userid){
    for(int i=0; i<_iac; i++){
        if( accounts[i].id == _userid ){ // Account verification
            return true; // Return account id
        }
    }
    return false;
};
int genUniqueRandId(){
    int _rd = -1;
    bool _r = false;
    srand(time(NULL)); // Initialize random seed
    _rd = ( rand()%8999 ) + 1000; // Generate random number from 1000 - 9999
    // Check if it is already taken
    /* SERVER FUNCTION */
    do{
        _r = userIdExists(_rd);
    }while( _r );
    return _rd;
}



#endif
