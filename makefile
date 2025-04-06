# all : phylo.exe

# phylo.exe : test_arbre.o arbre_binaire.o noeud.o verification_grammaire.o
# 	gcc -o phylo.exe test_arbre.o arbre_binaire.o noeud.o verification_grammaire.o

# test_arbre.o : test_arbre.c arbre_binaire.h noeud.h verification_grammaire.h
# 	gcc -c test_arbre.c

# arbre_binaire.o : arbre_binaire.c arbre_binaire.h noeud.h
# 	gcc -c arbre_binaire.c

# noeud.o : noeud.c noeud.h
# 	gcc -c noeud.c

# verification_grammaire.o : verification_grammaire.c verification_grammaire.h
# 	gcc -c verification_grammaire.c

# clean :
# 	rm -f *.o
# 	rm -f *.exe

all : phylo.exe

phylo.exe : main.o arbre_binaire.o noeud.o verification_grammaire.o
	gcc -o phylo.exe main.o arbre_binaire.o noeud.o verification_grammaire.o

main.o : main.c arbre_binaire.h noeud.h verification_grammaire.h
	gcc -c main.c

arbre_binaire.o : arbre_binaire.c arbre_binaire.h noeud.h
	gcc -c arbre_binaire.c

noeud.o : noeud.c noeud.h
	gcc -c noeud.c

verification_grammaire.o : verification_grammaire.c verification_grammaire.h
	gcc -c verification_grammaire.c

clean :
	rm -f *.o
	rm -f *.exe
