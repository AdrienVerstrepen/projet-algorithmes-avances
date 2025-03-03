#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "noeud.h"

void initialiser_noeud(t_noeud* ceci, char* chaine, double distance) {
    // on vérifie que le noeud n'est pas vide
    if (ceci == NULL) {
        return;
    }

    if (chaine != NULL) {
        ceci->l_espece = malloc(strlen(chaine));
        if (ceci->l_espece != NULL) {
            strcpy(ceci->l_espece, chaine);
        }
    } else {
        ceci->l_espece = NULL;
    }

    ceci->la_distance = distance;
    ceci->espece_gauche = NULL;
    ceci->espece_droite = NULL;
}

void liberer_noeud(t_noeud* ceci) {
    if (ceci == NULL) {
        return;
    }

    liberer_noeud(ceci->espece_gauche);
    liberer_noeud(ceci->espece_droite);
    if (ceci->est_espece && ceci->l_espece != NULL) {
        free(ceci->l_espece);
    }

    free(ceci);
}

// on considère que les deux noms existent déjà
void copier_noeud(t_noeud* ceci, t_noeud* cela) {
    if (ceci == NULL || cela == NULL) {
        return;
    }

    cela->la_distance = ceci->la_distance;
    cela->est_espece = ceci->est_espece;
    cela->espece_gauche = ceci->espece_gauche;
    cela->espece_droite = ceci->espece_droite;

    if (ceci->est_espece && ceci->l_espece != NULL && cela->l_espece != NULL) {
        strcpy(cela->l_espece, ceci->l_espece);
    }
}

a_noeud nouveau_noeud_arbre(t_distance distance, a_noeud gauche, a_noeud droite) {
    a_noeud noeud = (a_noeud) malloc(sizeof(t_noeud));
    initialiser_noeud(noeud, NULL, distance);

    noeud->espece_gauche = gauche;
    noeud->espece_droite = droite;
    // comme c'est pas un noeud espèce on met à 0
    noeud->est_espece = 0;

    return noeud;
}

a_noeud nouveau_noeud_espece(t_nom_espece nom_espece, t_distance distance) {
    a_noeud noeud = (a_noeud) malloc(sizeof(t_noeud));

    initialiser_noeud(noeud, nom_espece, distance);

    // comme c'est pas un noeud espèce on met à 1
    noeud->est_espece = 1;
    noeud->espece_gauche = NULL;
    noeud->espece_droite = NULL;

    return noeud;
}

void liberer_noeud(a_noeud ceci) {
    if (ceci == NULL) {
        return;
    }
    liberer_noeud(ceci);
}

int est_espece(a_noeud ceci) {
    if (ceci == NULL) {
        return 0;
    }
    return ceci->est_espece;
}