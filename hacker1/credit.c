#include <stdio.h>
#include <cs50.h>
#include <string.h>

const   char*   kInvalid    = "INVALID";
const   char*   kVisa       = "VISA";
const   char*   kAmex       = "AMEX";
const   char*   kMastercard = "MASTERCARD";

const char* Identify(char* pole);

int main(void)
{
    printf("Number: ");
    long long cardnum = GetLongLong();
    char pole[20];
    
    // input conversion from long long to char stored in array
    snprintf(pole, 20, "%lld", cardnum);
    pole[19] = '\0';

    int len;
    len = strlen(pole);

    int i;
    int j;
    int sum = 0;
    
    for(i = len - 1, j = 1; i >= 0; i--, j++)
    {
        // printf("XXX len=%d i=%d j=%d pole[i]=%c\n", len, i, j, pole[i]);
        if (j % 2 == 0)
        {
        // parne    
            char product[3];
            int digit;
            digit = pole[i] - '0';
            digit = (digit * 2);
            // printf("multiplied: %i \n",digit);
            snprintf(product, 3, "%i", digit);
            product[2] = '\0';

            for(int k = 0; k < strlen(product); k++)
            {                  
                digit = product[k] - '0';
               // printf("product[%d] = %d\n", k, digit);
                sum += digit;
                    
            }


        }else
        {
        // neparne
            sum += (pole[i] - '0');
        }
    }
    
    // printf("Sum: %i\n",sum);
    if (sum % 10 == 0 )
    {
        printf("%s\n", Identify(pole));
    }else
    {
        printf("%s\n", kInvalid);
    }            
}

// Indentify type of the card and validates each types lenght
const char* Identify(char* pole)
{
    int len;
    len = strlen(pole);
    // AMEX cards begin with numbers 34 or 37 and consist of 15 digits
    if ((pole[0] == '3' && ((pole[1] == '4')
                    || (pole[1] == '7'))) && (len == 15))
    {
        
        return kAmex; 
    }
    
    // MAESTRO cards begin with numbers
    // between 51 - 55 and consist of 16 digits.
    else if ((pole[0] == '5' && (pole[1] >= '1')
                && (pole[1] <= '5')) && (len == 16))
    {   
        return kMastercard;
    }   
    
    // VISA cards begins with  number 4 and consists of either 13 or 16 digits.
    else if (pole[0] == '4'
            && (len >= 13 || len <= 16))
    {
        return kVisa;
    }
    else
    {
        return kInvalid;
    }
}





