#ifndef P_ARBRE_H
#define P_ARBRE_H
#include "noeud.h"
#define ARBRE_VIDE NULL

typedef a_noeud t_arbre_binaire;

int est_arbre_vide(a_noeud ceci);

t_arbre_binaire nouveau_arbre_binaire(t_distance distance, t_nom_espece nom_espece, a_noeud gauche, a_noeud droite, int est_espece);

int hauteur_arbre_binaire(t_arbre_binaire ceci);

int nb_elements_arbre_binaire(t_arbre_binaire ceci);

void detruire_arbre_binaire(t_arbre_binaire ceci);

void finaliser_arbre_binaire(t_arbre_binaire* ceci);

a_noeud construire_arbre_phylogenetique();

#endif