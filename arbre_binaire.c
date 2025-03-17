#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "noeud.h"
#include "arbre_binaire.h"
#include "verification_grammaire.h"
extern char mon_caractere;

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

// marche pas actuellement
// ça marche seulement pour les arbres qui ont des enfants qui sont des arbres especes, mais pas les arbres imbriqués
int hauteur_arbre_binaire(a_noeud ceci) {
    //int max_hauteur;

    if (ceci == NULL) {
        return 0;
    }

    if (ceci->est_espece) {
        // printf("\nhauteur espece : 1");
        return 1;
    }
    // printf("\n distance droite : %d\n", ceci->distance_droite);
    int hauteur_gauche = hauteur_arbre_binaire(ceci->espece_gauche);
    int hauteur_droite = hauteur_arbre_binaire(ceci->espece_droite);
    
    // if (hauteur_gauche > hauteur_droite) {
    //     max_hauteur = hauteur_gauche;
    //     printf("\nentré gauche\n");
    // } else {
    //     max_hauteur = hauteur_droite;
    //     printf("\nentré droit\n");
    // }
    // printf("\nhauteur arbre : %d", max_hauteur+1);
    // return 1 + max_hauteur;

    int max_hauteur = (hauteur_gauche > hauteur_droite) ? hauteur_gauche : hauteur_droite;

    // printf("\nentré %s", (hauteur_gauche > hauteur_droite) ? "gauche" : "droit");
    // printf("\nhauteur arbre : %d", max_hauteur + 1);

    return 1 + max_hauteur;
}

int nb_elements_arbre_binaire(a_noeud ceci){
    // if (ceci->l_espece!=NULL){
    //     printf("\npassage %s\n", ceci->l_espece);
    // }
    
    if (ceci == NULL) {
        return 0;
    }

    // int nb_gauche  = nb_elements_arbre_binaire(ceci->espece_gauche);
    // int nb_droite = nb_elements_arbre_binaire(ceci->espece_droite);

    if (ceci->est_espece){
        return 1;
    } else {
        int nb_gauche  = nb_elements_arbre_binaire(ceci->espece_gauche);
        int nb_droite = nb_elements_arbre_binaire(ceci->espece_droite); 
        return nb_gauche  + nb_droite;
    }

    // return 1 + nb_gauche  + nb_droite;
}

void detruire_arbre_binaire(a_noeud ceci){
    if (ceci!=NULL){
        // if(ceci->espece_droite != NULL){
        //     detruire_arbre_binaire(ceci->espece_droite);
        //     detruire_arbre_binaire(ceci->espece_gauche);
        //     liberer_noeud(ceci);
        // }
        detruire_arbre_binaire(ceci->espece_gauche);
        detruire_arbre_binaire(ceci->espece_droite);
        liberer_noeud(ceci);
    }
}

void finaliser_arbre_binaire(a_noeud* ceci){
    if (ceci != NULL && *ceci != NULL) {
        detruire_arbre_binaire(*ceci);
        *ceci = NULL;
    }
}

// void finaliser_arbre_binaire(a_noeud ceci){
//     if (ceci != NULL) {
//         detruire_arbre_binaire(ceci);
//         ceci = NULL;
//     }
// }

// a_noeud construire_arbre_phylogenetique() {
//     if (est_par_ouvr()) {
//         consommer_caractere('(');
//         separation();

//         a_noeud arbre_gauche = construire_arbre_phylogenetique();
//         consommer_caractere(':');
//         separation();

//         t_distance distance_gauche;
//         nombre_a_virgule();
//         distance_gauche = strtod(&mon_caractere, NULL);

//         a_noeud gauche = construire_arbre_phylogenetique(distance_gauche);

//         consommer_caractere(',');
//         separation();

//         a_noeud arbre_droite = construire_arbre_phylogenetique();
//         separation();
//         consommer_caractere(':');
//         separation();

//         t_distance distance_droit;
//         nombre_a_virgule();
//         distance_droit = strtod(&mon_caractere, NULL);
//         a_noeud droite = construire_arbre_phylogenetique(distance_droit);

