# Projet Phylo - Analyse d'Arbres Phylogénétiques

Ce projet permet de lire et de valider des arbres phylogénétiques à partir de fichiers respectant une grammaire donnée. Deux modes sont disponibles : un mode automatisé et un mode interactif.

## Compilation

Avant de lancer l'un des programmes, compilez le projet en tapant dans la console :

make

Cela générera les exécutables `phylo_automatise` et `phylo_interactif`.

## Lancement des programmes

Les deux programmes prennent en entrée le chemin vers un fichier contenant un arbre phylogénétique. Ce chemin doit être relatif au dossier dans lequel se trouve le fichier `main`.

### Mode automatisé

Pour lancer le programme en mode automatisé, tapez dans votre console :

./phylo_automatise

- Le programme vous demandera de saisir dans la console le chemin du fichier à analyser.
- Il effectuera automatiquement les opérations suivantes :
  1. Lecture et vérification syntaxique de l’arbre selon la grammaire donnée.
  2. Affichage dans la console de l’arbre tel qu’il est défini dans le fichier.
  3. Affichage de l’arbre reconstruit selon notre propre méthode.
  4. Sauvegarde automatique de cet arbre dans un fichier nommé `arbre{nombre}.txt`.

### Mode interactif

Pour lancer le programme en mode interactif, tapez dans votre console :

./phylo_interactif

- Le programme vous demandera également de saisir le chemin du fichier à analyser.
- Il exécutera ensuite les étapes suivantes :
  1. Lecture et validation de l’arbre selon la grammaire imposée.
  2. Affichage dans la console de l’arbre tel qu'il est décrit dans le fichier.
  3. Affichage de l’arbre reconstruit avec notre méthode.
  4. Vous devrez ensuite choisir le nom du fichier dans lequel vous souhaitez sauvegarder l’arbre.
  5. L’arbre est alors sauvegardé dans le fichier spécifié.

## Exemple de chemin d’entrée

Si votre fichier `arbre_0.phy` se trouve dans le dossier `exemples` de ce dossier, vous devez entrer :

exemples/arbre_0.phy

## Remarques

- Le format attendu du fichier est strictement défini par la grammaire fournie dans l'énoncé du projet.
- En cas d'erreur de syntaxe ou de structure, des messages explicites sont affichés pour aider à identifier l’origine du problème.