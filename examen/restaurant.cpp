#include "restaurant.h"

restaurant::restaurant()
{
    //ctor
}

restaurant::~restaurant()
{
    for (Ingredient* ingredient : tab_ingredients)
    {
        delete ingredient;
    }
    tab_ingredients.clear();
}

restaurant::restaurant(const restaurant& other)
{
    nom = other.nom;

    for (vector<Plat>::const_iterator it = other.tab_plats.begin(); it != other.tab_plats.end(); ++it)
    {
        this->tab_plats.push_back(*it);
    }

    for (vector<Ingredient*>::const_iterator it = other.tab_ingredients.begin(); it != other.tab_ingredients.end(); ++it)
    {
        if (typeid(**it) == typeid(Supplement))
        {
            Supplement* supplement = static_cast<Supplement*>(*it);
            this->tab_ingredients.push_back(new Supplement(*supplement));
        }
        else
        {
            Ingredient* ingredient = static_cast<Ingredient*>(*it);
            this->tab_ingredients.push_back(new Ingredient(*ingredient));
        }
    }
}


restaurant& restaurant::operator=(const restaurant& other)
{
    if (this != &other)
    {
        tab_plats.clear();

        for (Ingredient* ingredient : tab_ingredients)
        {
            delete ingredient;
        }
        tab_ingredients.clear();

        nom = other.nom;

        for (vector<Plat>::const_iterator it = other.tab_plats.begin(); it != other.tab_plats.end(); ++it)
        {
            this->tab_plats.push_back(*it);
        }

        for (vector<Ingredient*>::const_iterator it = other.tab_ingredients.begin(); it != other.tab_ingredients.end(); ++it)
        {
            if (typeid(**it) == typeid(Supplement))
            {
                Supplement* supplement = static_cast<Supplement*>(*it);
                this->tab_ingredients.push_back(new Supplement(*supplement));
            }
            else
            {
                Ingredient* ingredient = static_cast<Ingredient*>(*it);
                this->tab_ingredients.push_back(new Ingredient(*ingredient));
            }
        }
    }
    return *this;
}


void restaurant::ajouterNouveauPlat(Plat plat)
{
    vector<Plat>::iterator it;
    for (it = tab_plats.begin(); it != tab_plats.end(); ++it)
    {
        if (it->Getdesignation() == plat.Getdesignation())
        {
            return;
        }
    }
    tab_plats.push_back(plat);
}


vector<Ingredient*>::iterator restaurant::rechercherSupplement(const string& nomSupplement)
{
    for (vector<Ingredient*>::iterator it = tab_ingredients.begin(); it != tab_ingredients.end(); ++it)
    {
      //  if ((*it).Getnom() == nomSupplement)
            return it;
    }
    return tab_ingredients.end();
}

vector<Ingredient>::iterator restaurant::rechercherIngredient(const string& nomIngredient)
{
  /*  for (vector<Ingredient*>::iterator it = tab_ingredients.begin(); it != tab_ingredients.end(); ++it)
    {
        if ((*it).Getnom() == nomIngredient)
            return it;
    }
    return tab_ingredients.end();*/
}

void restaurant::ajouterSupplement(const Supplement& supplement)
{
    try
    {
        if (rechercherSupplement(supplement.Getnom()) == tab_supplements.end())
        {
            tab_supplements.push_back(supplement);
        }
        else
        {
            throw string("Le supplement existe deja !");
        }
    }
    catch (const string& ch)
    {
        cerr << ch << endl;
    }
}

void restaurant::ajouterIngredient(const Ingredient& ingredient)
{
    try
    {
        if (rechercherIngredient(ingredient.Getnom()) == tab_ingredients.end())
        {
            tab_ingredients.push_back(ingredient);
        }
        else
        {
            throw string("L'ingredient existe deja !");
        }
    }
    catch (const string& ch)
    {
        cerr << ch << endl;
    }
}

int restaurant::nombrePlatsUtilisantIngredient(const Ingredient& ingredient)
{
    int count = 0;

    for (const Plat& plat : tab_plats)
    {
        for (const int& ingredientID : plat.tab_ing)
        {
            if (ingredientID == ingredient.Getidentifiant())
            {
                count++;
                break;  // On passe au plat suivant dès qu'on trouve l'ingrédient
            }
        }
    }

    return count;
}


void restaurant::enregistrerSupplementsParCategorie(int categorie)
{
    ofstream fichier("Restaurant.txt");

    if (fichier.is_open())
    {
        fichier << "Suppléments de la catégorie " << categorie << ":" << endl;

        for (Ingredient* ingredient : tab_ingredients)
        {
            if (Supplement* supplement = dynamic_cast<Supplement*>(ingredient))
            {
                if (supplement->Getcategorie() == categorie)
                {
                    fichier << "Nom: " << supplement->Getnom() << endl;
                    fichier << "Identifiant: " << supplement->Getidentifiant() << endl;
                    fichier << "Prix: " << supplement->Getprix() << endl;
                    fichier << "Quantité: " << supplement->Getquantite() << endl;
                    fichier << endl;
                }
            }
        }

        fichier.close();
        cout << "Les suppléments de la catégorie " << categorie << " ont été enregistrés dans le fichier 'Restaurant.txt'." << endl;
    }
    else
    {
        cerr << "Impossible d'ouvrir le fichier 'Restaurant.txt'." << endl;
    }
}




