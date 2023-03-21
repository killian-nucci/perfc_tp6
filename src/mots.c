#include "mots.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


char *strtolower(char *dest, const char *src) {
    char *result = dest;
    while((*(dest++) = tolower(*src++)));
    return result;
}


Mot *alloue_mot(char *mot) {
    Mot *cell_mot;
    cell_mot = malloc(sizeof(Mot));
    if (cell_mot == NULL)
        return NULL;
    cell_mot->mot = malloc(sizeof(char)*strlen(mot)+1); //on met +1 pour '\0'
    if (cell_mot->mot == NULL) {
        return NULL;
    }
    strtolower(cell_mot->mot, mot);

    cell_mot->occurence = 1;
    cell_mot->position = NULL;
    return cell_mot;
}


Cellule_position *alloue_pos(int i) {
    Cellule_position *cell = malloc(sizeof(Cellule_position));
    if (cell) {
        cell->pos = i;
        cell->suivant = NULL;
        return cell;
    }
    return NULL;
}

int insere_pos(Liste_position liste_position, int i) {
    Cellule_position *cell = alloue_pos(i);
    if (liste_position == NULL) {
        liste_position = cell;
        return 1;
    }
    for (;liste_position->suivant; liste_position = liste_position->suivant);
    liste_position->suivant = cell;
    return 1;
}



int mot_est_correct(char *mot) {
    for (int i = 0; mot[i]; i++) {
        if (!isalpha(mot[i])) {
            return 0;
        }
    }
    return 1;
}



