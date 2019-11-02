## ALGORITHM PROYECT - work agency
# by HYAR7E

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
        Publish cv (add to workers)
        Look announcements
        Apply for work (show announcements paginated)
        return main menu / exit
    Enterprise menu
        Publish job offer (add to enterprise and request)
        Check out applicants
        return main menu / exit
    Admin menu
        Look databases
        New activities
        Delete accounts
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
        In function, when we want to emphasize the parameter variable type use '${type_name[0]_' prefix as 'i_age' or 'x_name'
        In utilitaries functions, variables should be declared with no prefix
        In utilitaries functions, variables created to be compared should be declared with '_' prefix
    # Variable's specifications
        Global variables should be declared with no prefix in database.cpp (user)
        Global structures array should be declared with no prefix in database.cpp
        Global array iteration variables should be declared with '_i' prefix in database.cpp
        Static variables should be declared with 'st_' prefix
        When there is two or more variables with same name and different type, should be declared with '${type_name[0]}_' prefix
            In case of string type variable the prefix should be 'x_'
            Exm: string x_age; int i_age; char c_age; double d_age; bool b_age;


    CHANGES MADE v0.3
        Separate functions into User, Logic and Server layer
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

    CHANGES MADE v0.4
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




