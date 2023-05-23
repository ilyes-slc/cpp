#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int identifiant;
    char marque[50];
    int etat;
    int id_etudiant;
} Ordinateur;

typedef struct {
    int identifiant;
    char nom[50];
    char classe[50];
} Etudiant;

typedef struct Cellule {
    Ordinateur ordinateur;
    struct Cellule* suivant;
    struct Cellule* precedent;
} Cellule;

typedef struct {
    Cellule* debut;
    Cellule* fin;
} LDC;

typedef struct ABR {
    Etudiant etudiant;
    struct ABR* gauche;
    struct ABR* droite;
} ABR;


Etudiant saisir_etudiant();
ABR* inserer_etudiant(ABR* arbre, Etudiant etudiant);
ABR* chercher_etudiant(ABR* arbre, int id);
void afficher_etud_emprunt(LDC liste, ABR* arbre);
Cellule* chercher_ord(LDC liste, int id);
void saisir_ord(Ordinateur* ordinateur, LDC liste);
LDC ajouter_ord(LDC liste);
void emprunter_ord(LDC liste, ABR* arbre);
LDC retirer_ord(LDC liste);
void enregistrer(char* nomFichier, LDC liste);


#endif // HEADER_H_INCLUDED
