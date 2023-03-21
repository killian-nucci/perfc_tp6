#ifndef TABLEAU_H
#define TABLEAU_H
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "mots.h"
#define TAILLE_MAX 500
#define COEF_TAILLE 2

/**
 * @brief Fonction de comparaison entre deux nombre d'occurence de mots
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int compare_occ(const void* a, const void* b);


/**
 * @brief Fonction de comparaison entre deux mots dans l'ordre lexicographique
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int compare_lex(const void* a, const void* b);


/**
 * @brief Fonction qui permet le redimensionnement d'un tableau
 * 
 * @param texte 
 * @param taille 
 * @return true 
 * @return false 
 */
bool redimensionne(Texte *texte, int taille);


/**
 * @brief Fonction de test d'appartenance d'un mot dans un tableau
 * 
 * @param liste_mot 
 * @param taille 
 * @param mot 
 * @return int 
 */
int appartient(Mot liste_mot[], int taille, char* mot);


/**
 * @brief Fonction d'insertion d'un mot dans un tableau
 * 
 * @param texte 
 * @param mot 
 * @param indice 
 * @return int 
 */
int insere_tableau(Texte *texte, char* mot, int indice);


/**
 * @brief Fonction de tri en fonction du nombre d'occurence
 * 
 * @param tab 
 * @param taille 
 */
void tri_occurence(Mot tab[], int taille);


/**
 * @brief Fonction de tri en fonction de l'ordre lexicographique
 * 
 * @param tab 
 * @param taille 
 */
void tri_lex(Mot tab[], int taille);


/**
 * @brief Fonction qui va lire un fichier et stoquer les mots dans un tableau une unique fois
 * 
 * @param nom 
 * @param texte 
 * @return int 
 */
int cree_texte(char *nom, Texte *texte);


/**
 * @brief Fonction qui libère un tableau de mots
 * 
 * @param texte 
 */
void libere_texte(Texte texte);

/**
 * @brief Fonction qui initialise la structure texte
 * 
 * @param texte 
 */
int init_texte(Texte *texte);
#endif