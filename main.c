#include <getopt.h>
#include "mots.h"

typedef struct {
    char *texte;
} Arguments;

/**
 * @brief Fonction qui affiche l'aide
 * pour l'exécution
 * 
 */
void print_help(void) {
    printf("Utilisation : ./build/main [-v] [texte] [filtre]\n"
           "Option :\n"
           "-v : Création pdf");
}



/**
 * @brief Fonction pour parser les arguments
 * 
 * @param argc 
 * @param argv 
 * @return Arguments 
 */
Arguments parser(int argc, char *argv[]) {
    Arguments args;
    char c;
    while ((c = getopt(argc, argv, "v")) != -1)
    {
        switch (c)
        {
        case 'v':
            break;

        default:
            print_help();
        }
    }
    args.texte = argv[optind];
    if (args.texte == NULL)
    {
        fprintf(stderr, "Fichier manquant\n");
        exit(1);
    }
    return args;
}

int main(int argc, char* argv[]) {
    Arguments args = parser(argc, argv);
    Texte texte;
    cree_texte(args.texte, &texte);
}
