#include "apc.h"
#include "functions.h"


void addition_operation(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **res_h, Dlist **res_tail)
{
    Dlist* temp1=*tail1;
    Dlist* temp2=*tail2;
    int carry=0;
    while(temp1 != NULL && temp2 != NULL)
    {
        int res = temp1->data + temp2->data + carry;
        
        if(res > 9)
        {
            carry=1;
            res=res%10;
        }
        else
        {
            carry=0;
        }
        temp1=temp1->prev;
        temp2=temp2->prev;
        dl_insert_first(res_h, res_tail , res);
    }

    while(temp1 != NULL)
    {
        int res = temp1->data + carry;
        
        if(res > 9)
        {
            carry=1;
            res=res%10;
        }
        else
        {
            carry=0;
        }
        temp1=temp1->prev;
        
        dl_insert_first(res_h, res_tail , res);
    }

    while(temp2 != NULL)
    {
        int res = temp2->data + carry;
        
        if(res > 9)
        {
            carry=1;
            res=res%10;
        }
        else
        {
            carry=0;
        }
        temp2=temp2->prev;
        dl_insert_first(res_h, res_tail , res);
    }

    if(carry)
    {
        dl_insert_first(res_h, res_tail, carry);
    }
}