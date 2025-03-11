#include <stdio.h> // pour lire le fichier
#include <stdlib.h> // pour avoir exit();
#include "verification_grammaire.c"
#include "noeud.h"
#include "arbre_binaire.h"
FILE* mon_fichier;
char mon_caractere;

// on appelle la fonction principale
int main() {
	// on indique ici le document à utiliser
	amorcer_lecture("exemples/exemple_correct_1d.phy");
	// amorcer_lecture("exemples/test_corrige_1.phy");
	arbre_phylogenetique();

	// amorcer_lecture("exemples/exemple_correct_2_test.phy");
	// // cette fonction va vérifier que l'arbre donné est bien du bon format
	// arbre_phylogenetique();
	fclose(mon_fichier);
	return 0;
}