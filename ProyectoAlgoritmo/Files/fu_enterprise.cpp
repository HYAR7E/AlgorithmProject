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
    int _ei = 0; // Error iterator
    int _maxerror = 2; // Maximous amount of error allowed
    string _msg=""; // Mensaje a ser modificado

    clear();

    _ei=0;
    do{ // Profesion
        cout<<"Profesion requerida: "; cin>>_profession; pauseClear();
        if( !isString(_profession) || _profession.length()<4 || _profession.length()>20 ){ // Is not string, contains special characters or is not long enough
            if( _ei == _maxerror ){
                cout<<"Maxima cantidad de errores permitidos, abortando"<<endl;
                return; // Exit the function
            }
            cout<<"La profesion debe contener entre 4 y 20 letras"<<endl; // Error
            _ei++; // Iterate error amount
        }else{ // It is alrigth
            break; // Continue
        }
    }while(true);

    _msg = "Introduzca un numero valido mayor que o igual que " + to_string(st_minpay);
    _salary = getValidIntInput("Salario ofrecido (min:"+to_string(st_minpay)+"): ",_msg,st_minpay); pauseClear();
    if( _salary == -1 ){ // Result of error
        cout<<"Maxima cantidad de errores permitidos, abortando"<<endl;
        return;
    }

    _msg = "Introduzca un numero valido mayor o igual que " + to_string(st_minduration);
    _duration = getValidIntInput("Duracion del trabajo en meses: ",_msg,st_minduration); pauseClear();
    if( _duration == -1 ){ // Result of error
          cout<<"Maxima cantidad de errores permitidos, abortando"<<endl;
          return;
    }

    _amount = getValidIntInput("Cantidad de personas requeridas: ","Introduzca un numero valido",1); pauseClear();
    if( _amount == -1 ){ // Return of error
      cout<<"Maxima cantidad de errores permitidos, abortando"<<endl;
      return;
    }

    _msg = "Introduzca un numero valido mayor o igual que " + to_string(st_minage);
    _minage = getValidIntInput("Edad minima para el trabajo("+to_string(st_minage)+"): ",_msg,st_minage); pauseClear();
    if( _minage == -1 ){ // Return of error
       cout<<"Maxima cantidad de errores permitidos, abortando"<<endl;
       return;
    }

    _msg = "Introduzca un numero valido menor o igual que " + to_string(st_maxage);
    _maxage = getValidIntInput("Edad maxima para el trabajo("+to_string(st_maxage)+"): ",_msg,st_minage,st_maxage); pauseClear();
    if( _maxage == -1 ){ // Return of error
      cout<<"Maxima cantidad de errores permitidos, abortando"<<endl;
      return;
    }

    _ei=0; // Reiniciate error iterator
    do{ // Description
        cout<<"Descripcion del trabajo: "; getline(cin,_profession);
        if( !isString(_profession) || _profession.length()<8 ){
            if( _ei == _maxerror ){
                cout<<"Maxima cantidad de errores permitidos, abortando"<<endl;
                return; // Exit the function
            }
            cout<<"La profesion debe contener al menos 8 caracteres"<<endl; // Error
            _ei++; // Iterate error amount
        }else{ // It is alright
            break; // Continue
        }
    }while(true);

    bool _result;
    _result = _postJobOffers(user->e_ma,_profession,_salary,_duration,_amount,_minage,_maxage,_description); // Send to logical layer
    if( _result ){
        cout<<"\nLa oferta de trabajo se agrego correctamente."<<endl;
    }else{
        cout<<"\nSe ha producido un error y los datos no han podido ser procesados."<<endl;
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
