#include <stdio.h>
#include <stdlib.h>

#include <limits.h> // INT_MIN...
#include <float.h>  // FLT_MIN...

//-----------------------------------------------------------------
// Structure
//-----------------------------------------------------------------

// une structure permet de stocker plusieurs types groupés au même endroit.
typedef struct {
    int entier;
    float flottant;
} t_ma_struct;

void var_struct()
{
    //------- struct type
    printf("\n-- struct type --\n");

    // on peut initialiser une structure comme ça:
    t_ma_struct st = {0, 0.f};

    // puis modifier les valeurs des variables qui la composent:
    st.entier = 10;
    st.flottant = 3.14f;

    printf("ma struct contient : { entier : %i et flottant : %f} \n", st.entier, st.flottant);

    // la structure que l'on vient de voir contient seulement un entier et un flottant
    // mais elle pourrait tout aussi bien contenir n'importe quelle type de variables.
}

//-----------------------------------------------------------------
// Tableaux de taille fixe
//-----------------------------------------------------------------

void var_array_fixed_alloc()
{
    //------- arrays
    printf("\n-- array --\n");

    // il y a deux sortes de tableaux:
    // - les tableaux à taille fixe
    // - les tableaux à taille dynamique.

    // on peut créer un tableau de n'importe quel type,
    // mais un tableau stockera toujours des données du même type

    // Un tableau de 4 int se déclare comme ça:
    int int_array[4];

    // et peut s'initialiser comme suit:
    // (attention un tableau commence toujours à la case 0 (de 0 à 3 dans ce cas))
    int_array[0] = 1; // on initialise la première case du tableau à 1
    int_array[1] = 2; // la deuxième...
    int_array[2] = 3; // ...
    int_array[3] = 4;

    // pour lire les valeurs on accède simplement au tableau de la même façon:
    printf("int_array[0] = %i \nint_array[1] = %i \n", int_array[0], int_array[1]);

    // une autre façon d'initialiser un tableau
    //int int_array_2[] = {0, 9, 7, 4, 1}; // un tableau à 5 cases

    // pour réinitialiser toutes les valeurs de notre tableau à 0 on pourrait écrire
    /*
    int_array[0] = 0;
    int_array[1] = 0;
    int_array[2] = 0;
    int_array[3] = 0;
    */


    // Mais le plus souvent on va recourir à une boucle pour initialiser un tableau:
    int i = 0;
    for(; i < 4; ++i)
    {
        printf("-- iteration %i : \n", i);
        printf("int_array[%i] valait %i \n", i, int_array[i]);
        int_array[i] = 0;
        printf("int_array[%i] vaut maintenant %i \n", i, int_array[i]);
    }
}

//-----------------------------------------------------------------
// Types basiques
//-----------------------------------------------------------------

// il y a différents types de variables
// suivant le type de variable on va pouvoir stocker des nombres plus ou moins grands:
// la mémoire d'un ordinateur ne sait stocker que des nombres !!
// https://en.wikipedia.org/wiki/C_data_types

void var_basic()
{
    //------- integer types
    printf("\n-- integer types --\n");
    // un type entier peut être signé ou non-signé (signed or unsigned)
    // représenter un nombre entier
    int entier = 22; // prendre l'habitude de toujours initialiser une variable
    // par defaut un nombre est signé, on peut donc stocker des valeurs négatives.
    entier = -22;
    // signed int entier; => equivalent

    printf("entier : %i \n", entier); // affiche un entier de type int

    // un byte (aujourd'hui composé d'un octet, 8 bits) est la plus petite unité adressable d'un ordinateur.
    // l'operateur sizeof permet de connaitre la taille (en bytes) d'une variable ou d'un type de donnée.
    // sur ma machine un int fait 4 bytes.
    printf("sizeof(int) : %lu \n", sizeof(int));

    // la valeur minimum et maximum qu'un int peut stocker
    printf("int min/max : %i | %i \n", INT_MIN, INT_MAX);

    printf("sizeof(long) : %lu \n", sizeof(long));
    // la valeur minimum et maximum qu'un long peut stocker
    printf("long min/max : %li | %li \n", LONG_MIN, LONG_MAX);

    //------- unsigned integer types
    printf("\n-- unsigned integer types --\n");
    // un entier non signé a la même taille (en bytes) qu'un entier mais peut stocker des nombres 2x plus grands (mais uniquement positifs)
    printf("sizeof(unsigned int) : %lu \n", sizeof(unsigned int));
    // la valeur minimum et maximum qu'un unsigned int peut stocker:
    printf("unsigned int min/max : 0 | %u \n", UINT_MAX);

    //------- floating-point types
    printf("\n-- floating-point types --\n");
    // un nombre flottant est forcémment signé (peut être négatif ou positif)
    float flottant = 3.14159;
    // afficher un nombre flottant (float ou double)
    printf("flottant : %f \n", flottant);
    // sur ma machine un float fait 4 bytes et un double... le double
    printf("sizeof(float) : %lu \n", sizeof(float));
    printf("sizeof(double) : %lu \n", sizeof(double));
    // la valeur minimum et maximum qu'un float et un double peuvent stocker:
    printf("float min/max : %e | %e \n", FLT_MIN, FLT_MAX);
    printf("double min/max : %e | %e \n", DBL_MIN, DBL_MAX);
}

