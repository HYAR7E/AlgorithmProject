// Worker User Functions
#ifndef FU_WORKER
#define FU_WORKER
/*** FUNCTIONS PROTOTYPE ***/
// Capa Usuario

// Capa Logica
#ifndef PROTO_APPLYOFFER
#define PROTO_APPLYOFFER
bool applyForJobOffer(int _idjob); // Apply to job offer prototype function
#endif

// Capa Servidor


/*** FUNCTIONS DECLARATION ***/
/* ### USER LAYER ### */

/* ### LOGIC LAYER ### */
// If this file is declared before or after the fu_global.cpp file is included, there would not be any error
bool applyForJobOffer(int _idjob){
    if( user->accounttype != 1 ) return false; // Check that logged in user is worker
    if( !jobOfferExists(_idjob) ) return false; // Check that job offer is available

    Request* _r = NULL;
    _r = getRequestStructAddress(_idjob); // Pass request ma

    // Check if job specifications fit with user's characteristics
    // Check age
    if( getAge(user->borndate) > _r->maxAge || getAge(user->borndate) < _r->minAge ) return false;
    // Check profession
    if( user->w_ma->profession != _r->rProfession ) return false;

    // Add applicant
    if( !_r->addApplicant(user->w_ma) ) return false; // Check that job offer is not full

    return true;
}

/* ### SERVER LAYER ### */

#endif
