---
title: Perfectionnement à la programmation C
subtitle: TP6
date: 22 mars 2023
author:
    - Killian NUCCI
    - Victor MINARD
geometry: margin=3cm
...
 
# Introduction

Le but de se projet est de nous faire travailler sur la modularisation d'un projet et la conception de test pour notre projet

# Exercices:

## Exercice 1

### Question 2

- -a = Trie les mots dans l'ordre lexico.

- -n = Trie dans l'ordre dècroissant et si 2 mot on le même nombre d'occurence alors on les trie dans l'ordre lexico.

- -s = Compte les mot après le mot donnés.

- -p = Pareil que -s sauf qu'il prend les mot qui pécèdent le mot donnés.

- -e = Qui compte le nombre d'occurence de un ou d'un ensemble de mot en fonction de N.

- -h = Qui affiche l'aide pour la liste des arguments.

- -t = Lance les fontions de test du programme.

### Question 3

On a décider de découper notre projet en 3 parties:

1. La première partie est l'affichage qui consiste à afficher le resultats.
2. La deuxième partie comprend toute les fonction pour creer le tableaux en fonction des options.
3. Et la dernière partie permet de d'allouer la liste position qui est la liste de base.
4. Puis un dernier module qui regroupe tout les fichiers.

# Compilation

Pour cet exercice on utilise un make file

La compilation se fait avec la commande 

```bash
make
```

Et un `main` sera crée dans le répertoir `build`

Pour nettoyer les `.o` on utilisera la commande

```bash
make clean
```

