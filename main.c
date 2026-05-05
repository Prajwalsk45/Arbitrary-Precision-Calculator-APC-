/*
Name : Prajwal S K
Date : 07/04/2025
Project Name : Arbitrary Precision Calculator.
Description : The Arbitrary Precision Calculator (APC) is a C-based application designed to perform arithmetic operations
              on integers of unlimited size, overcoming the limitations of standard data types. In this project, each number
              is represented using a doubly linked list, where every node stores a single digit, allowing dynamic memory
              allocation and precise digit-by-digit computation

*/

#include "apc.h"
#include "functions.h"
#include <string.h>

int main(int argc, char *argv[])
{
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *res_head = NULL, *res_tail = NULL;

    if (!validate(argc, argv))    //validate arguments
    {
        return 1;
    }

    printf("validate success\n");

    // Extract signs
    int sign1 = 1, sign2 = 1;

    char *num1 = argv[1];
    char *num2 = argv[3];

    if (num1[0] == '-')
    {
        sign1 = -1;
        num1++;   
    }

    if (num2[0] == '-')
    {
        sign2 = -1;
        num2++;   
    }

    // Build lists
    convert_string_to_DLL(num1, &head1, &tail1);
    convert_string_to_DLL(num2, &head2, &tail2);

    printf("A = "); 
    print_list(head1);
    printf("B = "); 
    print_list(head2);

    switch (argv[2][0])
    {
        //  ADDITION
        case '+':
        {
            int result_sign;

            if (sign1 == sign2)
            {
                addition_operation(&head1, &tail1, &head2, &tail2,&res_head, &res_tail);
                result_sign = sign1;
            }
            else
            {
                int cmp = compare_two_list(&head1, &head2);

                if (cmp == 0)
                {
                    subtraction_operation(&head1, &tail1, &head2, &tail2,&res_head, &res_tail);
                    result_sign = sign1;
                }
                else
                {
                    subtraction_operation(&head2, &tail2, &head1, &tail1,&res_head, &res_tail);
                    result_sign = sign2;
                }
            }

            
            strip_leading_zeros(&res_head, &res_tail);

            if (res_head == NULL || is_zero_list(res_head))
                printf("Result = 0\n");
            else
            {
                printf("Result = ");
                if (result_sign == -1) printf("-");
                print_list(res_head);
            }

            
        }
        break;
        // SUBTRACTION
        case '-':
        {
            sign2 = -sign2;
            int result_sign;

            if (sign1 == sign2)
            {
                addition_operation(&head1, &tail1, &head2, &tail2,&res_head, &res_tail);
                result_sign = sign1;
            }
            else
            {
                int cmp = compare_two_list(&head1, &head2);

                if (cmp == 0)
                {
                    subtraction_operation(&head1, &tail1, &head2, &tail2,&res_head, &res_tail);
                    result_sign = sign1;
                }
                else
                {
                    subtraction_operation(&head2, &tail2, &head1, &tail1,&res_head, &res_tail);
                    result_sign = sign2;
                }
            }

            // PRINT RESULT
            strip_leading_zeros(&res_head, &res_tail);

            if (res_head == NULL || is_zero_list(res_head))
                printf("Result = 0\n");
            else
            {
                printf("Result = ");
                if (result_sign == -1) printf("-");
                print_list(res_head);
            }

            
        }
        break;
        //  MULTIPLICATION
        case 'x':
        {
            multiplication_operation(&head1, &tail1, &head2, &tail2,&res_head, &res_tail);

            int result_sign = (sign1 * sign2 == -1) ? -1 : 1;

            strip_leading_zeros(&res_head, &res_tail);

            if (res_head == NULL || is_zero_list(res_head))
                printf("Result = 0\n");
            else
            {
                printf("Result = ");
                if (result_sign == -1) printf("-");
                print_list(res_head);
            }
        }
        break;
        // DIVISION
        case '/':
        {
            printf("Quotient = ");
            if (sign1 * sign2 == -1) printf("-");

            division_operation(&head1, &tail1, &head2, &tail2,&res_head, &res_tail);

            // remainder
            strip_leading_zeros(&res_head, &res_tail);

            printf("Remainder = ");
            if (res_head == NULL || is_zero_list(res_head))
                printf("0\n");
            else
                print_list(res_head);

        }
        break;
        default:
            printf("Unknown operator\n");
            break;
    }

    return 0;
}