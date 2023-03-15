#include "mots.h"

Mot *alloue_mot(char *mot) {
    Mot *cell_mot;
    cell_mot = malloc(sizeof(Mot));
    if (cell_mot == NULL)
        return NULL;
    cell_mot->mot = malloc(sizeof(char)*strlen(mot)+1); //on met +1 pour '\0'
    if (cell_mot->mot == NULL) {
        return NULL;
    }
    strcpy(cell_mot->mot, mot);
    cell_mot->occurence = 0;
    cell_mot->position = NULL;
    cell_mot->suivant_app= NULL;
    cell_mot->suivant_lex = NULL;
    cell_mot->suivant_occ = NULL;
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
    for (;liste_position->suivant; liste_position = liste_position->suivant);
    liste_position->suivant = cell;
    return 1;
}

int insere_app(Mot *liste_app, char* mot, int i) {
    if (liste_app == NULL) {
        liste_app = alloue_mot(mot);
        return 1;    
    }
    for(; liste_app->suivant_app; liste_app = liste_app->suivant_app) {
        if (strcmp(liste_app->mot, mot) == 0) {
            liste_app->occurence++;
            insere_pos(liste_app->position, i);
            return 1;
        }
    }
    liste_app->suivant_app = alloue_mot(mot);
    return 1;
}

int insere_lex(Mot *mot, Mot *liste_lex) {
    for (; liste_lex; liste_lex = liste_lex->suivant_lex) {
        if (strcmp(mot->mot, liste_lex->mot) > 0) {
            mot->suivant_lex = liste_lex;
            liste_lex = mot;
            return 1;
        }
    }
    if (liste_lex == NULL) {
        liste_lex = mot;
        return 1;
    }
    return 0;
}

int tri_lex(Mot *liste_app, Mot *liste_lex) {
    for (; liste_app; liste_app = liste_app->suivant_app) {
        insere_lex(liste_app, liste_lex);
    }
    return 1;
}

int insere_occ(Mot *mot, Mot *liste_occ) {
    for (; liste_occ; liste_occ = liste_occ->suivant_occ) {
        if (mot->occurence > liste_occ->occurence) {
            mot->suivant_occ = liste_occ;
            liste_occ = mot;
            return 1;
        }
        if (mot->occurence == liste_occ->occurence) {
            if (strcmp(mot->mot, liste_occ->mot) > 0) {
                mot->suivant_occ = liste_occ;
                liste_occ = mot;
                return 1;
            } else {
                continue;
            }
        }
    }
    if (liste_occ == NULL) {
        liste_occ = mot;
        return 1;
    }
    return 0;
}


int tri_occ(Mot *liste_app, Mot *liste_occ) {
    for (; liste_app; liste_app = liste_app->suivant_app) {
        insere_occ(liste_app, liste_occ);
    }
    return 1;
}

char *strtolower(char *dest, const char *src) {
    char * result = dest;
    while((*(dest++) = tolower(*src++)));
    return result;
}

int cree_texte(char *nom, Texte *texte) {
    FILE *f = fopen(nom, "r");
    if (!f){
        printf("Impossible de lire le fichier\n");
        return 0;
    }
    int i = 0;
    char buffer[512];
    char* token;
    char* lower_token = NULL;
    const char *separateur = " \n,;:.?!\"()-'’123456789";
    while (fgets(buffer, 512, f)) {
        token = strtok(buffer, separateur);
        strtolower(lower_token, token);
        while (token != NULL) {
            if(!insere_app(texte->liste_app, lower_token, i)) {
                exit(1);
            }
            token = strtok(NULL, separateur);
            i++;
        }
        tri_lex(texte->liste_app, texte->liste_lex);
        tri_occ(texte->liste_app, texte->liste_occ);
    }
    fclose(f);
    return 1;
}

