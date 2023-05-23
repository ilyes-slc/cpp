#include "header.h"

Etudiant saisir_etudiant() {
    Etudiant etudiant;
    printf("Saisir l'identifiant de l'etudiant : ");
    scanf("%d", &etudiant.identifiant);
    printf("Saisir le nom de l'etudiant : ");
    scanf("%s", etudiant.nom);
    printf("Saisir la classe de l'etudiant : ");
    scanf("%s", etudiant.classe);
    return etudiant;
}

ABR* inserer_etudiant(ABR* arbre, Etudiant etudiant) {
    if (arbre == NULL) {
        ABR* nouveau = (ABR*)malloc(sizeof(ABR));
        nouveau->etudiant = etudiant;
        nouveau->gauche = NULL;
        nouveau->droite = NULL;
        return nouveau;
    }

    if (etudiant.identifiant < arbre->etudiant.identifiant) {
        arbre->gauche = inserer_etudiant(arbre->gauche, etudiant);
    } else if (etudiant.identifiant > arbre->etudiant.identifiant) {
        arbre->droite = inserer_etudiant(arbre->droite, etudiant);
    }

    return arbre;
}

ABR* chercher_etudiant(ABR* arbre, int id) {
    if (arbre == NULL || arbre->etudiant.identifiant == id) {
        return arbre;
    }

    if (id < arbre->etudiant.identifiant) {
        return chercher_etudiant(arbre->gauche, id);
    } else {
        return chercher_etudiant(arbre->droite, id);
    }
}

void afficher_etud_emprunt(LDC liste, ABR* arbre) {
    Cellule* courant = liste.debut;
    while (courant != NULL) {
        if (courant->ordinateur.etat == 0) {
            ABR* etudiant = chercher_etudiant(arbre, courant->ordinateur.id_etudiant);
            if (etudiant != NULL) {
                printf("Identifiant : %d, Nom : %s, Classe : %s\n",
                       etudiant->etudiant.identifiant, etudiant->etudiant.nom, etudiant->etudiant.classe);
            }
        }
        courant = courant->suivant;
    }
}

Cellule* chercher_ord(LDC liste, int id) {
    Cellule* courant = liste.debut;
    while (courant != NULL) {
        if (courant->ordinateur.identifiant == id) {
            return courant;
        }
        courant = courant->suivant;
    }
    return NULL;
}

void saisir_ord(Ordinateur* ordinateur, LDC liste) {
    printf("Saisir l'identifiant de l'ordinateur : ");
    scanf("%d", &ordinateur->identifiant);
    printf("Saisir la marque de l'ordinateur : ");
    scanf("%s", ordinateur->marque);
    ordinateur->etat = 1;
    ordinateur->id_etudiant = -1;
}

LDC ajouter_ord(LDC liste) {
    Ordinateur ordinateur;
    saisir_ord(&ordinateur, liste);
    Cellule* nouvelle_cellule = (Cellule*)malloc(sizeof(Cellule));
    nouvelle_cellule->ordinateur = ordinateur;
    nouvelle_cellule->suivant = NULL;

    if (liste.debut == NULL) {
        liste.debut = nouvelle_cellule;
        liste.fin = nouvelle_cellule;
        nouvelle_cellule->precedent = NULL;
    } else {
        nouvelle_cellule->precedent = liste.fin;
        liste.fin->suivant = nouvelle_cellule;
        liste.fin = nouvelle_cellule;
    }

    return liste;
}

void emprunter_ord(LDC liste, ABR* arbre) {
    int id_etudiant;
    printf("Saisir l'identifiant de l'etudiant : ");
    scanf("%d", &id_etudiant);

    Cellule* courant = liste.debut;
    while (courant != NULL) {
        if (courant->ordinateur.etat == 1) {
            courant->ordinateur.etat = 0;
            courant->ordinateur.id_etudiant = id_etudiant;
            ABR* etudiant = chercher_etudiant(arbre, id_etudiant);
            if (etudiant != NULL) {
                printf("L'ordinateur %d a ete emprunte par l'etudiant %d\n",
                       courant->ordinateur.identifiant, etudiant->etudiant.identifiant);
            }
            return;
        }
        courant = courant->suivant;
    }
    printf("Aucun ordinateur disponible pour l'emprunt.\n");
}

LDC retirer_ord(LDC liste) {
    Cellule* courant = liste.debut;
    while (courant != NULL) {
        if (courant->ordinateur.etat == 0) {
            if (courant == liste.debut && courant == liste.fin) {
                liste.debut = NULL;
                liste.fin = NULL;
            } else if (courant == liste.debut) {
                liste.debut = courant->suivant;
                liste.debut->precedent = NULL;
            } else if (courant == liste.fin) {
                liste.fin = courant->precedent;
                liste.fin->suivant = NULL;
            } else {
                courant->precedent->suivant = courant->suivant;
                courant->suivant->precedent = courant->precedent;
            }

            free(courant);
            courant = liste.debut;
        } else {
            courant = courant->suivant;
        }
    }
    return liste;
}

void enregistrer(char* nomFichier, LDC liste) {
    FILE* fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    Cellule* courant = liste.debut;
    while (courant != NULL) {
        if (courant->ordinateur.etat == 1) {
            fprintf(fichier, "Identifiant : %d, Marque : %s\n",
                    courant->ordinateur.identifiant, courant->ordinateur.marque);
        }
        courant = courant->suivant;
    }

    fclose(fichier);
}


