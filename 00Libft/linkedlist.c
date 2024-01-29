#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
     int x;
     struct Nodo*   next;
} Nodo;

void insert_end(Nodo **root, int value)
{
     Nodo *new_nodo = malloc(sizeof(Nodo));
     if(new_nodo == NULL)
          exit (1); //es una comprobación para saber si se aloca bien la memoria
     new_nodo->next = NULL;
     new_nodo->x = value;
     Nodo *curr = *root;
     while (curr->next != NULL)
     {
          curr = curr->next;
     }
     curr->next = new_nodo;
}

int main()
{
     Nodo *root = malloc(sizeof(Nodo));

     root->x = 15;
     root->next = NULL;
     insert_end(&root, -2);
     insert_end(&root, -11);
     Nodo *curr = root;
     while (curr != NULL)
     {    
          printf("%d\n", curr-> x);
          curr = curr->next; //Esto se sirve para avanzar
     }
     return (0);
}