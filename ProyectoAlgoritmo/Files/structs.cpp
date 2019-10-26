#ifndef STRUCT_FILE
#define STRUCT_FILE
struct ContactInfo{
    string email;
    string telf1;
    string telf2;
    string address;
};
struct Person{
    int id;
    string name;
    string lastname;
    /* Variable type (?) */string borndate; // Allows calculate age DD/MM/AAAA
    /* Variable type (?) */string dni;
    string password;
    short accounttype; // 0: Guest  1: Worker  2: Enterprise
    ContactInfo contact; // email, telf1, telf2, address, personContact
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
