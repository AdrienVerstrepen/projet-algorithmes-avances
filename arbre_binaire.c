#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "noeud.h"
#include "arbre_binaire.h"

int est_arbre_vide(a_noeud ceci){
    return ceci==NULL;
}

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
    if (ceci == NULL) {
        return 0;
    }
    int hauteur_gauche = hauteur_arbre_binaire(ceci->espece_droite);
    int hauteur_droite = hauteur_arbre_binaire(ceci->espece_gauche);
    return 1 + (hauteur_gauche > hauteur_droite ? hauteur_gauche : hauteur_droite);
}

int nb_elements_arbre_binaire(t_arbre_binaire ceci){
    if (ceci == NULL) {
        return 0;
    }

    int hauteur_gauche = nb_elements_arbre_binaire(ceci->espece_droite);
    int hauteur_droite = nb_elements_arbre_binaire(ceci->espece_droite);

    return 1 + hauteur_droite + hauteur_gauche;
}

void detruire_arbre_binaire(t_arbre_binaire ceci){
    if (ceci!=NULL){
        if(ceci->espece_droite != NULL){
            detruire_arbre_binaire(ceci->espece_droite);
        }
        if(ceci->espece_droite != NULL){
            detruire_arbre_binaire(ceci->espece_droite);
        }
        liberer_noeud(ceci);
    }
}

void finaliser_arbre_binaire(t_arbre_binaire* ceci){
    if (ceci!=NULL){
        detruire_arbre_binaire(*ceci);
        ceci=NULL;
    }
}