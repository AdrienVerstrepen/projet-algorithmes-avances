#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "noeud.h"
#include "arbre_binaire.h"

// on a une fonction pour regarder si un arbre est vide ou non
int est_arbre_vide(a_noeud ceci){
    return ceci==NULL;
}

// on a une fonction pour créer un arbre binaire avec les éléments qu'on lui met en paramètres
t_arbre_binaire nouveau_arbre_binaire(t_distance distance, t_nom_espece nom_espece, a_noeud gauche, a_noeud droite, int est_espece){
    if (est_espece){
        a_noeud arbre_binaire = nouveau_noeud_espece(nom_espece, distance);
        return arbre_binaire;
    } else {
        a_noeud arbre_binaire = nouveau_noeud_arbre(distance, gauche, droite);
        return arbre_binaire;
    }
}

int hauteur_arbre_binaire(t_arbre_binaire ceci) {
    int max_hauteur;
    
    if (ceci == NULL) {
        return 0;
    }
    int hauteur_gauche = hauteur_arbre_binaire(ceci->espece_gauche);
    int hauteur_droite = hauteur_arbre_binaire(ceci->espece_droite);
    
    if (hauteur_gauche > hauteur_droite) {
        max_hauteur = hauteur_gauche;
    } else {
        max_hauteur = hauteur_droite;
    }
    return 1 + max_hauteur;
}

int nb_elements_arbre_binaire(t_arbre_binaire ceci){
    if (ceci == NULL) {
        return 0;
    }

    int hauteur_gauche = nb_elements_arbre_binaire(ceci->espece_gauche);
    int hauteur_droite = nb_elements_arbre_binaire(ceci->espece_droite);

    return 1 + hauteur_droite + hauteur_gauche;
}

void detruire_arbre_binaire(t_arbre_binaire ceci){
    if (ceci!=NULL){
        if(ceci->espece_droite != NULL){
            detruire_arbre_binaire(ceci->espece_droite);
            detruire_arbre_binaire(ceci->espece_gauche);
            liberer_noeud(ceci);
        }
    }
}

void finaliser_arbre_binaire(t_arbre_binaire* ceci){
    if (ceci != NULL && *ceci != NULL) {
        detruire_arbre_binaire(*ceci);
        *ceci = NULL;
    }
}