#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "noeud.h"
#include "arbre_binaire.h"
#include "verification_grammaire.h"

int main() {
    t_noeud* espece1 = (t_noeud*)malloc(sizeof(t_noeud));
    initialiser_noeud(espece1, "Espèce1");
    // a_noeud espece1 = (a_noeud)malloc(sizeof(a_noeud));
    // initialiser_noeud(espece1, "Espèce1");

    t_noeud* espece2 = (t_noeud*)malloc(sizeof(t_noeud));
    initialiser_noeud(espece2, "Espèce2");

    t_noeud* espece3 = (t_noeud*)malloc(sizeof(t_noeud));
    initialiser_noeud(espece3, "Espèce3");

    a_noeud arbre = nouveau_arbre_binaire(1.0, 2.0, NULL, espece1, espece2, 0);
    printf("\nArbre\n");
    printf("Distance gauche : %.1f\n", arbre->distance_gauche);
    printf("Distance droite: %.1f\n", arbre->distance_droite);
    printf("Est espèce: %d\n", arbre->est_espece);

    // printf("\n Arbre 1\n");
    // int hauteur = hauteur_arbre_binaire(arbre);
    // printf("\nHauteur prévue : 2\nHauteur de l'arbre : %d\n", hauteur);

    // int nb_elements = nb_elements_arbre_binaire(arbre);
    // printf("Nb éléments dans l'arbre prévu : 2\n Nombre d'éléments dans l'arbre : %d\n", nb_elements);

    finaliser_arbre_binaire(&arbre);

    int vide = est_arbre_vide(arbre);
    printf("L'arbre est vide (1 oui 0 non) : %d\n", vide);


    a_noeud arbre2 = nouveau_arbre_binaire(3.0, 0.5, NULL, arbre, espece3, 0);
    printf("\n\nArbre 2\n");
    printf("Distance gauche: %.1f\n", arbre2->distance_gauche);
    printf("Distance droite: %.1f\n", arbre2->distance_droite);
    printf("Est espèce: %d\n", arbre2->est_espece);

    // int hauteur2 = hauteur_arbre_binaire(arbre2);
    // printf("\nHauteur prévue : 3\nHauteur de l'arbre : %d\n", hauteur2);

    // int nb_elements2 = nb_elements_arbre_binaire(arbre2);
    // printf("Nb éléments dans l'arbre prévu : 3\nNombre d'éléments dans l'arbre : %d\n", nb_elements2);

    finaliser_arbre_binaire(&arbre2);

    int vide2 = est_arbre_vide(arbre2);
    printf("L'arbre est vide (1 oui 0 non) : %d\n", vide2);


    printf("\nAffichage de l'arbre phylogénétique : ");
    afficher_arbre(arbre2);
    printf("\n");

    // int hauteur = hauteur_arbre_binaire(arbre2);
    // printf("Hauteur de l'arbre : %d\n", hauteur);

    return 0;
}