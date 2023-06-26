#ifndef PLAT_H
#define PLAT_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;


class Plat
{
    public:
        Plat();
        virtual ~Plat();

        string Getdesignation() { return designation; }
        void Setdesignation(string val) { designation = val; }
        string Getdate_vente() { return date_vente; }
        void Setdate_vente(string val) { date_vente = val; }
        void afficher();

    protected:

    private:
        string designation;
        string date_vente;
        vector<int> tab_ing;
};

#endif // PLAT_H
