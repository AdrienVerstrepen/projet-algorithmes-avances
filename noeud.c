#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "noeud.h"

// cette fonction permet d’initialiser un noeud

void initialiser_noeud(t_noeud* ceci, char* chaine) {
    // on vérifie que le noeud n'est pas vide
    if (ceci == NULL) {
        return;
    }

    // on a deux cas : le cas où c'est une espèce, où on récupère la chaîne qui est donnée
    // s'il n'y a pas de chaîne, c'est qu'on a un sous-arbre
    if (chaine != NULL) {
        ceci->l_espece = malloc(strlen(chaine)+1);
        if (ceci->l_espece != NULL) {
            strcpy(ceci->l_espece, chaine);
            ceci->est_espece = 1;
        }
    } else {
        ceci->l_espece = NULL;
        ceci->est_espece = 0;
    }

    // on initialise tous les attributs du noeud
    ceci->distance_gauche = 0.0;
    ceci->distance_droite = 0.0;
    ceci->espece_gauche = NULL;
    ceci->espece_droite = NULL;
}

// on fait une fonction pour libérer le noeud de la mémoire
void liberer_noeud(a_noeud ceci) {
    if (ceci == NULL) {
        return;
    }
    if (ceci->est_espece && ceci->l_espece != NULL) {
        free(ceci->l_espece);
    }
    free(ceci);
}

// on a une fonction pour créer un noeud de type arbre, c'est-à-dire un noeud qui est un sous-arbre et non une espèce
a_noeud nouveau_noeud_arbre(a_noeud gauche, a_noeud droite, t_distance distance_gauche, t_distance distance_droite) {
    a_noeud noeud = (a_noeud) malloc(sizeof(t_noeud));
    if (noeud == NULL) {
        return NULL;
    }
    initialiser_noeud(noeud, NULL);
    noeud->espece_gauche = gauche;
    noeud->espece_droite = droite;
    noeud->distance_droite = distance_droite;
    noeud->distance_gauche = distance_gauche;
    return noeud;
}

// on a une fonction pour créer un noeud de type espèce, c'est-à-dire un noeud qui représente une espèce et non un sous-arbre
a_noeud nouveau_noeud_espece(t_nom_espece l_espece) {
    a_noeud noeud = (a_noeud) malloc(sizeof(t_noeud));
    initialiser_noeud(noeud, l_espece);
    return noeud;
}
// on a une fonction qui regarde si un noeud est de type espèce ou de type sous-arbre
int est_espece(a_noeud ceci) {
    if (ceci == NULL) {
        return 0;
    }
    return ceci->est_espece;
}