#ifndef MOTS_H
#define MOTS_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct mots{
    char *mot;
    int occurence;
}Mot;


typedef struct {
    int nb_mot;
    int taille_max_mot;
    int taille_max_liste;
    Mot *liste_mot;
}Texte;


/**
 * @brief Fonction qui retire les majuscules d'un string
 * 
 * @param dest 
 * @param src 
 * @return char* 
 */
char *strtolower(char *dest, const char *src);


/**
 * @brief Fonction d'allocation d'un Mot
 * 
 * @param mot 
 * @return Mot* 
 */
Mot *alloue_mot(char *mot);

/**
 * @brief Test si un mot est syntaxiquement correct
 * 
 * @param mot 
 * @return int 
 */
int mot_est_correct(char *mot);
#endif