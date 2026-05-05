#include "apc.h"
#include "functions.h"
#include <string.h>


int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new_node = (Dlist *)malloc(sizeof(Dlist));
    if (!new_node) return FAILURE;

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = *head;

    if(*head)
    {
        (*head)->prev = new_node;
    }
    else
    {
        *tail = new_node; 
    }  

    *head = new_node;
    return SUCCESS;
}



int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new_node = (Dlist *)malloc(sizeof(Dlist));
    if (!new_node) return FAILURE;

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = *tail;

    if(*tail)
    {
        (*tail)->next = new_node;
    }
    else
    {
        *head = new_node;  
    } 

    *tail = new_node;
    return SUCCESS;
}


void print_list(Dlist *head)
{
    Dlist *temp = head;
    while (temp)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int dl_delete_list(Dlist **head, Dlist **tail)
{
    Dlist *temp = *head;
    while (temp)
    {
        Dlist *next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
    *tail = NULL;
    return SUCCESS;
}


//Validate command-line arguments
int validate(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <number1> <operator> <number2>\n", argv[0]);
        return FAILURE;
    }

    
    if (argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != 'x' && argv[2][0] != '/')
    {
        printf("Invalid operator. Use +, -, x, /\n");
        return FAILURE;
    }

    //valid number 1
    int start = (argv[1][0] == '-') ? 1 : 0;
    if (argv[1][start] == '\0')
    {
        printf("Invalid number: %s\n", argv[1]);
        return FAILURE;
    }
    for (int i = start; argv[1][i]; i++)
    {
        if (!isdigit((unsigned char)argv[1][i]))
        {
            printf("Invalid number: %s\n", argv[1]);
            return FAILURE;
        }
    }

    //Valid number 2 
    start = (argv[3][0] == '-') ? 1 : 0;
    if (argv[3][start] == '\0')
    {
        printf("Invalid number: %s\n", argv[3]);
        return FAILURE;
    }
    for (int i = start; argv[3][i]; i++)
    {
        if (!isdigit((unsigned char)argv[3][i]))
        {
            printf("Invalid number: %s\n", argv[3]);
            return FAILURE;
        }
    }

    //Division by zero check 
    if (argv[2][0] == '/')
    {
        int all_zero = 1;
        int start = (argv[3][0] == '-') ? 1 : 0;
        for (int i = start; argv[3][i]; i++)
        {
            if (argv[3][i] != '0') 
            { 
                all_zero = 0; 
                break; 
            }
        }
        if (all_zero)
        {
            printf("Error - Division by zero\n");
            return FAILURE;
        }
    }

    return SUCCESS;
}


//Convert a digit string to a doubly linked list
void convert_string_to_DLL(char *input, Dlist **head, Dlist **tail)
{
    for (int i = 0; input[i]; i++)
    {
        dl_insert_last(head, tail, input[i] - '0');
    }
}


int compare_two_list(Dlist **head1, Dlist **head2)
{
    Dlist *t1 = *head1;
    Dlist *t2 = *head2;

    /* Count lengths */
    int len1 = 0, len2 = 0;
    Dlist *temp;
    for (temp = t1; temp; temp = temp->next) 
    {
        len1++;
    }
    for (temp = t2; temp; temp = temp->next)
    {
         len2++;
    }

    if (len1 > len2) return 0;  
    if (len1 < len2) return 1;  
    while (t1 && t2)
    {
        if (t1->data > t2->data) return 0;
        if (t1->data < t2->data) return 1;
        t1 = t1->next;
        t2 = t2->next;
    }
    return 0;   
}


//Remove leading zeros
void strip_leading_zeros(Dlist **head, Dlist **tail)
{
    while (*head && (*head)->data == 0 && (*head)->next)
    {
        Dlist *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
}


//Return 1 if the list represents the value 0
int is_zero_list(Dlist *head)
{
    return (head != NULL && head->next == NULL && head->data == 0);
}
