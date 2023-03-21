#include <getopt.h>
#include "mots.h"
#include "affichage.h"
#include "tableau.h"

typedef struct {
    char *texte;
    short lex;
    short dec;
    char *next;
    char *prev; 
    int n;
    int test;
} Arguments;

/**
 * @brief Fonction qui affiche l'aide
 * pour l'exécution
 * 
 */
void print_help(void) {
    printf("Utilisation : ./build/main [-anspe] [texte]\n"
           "Option :\n"
           "-h : Affiche la liste des arguments\n"
           "-a : Trie les mtos dans l'odre lexicographique\n"
           "-n : Trie en fonction du nombre d'occurence d'un mot dans l'odre décroissant\n"
           "-s : Prend que les mots situé une position après un mot donné\n"
           "-p : Prend que les mots situé une position avant un mot donné\n"
           "-e : Compte le nombre d'occurence d'un groupe de N mots donné\n"
           "-t : Lance les fonctions de test du programme\n"
           "\n Si vous ne metez pas d'argument après -s -p ou -e, cela resultera sur une erreur");
           exit(1);
}



/**
 * @brief Fonction pour parser les arguments
 * 
 * @param argc 
 * @param argv 
 * @return Arguments 
 */
Arguments parser(int argc, char *argv[]) {
    Arguments args = {
        .dec=0, .lex=0, .next=0, .prev=0, .test=0,
    };
    char c;
    while ((c = getopt(argc, argv, "ans:p:e:ht")) != -1)
    {
        switch (c) {

        case 't':
            args.test = 1;
            return args;
            
        case 'a':
            args.lex = 1;
            break;
        
        case 'n':
            args.dec = 1;
            break;
        
        case 's':
            args.next = optarg;
            break;

        case 'p':
            args.prev = optarg;
            break;
        
        case 'e':
            args.n = atoi(optarg);
            break;
        

        case 'h':
            print_help();
            break;

        default:
            print_help();
        }
    }
    args.texte = argv[optind];
    if (args.texte == NULL)
    {
        fprintf(stderr, "Argument manquant\n");
        exit(1);
    }
    return args;
}

int main(int argc, char* argv[]) {
    Arguments args = parser(argc, argv);
    Texte texte;
    cree_texte(args.texte, &texte);
    if (args.lex) {
        tri_lex(texte.liste_mot, texte.nb_mot);
    }
    if (args.dec) {
        tri_occurence(texte.liste_mot, texte.nb_mot);
    }
    affiche_texte(texte);
    libere_texte(texte);
    return 0;
}
