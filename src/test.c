#include "mots.h"
#include "tableau.h"
#include "affichage.h"

int test_strtolower(){
    char* tmp = "AzErtY";
    char* tmp2 = malloc(sizeof(char));
    strtolower(tmp2,tmp);
    if(!(strcmp("azerty", tmp2))){
        return 1;
    }
    return 0;
}

int test_mot_est_correct(){
    char* tmp1 = "aZecLhds";
    char* tmp2 = "12jnjbjzda13";
    if (mot_est_correct(tmp1) && !mot_est_correct(tmp2)){
        return 1;
    }
    return 0;
}

int test_trie_occurence(){
    Texte texte;
    char* tab[4] = {"un","deux","quatre"};
    init_texte(&texte);
    insere_tableau(&texte, "deux", 0);
    insere_tableau(&texte, "un", 1);
    insere_tableau(&texte, "un", 2);
    insere_tableau(&texte, "quatre", 3);
    tri_occurence(texte.liste_mot,texte.nb_mot);
    for(int i = 0; i < texte.nb_mot; i++) {
        if((strcmp( texte.liste_mot[i].mot, tab[i])))
            return 0;
    }
    return 1;
}

int test_trie_lex(){
    Texte texte;
    char* tab[3] = {"deux","quatre","un"};
    init_texte(&texte);
    insere_tableau(&texte, "deux", 0);
    insere_tableau(&texte, "un", 1);
    insere_tableau(&texte, "un", 2);
    insere_tableau(&texte, "quatre", 3);
    tri_lex(texte.liste_mot,texte.nb_mot);
    for (int i = 0; i < 3;i++){
        if((strcmp(texte.liste_mot[i].mot, tab[i])))
            return 0;
    }
    return 1;
}

int test(){
    if(!(test_strtolower())){
        printf("erreur test_strtolower\n");
        return 0;
    }
    if(!test_mot_est_correct()){
        printf("erreur test_mot_est_correct\n");
        return 0;
    }
    if(!test_trie_occurence()){
        printf("erreur test_trie_occurence\n");
        return 0;
    }
    if(!test_trie_lex()){
        printf("erreur test_trie_les\n");
        return 0;
    }
    return 1;
}
