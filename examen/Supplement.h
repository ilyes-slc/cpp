#ifndef SUPPLEMENT_H
#define SUPPLEMENT_H
#include <string>
#include <iostream>

#include <Ingredient.h>

using namespace std;

class Supplement : public Ingredient
{
    public:
        Supplement();
        virtual ~Supplement();

        int Getcategorie() { return categorie; }
        void Setcategorie(int val) { categorie = val; }
        void afficher();
    protected:

    private:
        int categorie;
};

#endif // SUPPLEMENT_H
