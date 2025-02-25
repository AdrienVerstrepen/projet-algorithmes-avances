#ifndef NOEUD_H
#define NOEUD_H

// on utilise un type char* pour le nom de l'espece
typedef char* t_nom_espece;
// on utilise un double pour la distance car dans le fichier original on a une structure de type 2.3 ou 9.6, qui sont apparentés aux doubles en C
typedef double t_distance;

typedef struct noeud t_noeud;

// on construit un seul type de noeud
// cela concerne à la fois les noeuds qui seront une feuille, donc qui auront un nom d'espece et une distance, ou un noeud qui est un sous-arbre phylogénétique, qui va avoir deux fils et une distance
// nous auront donc deux types de noeuds, les noeuds "espece" sans fils et avec un nom d'espèce, et les noeuds "arbre" qui ont une distance et deux fils mais pas de nom
typedef struct noeud {
    t_nom_espece l_espece;
    t_distance la_distance;
    t_noeud *espece_gauche;
    t_noeud *espece_droite;
} t_noeud;

typedef t_noeud* a_noeud;

void initialiser_element(t_noeud* ceci, char* chaine, double distance);

void finaliser_element(t_noeud* ceci);

void copier_element(t_noeud ceci, t_noeud* cela);

// création d'un nouveau noeud de type arbre, on ne met pas d'élément nom_espece car il sera vide 
a_noeud nouveau_noeud_arbre(t_distance distance, a_noeud gauche, a_noeud droite);

// création d'un nouveau noeud espece, il n'aura donc ni fils gauche ni fils droit
a_noeud nouveau_noeud_espece(t_nom_espece nom_espece, t_distance distance);

// suppression d'un noeud
void liberer_noeud(a_noeud ceci);

void afficher_noeud(a_noeud ceci);

// on indique si le noeud est une espèce ou un sous-arbre phylogénétique
int est_espece(a_noeud ceci);

#endif