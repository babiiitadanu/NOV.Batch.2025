#include <stdio.h>


int multiplication()
{

   int firstnumber=250;
   int secoundnumber=50;

   printf("Multiplication: %d",firstnumber*secoundnumber);


}
int division()
{

   int firstnumber=250;
   int secoundnumber=50;

   printf("Division: %d",firstnumber/secoundnumber);


}


int main()
{
int num;
printf("\n1. Multiplication: ");
printf("\n2. Division: ");
printf("\n3. Please select any option: ");
scanf("%d",&num);

if(num==1)
{

  multiplication();

}
else if(num==2)
{

  division();

}


return 0;

}


