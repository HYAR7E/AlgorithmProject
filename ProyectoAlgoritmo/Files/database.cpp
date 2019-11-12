#ifndef DATABASE
#define DATABASE
// Arrays
Person accounts[30]={0}; // It gets initializated with {0} cuz first element is int type
    // Can't declarate with Person{0} cuz it requires array elements
int _iac = 0; // Iterator for accounts
Worker workers[30]={0};
int _iwk = 0; // Iterator for workers
Enterprise enterprises[30]={0};
int _iet = 0; // Iterator for enterprises
Request requests[30]={0};
int _irq = 0; // Iterator for requests

// Global variables
Person *user = NULL; // Initialize pointer with NULL value for good practices
static Person noone = Person{0};

// Static variables
char st_dateseparator = '/';
int st_clearlines = 8;
/*
    We're gonna check the users session by having a pointer to the current user struct variable
    so we're gonna get his data by pointer->person_element like user->id, and make changes to their data too
    We're gonna store the user's struct variable but when the user get to be a worker or a enterprise account we should
*/
#endif

#ifndef PreLoad
#define PreLoad
bool preload(){
    // Declaration of empty user 'noone'
    noone.id = 0;
    noone.name = "";
    noone.lastname = "";
    noone.accounttype = -1;
    noone.w_ma = NULL;
    noone.e_ma = NULL;
    user = &noone;
    // cout<<user->accounttype<<endl; cin.ignore(1);


/*
*/
    // PRE SET WORKER
    Person _new = Person{0};
    // Add data
    _new.set(1111, "nelson", "agustin", "20/05/2000", "72112258", "neldoaf");
    _new.contact.email="a@b.c";
    _new.contact.telf1="977865134";
    _new.contact.address="mikaza";
    _new.setAccountType(1);
    _new.setWorker( &workers[_iwk] ); // Set memory address before store in array
    accounts[_iac] = _new; // Add to accounts array
    workers[_iwk].setPerson(&accounts[_iac] ); // Add person to worker array element
    workers[_iwk].profession = "asesinador";
    _iac++; // Iterate
    _iwk++; // Iterate
    workers[0].printData(true);
    /* BUG FIXED
        We use should use the global variable to set a pointer, otherwise they will store thrash data and will be UB(undefined behavior)
        workers[_iwk].setPerson(&accounts[_iac] );
    */





    Person _new1 = Person{0};
    _new1.set(2222, "kailen", "agustin falcon", "11/04/2000", "72112251", "kailen123");
    _new1.contact.email="a@b.c";
    _new1.contact.telf1="977865134";
    _new1.contact.address="mikaza";
    _new1.setAccountType(1);
    _new1.setWorker( &workers[_iwk] );
    accounts[_iac] = _new1;
    workers[_iwk].setPerson(&accounts[_iac]);
    workers[_iwk].profession = "cocinero";
    _iac++;
    _iwk++;
    // workers[1].printData(true);
    Person _new5 = Person{0};
    _new5.set(6666, "carlos", "falcon", "11/04/2000", "72112252", "kailen123");
    _new5.contact.email="a@b.c";
    _new5.contact.telf1="977865134";
    _new5.contact.address="mikaza";
    _new5.setAccountType(1);
    _new5.setWorker( &workers[_iwk] );
    accounts[_iac] = _new5;
    workers[_iwk].setPerson(&accounts[_iac]);
    workers[_iwk].profession = "barrendero";
    _iac++;
    _iwk++;
    // workers[2].printData(true);


    // PRE SET ENTERPRISE
    Person _new2 = Person{0};
    // Add data
    _new2.set(3333, "jefe1", "boss", "18/07/2000", "12345673", "boos123");
    _new2.contact.email="a@b.c";
    _new2.contact.telf1="987654321";
    _new2.contact.address="mikaza";
    _new2.setAccountType(2);
    _new2.setEnterprise( &enterprises[_iet] );
    accounts[_iac] = _new2;
    enterprises[_iet].setPerson(&accounts[_iac]);
    enterprises[_iet].name = "mibakita sac";
    _iac++;
    _iet++;
    // enterprises[0].printData(true);
    Person _new3 = Person{0};
    _new3.set(4444, "jefe2", "boss", "22/05/1999", "12345674", "boos123");
    _new3.contact.email="a@b.c";
    _new3.contact.telf1="977865134";
    _new3.contact.address="mikaza";
    _new3.setAccountType(2);
    _new3.setEnterprise( &enterprises[_iet] );
    accounts[_iac] = _new3;
    enterprises[_iet].setPerson(&accounts[_iac]);
    enterprises[_iet].name = "inkofarma sac";
    _iac++;
    _iet++;
    // cout<<"_new3.id: "<<_new3.id<<endl;
    // cout<<"_new3.e_ma: "<<_new3.e_ma<<endl;
    // cout<<"enterprises[1].one.id: "<<enterprises[1].one.id<<endl;
    // cout<<"enterprises[1].one.e_ma: "<<enterprises[1].one.e_ma<<endl;
    // enterprises[1].printData(true);


    // PRE SET REQUEST
    Request _new4 = Request{0};
    _new4.create(5555,enterprises[0],"asesino",1200,8,1,20,28,"necesito alguien que mate los mosquitos de mi fabrica");
    enterprises[0].addRequest( &_new4 );
    requests[_irq] = _new4;
    _irq++;


    // PRE SET ADMIN
    Person _admin = Person{0};
    // Add data
    _admin.set(0000, "admin", "god", "01/02/1993", "25478260", "admin");
    _admin.contact.email="admin@root.ez";
    _admin.contact.telf1="987654321";
    _admin.contact.address="milap";
    _admin.setAccountType(3);
    accounts[_iac] = _admin; // Add to accounts array
    _iac++; // Iterate

    // cin.ignore();
/**/


    return true;
}
#endif
