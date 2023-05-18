#include <iostream>

using namespace std;

#include <iostream>
#include "Application.h"

int main() {
    // Create an instance of the Application
    Application app;

    // Set the name of the company
    app.SetnomEntreprise("My Company");

    // Create some articles and add them to the application
    Article article1;
    article1.Setreference("REF001");
    article1.Setdesignation("Article 1");
    article1.SetprixBase(10.0);
    app.ajouter(article1);

    Article article2;
    article2.Setreference("REF002");
    article2.Setdesignation("Article 2");
    article2.SetprixBase(15.0);
    app.ajouter(article2);

    // Create payment methods and calculate the payment amount
    PaiementPaypal paypalPayment;
    paypalPayment.Setidentifiant("PAY001");
    paypalPayment.SetidentifiantObjet("REF001");
    paypalPayment.Setdate("2023-05-18");
    paypalPayment.SetnumeroCompte("paypal_account123");
    float paypalAmount = app.calculerMontantPaiement(&paypalPayment, article1);

    PaiementCarteBancaire cardPayment;
    cardPayment.Setidentifiant("PAY002");
    cardPayment.SetidentifiantObjet("REF002");
    cardPayment.Setdate("2023-05-18");
    float cardAmount = app.calculerMontantPaiement(&cardPayment, article2);

    // Display the payment amounts
    std::cout << "Paypal Payment Amount: " << paypalAmount << std::endl;
    std::cout << "Card Payment Amount: " << cardAmount << std::endl;

    // Save the total base price to a file
    app.SaveAmountToFile("total_base_price.txt");

    return 0;
}
