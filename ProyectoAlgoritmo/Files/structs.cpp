#ifndef STRUCT_FILE
#define STRUCT_FILE
struct ContactInfo{
    string email;
    string telf1;
    string telf2;
    string address;
};
struct Person{
    int id; // For security reasons we can't have the dni as the id of person, so we create a random number
    string name;
    string lastname;
    /* Variable type (?) */string borndate; // Allows calculate age DD/MM/AAAA
    /* Variable type (?) */string dni;
    string password;
    // Elements with default values
    short accounttype; // 0: Guest  1: Worker  2: Enterprise -1: undefined || default: 0
    ContactInfo contact; // email, telf1, telf2, address, personContact || default: ""
    bool online; // true: online  false: offline || default: false
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
    }
};
struct Worker{
    Person wData;
    string wProfession;
    string description;
};
struct Enterprise{
    Person eDirector;
    string eName;
    string description;
};
struct Request{
    Enterprise rEnterprise;
    string rProfession;
    short rSalary; // Amount in dollars
    short rWorkDuration; // Time in months
    short rDuration; // Time in months
    short rAmount; // Number of people requested
    short minAge;
    short maxAge;
};
struct Applications{ // Apply for working
    Person aPerson;
    Request aRequest;
    string aMessaege;
};

#endif
