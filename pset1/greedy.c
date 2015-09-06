#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){

    printf("How much change is owned?\n");
    float n;
    n = GetFloat();
    do{
        if (n <= 0)
        {
            printf("Incorrect input!\n");
            n = GetFloat();
        }
    }while(n <= 0);
    
    float rounded = 0;
    float change;
    change = (n*100);
    rounded = roundf(change);
    
    int coins=0;
    int i;
    int j;
    int k;
    int l;
    
    do{
        
         for (i = 0; rounded >= 25; i++)
         {
            rounded = rounded - 25;
            coins ++;
         }
        
         for (j = 0; rounded >= 10; j++)
         {
            rounded = rounded - 10;
            coins++; 
         }
        
         for (k = 0; rounded  >= 5; k++)
         {
            rounded = rounded - 5;
            coins++; 
         }
        
         for (l = 0; rounded >= 1; l++)
         {
            rounded = rounded - 1;
            coins++; 
         }
        
     }while(rounded != 0);
        
     printf("%i\n", coins);
         
 }
