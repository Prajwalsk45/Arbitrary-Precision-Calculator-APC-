#include "apc.h"
#include "functions.h"


int division_operation(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR)
{
    Dlist *temp1 = *head1;

    
    Dlist *curr_head = NULL;
    Dlist *curr_tail = NULL;

    // Quotient list 
    Dlist *headQ = NULL, *tailQ = NULL;

    while (temp1)
    {
        //Bring down the next digit 
        dl_insert_last(&curr_head, &curr_tail, temp1->data);

        // Strip leading zeros from the current chunk 
        strip_leading_zeros(&curr_head, &curr_tail);

        // If current chunk < divisor, quotient digit is 0 
        if (compare_two_list(&curr_head, head2) == 1)
        {
            dl_insert_last(&headQ, &tailQ, 0);
            temp1 = temp1->next;
            continue;
        }

        // Count how many times divisor goes into current chunk 
        int count = 0;
        while (compare_two_list(&curr_head, head2) == 0)
        {
            Dlist *new_head = NULL, *new_tail = NULL;

            subtraction_operation(&curr_head, &curr_tail,head2, tail2,&new_head, &new_tail);

            dl_delete_list(&curr_head, &curr_tail);
            curr_head = new_head;
            curr_tail = new_tail;

            strip_leading_zeros(&curr_head, &curr_tail);

            count++;
        }

        dl_insert_last(&headQ, &tailQ, count);
        temp1 = temp1->next;
    }

    
    strip_leading_zeros(&headQ, &tailQ);

    
    if (headQ == NULL || is_zero_list(headQ))
        printf("0\n");
    else
        print_list(headQ);

    dl_delete_list(&headQ, &tailQ);

    // Return remainder 
    *headR = curr_head;
    *tailR = curr_tail;

    return SUCCESS;
}
