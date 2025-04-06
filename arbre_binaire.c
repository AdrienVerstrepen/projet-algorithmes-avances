#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "noeud.h"
#include "arbre_binaire.h"
#include "verification_grammaire.h"

#define LARGEUR_MAX 100
#define HAUTEUR_MAX 100

extern char mon_caractere;
char affichage[HAUTEUR_MAX][LARGEUR_MAX];

// on a une fonction pour regarder si un arbre est vide ou non
int est_arbre_vide(a_noeud ceci){
    return ceci==NULL;
}

// on a une fonction pour créer un arbre binaire avec les éléments qu'on lui met en paramètres
a_noeud nouveau_arbre_binaire(t_distance distance_gauche, t_distance distance_droite, t_nom_espece nom_espece, a_noeud gauche, a_noeud droite, int est_espece){
    if (est_espece){
        a_noeud arbre_binaire = nouveau_noeud_espece(nom_espece);
        return arbre_binaire;
    } else {
        a_noeud arbre_binaire = nouveau_noeud_arbre(gauche, droite, distance_gauche, distance_droite);
        return arbre_binaire;
    }
}

// on a une fonction pour calculer la hauteur de l'arbre
// la hauteur, qu'on pourrait également appeler la profondeur, représente le nombre le plus grand de noeuds séparant un noeud de l'arbre et la racine
int hauteur_arbre_binaire(a_noeud ceci) {
    if (ceci == NULL) {
        return 0;
    }

    if (ceci->est_espece) {
        return 1;
    }
    int hauteur_gauche = hauteur_arbre_binaire(ceci->espece_gauche);
    int hauteur_droite = hauteur_arbre_binaire(ceci->espece_droite);    
    int max_hauteur = (hauteur_gauche > hauteur_droite) ? hauteur_gauche : hauteur_droite;
    return 1 + max_hauteur;
}

// on a également une fonction pour compter le nombre d'espèces contenues dans l'arbre
int nb_elements_arbre_binaire(a_noeud ceci){
    if (ceci == NULL) {
        return 0;
    }
    if (ceci->est_espece){
        return 1;
    } else {
        int nb_gauche  = nb_elements_arbre_binaire(ceci->espece_gauche);
        int nb_droite = nb_elements_arbre_binaire(ceci->espece_droite); 
        return nb_gauche  + nb_droite;
    }
}

// on a une fonction pour détruire un arbre binaire et libérer l'espace de cet arbre une fois qu'on l'a utilisé
void detruire_arbre_binaire(a_noeud ceci){
    if (ceci!=NULL){
        detruire_arbre_binaire(ceci->espece_gauche);
        detruire_arbre_binaire(ceci->espece_droite);
        liberer_noeud(ceci);
    }
}

// on a une fonction pour détruire l'arbre et remettre le pointeur à NULL
void finaliser_arbre_binaire(a_noeud* ceci){
    if (ceci != NULL && *ceci != NULL) {
        detruire_arbre_binaire(*ceci);
        *ceci = NULL;
    }
}

// on a une fonction qui va lire dans le fichier en cours de lecture un nombre à virgule
// on appelle cette fonction dans la lecture du fichier pour construire l'arbre binaire
double recuperer_nombre_a_virgule() {
    double resultat = 0.0;
    double facteur = 1.0;
    int partie_decimale = 0;

    // on va récupèrer chaque caractère tant que ce n'est pas un caractère de fin
    while (mon_caractere != ',' && mon_caractere != ' ' && mon_caractere != ')' && mon_caractere != '\t' && mon_caractere != '\n' && mon_caractere != '\r') {
        if (mon_caractere >= '0' && mon_caractere <= '9') {
            // si on est dans la partie décimale, on applique le facteur pour bien placer le chiffre après la virgule
            if (partie_decimale) {
                facteur /= 10.0;
                resultat += (mon_caractere - '0') * facteur;
            } else {
                // sinon on est encore dans la partie entière on construit le nombre comme d’habitude
                resultat = resultat * 10 + (mon_caractere - '0');
            }
        } else if (mon_caractere == '.') {
            partie_decimale = 1;
        }
        lire_caractere();
    }
    // on pense à bien enlever tous les caracrères transitoires comme les espaces ou les retours à la ligne
    while (mon_caractere == ' ' || mon_caractere == '\t' || mon_caractere == '\n' || mon_caractere == '\r') {
        lire_caractere();
    }
    return resultat;
}

