/*
During this lab, we were able to successfully implement a C program to print all the
semiprimes in a given range. We did this by designing the program to call the print functio
n if both the inputs, a and b, are both positive and if b is greater than or equal to a.
This program also used brak and continue loops.
Thanks for your time.
raghavv2 ishanj2 pujithb2
*/

#include <stdio.h>

int is_prime(int number);
int print_semiprimes(int a,int b);

int main()
{
  int a,b = 0;
  printf("Input two numbers: ");
  scanf("%d %d", &a, &b);
  print_semiprimes(a,b); //calls print semiprime
}

int is_prime(int number)
{
  int prime =1;
  for(int i=2;i<number;i++)
  {
    if(number%i==0)
    {
      prime=0; //if the number is a factor not a prime
    }
  }
  if((prime == 1 && number !=1) || number==2)
  {
    return 1; // base cases to see if isPrime is true
  }
  return 0;
}

int print_semiprimes(int a,int b)
{
  int semiprime=0;
  int z=0;
  for(int i=a;i<=b;i++) //outer loop for semiprime
  {
    for(int j=2;j<=i;j++) // inner loop to test particular number
    {
      z=i/j;
      if (i % j != 0) {
        continue; //next step in loop if is a factor
      }
      if(is_prime(j) == 1)
      {
        if(is_prime(z) == 1)
        {
          printf("%d ",i); // prints semiprime
          semiprime=1;
          break; //next step in loop
        }
      }

    }
  }
  printf("\n");
  if(semiprime==0)
  {
    return 0; //final return values to meet reference standards
  }
  else
  {
    return 1;
  }
}
