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

// Global variables
// Person* p_user = NULL; // Initialize pointer with NULL value for good practices
Person *user = NULL;
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
    // usuarios predefinidos

    Person _new = Person{0};
    // Add data
    _new.set(1111, "neldo", "agustin", "20/05/2000", "72112258", "neldoaf");
    _new.contact.email="a@b.c";
    _new.contact.telf1="977865134";
    _new.contact.address="mikaza";
    _new.setAccountType(1);
    _new.setWorker( &workers[_iwk] ); // Set memory address before store in array
    workers[_iwk].setPerson(_new); // Add person to worker array element
    _iwk++; // Iterate
    accounts[_iac] = _new; // Add to accounts array
    _iac++; // Iterate
    // cout<<"_new.w_ma: "<<_new.w_ma<<endl;
    // cout<<"workers[0].one.id: "<<workers[0].one.id<<endl;
    // cout<<"workers[0].one.w_ma: "<<workers[0].one.w_ma<<endl;

    Person _new1 = Person{0};
    _new1.set(2222, "kailen", "agustin falcon", "11/04/2000", "72112251", "kailen123");
    _new1.contact.email="a@b.c";
    _new1.contact.telf1="977865134";
    _new1.contact.address="mikaza";
    _new1.setAccountType(1);
    _new1.setWorker( &workers[_iwk] );
    workers[_iwk].setPerson(_new1);
    _iwk++;
    accounts[_iac] = _new1;
    _iac++;
    // cout<<"_new1.w_ma: "<<_new1.w_ma<<endl;
    // cout<<"workers[1].one.id: "<<workers[1].one.id<<endl;
    // cout<<"workers[1].one.w_ma: "<<workers[1].one.w_ma<<endl;
    // workers[0].printData(false);
    // cin.ignore();
/**/


    return true;
}
#endif
