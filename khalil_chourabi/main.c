#include <stdio.h>
#include <stdlib.h>
#include "header.h"


int main() {
    LDC liste;
    liste.debut = NULL;
    liste.fin = NULL;

    ABR* arbre = NULL;

    int choix;
    do {
        printf("1. Ajouter un etudiant\n");
        printf("2. Afficher les etudiants ayant un ordinateur empruntes\n");
        printf("3. Ajouter un ordinateur au stock\n");
        printf("4. Emprunter un ordinateur\n");
        printf("5. Enregistrer dans un fichier les ordinateurs non empruntes\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: {
                Etudiant etudiant = saisir_etudiant();
                arbre = inserer_etudiant(arbre, etudiant);
                printf("Etudiant ajoute avec succes.\n");
                break;
            }
            case 2:
                afficher_etud_emprunt(liste, arbre);
                break;
            case 3:
                liste = ajouter_ord(liste);
                break;
            case 4:
                emprunter_ord(liste, arbre);
                break;
            case 5:
                enregistrer("ordinateurs_non_empruntes.txt", liste);
                printf("Ordinateurs non empruntes enregistres dans le fichier.\n");
                break;
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
                break;
        }

        printf("\n");
    } while (choix != 0);

    return 0;
}
