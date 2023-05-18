#ifndef PAIEMENTCARTEBANCAIRE_H
#define PAIEMENTCARTEBANCAIRE_H

#include <paiement.h>

using namespace std;

class PaiementCarteBancaire : public Paiement
{
    public:
        PaiementCarteBancaire();
        virtual ~PaiementCarteBancaire();

    protected:

    private:
};

#endif // PAIEMENTCARTEBANCAIRE_H
