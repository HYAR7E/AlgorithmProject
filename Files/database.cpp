#ifndef DATABASE
#define DATABASE
// Arrays
// These arrays should be of variable type, no pointers cuz these store the structure data
static Person accounts[30]={0}; // It gets initializated with {0} cuz first element is int type
    // Can't declarate with Person{0} cuz it requires array elements
static int _iac = 0; // Iterator for accounts
static Worker workers[30]={0};
static int _iwk = 0; // Iterator for workers
static Enterprise enterprises[30]={0};
static int _iet = 0; // Iterator for enterprises
static Request requests[30]={0};
static int _irq = 0; // Iterator for requests

// Global variables
static Person *user = NULL; // Initialize pointer with NULL value for good practices
static Person noone = Person{0};

// Static variables
static const char st_dateseparator = '/';
static const int st_clearlines = 38;
static const int st_maxerror = 3;
static const int st_minage = 18;
static const int st_maxage = 65;
static const int st_minduration = 1;
static const int st_minpay = 800;
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
    _new.create(1111, "nelson", "agustin", "20/05/2000", "72112258", "neldoaf");
    _new.contact.email="asesino@gmail.trb";
    _new.contact.telf1="977865134";
    _new.contact.address="mikaza";
    _new.setAccountType(1);
    _new.setWorker( &workers[_iwk] ); // Set memory address before store in array
    accounts[_iac] = _new; // Add to accounts array
    workers[_iwk].setPerson(&accounts[_iac] ); // Add person to worker array element
    workers[_iwk].profession = "asesinador";
    _iac++; // Iterate
    _iwk++; // Iterate
    // workers[0].printData(true);
    /* BUG FIXED
        We use should use the global variable to set a pointer, otherwise they will store thrash data and will be UB(undefined behavior)
        workers[_iwk].setPerson(&accounts[_iac] );
    */
    Person _new1 = Person{0};
    _new1.create(2222, "kailen", "agustin falcon", "11/04/2000", "72112251", "kailen123");
    _new1.contact.email="cocinero@gmail.trb";
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
    Person _new11 = Person{0};
    _new11.create(3333, "carlos", "falcon", "11/04/2000", "72112252", "kailen123");
    _new11.contact.email="barrendero@gmail.trb";
    _new11.contact.telf1="977865134";
    _new11.contact.address="mikaza";
    _new11.setAccountType(1);
    _new11.setWorker( &workers[_iwk] );
    accounts[_iac] = _new11;
    workers[_iwk].setPerson(&accounts[_iac]);
    workers[_iwk].profession = "barrendero";
    _iac++;
    _iwk++;
    // workers[2].printData(true);
    _new1 = Person{0};
    _new1.create(9999, "Homero", "Thompson", "15/04/2001", "12345698", "jay123");
    _new1.contact.email="homero69@gmail.com";
    _new1.contact.telf1="978645312";
    _new1.contact.address="Springfield - Callefalsa N°123";
    _new1.setAccountType(0);
    accounts[_iac] = _new1;
    _iac++;


    // PRE SET ENTERPRISE
    Person _new2 = Person{0};
    // Add data
    _new2.create(4444, "jefe1", "boss", "18/07/2000", "12345673", "boos123");
    _new2.contact.email="mibakita@empresa.etp";
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
    _new3.create(5555, "jefe2", "boss", "22/05/1999", "12345674", "boos123");
    _new3.contact.email="inkofamra@empresa.etp";
    _new3.contact.telf1="977865134";
    _new3.contact.address="mikaza";
    _new3.setAccountType(2);
    _new3.setEnterprise( &enterprises[_iet] );
    accounts[_iac] = _new3;
    enterprises[_iet].setPerson(&accounts[_iac]);
    enterprises[_iet].name = "inkofarma sac";
    _iac++;
    _iet++;
    // enterprises[1].printData(true);


    // PRE SET REQUEST
    Request _new4 = Request{0};
    _new4.create(6666,&enterprises[0],"asesinador",1200,8,1,19,28,"necesito alguien que mate los mosquitos de mi fabrica");
    requests[_irq] = _new4;
    enterprises[0].addRequest( &requests[_irq] );
    // myJobOffer();
    _irq++;
    Request _new5 = Request{0};
    _new5.create(7777,&enterprises[0],"cocinero",900,8,3,22,48,"necesito alguien que sazone bien a mis pollos");
    requests[_irq] = _new5;
    enterprises[0].addRequest( &requests[_irq] );
    // myJobOffer();
    _irq++;
    Request _new6 = Request{0};
    _new6.create(8888,&enterprises[1],"soplavelas",850,1,1,18,20,"no puedo soplar las velas de mi pastel de cumpleaños");
    requests[_irq] = _new6;
    enterprises[1].addRequest( &requests[_irq] );
    // myJobOffer();
    _irq++;


    // PRE SET APPLIES
    requests[0].addApplicant(accounts[0].w_ma);
    requests[1].addApplicant(accounts[1].w_ma);


    // PRE SET ADMIN
    Person _admin = Person{0};
    // Add data
    _admin.create(0000, "admin", "god", "01/02/1993", "25478260", "admin");
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
