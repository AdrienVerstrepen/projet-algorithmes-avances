#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "noeud.h"

void initialiser_noeud(t_noeud* ceci, char* chaine) {
    // on vérifie que le noeud n'est pas vide
    if (ceci == NULL) {
        return;
    }

    if (chaine != NULL) {
        ceci->l_espece = malloc(strlen(chaine)+1);
        if (ceci->l_espece != NULL) {
            strcpy(ceci->l_espece, chaine);
            ceci->est_espece = 1;
        }
    } else {
        // cas où on a pas une espèce
        ceci->l_espece = NULL;
        ceci->est_espece = 0;
    }

    ceci->distance_gauche = 0.0;
    ceci->distance_droite = 0.0;
    ceci->espece_gauche = NULL;
    ceci->espece_droite = NULL;
}

void liberer_noeud(a_noeud ceci) {
    if (ceci == NULL) {
        return;
    }

    if (ceci->est_espece && ceci->l_espece != NULL) {
        free(ceci->l_espece);
    }

    free(ceci);
}

// on considère que les deux existent déjà
void copier_noeud(t_noeud* ceci, t_noeud* cela) {
    if (ceci == NULL || cela == NULL) {
        return;
    }

    if (ceci->est_espece) {
        cela->l_espece = malloc(strlen(ceci->l_espece) + 1);
        if (cela->l_espece != NULL) {
            strcpy(cela->l_espece, ceci->l_espece);
        }
    } else {
        cela->l_espece = NULL;
    }

    cela->distance_gauche = ceci->distance_gauche;
    cela->distance_droite = ceci->distance_droite;
    cela->est_espece = ceci->est_espece;

    if (ceci->espece_gauche != NULL) {
        cela->espece_gauche = (t_noeud*)malloc(sizeof(t_noeud));
        if (cela->espece_gauche != NULL) {
            copier_noeud(ceci->espece_gauche, cela->espece_gauche);
        }
    } else {
        cela->espece_gauche = NULL;
    }

    if (ceci->espece_droite != NULL) {
        cela->espece_droite = (t_noeud*)malloc(sizeof(t_noeud));
        if (cela->espece_droite != NULL) {
            copier_noeud(ceci->espece_droite, cela->espece_droite);
        }
    } else {
        cela->espece_droite = NULL;
    }
}

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

a_noeud nouveau_noeud_espece(t_nom_espece l_espece) {
    a_noeud noeud = (a_noeud) malloc(sizeof(t_noeud));
    initialiser_noeud(noeud, l_espece);
    return noeud;
}

int est_espece(a_noeud ceci) {
    if (ceci == NULL) {
        return 0;
    }
    return ceci->est_espece;
}