//         consommer_caractere(')');

//         return nouveau_arbre_binaire(distance_gauche, distance_droit, NULL, gauche, droite, 0);
//     } else {
//         t_nom_espece nom_espece = nom();
        
//         a_noeud espece = (a_noeud)malloc(sizeof(t_noeud));
//         initialiser_noeud(espece, nom_espece);
        
//         espece->est_espece = 1;
        
//         return espece;
//     }
// }

// double recuperer_nombre_a_virgule() {
//     char buffer[50];
//     int i = 0;
    
//     while (mon_caractere != ',' && mon_caractere != ' ' && mon_caractere != ')') {
//         buffer[i++] = mon_caractere;
//         lire_caractere();
//     }
//     buffer[i] = '\0';

//     return strtod(buffer, NULL);
// }

// double recuperer_nombre_a_virgule() {
//     char buffer[50];
//     int i = 0;
    
//     while (mon_caractere != ',' && mon_caractere != ' ' && mon_caractere != ')') {
//         buffer[i++] = mon_caractere;
//         lire_caractere_sans_affichage();
//     }
//     buffer[i] = '\0';

//     while (mon_caractere == ' ' || mon_caractere == '\t' || mon_caractere == '\n') {
//         lire_caractere_sans_affichage();
//     }

//     return strtod(buffer, NULL);
// }

// double recuperer_nombre_a_virgule() {
//     double resultat = 0.0;
//     double facteur = 1.0;
//     int partie_decimale = 0;

//     while (mon_caractere != ',' && mon_caractere != ' ' && mon_caractere != ')') {
//         if (mon_caractere >= '0' && mon_caractere <= '9') {
//             resultat = resultat * 10 + (mon_caractere - '0');
//         }
//         else if (mon_caractere == '.') {
//             partie_decimale = 1;
//         }
//         else if (partie_decimale && mon_caractere >= '0' && mon_caractere <= '9') {
//             facteur /= 10.0;
//             resultat += (mon_caractere - '0') * facteur;
//         }
//         // printf("%c", mon_caractere);

//         lire_caractere_sans_affichage();
//     }

//     while (mon_caractere == ' ' || mon_caractere == '\t' || mon_caractere == '\n') {
//         lire_caractere_sans_affichage();
//     }

//     printf("%d", resultat);

//     return resultat;
// }

double recuperer_nombre_a_virgule() {
    double resultat = 0.0;
    double facteur = 1.0;
    int partie_decimale = 0;

    while (mon_caractere != ',' && mon_caractere != ' ' && mon_caractere != ')' && mon_caractere != '\t' && mon_caractere != '\n' && mon_caractere != '\r') {
        if (mon_caractere >= '0' && mon_caractere <= '9') {
            if (partie_decimale) {
                facteur /= 10.0;
                resultat += (mon_caractere - '0') * facteur;
            } else {
                resultat = resultat * 10 + (mon_caractere - '0');
            }
        } else if (mon_caractere == '.') {
            partie_decimale = 1;
        }

        lire_caractere_sans_affichage();
    }

    while (mon_caractere == ' ' || mon_caractere == '\t' || mon_caractere == '\n' || mon_caractere == '\r') {
        lire_caractere_sans_affichage();
    }

    // printf("%.2f", resultat);

    return resultat;
}

// double recuperer_nombre_a_virgule() {
//     double resultat = 0.0;
//     double facteur = 1.0;
//     int partie_decimale = 0;

//     lire_caractere_sans_affichage(); // Lire le premier caractère

//     while (mon_caractere != ',' && mon_caractere != ' ' && mon_caractere != ')' && 
//            mon_caractere != '\t' && mon_caractere != '\n' && mon_caractere != '\r' && 
//            mon_caractere != EOF) {
//         // printf("Lu : %c\n", mon_caractere);  // Debug : Voir les caractères lus

