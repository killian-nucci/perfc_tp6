#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "mots.h"
#include "tableau.h"
#define TAILLE_MAX 500
#define COEF_TAILLE 2

int compare_occ(const void* a, const void* b) {
    Mot mot_a = *((Mot*)a);
    Mot mot_b = *((Mot*)b);
    if (mot_a.occurence == mot_b.occurence) {
        return 0;
    }
    if (mot_a.occurence > mot_b.occurence) {
        return -1;
    }
    return 1;
}

int compare_lex(const void* a, const void* b) {
    Mot mot_a = *((Mot*)a);
    Mot mot_b = *((Mot*)b);
    if (strcmp(mot_a.mot,mot_b.mot) == 0) {
        return 0;
    }
    if (strcmp(mot_a.mot, mot_b.mot) < 0) {
        return -1;
    }
    return 1;
}

//fonction inspiré du code fournis dans le TP 1 d'algo des arbres
bool redimensionne(Texte *texte, int taille) {
    Mot *tmp = realloc(texte->liste_mot, taille * sizeof(long int));
    if (tmp == NULL)
        return false;
    texte->liste_mot = tmp;
    texte->taille_max_liste = taille;
    return true;
}

int appartient(Mot liste_mot[], int taille, char* mot) {
    for (int i = 0; i < taille; i++) {
        if (strcmp(liste_mot[i].mot, mot) == 0) {
            return i;
        }
    }
    return -1;   
}

//fonction inspiré du code fournis dans le TP 1 d'algo des arbres
int insere_tableau(Texte *texte, char* mot, int indice) {
    int i;
    if ((i = appartient(texte->liste_mot, texte->nb_mot, mot)) >= 0) {
        texte->liste_mot[i].occurence++;
        return 0;
    }
    if (texte->nb_mot == texte->taille_max_liste) {
        if (!redimensionne(texte, texte->nb_mot * COEF_TAILLE))
            return -1; 
    }
    Mot *cell = alloue_mot(mot);
    texte->liste_mot[texte->nb_mot] = *cell;
    texte->nb_mot++;
    int taille_mot = strlen(mot);
    if (taille_mot > texte->taille_max_mot) {
        texte->taille_max_mot = taille_mot; 
    }
    return 1;
}

void tri_occurence(Mot tab[], int taille) {
    qsort(tab, taille, sizeof(Mot), compare_occ);
}

void tri_lex(Mot tab[], int taille) {
    qsort(tab, taille, sizeof(Mot), compare_lex);
}

int init_texte(Texte *texte) {
    texte->nb_mot = 0;
    texte->taille_max_mot = 0;
    texte->taille_max_liste = 500;
    texte->liste_mot = malloc(sizeof(Mot)*texte->taille_max_liste);
    if (!texte->liste_mot) {
        return 0;
    }
    return 1;
}


int cree_texte(char *nom, Texte *texte) {
    init_texte(texte); 
    FILE *f = fopen(nom, "r");
    if (!f){
        printf("Impossible de lire le fichier\n");
        return 0;
    }
    int i = 0;
    char buffer[512];
    char* token;
    const char *separateur = " \n,;:.?!\"()'’";
    while (fgets(buffer, 512, f)) {
        token = strtok(buffer, separateur);
        while (token != NULL) {
            if (mot_est_correct(token)) {
                if(insere_tableau(texte, token, i) < 0) {
                    exit(1);
                }
                i++;
            }
            token = strtok(NULL, separateur);
        }
    }
    fclose(f);
    return 1;
}