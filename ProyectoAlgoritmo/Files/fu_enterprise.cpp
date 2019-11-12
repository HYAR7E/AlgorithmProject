// Enterprise User Functions
#ifndef FU_ENTERPRISE
#define FU_ENTERPRISE
/*** FUNCTIONS PROTOTYPE ***/
// Capa Usuario
void ac2_postJobOffers(); // Post job offers
// Capa Logica
bool _postJobOffers(Enterprise *_e, string _p, int _s, int _d, int _a, int _minage, int _maxage, string _dsc);
// Capa Servidor


/*** FUNCTIONS DECLARATION ***/
/* ### USER LAYER ### */
void ac2_postJobOffers(){
    // if user is not enterprise type or if it is and does not have a enterprise ma setted
    if( user->accounttype != 2 || user->e_ma == NULL ) return; // Verify that the one using this function is enterprise type
    // Colect the job offer data and send it to logical layer function
    string _profession, _description;
    int _salary, _duration, _amount, _minage, _maxage;

    clear();
    cout<<"Profesion requerida: "; cin>>_profession; pauseClear();
    if( !isString(_profession) ){ // Is not string, contains special characters or is not long enough
        if( _profession.length() < 4 ) cout<<"La profesion debe contener 4 caracteres"<<endl;
        else cout<<"Un error ha ocurrido y el dato no ha podido ser procesado"<<endl;
    }

    _salary = getValidIntInput("Salario ofrecido: ","Introduzca un numero valido mayor que 800"); pauseClear();
    if( _salary < 800 ){
        cout<<"Error en el monto"<<endl;
        return;
    }
    _duration = getValidIntInput("Duracion del trabajo en meses: ","Introduzca un numero valido mayor o igual que 6"); pauseClear();
    if( _duration < 6 ){
        cout<<"La duracion minima de un trabajo es de un semestre"<<endl;
        return;
    }
    _amount = getValidIntInput("Cantidad de personas requeridas: ","Introduzca un numero valido"); pauseClear();
    if( _amount < 1 ){
        cout<<"La cantidad minima de trabajadores es 1"<<endl;
        return;
    }

    _minage = getValidIntInput("Edad minima para el trabajo: ","Introduzca un numero valido"); pauseClear();
    if( _minage < 18 ){
        cout<<"La edad minima para trabajar es 18"<<endl;
        return;
    }
    _maxage = getValidIntInput("Edad maxima para el trabajo: ","Introduzca un numero valido"); pauseClear();
    if( _maxage > 65 ){
        cout<<"La edad maxima para trabajar es 65"<<endl;
        return;
    }
    cout<<"Descripcion del trabajo: "; getline(cin,_description);
    if( _description.length() < 8 ){
        cout<<"La descripcion debe contener minimo 8 letras."<<endl;
        return;
    }

    bool _result;
    _result = _postJobOffers(user->e_ma,_profession,_salary,_duration,_amount,_minage,_maxage,_description); // Send to logical layer
    if( _result ){
        cout<<"La oferta de trabajo se agrego correctamente."<<endl;
    }else{
        cout<<"Se ha producido un error y los datos no han podido ser procesados."<<endl;
    }
}
/* ### LOGIC LAYER ### */
bool _postJobOffers(Enterprise *_e, string _p, int _s, int _d, int _a, int _minage, int _maxage, string _dsc){
    bool _result=false;
    Request _r = Request{0}; // Declarate request variable
    int _id = genUniqueRandId(2); // Generate a random number id(2: request type) and check if it is not taken

    _result = _r.create(_id,*_e,_p,_s,_d,_a,_minage,_maxage,_dsc); // Pass values to request
    if( !_result ) return false; // If fail return false

    requests[_irq] = _r; // Store request in global array
    _e->addRequest( &requests[_irq] ); // Add request in enterprise variable
    _irq++; // Iterate global requests iterator

    return true;
}

/* ### SERVER LAYER ### */

#endif
