#ifndef STRUCT_FILE
#define STRUCT_FILE
// Structures prototype
struct Person;
// Previous definition of worker and enterprise to allow the variable type for memory address storage in Person
struct Worker;
struct Enterprise;
struct Request;

// In printData function, when _code is false do not show data, or do not show empty data

// Structures declaration
struct ContactInfo{
    string email;
    string telf1;
    string telf2;
    string address;
    void setEmail(string _email){
        email = _email;
    }
    void setTelf1(string _telf1){
        telf1 = _telf1;
    }
    void setTelf2(string _telf2){
        telf2 = _telf2;
    }
    void setAddress(string _address){
        address = _address;
    }
    void printContactData(bool _code){
        // Print code for modification
        cout<< (_code ? "cem \t":"") <<"Email: "<<email<<endl;
        cout<< (_code ? "ct1 \t":"") <<"Telefono 1: "<<telf1<<endl;
        cout<< (_code ? "ct2 \t":"") <<"Telefono 2: "<<telf2<<endl;
        cout<< (_code ? "cad \t":"") <<"Direccion: "<<address<<endl;
    }
};
struct Person{
    int id; // For security reasons we can't have the dni as the id of person, so we create a random number
    string name;
    string lastname;
    /* Variable type (?) */string borndate; // Allows calculate age DD/MM/AAAA
    /* Variable type (?) */string dni;
    string password;
    // Elements with default values
    int accounttype; // 0: Guest  1: Worker  2: Enterprise 3: Admin -1: undefined || default: 0
    ContactInfo contact; // email, telf1, telf2, address, personContact || default: ""
    bool online; // true: online  false: offline || default: false
    Worker* w_ma; // Memory address of the Worker or Enterprise struct owned by this Person
    Enterprise* e_ma; // Memory address of the Worker or Enterprise struct owned by this Person
        // A Enterprise can be owned by more than one person
// Setter functions
    bool set(int _id, string _name, string _lastname, string _borndate, string _dni, string _password){ // Constructor or setter
        if( id!=0 ) return false; // Only allow to set data once
        id = _id;
        name = _name;
        lastname = _lastname;
        borndate = _borndate;
        dni = _dni;
        password = _password;
        // Default valuess
        accounttype = 0;
        contact = ContactInfo{""}; // Declare an empty ContactInfo structure
    // We don't want to declare contactinfo yet so we initialize it as an empty string cuz its first element is string type variable
        online = false;
        w_ma = NULL; // Memory address empty
        e_ma = NULL; // Memory address empty
    };
    bool setAccountType(int _actype){
        if( accounttype!=0 ) return false; // Only allow to set of account type if the user is a guest yet
        if( _actype==0 ) return false; // Do not allow to set account type to Guest
        accounttype = _actype;
        return true;
    }
    bool setWorker(Worker *_w_ma){ // Parameter is worker array element memory address
        if( accounttype!=1 ) return false; // Only allow if Person account type is Worker
        if( w_ma!=NULL ) return false; // Worker ma is already setted
        w_ma = _w_ma;
        return true;
    }
    bool setEnterprise(Enterprise *_e_ma){ // Parameter is enterprise array element memory address
        if( accounttype!=2 ) return false; // Only allow if Person account type is Enterprise
        if( e_ma!=NULL ) return false; // Enterprise ma is already setted
        e_ma = _e_ma;
        return true;
    }
    // Print function
    void printData(bool _code){ // Print code for modification
        if( _code ) cout<<"    \tID: "<<id<<endl; // Only if it's the actual user
        cout<< (_code ? "pnm\t":"") <<"Nombre: "<<name<<endl;
        cout<< (_code ? "pln\t":"") <<"Apellido: "<<lastname<<endl;
        if( _code ) cout<<"pwd \tContrasena: "<<password<<endl; // Only if it's the actual user
        cout<< (_code ? "   \t":"") <<"Fecha de nacimiento: "<<borndate<<endl;
        if( _code ) cout<<"    \tDNI: "<<dni<<endl; // Only if it's the actual user
        cout<< (_code ? "   \t":"") <<"Activo ahora: "<< ( online? "SI":"NO" ) <<endl;
        contact.printContactData(_code); // Contact data && send _code
    }
};
struct Worker{
    Person one;
    string profession;
    string description;
    void setPerson(Person _person){ // Created by Person
        one = _person;
    }
    void printData(bool _code){
        cout<<"Informacion del trabajador"<<endl;
        one.printData(_code); // Person data && end _code
        cout<< (_code ? "wpf\t":"") <<"Profesion: "<<profession<<endl;
        cout<< (_code ? "wdc\t":"") <<"Descripcion del perfil: "<<description<<endl;
    }
};
struct Enterprise{
    Person one;
    string name;
    string description;
    // Requests memory address
    Request* r_ma[5]; // One enterprise can post up to 5 job requests
    void setPerson(Person _person){ // Created by Person
        one = _person;
        // Request ma initializated to NULL
        r_ma[0] = NULL;
        r_ma[1] = NULL;
        r_ma[2] = NULL;
        r_ma[3] = NULL;
        r_ma[4] = NULL;
    }
    void printData(bool _code){
        cout<<"\nInformacion de la empresa\n"<<endl;
        cout<< (_code ? "enm\t":"") <<"Nombre: "<<name<<endl;
        cout<< (_code ? "edc\t":"") <<"Descripcion: "<<description<<endl;
        if( _code ){ // If it's the actual user
            cout<<"Informacion del director\n"<<endl;
            one.printData(_code); // Print director data
        }else{ // Shown as enterprise information
            cout<<"Telefono: "<<one.contact.telf1<<endl;
            cout<<"Email: "<<one.contact.email<<endl;
            cout<<"Direccion: "<<one.contact.address<<endl;
        }
    }
    bool addRequest(Request *_r_ma){
        for(int _i=0; _i<5; _i++){ // Iterate the 5 elements in array
            if( r_ma[_i] == NULL ){ // If rma if empty
                r_ma[_i] = _r_ma; // Store rma
                return true; // _rma stored
            }
        }
        return false; // All spaces ocupated
    }
    int countRequests(){
        for(int _i=0; _i<5; _i++){
            if( r_ma[_i] == NULL ) return _i; // If rma is empty then return the iterator value
        }
        return 5; // All requests spaces available ocupated
    }
};
struct Request{
    int id;
    Enterprise rEnterprise;
    string rProfession;
    int rSalary; // Amount in dollars
    int rWorkDuration; // Time in months
    int rAmount; // Number of people requested
    int minAge;
    int maxAge;
    string description; // Description of the work
    bool create(int _id, Enterprise _e, string _p, int _s, int _d, int _a, int _minage, int _maxage, string _dsc){
        id = _id;
        rEnterprise = _e;
        rProfession = _p;
        rSalary = _s;
        rWorkDuration = _d;
        rAmount = _a;
        minAge = _minage;
        maxAge = _maxage;
        description = _dsc;
        return true;
    }
};
struct Applicants{ // Applicants for working
    Person aPerson;
    Request aRequest;
    string aMessaege;
};
#endif
