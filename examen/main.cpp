#include "Ingredient.h"
#include "Supplement.h"
#include "Plat.h"
#include "restaurant.h"

int main()
{
    Ingredient ingr1;
    ingr1.Setidentifiant(1);
    ingr1.Setnom("Sel");
    ingr1.Setprix(1.5);
    ingr1.Setquantite(10);

    Supplement supp1;
    supp1.Setidentifiant(2);
    supp1.Setnom("Sucre");
    supp1.Setprix(2.0);
    supp1.Setquantite(5);
    supp1.Setcategorie(1);

    Plat plat1;
    plat1.Setdesignation("Plat 1");
    plat1.Setdate_vente("2023-06-26");
    plat1.ajouterIngredient(&ingr1);
    plat1.ajouterIngredient(&supp1);

    restaurant restau;
    restau.Setnom("Restaurant 1");

    restau.ajouterPlat(plat1);

    cout << "Informations du plat :" << endl;
    restau.afficherPlats();

    restau.enregistrerSupplementsParCategorie(1);

    return 0;
}
