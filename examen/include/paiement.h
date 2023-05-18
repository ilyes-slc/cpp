#ifndef PAIEMENT_H
#define PAIEMENT_H

using namespace std;

class paiement
{
    public:
        paiement();
        virtual ~paiement();

        string Getidentifiant() { return identifiant; }
        void Setidentifiant(string val) { identifiant = val; }
        string GetidentifiantObjet() { return identifiantObjet; }
        void SetidentifiantObjet(string val) { identifiantObjet = val; }
        string Getdate() { return date; }
        void Setdate(string val) { date = val; }

    protected:
        string identifiant;
        string identifiantObjet;
        string date;

    private:
};

#endif // PAIEMENT_H
