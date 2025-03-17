#include <stdio.h> // pour lire le fichier
#include <stdlib.h> // pour avoir exit();
#include <string.h> 
#include "noeud.h"
#include "arbre_binaire.h"
#include "verification_grammaire.h"
FILE* mon_fichier;
char mon_caractere;
int cpt = 0;

// on lit chaque caractère du fichier
void lire_caractere() {
	mon_caractere = fgetc(mon_fichier);
	printf("%c", mon_caractere);
	cpt++;
}

// on ouvre le fichier à lire en mode lecture car on n'effectue pas d'écriture sur ce fichier là
// on va ensuite regarder chaque caractère les uns après les autres
void amorcer_lecture(char* nom_fichier){
	mon_fichier = fopen(nom_fichier, "r");
	lire_caractere();
}

// on effectue la vérification pour s'assurer que l'on obtient bien le caracrère que l'on veut en comparant le caractère prévu et celui dans le fichier
void consommer_caractere(char attendu) {
	// on traite le cas où le caractère trouvé ne correspond pas en faisant un affichage du caractère qui pose problème et en forçant un exit
	if(mon_caractere != attendu) {
		printf("\ncaractere n %d trouve : %c, caractere attendu : %c\n", cpt, mon_caractere, attendu);
		exit(-1);
	}
	// lire_caractere(mon_caractere);
	lire_caractere();
}

// on vérifie qu'on a bien un des caractères que l'on classifie comme séparateur là où l'on regarde
// si cela n'est pas le cas, ça veut dire que le fichier ne suit pas notre grammaire
int est_separateur() {
	return  mon_caractere == ' ' || mon_caractere == '\t' || mon_caractere == '\n' || mon_caractere == '\r';
}

void separation() {
	while(est_separateur()){
		consommer_caractere(mon_caractere);
	}
}

int est_nul() {
	return mon_caractere == '0';
}

void zero() {
	consommer_caractere('0');
}

// on vérifie que le caractère que l'on regarde est bien une paranthèse ouvrante
int est_par_ouvr() {
	return mon_caractere == '(';
}

int est_chiffre_non_nul() {
	return '1' <= mon_caractere && mon_caractere <= '9';
}

int est_chiffre() {
	return '0' <= mon_caractere && mon_caractere <= '9';
}

void chiffre_non_nul() {
	if (est_chiffre_non_nul()) {
		consommer_caractere(mon_caractere);
	} else {
		// cas où le caractère que l'on a trouvé ne correspond pas à un caractère non nul
		printf("\nchiffre non nul attendu caractere trouve : [%c]", mon_caractere);
		exit(-1);
	}
}

// un chiffre peut être un zéro ou un chiffre compris entre 1 et 9
void chiffre() {
	if(est_nul()) {
		zero();
	} else {
		chiffre_non_nul();
	}
}

// si une séquence de chiffres n'est pas nulle, elle ne peut être composée que d'un ou plusieurs chiffres
void sequence_de_chiffres() {
	// int nombre = 1;
	while(est_chiffre()) {
		// nombre *= 10;
		// nombre += mon_caractere - '0';
		chiffre();
	}
}

// une partie entière est composée d'un zéro ou d'un chiffre non nul suivi d'une séquence de chiffres
void partie_entiere() {
	if (est_nul()) {
		zero();
	} else {
		chiffre_non_nul();
		sequence_de_chiffres();
	}
}

// une partie fractionnaire est composée d'une séquence de chiffre
void partie_fractionnaire() {
	sequence_de_chiffres();
}

// un nombre à virgule est composé d'une partie entière et potentiellement d'une partie fractionnaire précédée d'un point
void nombre_a_virgule() {
	partie_entiere();
	if(mon_caractere == '.') {
		consommer_caractere('.');
		partie_fractionnaire();
	}
}

int est_lettre_min() {
	return 'a' <= mon_caractere && mon_caractere <= 'z';
}

int est_lettre_maj() {
	return 'A' <= mon_caractere && mon_caractere <= 'Z';
}

int est_lettre() {
	return est_lettre_min() || est_lettre_maj();
}

// on vérifie que le caractère récupéré est bien une lettre
void lettre() {
	if(est_lettre()) {
		consommer_caractere(mon_caractere);
	} else {
		printf("\nErreur lettre attendu caractere trouve : [%c]\n", mon_caractere);
	}
}

// un mot est un ensemble de une ou plusieurs lettres
void mot() {
	while(est_lettre() && mon_caractere != EOF) {
		lettre();
	}
}

// un nom est composé d'au moins un mot et peut-être suivi de plusieurs fois la combinaison d'un caractère _ et d'un mot
void nom() {
	mot();
	while (mon_caractere == '_') {
		consommer_caractere('_');
		mot();
	}
}

// un arbre phylogénétique est composé d'un nom ou d'une combinaison de paranthèses, de : pour indiquer les distances ainsi que des noms des espèces, ce qui donne ce genre d'arbre (Homo_sapiens:0.1, Felis_catus:0.2)
// les arbres phylogénétiques peuvent être entièrement imbriqués
void arbre_phylogenetique() {
	// printf("\npassage arbre\n");
	if (est_par_ouvr()) {
		consommer_caractere('(');
		arbre_phylogenetique();
		separation();
		consommer_caractere(':');
		separation();
		nombre_a_virgule();
		consommer_caractere(',');
		separation();
		arbre_phylogenetique();
		separation();
		consommer_caractere(':');
		separation();
		nombre_a_virgule();
		consommer_caractere(')');
	} else {
		nom();
	}
}

// void fermer_fichier(mon_fichier){
// void fermer_fichier(FILE* mon_fichier) {
// 	fclose(mon_fichier);
// }