#ifndef TABLEAU_H
#define TABLEAU_H
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "mots.h"
#define TAILLE_MAX 500
#define COEF_TAILLE 2

int compare_occ(const void* a, const void* b);
int compare_lex(const void* a, const void* b);
bool redimensionne(Texte *texte, int taille);
int appartient(Mot liste_mot[], int taille, char* mot);
int insere_tableau(Texte *texte, char* mot, int indice);
void tri_occurence(Mot tab[], int taille);
void tri_lex(Mot tab[], int taille);
int cree_texte(char *nom, Texte *texte);
#endif