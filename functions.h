#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "apc.h"

int  dl_insert_first(Dlist **head, Dlist **tail, int data);
int  dl_insert_last(Dlist **head, Dlist **tail, int data);
void print_list(Dlist *head);
int  validate(int argc, char *argv[]);
void convert_string_to_DLL(char *input, Dlist **head, Dlist **tail);
int  dl_delete_list(Dlist **head, Dlist **tail);
int  compare_two_list(Dlist **head1, Dlist **head2);
void strip_leading_zeros(Dlist **head, Dlist **tail);
int  is_zero_list(Dlist *head);

#endif
