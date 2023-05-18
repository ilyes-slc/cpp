#ifndef APPLICATION_H
#define APPLICATION_H
#include <vector>
#include "PaiementPaypal.h"
#include "paiement.h"
#include "PaiementCarteBancaire.h"
using namespace std;


class Application
{
    public:
        Application();
        Application(const Application& other);  // Copy constructor
        Application& operator=(const Application& other);  // Assignment operator
        void ajouter(Article article)
        virtual ~Application();  // Destructor
        float calculerMontantPaiement(Paiement* paiement, Article a);

        string GetnomEntreprise() { return nomEntreprise; }
        void SetnomEntreprise(string val) { nomEntreprise = val; }
        double GetTotalBasePrice();
        void SaveAmountToFile(const string& filename);

    protected:

    private:
        string nomEntreprise;
        vector<Article> articles;
        vector<Paiement*> paiements;
};

#endif // APPLICATION_H
