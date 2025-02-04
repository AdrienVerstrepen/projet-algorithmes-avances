#include <stdio.h>

FILE* mon_fichier;
char mon_caractere;

void lire_caractere() {
	mon_caractere = fgetc(mon_fichier);  // Permet de lire un caractère de mon fichier
	printf("%c", mon_caractere);
}

int est_separateur() {
	return  mon_caractere == ' ' || mon_caractere == '\t' || mon_caractere == '\n' || mon_caractere == '\r';
}

void separation() {
	while(est_separateur(mon_caractere)){
		lire_caractere(mon_caractere);
	}
}

void amorcer_lecture(char* nom_fichier){
	mon_fichier = fopen(nom_fichier, "r");
	lire_caractere();
	separation();
}

void consommer_caractere(char attendu) {
	if(mon_caractere != attendu) {
		printf("caractere trouve : %c, caractere attendu : %c", mon_caractere, attendu);
		exit(-1);
	}
	lire_caractere(mon_caractere);
}

void arbre_phylogenetique() {
	if (est_parenthese()) {
		consommer_caractere('(');
		arbre_phylogenetique();
		separation();
		consommer_caractere(':');
		separation();
		nombre_a_virgule();
		consommer_caractere(',');
		separation();
		arbre_phylogenetique();
		consommer_caractere(':');
		nombre_a_virgule();
		consommer_caractere(')');
	} else {
nom();
}
	
}

int main() {

	amorcer_lecture("exemples/exemple_correct_1.phy");
	arbre_phylogenetique();
	
	return 0;
}