#include <stdio.h>
#include <cs50.h>

/*
 1. get input on pyramid height and store it into variable hg ( hg as height)
 2. evaluate variable to fit into the range 1 to 23
 3. print hg as the beggining of the pyramid
 4. start the main loop and do *ALL THE MAGIC* !
 5. enjoy the feeling !
 6. go to sleep ;)
*/




int main(void){

        int s;
        int hg;
        int h;
        int a;
        int i;
        //int b;
        
        // get input on pyramid height
        printf("Height: ");
        hg = GetInt();
        //printf("%i", hg);
        // evaluation of input (input must be in range of 1 to 23, otherwise ask for input again
        do {            
            if (hg == 0){
                exit(0);}
            if (hg < 1 || hg > 23) {
                printf("Incorrect value! \n");
                printf("Height: ");
                hg = GetInt();}
        }while(hg < 1 || hg > 23);
        
        // initiation of variables
        s = hg - 1;
        h = 2;
        
        // begins pyramid by printing pyramid height as a top piece
        // If height  is greater or equal to 10, print one less space (cosmetic issue o_O)
        //if (hg >= 10){        
        //    for (b = 0; b <= (s-3); b++){
        //        printf(" ");}
        //   printf("%i", hg);
        //   printf("\n");}
        // If height of the pyramid is less or equal to 9 print one more space
        //if (hg <= 9){
        //    for (b = 0; b <= s-1; b++){
        //        printf(" ");}   
        //    printf("%i", hg);
        //    printf("\n");}
            
        // beggining of the main loop that will be executed until hg is 0 (until last piece has been placed)
        do {
                        // loop prints blank spaces based on its variable s (s as space)
                        for (i=1; i<=s; i++){
                                        printf(" ");
                        }
                        
            s = s-1;         
                        // loop prints # based on its variable h (h as hash)
                        for (a=1; a<=h; a++){
                                        printf("#");
                                    
                        }
       
            h = h+1;   
            printf ("\n");                   
            hg = hg-1;
        }while (hg > 0); 
    }
