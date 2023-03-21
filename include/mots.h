#ifndef MOTS_H
#define MOTS_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct cellule_position {
    int pos;
    struct cellule_position *suivant;
}Cellule_position, *Liste_position;

typedef struct mots{
    char *mot;
    int occurence;
    Liste_position position;
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
 * @brief Fonction d'allocation d'une position
 * 
 * @param i 
 * @return Cellule_position* 
 */
Cellule_position *alloue_pos(int i);


/**
 * @brief Fonction d'insertion d'une position
 * 
 * @param liste_position 
 * @param i 
 * @return int 
 */
int insere_pos(Liste_position liste_position, int i);

int mot_est_correct(char *mot);
#endif