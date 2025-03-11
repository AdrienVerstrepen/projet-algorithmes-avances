#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "noeud.h"
#include "arbre_binaire.h"
#include "verification_grammaire.c"

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

    int nb_gauche  = nb_elements_arbre_binaire(ceci->espece_gauche);
    int nb_droite = nb_elements_arbre_binaire(ceci->espece_droite);

    return 1 + nb_gauche  + nb_droite;
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

// a_noeud construire_arbre_phylogenetique_racine() {
//     if (est_par_ouvr()) {
//         consommer_caractere('(');
//         separation();
//         consommer_caractere(':');
//         separation();

//         t_distance distance_gauche;
//         nombre_a_virgule();
//         distance_gauche = strtod(&mon_caractere, NULL);
//         // on appelle récursivement dans une fonction à part car le premier arbre est unique car il n'a pas de distance, mais les auytres si
//         // on ajoute un attribut qui permet de récupérer la distance du noeud, ce qui est en dehors du noeud lui-même
//         a_noeud gauche = construire_arbre_phylogenetique(distance_gauche);

//         consommer_caractere(',');
//         separation();
//         consommer_caractere(':');
//         separation();

//         t_distance distance_droit;
//         nombre_a_virgule();
//         distance_droit = strtod(&mon_caractere, NULL);
//         a_noeud droit = construire_arbre_phylogenetique(distance_droit);

//         consommer_caractere(')');

//         return nouveau_noeud_racine(gauche, droit);
//     } else {
//         return NULL;
//     }
// }

// a_noeud construire_arbre_phylogenetique(t_distance distance) {
//         // cas où on a un arbre phylogénétique et non pas un nom
//     if (est_par_ouvr()) {
//         consommer_caractere('(');
//         a_noeud gauche = construire_arbre_phylogenetique();

//         separation();
//         consommer_caractere(':');
//         separation();

//         t_distance distance_gauche;
//         nombre_a_virgule();
//             // on pense bien à passer l'élément qui est un string en double
//         distance_gauche = strtod(&mon_caractere, NULL);

//         consommer_caractere(',');
//         separation();
//         a_noeud droit = construire_arbre_phylogenetique();

//         consommer_caractere(':');
//         separation();

//         t_distance distance_droit;
//         nombre_a_virgule();
//         distance_droit = strtod(&mon_caractere, NULL);
        
//         consommer_caractere(')');

//         return nouveau_noeud_arbre(distance, gauche, droit);
//     } else {
//         t_nom_espece nom_espece;
//         nom();
//         separation();

//         consommer_caractere(':');
//         separation();

//         t_distance distance;
//         nombre_a_virgule();
//         distance = strtod(&mon_caractere, NULL);

//         return nouveau_noeud_espece(nom_espece, distance);
//     }
// }