#include "Plat.h"

Plat::Plat()
{
    //ctor
}

Plat::~Plat()
{
    //dtor
}


void Plat::afficher()
{
    cout << "Plat details:\n";
    cout << "Designation: " << designation << "\n";
    cout << "Date de vente: " << date_vente << "\n";
    cout << "Ingredients:\n";
    for (int i = 0; i < tab_ing.size(); ++i)
    {
        cout << "- Ingredient ID: " << tab_ing[i] << "\n";
    }
}
