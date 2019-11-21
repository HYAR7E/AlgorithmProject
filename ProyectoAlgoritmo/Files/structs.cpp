#ifndef STRUCT_FILE
#define STRUCT_FILE
// Structures prototype
struct ContactInfo;
struct Person;
// Previous definition of worker and enterprise to allow the variable type for memory address storage in Person
struct Worker;
struct Request; // Request before Enterprise cuz enterprise::getJob() uses request elements
struct Enterprise;
struct Application;

#ifndef PROTO_CURDATE
#define PROTO_CURDATE
string getCurrentDate(); // Returns a string with the current date (no time)
#endif

static const int st_maxapplicants = 30;
static const int st_maxrequest = 5;

// Structures declaration
struct ContactInfo{
    string email;
    string telf1;
    string telf2;
    string address;
    void setEmail(string _email){
        this->email = _email;
    };
    void setTelf1(string _telf1){
        this->telf1 = _telf1;
    };
    void setTelf2(string _telf2){
        this->telf2 = _telf2;
    };
    void setAddress(string _address){
        this->address = _address;
    };
    void printContactData(bool _code){
        // Print code for modification
        cout<< (_code ? "cem \t":"") <<"Email: "<<this->email<<endl;
        cout<< (_code ? "ct1 \t":"") <<"Telefono 1: "<<this->telf1<<endl;
        cout<< (_code ? "ct2 \t":"") <<"Telefono 2: "<<this->telf2<<endl;
        cout<< (_code ? "cad \t":"") <<"Direccion: "<<this->address<<endl;
    };
};
struct Person{
    int id; // For security reasons we can't have the dni as the id of person, so we create a random number
    string name;
    string lastname;
    /* Variable type (?) */string borndate; // Allows calculate age DD/MM/AAAA
    /* Variable type (?) */string dni;
    string password;
    // Elements with default values
    int accounttype; // 0: Guest  1: Worker  2: Enterprise 3: Admin -1: undefined || default: 0
    ContactInfo contact; // email, telf1, telf2, address, personContact || default: ""
    bool online; // true: online  false: offline || default: false
    Worker* w_ma; // Memory address of the Worker or Enterprise struct owned by this Person
    Enterprise* e_ma; // Memory address of the Worker or Enterprise struct owned by this Person
        // A Enterprise can be owned by more than one person
// Setter functions
    bool create(int _id, string _name, string _lastname, string _borndate, string _dni, string _password){ // Constructor or setter
        if( this->id!=0 ) return false; // Only allow to set data once
        this->id = _id;
        this->name = _name;
        this->lastname = _lastname;
        this->borndate = _borndate;
        this->dni = _dni;
        this->password = _password;
        // Default valuess
        this->accounttype = 0;
        this->contact = ContactInfo{""}; // Declare an empty ContactInfo structure
    // We don't want to declare contactinfo yet so we initialize it as an empty string cuz its first element is string type variable
        this->online = false;
        this->w_ma = NULL; // Memory address empty
        this->e_ma = NULL; // Memory address empty
    };
    bool setAccountType(int _actype){
        if( this->accounttype!=0 ) return false; // Only allow to set of account type if the user is a guest yet
        if( _actype==0 ) return false; // Do not allow to set account type to Guest
        this->accounttype = _actype;
        return true;
    };
    bool setWorker(Worker *_w_ma){ // Parameter is worker array element memory address
        if( this->accounttype!=1 ) return false; // Only allow if Person account type is Worker
        if( this->w_ma!=NULL ) return false; // Worker ma is already setted
        this->w_ma = _w_ma;
        return true;
    };
    bool setEnterprise(Enterprise *_e_ma){ // Parameter is enterprise array element memory address
        if( this->accounttype!=2 ) return false; // Only allow if Person account type is Enterprise
        if( this->e_ma!=NULL ) return false; // Enterprise ma is already setted
        this->e_ma = _e_ma;
        return true;
    };
    // Print function
    void printData(bool _code){ // Print code for modification
        if( _code ) cout<<"    \tID: "<<this->id<<endl; // Only if it's the actual user
        cout<< (_code ? "pnm\t":"") <<"Nombre: "<<this->name<<endl;
        cout<< (_code ? "pln\t":"") <<"Apellido: "<<this->lastname<<endl;
        if( _code ) cout<<"pwd \tContrasena: "<<this->password<<endl; // Only if it's the actual user
        cout<< (_code ? "   \t":"") <<"Fecha de nacimiento: "<<this->borndate<<endl;
        if( _code ) cout<<"    \tDNI: "<<this->dni<<endl; // Only if it's the actual user
        cout<< (_code ? "   \t":"") <<"Activo ahora: "<< ( this->online? "SI":"NO" ) <<endl;
        this->contact.printContactData(_code); // Contact data && send _code
    };
};
struct Worker{
    Person* one;
    string profession;
    string description;
    Application* applications[st_maxrequest]; // One worker may apply to up to 5 job requests
    void setPerson(Person *_person){ // Created by Person
        this->one = _person;
        // applications auto sets to null
    };
    void printData(bool _code){
        cout<<"Informacion del trabajador"<<endl;
        this->one->printData(_code); // Person data && end _code
        cout<< (_code ? "wpf\t":"") <<"Profesion: "<<this->profession<<endl;
        cout<< (_code ? "wdc\t":"") <<"Descripcion del perfil: "<<this->description<<endl;
    };
    int countApplications(){
        for(int i=0; i<st_maxrequest; i++){
            if( this->applications[i] == NULL ) return i; // If ama is empty then return the iterator value
        }
        return st_maxrequest; // All requests spaces available ocupated
    };
    bool addApplication(Application *_a_ma){
        if( _a_ma == NULL ) return false;
        if( this->countApplications() < st_maxrequest ){
            this->applications[ countApplications() ] = _a_ma; // Store ama
            return true; // _ama stored
        }
        return false; // All spaces ocupated
    };
    Application* getApplication(int _idjob); // Get the application structure
    void printApplications();
};
// Many requests many workers => interaction create an applicant
struct Application{ // Applies for working
    Request* request;
    Worker* one;
    string joindate;
    bool status; // 1: accepted  0: denied
    bool create(Request *_r_ma, Worker *_w_ma){
        // Add this ma to worker structure
        if( !_w_ma->addApplication(this) ) return false; // Add application to worker
        this->one = _w_ma;
        this->request = _r_ma;
        this->status = false;
        this->joindate = getCurrentDate();
        return true;
    }
    void printApplication(int _actype);
};
struct Request{ // Job offer
    int id;
    Enterprise* rEnterprise;
    string rProfession;
    int rSalary; // Amount in dollars
    int rWorkDuration; // Time in months
    int rAmount; // Number of people requested
    int minAge;
    int maxAge;
    string description; // Description of the work
    Application applicants[st_maxapplicants]; // Applicants, max 30
    bool create(int _id, Enterprise *_e, string _p, int _s, int _d, int _a, int _minage, int _maxage, string _dsc){
        this->id = _id;
        this->rEnterprise = _e;
        this->rProfession = _p;
        this->rSalary = _s;
        this->rWorkDuration = _d;
        this->rAmount = _a;
        this->minAge = _minage;
        this->maxAge = _maxage;
        this->description = _dsc;
        // applicants auto initializated to NULL - false - ""
        return true;
    };
    int countApplicants(){
        for(int _i=0; _i<st_maxapplicants; _i++){
            if( this->applicants[_i].one == NULL ) return _i; // If applicant ma is empty then return the iterator value
        }
        return st_maxapplicants; // All applicants spaces available ocupated
    };
    bool isApplying(Worker *_w_ma){
        for(int i=0; i< this->countApplicants() ; i++){
            if( this->applicants[i].one->one->id == _w_ma->one->id ) return true;
        }
        return false;
    }
    bool addApplicant(Worker *_w_ma){
        if( _w_ma == NULL ) return false;
        if( this->countApplicants() < st_maxapplicants ){ // Add Aplicant
            int i = this->countApplicants();
            // Verify if worker is already applying
            if( this->isApplying(_w_ma) ) return false; // Worker already applying
            // Set values to applicant
            if( !this->applicants[i].create(this, _w_ma) ) return false; // Problem adding applicant to worker structure
            return true; // _rma stored
        }
        return false; // All spaces ocupated
    };
    void printApplications();
    void printRequest(bool _code){
        cout<<"\nInformacion de la solicitud\n"<<endl;
        if(_code) cout<<"   \tID: "<<this->id<<endl;
        cout<< (_code ? "rpf\t":"") <<"Profesion: "<<this->rProfession<<endl;
        cout<< (_code ? "rsl\t":"") <<"Salario: "<<this->rSalary<<endl;
        cout<< (_code ? "rwd\t":"") <<"Duracion: "<<this->rWorkDuration<<endl;
        cout<< (_code ? "rpr\t":"") <<"Personas requeridas: "<<this->rAmount<<endl;
        cout<< (_code ? "rmi\t":"") <<"Edad minima: "<<this->minAge<<endl;
        cout<< (_code ? "rma\t":"") <<"Edad maxima: "<<this->maxAge<<endl;
        cout<< (_code ? "rdc\t":"") <<"Descripcion: "<<this->description<<endl;
        if(_code) cout<<"   \tCantidad de postulantes: "<< this->countApplicants() <<endl;
    };
};
struct Enterprise{
    Person* one;
    string name;
    string description;
    // Requests memory address
    Request* r_ma[st_maxrequest]; // One enterprise can post up to 5 job requests
    bool setPerson(Person *_person){ // Created by Person
        if( _person == NULL ) return false;
        this->one = _person;
        // r_ma auto initializated to NULL
        return true;
    };
    void printData(bool _code){
        cout<<"\nInformacion de la empresa"<<endl;
        cout<< (_code ? "enm\t":"") <<"Nombre: "<<this->name<<endl;
        cout<< (_code ? "edc\t":"") <<"Descripcion: "<<this->description<<endl;
        if( _code ){ // If it's the actual user
            cout<<"\nInformacion del director"<<endl;
            this->one->printData(_code); // Print director data
        }else{ // Shown as enterprise information
            cout<<"Telefono: "<<this->one->contact.telf1<<endl;
            cout<<"Email: "<<this->one->contact.email<<endl;
            cout<<"Direccion: "<<this->one->contact.address<<endl;
        }
    };
    int countRequests(){
        for(int i=0; i<st_maxrequest; i++){
            if( this->r_ma[i] == NULL ) return i; // If rma is empty then return the iterator value
        }
        return st_maxrequest; // All requests spaces available ocupated
    };
    bool addRequest(Request *_r_ma){
        if( _r_ma == NULL ) return false;
        if( this->countRequests() < st_maxrequest ){
            // cout<<"count: "<< countRequests() <<endl;
            this->r_ma[ countRequests() ] = _r_ma; // Store rma
            // cout<<"r_ma[ ]->id: "<<r_ma[ countRequests()-1 ]->id<<endl;
            // cout<<"count: "<< countRequests() <<endl;
            return true; // _rma stored
        }
        return false; // All spaces ocupated
    };
    Request* getRequest(int _idjob){
        for(int i=0; i<this->countRequests(); i++){
            if( this->r_ma[i]->id == _idjob ) // Verify if the given job equals r_ma[i]->job
                return this->r_ma[i]; // Request ma
        }
        return NULL;
    };
};
// Remaining functions
Application* Worker::getApplication(int _idjob){ // Get the application structure
  for(int i=0; i<this->countApplications(); i++){
      if( this->applications[i]->request->id == _idjob ) // Verify if the given job equals the job application
          return this->applications[i]; // Request ma
  }
  return NULL;
};
void Worker::printApplications(){
    if( countApplications() == 0 ){ // There is no applications yet
        cout<<"Ud. aun no ha postulado a ningun trabajo";
        return;
    }
    // Print applications
    cout<<"\nTrabajos"<<endl;
    cout<<" ID\t\tProfesion\t\tSalario\t\tEmpresa\t\t\tEstado\tFecha"<<endl;
    for(int i=0; i<countApplications(); i++){
        applications[i]->printApplication(1); // Print applications for worker
    }
    cout<<endl<<endl;
}

