#include <stdio.h>
#include <stdlib.h>
#include "noeud.h"
#include "arbre_binaire.h"
#include "verification_grammaire.h"

// on appelle la fonction principale
int main() {
	// on indique ici le document à utiliser
	char nom_fichier_entree[100] = "exemples/arbre_4.phy";

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

    // on a également pensé à coder une fonction qui va trouver automatiquement à quel "nombre de fichier arbre" on est
    // cela nous permet que le code cherche de lui-même à quel indice de fichier on s'est arrêté
    // on écrit nos fichiers de retour sous la forme de "arbre{nombre}.txt" et au lieu de changer nous-mêmes le chffre, le code le fait automatiquement en cherchant quel nom de fichier n'existe pas encore
    int numero = 1;
    char nom_fichier[100];
    FILE *fichier = NULL;

    while (1) {
        sprintf(nom_fichier, "arbre%d.txt", numero);
        fichier = fopen(nom_fichier, "r");
        if (fichier == NULL) {
            break;
        }
        fclose(fichier);
        numero++;
    }

    FILE *f = fopen(nom_fichier, "w");
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