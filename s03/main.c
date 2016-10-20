#include <stdio.h>
#include <stdlib.h>

//-----------------------------------------------------------------
// Pointeur de structure, Opérateur de déréférencement * et d'indirection ->
//-----------------------------------------------------------------

// une structure permet de stocker plusieurs types groupés au même endroit.
typedef struct {
    int entier;
    float flottant;
} t_ma_struct;

static void var_struct_pointer()
{
    //------- struct type
    printf("\n-- struct pointer type --\n");
    
    t_ma_struct structure = {0, 0.f};
    
    // pointeur sur une structure (toujours initialiser un pointeur ou le mettre à NULL):
    t_ma_struct* st_ptr = NULL;
    st_ptr = &structure;
    
    // pour modifier les valeurs on doit déréférencer le pointeur avant d'accéder aux valeurs de la structure.
    
    // on peut donc écrire ça comme suit :
    (*st_ptr).entier = 10;
    (*st_ptr).flottant = 3.14;
    
    printf("ma struct contient : { entier : %i et flottant : %f} \n", (*st_ptr).entier, (*st_ptr).flottant);
    
    // mais le plus souvent on utilisera une autre syntaxe, complètement équivalente :
    st_ptr->entier = 20;
    st_ptr->flottant = 6.28;
    
    printf("ma struct contient : { entier : %i et flottant : %f} \n", st_ptr->entier, st_ptr->flottant);
    
    // le signe "->" est appelé opérateur d'indirection, il sert à dire "accède à la valeur pointée par mon pointeur"
}

//-----------------------------------------------------------------
// Incrémentation
//-----------------------------------------------------------------

static void incrementation()
{
    int a = 0;
    int b = 0;
    
    printf("1) a = %i \n", a);
    
    // on incrémente la valeur de a:
    a++;
    printf("2) a = %i \n", a);
    
    // on décrémente la valeur de a:
    a--;
    printf("3) a = %i \n", a);
    
    // on réinitialise "a" à 0
    a = 0;
    // à la ligne suivante, on assigne la valeur courante de a à b, PUIS on incrémente a
    b = a++;
    printf("4) a = %i et b = %i \n", a, b); // b vaut donc 0 et a désormais 1
    
    // on réinitialise "a" à 0
    a = 0;
    // à la ligne suivante, on incrémente a, PUIS on assigne la valeur courante de a à b
    b = ++a;
    printf("5) a = %i et b = %i \n", a, b); // a et b valent donc désormais 1
    
    // faire donc bien attention à l'endroit (avant ou après) où on place l'opérateur d'incrémentation.
    a = 0;
    printf("7) a = %i \n", a++); // on lit la valeur de a pour l'afficher, PUIS on l'incrémente.
    
    a = 0;
    printf("8) a = %i \n", ++a); // on incrémente a, PUIS on lit la valeur de a pour l'afficher.
}

//-----------------------------------------------------------------
// Retour sur les tableaux
//-----------------------------------------------------------------

static void var_array_pointer()
{
    // j'ai un tableau de 10 float.
    float array[10];
    
    // j'initialise mon tableau avec une boucle for
    int i=0;
    for(i = 0; i < 10; ++i)
    {
        array[i] = (float)i+1;
    }
    
    // un tableau se comporte en fait comme un pointeur
    
    // Si on passe directement:
    printf("array = %p \n", array);
    // on va afficher l'adresse de la première case du tableau
    
    // (array+1) correspond à l'adresse de la seconde case du tableau, et ainsi de suite...
    // vous remarquerez que l'adresse suivante est égale a :
    // l'adresse de la première case du tableau + la taille du type du tableau (ici la taille d'un float)
    printf("array = %p \n", array+1);
    
    // de la même manière qu'avec un simple pointeur sur une variable,
    // il est possible de déréférencer un tableau pour obtenir la valeur pointée.
    printf("*array = %f \n", *array);
    printf("*(array+1) = %f \n", *(array+1));
    printf("*array+1 = %f \n", *array+1);
    printf("*array+2 = %f \n", *array+2);
    
    // un pointeur sur un tableau ne peut pas être incrémenté directement
    // array++; // erreur
    
    float* array_ptr = array;
    printf("array_ptr = %p \n", array_ptr);
    printf("*array_ptr = %f \n", *array_ptr);
    
    // de la même manière qu'on incrémente une valeur
    // on peut incrémenter un pointeur (ce qui revient à dire "va à l'adresse suivante").
    array_ptr++;
    printf("array_ptr = %p \n", array_ptr);
    array_ptr++;
    printf("array_ptr = %p \n", array_ptr);
    
    // le pointeur pointe désormais sur la 3ème case du tableau
    printf("*array_ptr = %f \n", *array_ptr);
    
    // le pointeur pointe à nouveau sur la première case:
    array_ptr = array;
    printf("*array_ptr = %f \n", *array_ptr);
    
    // on a vu
    for(i=0; i < 10; ++i)
    {
        printf("valeur %i = %f \n", i, array_ptr[i]);
    }
    
    // mais on pourrai tout aussi bien écrire:
    for(i=0; i < 10; ++i)
    {
        printf("valeur %i = %f \n", i, *array_ptr);
        array_ptr++;
    }
    
    // ou bien encore plus directement:
    array_ptr = array;
    for(i=0; i < 10; ++i)
    {
        printf("valeur %i = %f \n", i, *array_ptr++);
        // qui signifie "incrémente mon pointeur (va à l'adresse suivante) puis déréférence le".
        
        // et équivaut à
        //printf("valeur %i = %f \n", i, *(array_ptr++) );
    }
}

//-----------------------------------------------------------------
// Main (entrée du programme)
//-----------------------------------------------------------------

// l'entrée du programme:
int main()
{
    var_struct_pointer();
    
    //incrementation();
    
    //var_array_pointer();
    
    return 0;
}