void Request::printApplications(){
    if( countApplicants() == 0 ){ // There is no applications yet
        cout<<"Aun no hay postulantes al trabajo";
        return;
    }
    // Print applications
    cout<<"\nPostulantes"<<endl;
    cout<<" ID\t\tNombre\t\tProfesion\tEmail\t\t\t\tEstado\t\t\tFecha"<<endl;
    for(int i=0; i<countApplicants(); i++){
        applicants[i].printApplication(2); // Print applications for worker
    }
    cout<<endl<<endl;
}

void Application::printApplication(int _actype){
    switch(_actype){
        case 1:
            cout<< this->request->id;
            cout<<"\t\t";
            cout<< this->request->rProfession;
            cout<<"\t\t";
            cout<< this->request->rSalary;
            cout<<"\t\t";
            cout<< this->request->rEnterprise->name;
            break;
        case 2:
            cout<< this->one->one->id;
            cout<<"\t\t";
            cout<< this->one->one->name;
            cout<<"\t\t";
            cout<< this->one->profession;
            cout<<"\t";
            cout<< this->one->one->contact.email;
            break;
    }
    cout<<"\t\t";
    cout<< (this->status ? "contratado":"pendiente");
    cout<<"\t\t";
    cout<< this->joindate;
    cout<<endl;
}

#endif
