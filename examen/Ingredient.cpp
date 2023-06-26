#include "Ingredient.h"
using namespace std;

Ingredient::Ingredient()
{
    //ctor
}

Ingredient::~Ingredient()
{
    //dtor
}

void Ingredient::afficher()
{
    cout << "Ingredient details:\n";
    cout << "Identifiant: " << identifiant << "\n";
    cout << "Nom: " << nom << "\n";
    cout << "Prix: " << prix << "\n";
    cout << "Quantite: " << quantite << "\n";
}

