#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "noeud.h"
#include "arbre_binaire.h"
#include "verification_grammaire.h"

int main() {
    // on teste d'abord les fonctions avec une structure d'arbre que l'on construit
    // ici, on ne récupère pas d'un fichier
    t_noeud* espece1 = (t_noeud*)malloc(sizeof(t_noeud));
    initialiser_noeud(espece1, "Espèce1");

    t_noeud* espece2 = (t_noeud*)malloc(sizeof(t_noeud));
    initialiser_noeud(espece2, "Espèce2");

    t_noeud* espece3 = (t_noeud*)malloc(sizeof(t_noeud));
    initialiser_noeud(espece3, "Espèce3");

    // on fait un premier test avec un arbre qui contient seulement deux espèces et pas de sous-arbre
    a_noeud arbre = nouveau_arbre_binaire(1.0, 2.0, NULL, espece1, espece2, 0);
    printf("Arbre 1\n");
    printf("Distance gauche : %.2f\n", arbre->distance_gauche);
    printf("Distance droite: %.2f\n", arbre->distance_droite);
    printf("Est espèce: %d\n", arbre->est_espece);

    printf("Affichage de l'arbre phylogénétique 1 : ");
    afficher_arbre(arbre);
    printf("\n");
    affichage_console(arbre, "", 1, 0.0);

    int hauteur = hauteur_arbre_binaire(arbre);
    printf("\nHauteur prévue : 2\nHauteur de l'arbre : %d\n", hauteur);
    int nb_elements = nb_elements_arbre_binaire(arbre);
    printf("Nb éléments dans l'arbre prévu : 2\nNombre d'éléments dans l'arbre : %d\n", nb_elements);

    // on teste maintenant avec un arbre qui comprend un sous-arbre
    a_noeud arbre2 = nouveau_arbre_binaire(3.0, 0.5, NULL, arbre, espece3, 0);
    printf("\nArbre 2\n");
    printf("Distance gauche: %.2f\n", arbre2->distance_gauche);
    printf("Distance droite: %.2f\n", arbre2->distance_droite);
    printf("Est espèce: %d\n", arbre2->est_espece);

    printf("Affichage de l'arbre phylogénétique 2 : ");
    afficher_arbre(arbre2);
    printf("\n");
    affichage_console(arbre2, "", 1, 0.0);

    int hauteur2 = hauteur_arbre_binaire(arbre2);
    printf("\nHauteur prévue : 3\nHauteur de l'arbre : %d\n", hauteur2);
    int nb_elements2 = nb_elements_arbre_binaire(arbre2);
    printf("Nb éléments dans l'arbre prévu : 3\nNombre d'éléments dans l'arbre : %d\n", nb_elements2);

    int vide2 = est_arbre_vide(arbre2);
    printf("L'arbre est vide (0 prévu) : %d\n", vide2);
    finaliser_arbre_binaire(&arbre2);
    vide2 = est_arbre_vide(arbre2);
    printf("L'arbre est vide (1 prévu) : %d\n", vide2);
    
    // on fait maintenant un test avec un arbre que l'on récupère de l'un des fichiers test que l'on a à notre disposition
    printf("\nArbre 3\n");
    amorcer_lecture("exemples/arbre_4.phy");
    a_noeud arbre3 = construire_arbre_phylogenetique();

    if (arbre3 == NULL) {
        printf("Erreur : L'arbre n'a pas été construit correctement.\n");
    }

    afficher_arbre(arbre3);
    printf("\n");
    affichage_console(arbre3, "", 1, 0.0);
    printf("\n");

    printf("Hauteur de l'arbre prévue : 7\nHauteur de l'arbre : %d\n", hauteur_arbre_binaire(arbre3));
    printf("Nb éléments dans l'arbre prévu : 18\nNombre de nœuds dans l'arbre : %d\n", nb_elements_arbre_binaire(arbre3));
    
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
            // on tombe dans le cas où le fichier n'existe pas encore
            break;
        }
        fclose(fichier);
        numero++;
    }
    FILE *f = fopen(nom_fichier, "w");
    if (f != NULL) {
        sauvegarder_arbre(f, arbre3);
        fprintf(f, "\n");
        fclose(f);
        
        // on n'oublie pas de finaliser l'arbre que l'on a créé
        int vide3 = est_arbre_vide(arbre3);
        printf("L'arbre est vide (0 prévu) : %d\n", vide3);
        finaliser_arbre_binaire(&arbre3);
        vide3 = est_arbre_vide(arbre3);
        printf("L'arbre est vide (1 prévu) : %d\n", vide3);
    } else {
        printf("Erreur lors de l'ouverture du fichier\n");
    }
    return 0;
}