//-----------------------------------------------------------------
// Pointeurs
//-----------------------------------------------------------------

int multiply_by_two(int entier);
void divide_hours_bad(int heures, int minutes);
void multiply_by_two_with_ptr(int* entier_ptr);
void divide_hours(int* heures, int* minutes);

void var_pointers()
{
    //------- pointers
    printf("\n-- pointers --\n");

    // quand on crée une variable, on demande à l'ordinateur de nous réserver un espace de mémoire libre,
    // une (ou souvent plusieurs) case(s) dans laquelle elle va pouvoir être stockée/représentée.

    int a = 42;

    // quand on assigne une variable à une autre variable, on COPIE sa VALEUR
    int b = 26;
    b = a;

    printf("b vaut %i \n", b);

    // de la même façon, quand on passe une variable en paramètre à une fonction,
    // on ne passe pas la variable elle même mais une copie de sa valeur.

    // pour modifier la valeur de b, on peut se servir de la valeur de retour d'une fonction
    b = multiply_by_two(b);
    printf("b vaut maintenant %i \n", b);

    // mais comment on fait pour modifier deux valeurs en même avec une fonction ?
    // j'ai par exemple deux variables
    int heures = 0;
    int minutes = 90;

    // comme on ne peut pas retourner plus d'une valeur, on voudrait écrire quelque chose comme ça:
    divide_hours_bad(heures, minutes);

    // mais si on affiche les valeurs on s'aperçoit qu'elles n'ont pas changé du tout !
    printf("%i heures et %i secondes \n", heures, minutes);

    // en fait pour réussir à faire ce qu'on veut on va être obligé de passer par des pointeurs !

    // => schéma mémoire |adresse|valeur|

    // à chaque variable est associé une adresse dans la machine.

    int ma_variable = 33;

    // on peut afficher l'adresse d'une variable comme ça: (%p pour pointeur)
    printf("ma_variable est sockée à l'adresse : %p \n", &ma_variable);

    // un pointeur est tout simplement un type de variable qui va nous permettre de stocker des adresses.
    // pour créer un pointeur d'int par exemple on va rajouter le symbole * avant le nom de la variable.

    int *mon_ptr = NULL; // j'initialise mon pointeur à NULL (il ne pointe pour l'instant vers rien)

    // on assigne maintenant l'adresse de ma_variable à mon_ptr
    mon_ptr = &ma_variable;

    // si on affiche la valeur de mon_ptr on obtiens la même adresse que celle de ma_variable
    printf("la valeur de mon_ptr est : %p \n", mon_ptr);

    // comme mon_ptr pointe désormais sur la même valeur que ma_variable
    // on peut s'en servir directement pour modifier ou afficher sa valeur.
    // pour cela on va "déréférencer le pointeur"

    printf("la valeur pointée par mon_ptr est : %i \n", *mon_ptr);

    // si j'écris ça:
    *mon_ptr = 55;
    // j'ai modifié la valeur pointée par mon pointeur (ma_variable)
    // ma_variable contient donc désormais la nouvelle valeur:
    printf("ma_variable vaut maintenant : %i \n", ma_variable);
    printf("ma_variable vaut maintenant : %i \n", *mon_ptr);

    // mais à quoi va nous servir un pointeur ??
    // Eh bien on va pouvoir s'en servir en les passant comme paramètre dans des fonctions !
    // par exemple :

    // on passe donc mon_ptr directement
    multiply_by_two_with_ptr(mon_ptr);
    printf("ma_variable vaut maintenant : %i \n", ma_variable);

    // ou alors on passe l'adresse de ma_variable
    multiply_by_two_with_ptr(&ma_variable);
    printf("ma_variable vaut maintenant : %i \n", ma_variable);

    // la fonction précédente peut donc être réecrite comme ça:
    divide_hours(&heures, &minutes);
    printf("%i heures et %i secondes \n", heures, minutes);
}

int multiply_by_two(int entier_copy)
{
    return entier_copy * 2;
}

void divide_hours_bad(int heures, int minutes)
{
    heures += minutes / 60;  // 90 / 60 = 1
    minutes = minutes % 60;  // 90 % 60 = 30

    printf("(divide_hours_bad) %i heures et %i secondes \n", heures, minutes);
}

void multiply_by_two_with_ptr(int* entier_ptr)
{
    *entier_ptr *= 2;
}

void divide_hours(int* heures, int* minutes)
{
    *heures += *minutes / 60;  // 90 / 60 = 1
    *minutes = *minutes % 60;  // 90 % 60 = 30
}

//-----------------------------------------------------------------
// Main (entrée du programme)
//-----------------------------------------------------------------

// l'entrée du programme:
int main()
{
    var_struct();

    var_array_fixed_alloc();

    var_basic();

    var_pointers();

    return 0;
}
