#ifndef INGREDIENT_H
#define INGREDIENT_H
#include <string>
#include <iostream>

using namespace std;
class Ingredient
{
    public:
        Ingredient();
        virtual ~Ingredient();

        int Getidentifiant() { return identifiant; }
        void Setidentifiant(int val) { identifiant = val; }
        string Getnom() { return nom; }
        void Setnom(string val) { nom = val; }
        float Getprix() { return prix; }
        void Setprix(float val) { prix = val; }
        int Getquantite() { return quantite; }
        void Setquantite(int val) { quantite = val; }
        void afficher();

    protected:
        int identifiant;
        string nom;
        float prix;
        int quantite;

    private:
};

#endif // INGREDIENT_H
