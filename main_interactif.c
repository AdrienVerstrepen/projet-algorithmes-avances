#include <stdio.h>
#include <stdlib.h>
#include "noeud.h"
#include "arbre_binaire.h"
#include "verification_grammaire.h"

// on appelle la fonction principale
int main() {
	// on indique ici le document à utiliser
	char nom_fichier_entree[100];
	printf("Entrez le nom du fichier : ");
	scanf("%s", nom_fichier_entree);

    // on vérifie que le fichier donné en entré existe et qu'il n'est pas vide
    FILE *fichier_test = fopen(nom_fichier_entree, "r");
    if (fichier_test == NULL) {
        printf("Erreur : impossible d’ouvrir le fichier.\nAssurez vous que le chemin de votre fichier est bien correct.\n");
        return 1;
    }
    if (fgetc(fichier_test) == EOF) {
        printf("Le fichier est vide.\n");
        fclose(fichier_test);
        return 1;
    }
    fclose(fichier_test);

	amorcer_lecture(nom_fichier_entree);
	// on teste pour vérifier si l'arbre dans le fichier suit bien la grammaire
	arbre_phylogenetique();

	// s'il n'y a pas de message d'erreur, c'est à dire si l'arbre du fichier est accepté, on passe à la création de l'arbre
	amorcer_lecture(nom_fichier_entree);
    a_noeud arbre = construire_arbre_phylogenetique();

    if (arbre == NULL) {
        printf("Erreur : L'arbre n'a pas été construit correctement.\n");
    }

    afficher_arbre(arbre);
    printf("\n");
    affichage_console(arbre, "", 1, 0.0);

    char nom_fichier_sortie[100];
	printf("Entrez le nom du fichier : ");
	scanf("%s", nom_fichier_sortie);

    FILE *f = fopen(nom_fichier_sortie, "w");
    if (f != NULL) {
        sauvegarder_arbre(f, arbre);
        fclose(f);
        // on n'oublie pas de finaliser l'arbre que l'on a créé
        finaliser_arbre_binaire(&arbre);
    } else {
        printf("Erreur lors de l'ouverture du fichier\n");
    }
	return 0;
}