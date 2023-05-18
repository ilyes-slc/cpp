#ifndef PAIEMENTPAYPAL_H
#define PAIEMENTPAYPAL_H

#include <paiement.h>

using namespace std;

class PaiementPaypal : public Paiement
{
    public:
        PaiementPaypal();
        virtual ~PaiementPaypal();

        string GetnumeroCompte() { return numeroCompte; }
        void SetnumeroCompte(string val) { numeroCompte = val; }

    protected:
        string numeroCompte;

    private:
};

#endif // PAIEMENTPAYPAL_H
