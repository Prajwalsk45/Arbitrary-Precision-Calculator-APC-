#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Dlist;

void addition_operation(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **res_h, Dlist **res_t);
void subtraction_operation(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **res_h, Dlist **res_t);
void multiplication_operation(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **res_h, Dlist **res_t);
int  division_operation(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **res_h, Dlist **res_t);

#endif