//         if (mon_caractere >= '0' && mon_caractere <= '9') {
//             if (partie_decimale) {
//                 facteur *= 0.1;
//                 resultat += (mon_caractere - '0') * facteur;
//             } else {
//                 resultat = resultat * 10 + (mon_caractere - '0');
//             }
//         } else if (mon_caractere == '.' || mon_caractere == ',') { // Support des deux séparateurs
//             partie_decimale = 1;
//         }

//         lire_caractere_sans_affichage();
//     }

//     // Ignorer les espaces et autres séparateurs restants
//     while (mon_caractere == ' ' || mon_caractere == '\t' || mon_caractere == '\n' || 
//            mon_caractere == '\r') {
//         lire_caractere_sans_affichage();
//     }

//     printf("%.2f\n", resultat);  // Debug final

//     return resultat;
// }


// char* recuperer_nom() {
//     char buffer[100];
//     int i = 0;

//     while (mon_caractere != ' ' && mon_caractere != ':' && mon_caractere != '\n' && mon_caractere != '(' && mon_caractere != ',' && mon_caractere != EOF) {
//         buffer[i++] = mon_caractere;
//         lire_caractere_sans_affichage();
//     }
//     buffer[i] = '\0';  // Terminer la chaîne

//     char* nom = (char*)malloc(i + 1);
//     strcpy(nom, buffer);
    
//     return nom;
// }

char* recuperer_nom() {
    char* nom = (char*)malloc(100 * sizeof(char));
    int i = 0;

    while (mon_caractere != ' ' && mon_caractere != ':' && mon_caractere != '\n' && mon_caractere != '(' && mon_caractere != ',' && mon_caractere != EOF) {
        nom[i++] = mon_caractere;
        // printf("%c", mon_caractere);
        lire_caractere_sans_affichage();
    }
    nom[i] = '\0';

    return nom;
}

a_noeud construire_arbre_phylogenetique() {
    if (est_par_ouvr()) {
        consommer_caractere_sans_affichage('(');
        separation_sans_affichage();

        a_noeud arbre_gauche = construire_arbre_phylogenetique();
        separation_sans_affichage();
        consommer_caractere_sans_affichage(':');
        separation_sans_affichage();

        t_distance distance_gauche = recuperer_nombre_a_virgule();

        consommer_caractere_sans_affichage(',');
        separation_sans_affichage();

        a_noeud arbre_droite = construire_arbre_phylogenetique();
        separation_sans_affichage();
        consommer_caractere_sans_affichage(':');
        separation_sans_affichage();

        t_distance distance_droite = recuperer_nombre_a_virgule();
        separation_sans_affichage();

        consommer_caractere_sans_affichage(')');

    //    if (mon_caractere == EOF) {
    //         return NULL;
    //     }
        
        return nouveau_arbre_binaire(distance_gauche, distance_droite, NULL, arbre_gauche, arbre_droite, 0);
    } else {
        t_nom_espece nom_espece = recuperer_nom();

        a_noeud espece = (a_noeud)malloc(sizeof(t_noeud));
        initialiser_noeud(espece, nom_espece);

        espece->est_espece = 1;

        return espece;
    }
}

void afficher_arbre(a_noeud ceci) {
    if (ceci == NULL) {
        printf("\nErreur : arbre NULL détecté !\n");
        return;
    }

    if (ceci->est_espece) {
        printf("%s", ceci->l_espece);
    } else {
        printf("(");
        if (ceci->espece_gauche){
            // printf("\npas nul");
        }
        
        afficher_arbre(ceci->espece_gauche);
        printf(":%.2f", ceci->distance_gauche);
        printf(", ");
        afficher_arbre(ceci->espece_droite);
        printf(":%.2f", ceci->distance_droite);
        printf(")");
    }
}

// char* nom() {
//     char* nom = malloc(100 * sizeof(char));
//     int i = 0;

//     while (est_lettre()) {
//         nom[i++] = mon_caractere;
//         lire_caractere();
//     }

//     nom[i] = '\0';

//     return nom;
// }