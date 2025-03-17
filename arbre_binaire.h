#ifndef P_ARBRE_H
#define P_ARBRE_H
#include "noeud.h"
#include "verification_grammaire.h"
#include "arbre_binaire.h"
#define ARBRE_VIDE NULL

int est_arbre_vide(a_noeud ceci);

a_noeud nouveau_arbre_binaire(t_distance distance_gauche, t_distance distance_droite, t_nom_espece nom_espece, a_noeud gauche, a_noeud droite, int est_espece);

int hauteur_arbre_binaire(a_noeud ceci);
int nb_elements_arbre_binaire(a_noeud ceci);

void detruire_arbre_binaire(a_noeud ceci);

void finaliser_arbre_binaire(a_noeud* ceci);

// a_noeud construire_arbre_phylogenetique();

void afficher_arbre(a_noeud ceci);

// char* recuperer_nom_espece();

#endif