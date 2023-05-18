#include "Application.h"


using namespace std;

Application::Application()
{
    //ctor
}

Application::Application(const Application& other)
{
     nomEntreprise = other.GetnomEntreprise();

    // Deep copy the articles
    articles.clear();
    articles.reserve(other.articles.size());
    for (const auto& article : other.articles)
    {
        articles.push_back(article);
    }

    // Deep copy the paiements
    paiements.clear();
    paiements.reserve(other.paiements.size());
    for (const auto& paiement : other.paiements)
    {
        if (typeid(*paiement) == typeid(PaiementPaypal))
        {
            const PaiementPaypal* paypal = dynamic_cast<const PaiementPaypal*>(paiement);
            paiements.push_back(new PaiementPaypal(*paypal));
        }
        else if (typeid(*paiement) == typeid(PaiementCarteBancaire))
        {
            const PaiementCarteBancaire* carteBancaire = dynamic_cast<const PaiementCarteBancaire*>(paiement);
            paiements.push_back(new PaiementCarteBancaire(*carteBancaire));
        }
    }
}


Application::~Application()
{
    //Delete all dynamically allocated paiements
    for (auto* paiement : paiements)
    {
        delete paiement;
    }
    paiements.clear();
}


Application& Application::operator=(const Application& other)
{
    if (this != &other)
    {
        Clear();
            nomEntreprise = other.GetnomEntreprise();

    // Deep copy the articles
    articles.clear();
    articles.reserve(other.articles.size());
    for (const auto& article : other.articles)
    {
        articles.push_back(article);
    }

    // Deep copy the paiements
    paiements.clear();
    paiements.reserve(other.paiements.size());
    for (const auto& paiement : other.paiements)
    {
        if (typeid(*paiement) == typeid(PaiementPaypal))
        {
            const PaiementPaypal* paypal = dynamic_cast<const PaiementPaypal*>(paiement);
            paiements.push_back(new PaiementPaypal(*paypal));
        }
        else if (typeid(*paiement) == typeid(PaiementCarteBancaire))
        {
            const PaiementCarteBancaire* carteBancaire = dynamic_cast<const PaiementCarteBancaire*>(paiement);
            paiements.push_back(new PaiementCarteBancaire(*carteBancaire));
        }
    }
    }
    return *this;
}


float Application::calculerMontantPaiement(Paiement* paiement, Article a)
{
    float montant = a.GetprixBase();


    // Calcul des frais supplémentaires en fonction du type de paiement
    if (typeid(*paiement) == typeid(PaiementPaypal))
    {
        double fraisFixe = prixBase * 0.01;
        double fraisVariable = (prixBase > 30000) ? prixBase * 0.03 : 0.0;
        montant += fraisFixe + fraisVariable;
    }
    else if (typeid(*paiement) == typeid(PaiementCarteBancaire))
    {
        double tauxTransaction = prixBase * 0.05;
        montant += tauxTransaction;
    }

    return montant;
}

void Application::ajouter(Article article)
{
    // Vérifier si l'article existe déjà
    for (const Article& existingArticle : articles)
    {
        if (existingArticle.Getidentifiant() == article.Getidentifiant())
        {
            throw new std::runtime_error("L'article existe déjà.");
        }
    }

    // Ajouter l'article à la liste des articles
    articles.push_back(article);
}

Application::double GetTotalBasePrice()
    {
        double totalBasePrice = 0.0;
        for (const auto& article : articles)
        {
            totalBasePrice = totalBasePrice + article;
        }
        return totalBasePrice;
    }

        void Application::SaveAmountToFile(const string& filename)
    {
        ofstream file(filename);
        if (file.is_open())
        {
            file << "Amount: " << basePrice << endl;
            file.close();
        }
        else
        {
            cout << "Error: Unable to open file." << endl;
        }
    }


