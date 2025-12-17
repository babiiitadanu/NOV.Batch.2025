#include <stdio.h>

int sum(int firstnumber, int secoundnumber)
{
 printf("Additation is: %d", firstnumber + secoundnumber);
}


int sub(int firstnumber, int secoundnumber)
{
    printf("Subtraction is: %d", firstnumber - secoundnumber);
}


int multiplication(int firstnumber, int secoundnumber)
{
   printf("Multiplication is: %d", firstnumber * secoundnumber);
}


int division(int firstnumber, int secoundnumber)
{
     printf("Division is: %d", firstnumber / secoundnumber);
}

int main()
{
    int firstnumber;
    int secoundnumber;

    while(1)
        {
            
            int num;
            printf("\n1. Additation: ");
            printf("\n2. Subtraction: ");
            printf("\n3. Multiplication: ");
            printf("\n4. Division: ");
            printf("\n5. Exit: ");
            printf("\nPlease select any option: ");
            scanf("%d", &num);
            if (num == 5){
                break;
            }
            printf("ENTER FIRST NUMBER: ");
            scanf("%d",&firstnumber);
            printf("ENTER SECOUND NUMBER: ");
            scanf("%d",&secoundnumber);

        

            if (num == 1)
            {

                sum( firstnumber, secoundnumber);
            }
            else if (num == 2)
            {

                sub(firstnumber, secoundnumber);
            }
            else if (num == 3)
            {

                multiplication(firstnumber, secoundnumber);
            }
            else if (num == 4)
            {

                division(firstnumber, secoundnumber);
            }
        }

    return 0;
}
