#include "apc.h"
#include "functions.h"

void multiplication_operation(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **res_h, Dlist **res_tail)
{

    Dlist* temp1=*tail1;
    Dlist* temp2=*tail2;

    Dlist *t_h1 = NULL; 
	Dlist *t_t1 = NULL; 

    Dlist *t_h2 = NULL; 
	Dlist *t_t2 = NULL; 

    int carry=0;
    int count=0;
    int res=0;

    while(temp2 != NULL)
    {
        temp1 = *tail1; 
        carry=0;
        while(temp1 != NULL)
        {
            res=(temp1->data * temp2->data)+carry;

            carry=res/10;
            res=res%10;

            dl_insert_first(&t_h1,&t_t1,res);

            temp1=temp1->prev;
        }

        if (carry > 0)
        {
            dl_insert_first(&t_h1, &t_t1, carry);
            carry = 0;
        }

        int k=count;
        while(k)
        {
            dl_insert_last(&t_h1,&t_t1,0);
            k--;
        }
        addition_operation(&t_h1, &t_t1, res_h, res_tail, &t_h2, &t_t2);

        dl_delete_list(res_h,res_tail);

        *res_h = t_h2;
        *res_tail = t_t2;

        dl_delete_list(&t_h1,&t_t1);

        t_h2=NULL;
        t_t2=NULL;

        count++;

        temp2=temp2->prev;
    }
}