// on a une fonction qui va lire dans le fichier en cours une chaîne de caractères
char* recuperer_nom() {
    char* nom = (char*)malloc(100 * sizeof(char));
    int i = 0;

    // on va récupèrer chaque caractère tant que ce n'est pas un caractère de fin
    while (mon_caractere != ' ' && mon_caractere != ':' && mon_caractere != '\n' && mon_caractere != '(' && mon_caractere != ',' && mon_caractere != EOF) {
        nom[i++] = mon_caractere;
        lire_caractere();
    }
    nom[i] = '\0';
    return nom;
}

// on a la fonction principale qui va créer la structure de l'arbre associé à l'arbre qui est écrit dans le fichier qui est donné en entrée
// on va parcourir l'arbre de manière récursive en récupérant la distance dans un double
a_noeud construire_arbre_phylogenetique() {
    if (est_par_ouvr()) {
        // on traite le cas d'un sous-arbre
        consommer_caractere('(');
        separation();

        a_noeud arbre_gauche = construire_arbre_phylogenetique();
        separation();
        consommer_caractere(':');
        separation();

        t_distance distance_gauche = recuperer_nombre_a_virgule();

        consommer_caractere(',');
        separation();

        a_noeud arbre_droite = construire_arbre_phylogenetique();
        separation();
        consommer_caractere(':');
        separation();

        t_distance distance_droite = recuperer_nombre_a_virgule();
        separation();

        consommer_caractere(')');
        return nouveau_arbre_binaire(distance_gauche, distance_droite, NULL, arbre_gauche, arbre_droite, 0);
    } else {
        // on traite le cas où on a un noeud, c'est-à-dire une espèce
        t_nom_espece nom_espece = recuperer_nom();
        a_noeud espece = (a_noeud)malloc(sizeof(t_noeud));
        initialiser_noeud(espece, nom_espece);
        espece->est_espece = 1;
        return espece;
    }
}

// on a la fonction qui permet d'afficher un arbre suivant la grammaire donnée
void afficher_arbre(a_noeud ceci) {
    if (ceci == NULL) {
        printf("\nErreur : arbre NULL détecté !\n");
        return;
    }

    if (ceci->est_espece) {
        printf("%s", ceci->l_espece);
    } else {
        printf("(");
        afficher_arbre(ceci->espece_gauche);
        printf(":%.2f", ceci->distance_gauche);
        printf(", ");
        afficher_arbre(ceci->espece_droite);
        printf(":%.2f", ceci->distance_droite);
        printf(")");
    }
}

// on a la fonction qui permet d'afficher un affichage alternatif dans la console
void affichage_console(a_noeud noeud, char *prefixe, int est_droit, double distance_depuis_parent) {
    if (noeud == NULL){
        return;
    }

    // on commence par afficher le préfixe pour l'indentation, puis le symbole '+--'
    printf("%s", prefixe);
    printf("+--");
    
    // si c'est une espèce, on affiche son nom et la distance
    // sinon, on affiche juste la distance entre les noeuds
    if (noeud->est_espece) {
        printf("%s:%.2f\n", noeud->l_espece, distance_depuis_parent);
    } else {
        printf("(%.2f)\n", distance_depuis_parent);
    }
    
    // on prépare un nouveau préfixe pour les sous-noeuds
    char nouveau_prefixe[1000];
    strcpy(nouveau_prefixe, prefixe);
    if (est_droit) {
        strcat(nouveau_prefixe, "    ");
    } else {
        strcat(nouveau_prefixe, "|   ");
    }    
    
    // on regarde ensuite si les noeuds gauche et droit existent, et si c'est le cas on les affiche de manière récursive
    if (noeud->espece_gauche){
        affichage_console(noeud->espece_gauche, nouveau_prefixe, 0, noeud->distance_gauche);
    }
    if (noeud->espece_droite){
        affichage_console(noeud->espece_droite, nouveau_prefixe, 1, noeud->distance_droite);
    }
}

// on a une fonction qui permet de sauvegarder un arbre dans un fichier texte selon le format 
// on lui donne un fichier ouvert en écriture et un noeud d’arbre à partir duquel commencer
void sauvegarder_arbre(FILE *fichier, a_noeud ceci) {
    if (ceci == NULL) {
        fprintf(stderr, "Erreur : arbre NULL détecté\n");
        return;
    }

    // si le noeud correspond à une espèce, on écrit simplement son nom dans le fichier
    if (ceci->est_espece) {
        fprintf(fichier, "%s", ceci->l_espece);
    } else {
        // sinon, on construit le texte de l'arbre en suivant la grammaire
        fprintf(fichier, "(");
        sauvegarder_arbre(fichier, ceci->espece_gauche);
        fprintf(fichier, ":%.2f, ", ceci->distance_gauche);
        sauvegarder_arbre(fichier, ceci->espece_droite);
        fprintf(fichier, ":%.2f", ceci->distance_droite);
        fprintf(fichier, ")");
    }
}