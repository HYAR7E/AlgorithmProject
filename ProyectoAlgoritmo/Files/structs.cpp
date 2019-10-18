#ifndef STRUCT_FILE
#define STRUCT_FILE
struct Person{
    string name;
    string lastname;
    short age;
    string telf; // Phone number
    string password;
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

#endif
