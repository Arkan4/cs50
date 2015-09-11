#include <stdio.h>
#include <cs50.h>
#include <string.h>

/*Why to use constants :
 *
 * Constants are values that stay the same throughout the whole program
 * They cannot be reasigneated 
 *
 * Program runs in 2 times - COMPILING and RUN
 * 
 * COMPILING    = in which code is compiled and binarised (0 and 1)
 * RUN          = in which 0 and 1 are being executed
 *
 * If one defines variables, they are initialized in a RUN time (procesor must initialize them and then use them).
 * If constants are used, thet become a part of the code in COMPILE time.
 *
 * Using constants helps procesor because it can work with them as with data and does not need to initialize them before.
 * Constants are also smaller in size because unlike variables they do not change their size = memory efficency.  
 *EXAMPLE : 
 *
 *  const char* kInvalid = "INVALID";
 *  in which :
 *
 *  const       = indicates that constant is going to be declared
 *  char*       = is pointer (points to the memory where constant is going to be stored and also stays that characters are gonna be stored tehre)
 *  kInvalid    = name of the constant (k as a constant - just a name, can be anything)
 *  "INVALID"   = value of the constant (unchanging)
 *
 */


/*How does a pointer work :
 * Arrays are stored in the memory as continous data.
 * If array[5] is created, compiler will reserve 5 block of memory to be used by that array.
 * If i want to create function that will operate with arrays i need to give the array name
 * but also pointer so that compiler will be able to POINT TO THE START OF THE ARRAY so it can 
 * determine the lenght to reserve in memory (which is done like this: 1 + lenght of an array);
 * Example :
 *
 * char* Identify(char* pole);
 * in which :
 *      char*       = pointers (to indicate that function is using arrays)
 *      Identify    = name of the function
 *      pole        = name of the concrete array to be used by function
*/

// prototype for function Identify
 /* 
 *snprintf is a function that can be used to change data type and to write it into an array;
 *EXAMPLE :
 *
 * snprintf(pole,20, "%lld", cardnum);
 * 
 *      cardnum     = card number inputed by a human (of type long long due to the immense lenght of the cards)
 *      "%lld"      = same as %i but %lld is used for long long
 *      pole        = name of an array in which converted carnum is to be stored (as an characters, no longer numbers)
 *
 *SECURITY :    
 *
 *snprintf will write to the array (in this case pole) a converted values.
 *Problem is however with the lenght.
 *Array has defined lenght (in this case it is pole[20]) and snprintf will print characters to that array but only
 *up to the limits of an array :
 *                      - if array[3] and i want to write APPLE into it snprintf will write it like this :
 *                      [A][P][P] and finish (it making sure that no more than the array lenght will be used)
 *                      This is a security feature by itself (one that SPRINTF doesnt use)
 *
 * And now to the PROBLEM associated witch this security feature :
 *
 *SNPRINTF will use only the lenght of an array, but will use it UP TO ITS FULL CAPACITY meaning that if there is not 
 *enought space it WILL NOT WRITE A STRING TERMINATOR (\0).
 *In beforementioned example : [A][P][P] where array lengh is defined to 3 characters, simply would not have enough space
 *to write a string terminator (\0) and if another function was called to operate on this array to lets say print the
 *array it would print APP and would continue printing behind the boundaries of array till it finds first string terminator in its way !!!
 *And this is called OVERFLOW !
 *
 *SOLUTION :
 *
 *Simply reserve last part (index) of an array to always have a value of string terminator.)
 *pole[19] = '\0'; (pole lenght is 20 byt starting on 0 for computer so the lst character is 19!)
 *
 *[A][P][\0] - of course it will not store what i wanted to (APPLE) but it cannot be because my array was always too small for that anyway
 *but at least it will turncate it (chop off) and stop it before something else have a chance to go wrong because of it
 *
 * Tadaaaaaa .... pretty cool right o_O :) 
 */  


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
    
    for(i = len-1, j=1; i>=0; i--, j++)
    {
        //printf("XXX len=%d i=%d j=%d pole[i]=%c\n", len, i, j, pole[i]);
        if(j % 2 == 0)
        {
        // parne    
            char product[3];
            int digit;
            digit = pole[i] - '0';
            digit = (digit * 2);
            //printf("multiplied: %i \n",digit);
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
   
    //printf("Sum: %i\n",sum);
    if (sum % 10 == 0 )
    {
        printf("%s\n",Identify(pole));
    }else
    {
        printf("%s\n", kInvalid);
    }            
}





//Indentify type of the card and validates each types lenght
const char* Identify(char* pole)
{
    int len;
    len = strlen(pole);
    // AMEX cards begin with numbers 34 or 37 and consist of 15 digits
    if ((pole[0] =='3' && ((pole[1] == '4') || (pole[1] == '7'))) && (len == 15))
    {
        
        return kAmex; 
    }
    
    // MAESTRO cards begin with numbers between 51 - 55 and consist of 16 digits.
    else if ((pole[0] == '5' && (pole[1] >= '1') && (pole[1] <= '5')) && (len == 16))
    {   
        return kMastercard;
    }   
    
    // VISA cards begins with  number 4 and consists of either 13 or 16 digits.
    else if (pole[0] == '4' && (len >= 13 || len <= 16))
    {
        return kVisa;
    }
    else
    {
        return kInvalid;
    }
}





