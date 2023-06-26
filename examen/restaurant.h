#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <iostream>
#include "Plat.h"
#include "Ingredient.h"
#include "Supplement.h"
using namespace std;
class restaurant
{
    public:
        restaurant();
        virtual ~restaurant();
        restaurant(const restaurant& other);
        restaurant& operator=(const restaurant& other);

        string Getnom() { return nom; }
        void Setnom(string val) { nom = val; }
        void ajouterNouveauPlat(Plat plat);
vector<Ingredient*>::iterator rechercherSupplement(const string& nomSupplement);
        vector<Ingredient>::iterator rechercherIngredient(const string& nomIngredient);
        void ajouterIngredient(const Ingredient& ingredient);
        void ajouterSupplement(const Supplement& supplement);
        int nombrePlatsUtilisantIngredient(const Ingredient& ingredient);
        void enregistrerSupplementsParCategorie(int categorie);






    protected:

    private:
        string nom;
        vector<Plat> tab_plats;
        vector<Ingredient*> tab_ingredients;

};

#endif // RESTAURANT_H
