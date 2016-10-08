#include <stdio.h> // fonction printf et autre
#include <stdlib.h>

// voici un commentaire

/*
 ceci est un commentaire
 sur plusieurs lignes
 */

// une fonction:
// - a un type de retour (quelque chose typé ou rien, par exemple int ou void)
// - a un nom (Attention, certains caractères sont interdits)
// - a des paramètres optionnels à passer entre les ()
// - on appelle "corps de la fonction" ce qui se trouve à l'intérieur des {}

// une fonction sans retour et sans paramètre:
void affiche_bonjour(void)
{
    // la fonction printf (pour print formatted data) sert à afficher du texte
    // formatté à l'écran. le header <stdio.h> doit être inclu pour qu'elle soit disponible.
    // pour plus d'information lire: http://www.cplusplus.com/reference/cstdio/printf/
    printf("Bonjour !\n");
}

// une fonction qui prend un type int comme seul paramètre :
void print_entier(int entier)
{
    printf("print_entier : %i \n", entier);
}

// une fonction qui prend un type int comme 1er paramètre et un type float comme 2ème :
void print_deux_nombres(int mon_entier, float mon_float)
{
    printf("print_deux_nombres : %i et %f\n", mon_entier, mon_float);
}

// une fonction qui prend un type int comme paramètre et qui retourne un int :
int multiply_by_two(int mon_entier)
{
    return mon_entier * 2;
}

// affiche une phrase différente suivant les valeurs passées en paramètre :
void print_conditional(int entier, int magic_number_1, int magic_number_2)
{
    if(entier == magic_number_1 || entier == magic_number_2)
    {
        printf("magic ! \n");
    }
    else
    {
        if(entier > 0)
        {
            printf("entier positif : %i \n", entier);
        }
        else if(entier == 0)
        {
            printf("entier égal à 0 \n");
        }
        else if(entier == magic_number_1)
        {
            printf("magic ! \n");
        }
        else
        {
            printf("entier négatif : %i \n", entier);
        }
    }

}

// cette fonction est déclarée ici (elle est définie après la fonction main)
// une fonction doit toujours être définie avant de pouvoir être appelée.
void printer(void);

// la fonction main est le point d'entrée de tout programme C/C++
int main()
{
    affiche_bonjour();
    printer();
    print_entier(33);
    print_deux_nombres(11, 1.1111);

    int resultat = 0;   // déclaration d'une variable de type int nommée "resultat"
    resultat = 88;      // assignation d'une nouvelle valeur a la variable "resultat"

    // nouvelle assignation de valeur par retour de la fonction "multiply_by_two"
    resultat = multiply_by_two(4);
    printf("resultat = %i \n", resultat); // affiche la valeur courante de "resultat"

    print_conditional(22, 42, 55);

    return 0; // retourne un code d'erreur (0 pour pas d'erreur)
}

// on définit ici la fonction déclarée plus haut dans le programme.
void printer(void)
{
    // type entier int
    int zozo = 42;
    // afficher la variable a: (int avec %i)
    printf("ma variable zozo contient : %i \n", zozo);

    // type float
    float flottant = 3.14;
    // afficher la variable flottant: (float avec %f)
    printf("ma variable flottant contient : %f \n", flottant);
    printf("ma variable zozo contient : %f \n", (float)zozo);
}
