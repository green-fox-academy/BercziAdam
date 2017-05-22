#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 struct pokemon{
    char name [256];
    int age;
 }pokemon_var_with_tag;
int main()
{

    pokemon_var_with_tag.age=1;
    strcpy(pokemon_var_with_tag.name,"Pikachu");




    printf("name%s\n",pokemon_var_with_tag.name);
    printf("age%d\n",pokemon_var_with_tag.age);


    struct pokemon magicarp;
    struct pokemon* magicarp_prt;
    magicarp_prt=&magicarp;
    magicarp_prt->age =100;
    strcpy(pokemon_var_with_tag.name,"Pikachu");

    return 0;
}
