#ifndef VERIFICATION_GRAMMAIRE_H
#define VERIFICATION_GRAMMAIRE_H
#include "noeud.h"

// j'avais des gros soucis d'imports de fonction entre cette partie et la suite donc je me suis permis de faire ce fichier là
// char mon_caractere;
extern FILE* mon_fichier;

void lire_caractere();

void amorcer_lecture(char* nom_fichier);

void consommer_caractere(char attendu);

int est_separateur();

void separation();

int est_nul();

void zero();

int est_par_ouvr();

int est_chiffre_non_nul();

int est_chiffre();

void chiffre_non_nul();

void chiffre();

void sequence_de_chiffres();

void partie_entiere();

void partie_fractionnaire();

void nombre_a_virgule();

int est_lettre_min();

int est_lettre_maj();

int est_lettre();

void lettre();

void mot();

void nom();

void arbre_phylogenetique();

void lire_caractere_sans_affichage();

void consommer_caractere_sans_affichage(char attendu);

void separation_sans_affichage();

void amorcer_lecture_sans_affichage(char* nom_fichier);

// void fermer_fichier(FILE mon_fichier);

#endif