#ifndef STRUCT_FILE
#define STRUCT_FILE
struct Person{
    int id;
    string name;
    string lastname;
    short age;
    string telf; // Phone number
    string password;
    short accounttype; // 0: Guest  1: Worker  2: Enterprise
};
struct Worker{
    Person wData;
    string wProfession;
};
struct Enterprise{
    string eName;
    Person eDirector;
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
