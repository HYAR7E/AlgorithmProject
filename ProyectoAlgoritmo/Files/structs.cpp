#ifndef STRUCT_FILE
#define STRUCT_FILE
// Structures prototype
struct Person;
// Previous definition of worker and enterprise to allow the variable type for memory address storage in Person
struct Worker;
struct Enterprise;


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
        // if( address != "") cout<<"\tDireccion: "<<address<<endl; // Do not show empty data
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
        accounttype = _actype;
        return true;
    }
    bool setWorker(Worker *_w_ma){ // Parameter is worker array element memory address
        if( accounttype!=1 ) return false; // Only allow if Person account type is Worker
        w_ma = _w_ma;
        return true;
    }
    bool setEnterprise(Enterprise *_e_ma){ // Parameter is enterprise array element memory address
        if( accounttype!=2 ) return false; // Only allow if Person account type is Enterprise
        e_ma = _e_ma;
        return true;
    }
    // Print function
    void printData(bool _code){
        // Print code for modification
        cout<< (_code ? "   \t":"") <<"ID: "<<id<<endl;
        cout<< (_code ? "pnm\t":"") <<"Nombre: "<<name<<endl;
        cout<< (_code ? "pln\t":"") <<"Apellido: "<<lastname<<endl;
        cout<< (_code ? "pwd\t":"") <<"Contrasena: "<<password<<endl;
        cout<< (_code ? "   \t":"") <<"Fecha de nacimiento: "<<borndate<<endl;
        cout<< (_code ? "   \t":"") <<"DNI: "<<dni<<endl;
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
        cout<<"Informacion del trabajador\n"<<endl;
        one.printData(_code); // Person data && end _code
        cout<< (_code ? "wpf\t":"") <<"Profesion: "<<profession<<endl;
        cout<< (_code ? "wdc\t":"") <<"Descripcion del perfil: "<<description<<endl;
    }
};
struct Enterprise{
    Person one;
    string name;
    string description;
    void setPerson(Person _person){ // Created by Person
        one = _person;
    }
    void printData(bool _code){
        cout<<"Informacion del director\n"<<endl;
        one.printData(_code); // Print director data
        cout<<"\nInformacion de la empresa\n"<<endl;
        cout<< (_code ? "enm\t":"") <<"Nombre: "<<name<<endl;
        cout<< (_code ? "edc\t":"") <<"Descripcion: "<<description<<endl;
    }
};
struct Request{
    Enterprise rEnterprise;
    string rProfession;
    int rSalary; // Amount in dollars
    int rWorkDuration; // Time in months
    int rDuration; // Time in months
    int rAmount; // Number of people requested
    int minAge;
    int maxAge;
    string description; // Description of the work
};
struct Applicants{ // Applicants for working
    Person aPerson;
    Request aRequest;
    string aMessaege;
};
#endif
