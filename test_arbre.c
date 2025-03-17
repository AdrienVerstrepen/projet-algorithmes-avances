#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "noeud.h"
#include "arbre_binaire.h"
#include "verification_grammaire.h"

int main() {
    // t_noeud* espece1 = (t_noeud*)malloc(sizeof(t_noeud));
    // initialiser_noeud(espece1, "Espèce1");

    // t_noeud* espece2 = (t_noeud*)malloc(sizeof(t_noeud));
    // initialiser_noeud(espece2, "Espèce2");

    // t_noeud* espece3 = (t_noeud*)malloc(sizeof(t_noeud));
    // initialiser_noeud(espece3, "Espèce3");

    // a_noeud arbre = nouveau_arbre_binaire(1.0, 2.0, NULL, espece1, espece2, 0);
    // printf("Arbre 1\n");
    // printf("Distance gauche : %.1f\n", arbre->distance_gauche);
    // printf("Distance droite: %.1f\n", arbre->distance_droite);
    // printf("Est espèce: %d\n", arbre->est_espece);

    // printf("Affichage de l'arbre phylogénétique 1 : ");
    // afficher_arbre(arbre);
    // // printf("\n");

    // int hauteur = hauteur_arbre_binaire(arbre);
    // printf("\nHauteur prévue : 2\nHauteur de l'arbre : %d\n", hauteur);

    // int nb_elements = nb_elements_arbre_binaire(arbre);
    // printf("Nb éléments dans l'arbre prévu : 2\nNombre d'éléments dans l'arbre : %d\n", nb_elements);

    // a_noeud arbre2 = nouveau_arbre_binaire(3.0, 0.5, NULL, arbre, espece3, 0);
    // printf("\nArbre 2\n");
    // printf("Distance gauche: %.1f\n", arbre2->distance_gauche);
    // printf("Distance droite: %.1f\n", arbre2->distance_droite);
    // printf("Est espèce: %d\n", arbre2->est_espece);

    // printf("Affichage de l'arbre phylogénétique : ");
    // afficher_arbre(arbre2);
    // // printf("fin");
    // printf("\n");

    // int hauteur2 = hauteur_arbre_binaire(arbre2);
    // printf("\nHauteur prévue : 3\nHauteur de l'arbre : %d\n", hauteur2);

    // int nb_elements2 = nb_elements_arbre_binaire(arbre2);
    // printf("Nb éléments dans l'arbre prévu : 3\nNombre d'éléments dans l'arbre : %d\n", nb_elements2);

    // int vide2 = est_arbre_vide(arbre2);
    // printf("L'arbre est vide (0 prévu) : %d\n", vide2);

    // finaliser_arbre_binaire(&arbre2);

    // vide2 = est_arbre_vide(arbre2);
    // printf("L'arbre est vide (1 prévu) : %d\n", vide2);

    amorcer_lecture_sans_affichage("exemples/test_corrige_1.phy");
    // a_noeud arbre3;
    // initialiser_noeud(arbre3, NULL);
    // arbre3 = construire_arbre_phylogenetique();
    a_noeud arbre3 = construire_arbre_phylogenetique();

    if (arbre3 == NULL) {
        printf("Erreur : L'arbre n'a pas été construit correctement.\n");
        // return EXIT_FAILURE;
    }

    printf("\nArbre phylogénétique lu depuis le fichier :\n");
    afficher_arbre(arbre3);
    printf("\n");

    printf("Hauteur de l'arbre : %d\n", hauteur_arbre_binaire(arbre3));
    printf("Nombre de nœuds dans l'arbre : %d\n", nb_elements_arbre_binaire(arbre3));

    // finaliser_arbre_binaire(&arbre);
    // fclose(mon_fichier);

    return 0;
}