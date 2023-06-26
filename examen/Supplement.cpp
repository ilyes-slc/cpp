#include "Supplement.h"

Supplement::Supplement()
{
    //ctor
}

Supplement::~Supplement()
{
    //dtor
}


void Supplement::afficher()
{
    Ingredient::afficher();

    cout << "Categorie: " << categorie << "\n";
}
