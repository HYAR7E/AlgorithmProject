#ifndef DATABASE
#define DATABASE

// Arrays
Person accounts[30]={};
int _iac = 0; // Iterator for accounts
Worker workers[30]={};
int _iwk = 0; // Iterator for workers
Enterprise enterprises[30]={};
int _iet = 0; // Iterator for enterprises

// Global variables
int _accountID = -1; // Actual sesion account id
int accountType = 0; // 0: Guest  1: Worker  2: Enterprise


#endif
