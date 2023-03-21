#include "affichage.h"
#include "mots.h"
#include "tableau.h"
#include <stdio.h>

void affiche_texte(Texte texte) {
    for(int i = 0; i < texte.nb_mot; i++) {
        printf("%-*s %d\n", texte.taille_max_mot, texte.liste_mot[i].mot, texte.liste_mot[i].occurence);
    }
}