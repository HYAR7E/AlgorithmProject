#ifndef STRUCT_FILE
#define STRUCT_FILE
// Structures prototype
struct Person;
struct Worker;
struct Enterprise;

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
};
struct Worker{
    Person wData;
    string wProfession;
    string description;
    void setPerson(Person _person){ // Created by Person
        wData = _person;
    }
};
struct Enterprise{
    Person eDirector;
    string eName;
    string description;
    void setPerson(Person _person){ // Created by Person
        eDirector = _person;
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
