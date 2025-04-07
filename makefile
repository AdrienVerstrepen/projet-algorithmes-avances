all : phylo_automatise.exe phylo_interactif.exe

# le code phylo_automatise représente la version du code où la création du fichier test est automatisé, donc où l'utilisateur ne choisit pas le nom du fichier de retour
phylo_automatise.exe : main_automatise.o arbre_binaire.o noeud.o verification_grammaire.o
	gcc -o phylo_automatise.exe main_automatise.o arbre_binaire.o noeud.o verification_grammaire.o

main_automatise.o : main_automatise.c arbre_binaire.h noeud.h verification_grammaire.h
	gcc -c main_automatise.c

# le code phylo_interactif représente la version du code où le nom du fichier de sortie est laissé au choix de l'utilisateur
phylo_interactif.exe : main_interactif.o arbre_binaire.o noeud.o verification_grammaire.o
	gcc -o phylo_interactif.exe main_interactif.o arbre_binaire.o noeud.o verification_grammaire.o

main_interactif.o : main_interactif.c arbre_binaire.h noeud.h verification_grammaire.h
	gcc -c main_interactif.c

arbre_binaire.o : arbre_binaire.c arbre_binaire.h noeud.h
	gcc -c arbre_binaire.c

noeud.o : noeud.c noeud.h
	gcc -c noeud.c

verification_grammaire.o : verification_grammaire.c verification_grammaire.h
	gcc -c verification_grammaire.c

clean :
	rm -f *.o
	rm -f *.exe
