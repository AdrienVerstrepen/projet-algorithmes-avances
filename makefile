all : phylo.exe 

phylo.exe : verification_grammaire.c
	gcc -o verification_grammaire.exe verification_grammaire.c

clean : verification_grammaire.o
	rm *.o
	rm *.exe