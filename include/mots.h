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
    struct mots *suivant_app;
    struct mots *suivant_lex;
    struct mots *suivant_occ;
}Mot;


typedef struct {
    int nb_mot;
    Mot *liste_app;
    Mot *liste_lex;
    Mot *liste_occ;
}Texte;


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


/**
 * @brief Fonction d'insertion en fonction de l'apparation
 * dans le texte
 * 
 * @param liste_app 
 * @param mot 
 * @param i 
 * @return int 
 */
int insere_app(Mot *liste_app, char* mot, int i);


/**
 * @brief Fonction d'insertion en fonction de l'ordre
 * alphabétique 
 * 
 * @param mot 
 * @param liste_lex 
 * @return int 
 */
int insere_lex(Mot *mot, Mot *liste_lex);


/**
 * @brief Fonction de création d'une liste chainé trier dans
 * l'ordre alphabétique en fonction d'une autre liste
 * chainé déjà crée
 * 
 * @param liste_app 
 * @param liste_lex 
 * @return int 
 */
int tri_lex(Mot *liste_app, Mot *liste_lex);


/**
 * @brief Fonction d'insertion en fonction du nombre
 * d'occurence du mot dans le texte
 * 
 * @param mot 
 * @param liste_occ 
 * @return int 
 */
int insere_occ(Mot *mot, Mot *liste_occ);


/**
 * @brief Fonction de création d'une liste chainé trier de manière
 * en décroissante fonction du nombre d'occurence du mot
 * 
 * @param liste_app 
 * @param liste_occ 
 * @return int 
 */
int tri_occ(Mot *liste_app, Mot *liste_occ);


/**
 * @brief Fonction qui retire les majuscules d'un string
 * 
 * @param dest 
 * @param src 
 * @return char* 
 */
char *strtolower(char *dest, const char *src);


/**
 * @brief Fonction principal qui va récupéré les mots d'un
 * texte et les placer dans les différentes listes approprié
 * 
 * @param nom 
 * @param texte 
 * @return int 
 */
int cree_texte(char *nom, Texte *texte);

#endif