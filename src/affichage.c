#include "affichage.h"
#include "mots.h"
#include "tableau.h"
#include <stdio.h>

void affiche_texte(Texte texte) {
    printf("Liste par position:\n\n");
    for(int i = 0; i < texte.nb_mot; i++) {
        printf("%-*s %d\n", texte.taille_max_mot, texte.liste_mot[i].mot, texte.liste_mot[i].occurence);
    }
    printf("Liste par nombre d'occurence\n\n");
    tri_occurence(texte.liste_mot, texte.nb_mot);
    for(int i = 0; i < texte.nb_mot; i++) {
        printf("%-*s %d\n", texte.taille_max_mot, texte.liste_mot[i].mot, texte.liste_mot[i].occurence);
    }
    printf("Liste par ordre lexicographique\n\n");
    tri_lex(texte.liste_mot, texte.nb_mot);
    for(int i = 0; i < texte.nb_mot; i++) {
        printf("%-*s %d\n", texte.taille_max_mot, texte.liste_mot[i].mot, texte.liste_mot[i].occurence);
    }
}