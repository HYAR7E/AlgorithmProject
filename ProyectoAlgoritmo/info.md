# ALGORITHM PROYECT - work agency
## by HYAR7E

    PROYECT ESPECIFICATIONS
        Struct data Profession is added as keywords like enginner, nurse, assassin, etc.
    *Main Menu
        *Register
        *Login
        *Exit
    Guest menu
        Choose accoun type
        Add contact info
    Worker menu
        Publish cv (add to workers) {check cv empty, min 15 rows}
        Look announcements {show table}
            Apply for work (show announcements paginated) {select by element index in table}
        Look enterprises
            Open chat
        Chats
        Applies status
        return main menu / exit
    Enterprise menu
        Change data {declare enterprise struct elements}
        Publish job offer (add to enterprise and request)
        Check out applicants
        Chats
        return main menu / exit
    Admin menu
        Look announcements
        Look worker
        Look enterprise
        Ban worker
        Ban enterprise
        Delete announcement
        return main menu / exit

    Enterprise sheet
        Show
            Information and contact
            Job vacancies
        Options
            Apply
    Worker sheet
        Show
            Information and contact
        Send job offer


    # Function's specifications
        In function, parameter variables should be declared with '_' prefix
        In function, when a variable is created to fill a formulary or a structure element, it should be declared with '_' prefix
        In function, parameter variable type can be emphasize by using '${type_name[0]}_' prefix as 'i_age' or 'x_name'
        In utilitaries functions, variables should be declared with no prefix
        In utilitaries functions, variables created to be compared should be declared with '_' prefix
        In user functions, user layer account menu functions should have the 'ac${account_type}_' prefix as ac0_changeInformation
        In user functions, global functions should be declared with no prefix as u_printData
    # Variable's specifications
        Global variables should be declared with no prefix in database.cpp (user)
        Global structures array should be declared with no prefix in database.cpp
        Global array iteration variables should be declared with '_i' prefix in database.cpp
        Static variables should be declared with 'st_' prefix
        When there is two or more variables with same name and different type, should be declared with '${type_name[0]}_' prefix
            In case of string type variable the prefix should be 'x_'
            Exm: string x_age; int i_age; char c_age; double d_age; bool b_age;
    # Operation explanation
        User layer is dedicated to interact with the user, get inputs and show outputs
            This layer sends data to process in Logical layer
            To communicate with Server layer have to pass through Logical layer
        Logical layer is dedicated to process all the data from User layer and Server layer
            This layer returns data to User layer and Server layer
        Server layer is dedicated to communicate with the database
    # Useful linux commands
        grep -iRl "text" // Search text in all files recursively(in the actual directory) and show file names where it was found


    CHANGES MADE v0.3 (login/register utilitarie functions)
        Separate functions into User, Logical and Server layer
        Added function to get date number (Y,M,D,h,m,s)
        Added function to calc valid date
        Changed Person.age to Person.borndate wich allows calculate age anytime
        Person.dni changed to string type for easier comparison
        Added check for valid F_Register->dni
        Added check for valid age in F_Register
        Added check min/max string length in function F_isString
        Removed name input of _login function (unnecessary)
        ERROR FIXED:
            ERROR: We can't declarate null contactinfo in _register function
            SOLUTION: We don't want to declare contactinfo yet so we initialize it as an empty string cuz its first element is string type. In f_program.cpp _register()

    CHANGES MADE v0.4 (global variables, control and usage of program)
        Storage static global variables into database.cpp
        Add global variable to control current account
        Static initial person(user) struct value accountype = -1
        Created variable 'user' for storage current user data
        Created function 'preload' to initialize variables
        Created function 'getpersonStruct' wich returns the Person struct of the current user
        Changed commentaries 'function declaration' to 'function prototype' and 'function explanation' to 'function declaration'
        Added 'online' element to Person struct
        Added 'set' function as a constructor in struct 'Person' with defaul values for accountype, contact and online
        Changed create user struct in register to use 'set' function of Person struct
        MOVE COMENTARIES ABOUT CHANGES MADE INTO A INFO FILE

    CHANGES MADE v0.5 (Bugs fixed, user pointer, all menus declared)
        Implemented function printMenu for scalability when adding more functions
        Added function to show all menus from account types
        Noticed that having a global variable 'user' is not secure at all cuz it is reachable from anywhere in the whole code
        Separate user/logical menu functions from other functions
        Global variable 'user' shall be a pointer to 'accounts' array element cuz we will made some changes when choosing account type and changing information
        Changed global variable user to be pointer and modified functions that use it
        Changed function getPersonStruct to *getPersonStructDirection
        Added logout in printMenu function
        Fixed bugs in _register and _login functions
        Added Request element description in structs.cpp
        Created new files 'f_menu.cpp','fu_guest.cpp','fu_worker.cpp','fu_enterprise.cpp','fu_admin.cpp'
        Changed file name 'f_program.cpp' to 'f_reglog.cpp'

    CHANGES MADE v0.6 ( Add worker && enterprise functions )
        Finalized _chooseAccountType with prevention of errors (only for worker and enterprise)
        Added elements 'w_ma' and 'e_ma' to Person structure (worker_memoryaddress && enterprise_memoryaddress)
            These elements lead to the "worker" and "enterprise" memory address
        Added store user into worker or enterprise array when account type has been selected
        Added function 'setPerson' in worker and enterprise structures to store Person element
        Added function 'setWorker' and 'setEnterprise' to storage element memory address in Person, and prevent errors
        Added function 'print${account_type}Data' for guest, worker and enterprise in structs.cpp
        Created new file 'fu_global.cpp'
        Added global function 'myData' in 'fu_global.cpp' to show data
            Reusable function that check if the logged in user is the one to be printed if so print element code and allows to edit data
            Used void data type variable
        Added global function 'changeData' in 'fu_global.cpp' to change user's data
            Used if sentences instead of switch sentence
            Changes are specified by element code printed in 'myData' only if it is the logged user
            Added restrictions to input values
            Added support for string with spaces
        Added isMail function in f_utilitaries.cpp
        *Active/inactive status of cv according to filled data
        *Do not allow to choose account type if there is empty user data
 


    CHANGES MADE v0.7 ( Add communication functions )
    CHANGES MADE v0.8 ( Add database conection and related functions )
    CHANGES MADE v0.9 ( Migrate to database functions )
    CHANGES MADE v0.9 ( Admin functions && Add GUI && hard look for errors )
    RELEASE v1.0 (delete debug commentaries)


