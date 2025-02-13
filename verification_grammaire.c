#include <stdio.h> // pour lire le fichier
#include <stdlib.h> // pour avoir exit();

FILE* mon_fichier;
char mon_caractere;
int cpt = 0;

void lire_caractere() {
	mon_caractere = fgetc(mon_fichier);  // Permet de lire un caractère de mon fichier
	printf("%c", mon_caractere);
}

void amorcer_lecture(char* nom_fichier){
	mon_fichier = fopen(nom_fichier, "r");
	lire_caractere();
}

void consommer_caractere(char attendu) {
	// cpt++;
	// printf("consommation %d\n", cpt);
	if(mon_caractere != attendu) {
		printf("caractere n%d trouve : %c, caractere attendu : %c\n", cpt, mon_caractere, attendu);
		exit(-1);
	}
	lire_caractere(mon_caractere);
}

int est_separateur() {
	return  mon_caractere == ' ' || mon_caractere == '\t' || mon_caractere == '\n' || mon_caractere == '\r';
}

void separation() {
	while(est_separateur()){
		// cpt++;
		// printf("<<<consommation separation%d\n", cpt);
		consommer_caractere(mon_caractere);
	}
}

int est_nul() {
	return mon_caractere == '0';
}

void zero() {
	consommer_caractere('0');
}

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
		// printf(">>>chiffre non nul : %c\n", mon_caractere);
		consommer_caractere(mon_caractere);
	} else {
		printf("chiffre non nul attendu caractere trouve : [%c]", mon_caractere);
		exit(-1);
	}
}

void chiffre() {
	if(est_nul()) {
		zero();
	} else {
		chiffre_non_nul();
	}
}

void sequence_de_chiffres() {
	// int nombre = 1;
	while(est_chiffre()) {
		// nombre *= 10;
		// nombre += mon_caractere - '0';
		chiffre();
	}
}

void partie_entiere() {
	if (est_nul()) {
		zero();
	} else {
		chiffre_non_nul();
		sequence_de_chiffres();
	}
}

void partie_fractionnaire() {
	sequence_de_chiffres();
}

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

void lettre() {
	if(est_lettre()) {
		consommer_caractere(mon_caractere);
	} else {
		printf("Erreur lettre attendu caractere trouve : [%c]\n", mon_caractere);
	}
}

void mot() {
	while(est_lettre() && mon_caractere != EOF) {
		lettre();
	}
}

void nom() {
	mot();
	while (mon_caractere == '_') {
		consommer_caractere('_');
		mot();
	}
}

void arbre_phylogenetique() {
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
	} else /*if (mon_caractere != EOF)*/ {
		nom();
	}
}

int main() {
	amorcer_lecture("exemples/exemple_correct_1b.phy");
	arbre_phylogenetique();
	fclose(mon_fichier);
	return 0;
}