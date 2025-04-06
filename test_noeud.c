#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "noeud.h"

int main() {
    // on teste ici les fonctions sur les noeuds
    t_noeud* noeud1 = (t_noeud*)malloc(sizeof(t_noeud));
    char* espece1 = "Espèce1";
    initialiser_noeud(noeud1, espece1);

    printf("Test 1: Noeud 1\n");
    printf("Espèce: %s\n", noeud1->l_espece);
    printf("Est espèce: %d\n", noeud1->est_espece);

    // on teste la fonction nouveau noeud_arbre
    t_noeud* noeud2 = nouveau_noeud_arbre(NULL, NULL, 10.5, 2.5);
    printf("\nTest 2: Noeud 2\n");
    printf("Distance gauche: %.2f\n", noeud2->distance_gauche);
    printf("Distance droite: %.2f\n", noeud2->distance_droite);
    printf("Est espèce: %d\n", noeud2->est_espece);

    // on teste la fonction nouveau noeud_espece
    t_noeud* noeud3 = nouveau_noeud_espece("Espece3");
    printf("\nNoeud 3\n");
    printf("Distance gauche: %s\n", noeud3->l_espece);
    printf("Est espèce: %d\n", noeud3->est_espece);

    // on teste est_espece
    printf("Est espèce: %d\n", est_espece(noeud3));

    // on teste la libération des noeuds
    liberer_noeud(noeud1);
    liberer_noeud(noeud2);

    return 0;
}