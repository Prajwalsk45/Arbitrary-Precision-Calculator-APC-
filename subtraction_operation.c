#include "apc.h"
#include "functions.h"


void subtraction_operation(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **res_h, Dlist **res_tail)
{
    
    int ret=compare_two_list(head1,head2);

    if(ret == 1)
    {
        //swap
        Dlist *temp_h = *head1;
        *head1 = *head2;
        *head2 = temp_h;

        Dlist* tmep3 = *tail1;
        *tail1 = *tail2;
        *tail2 = tmep3;

    }

    Dlist* temp1=*tail1;
    Dlist* temp2=*tail2;

    int borrow=0;
    int res;
    while(temp1 != NULL && temp2 != NULL)
    {
        int val1 = temp1->data;   

        if (borrow)
        {
            val1--;              
        }

        if(val1 >= temp2->data)
        {
            res = val1 - temp2->data;
            borrow = 0;
        }
        else
        {
            res = (val1 + 10) - temp2->data;
            borrow = 1;
        }

        dl_insert_first(res_h, res_tail , res);

        temp1 = temp1->prev;
        temp2 = temp2->prev;
    }

    while(temp1 != NULL)
    {
        if(borrow == 1)
        {
            temp1->data = temp1->data - 1;
            borrow=0;
        }
        if(temp1->data >= 0)
        {
            res=temp1->data - borrow;
        }
        else
        {
            res=(temp1->data+10) - borrow;
            borrow=1;
        }

        dl_insert_first(res_h, res_tail, res);
        temp1 = temp1->prev;
    }


    strip_leading_zeros(res_h, res_tail);
}