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
/* There is no reason why to use a pointer here */
// Person* p_user = NULL; // Initialize pointer with NULL value for good practices
Person *user = NULL;
static Person noone = Person{0};

// Static variables
char st_dateseparator = '/';
int st_clearlines = 8;

/*
    We're gonna check the users session by having a pointer to the current user struct variable
    so we're gonna get his data by pointer->user_data like p_user->id
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
    user = &noone;
    // cout<<user->accounttype<<endl; cin.ignore(1);
    return true;
}

#endif
