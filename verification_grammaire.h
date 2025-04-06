#ifndef VERIFICATION_GRAMMAIRE_H
#define VERIFICATION_GRAMMAIRE_H
#include "noeud.h"

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

#endif