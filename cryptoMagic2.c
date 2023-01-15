#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main ()
{
    char line[255];
    int e = 0;
    char ch;
    FILE *fr = fopen("test.txt", "r"); //points to fp and opens test.txt for reading
    FILE *fw = fopen("write.txt", "w");
    char /*ch*/ hexadec[100];
    int  temp, j, i=1;
    long int quo, outchar;
    //char hex;


    ch = fgetc(fr);
    while (ch!=EOF){ 
            if (ch == 9){
               /* fputs("TT", fw);
                ch = fgetc(fr);*/
            }
            else if (ch < 32 && ch != 9){   
                printf("%c", ch);
               outchar = (ch-16) + 112;
                outchar = ch-16; //substract character dec value from 16
                quo = outchar; 
                while(quo!=0)//converts outchar to hexadecimal
                {
                temp = quo%16;
                if (temp<10)
                temp = temp + 48; else
                temp = temp + 55;
                hexadec[i++]=temp;
                quo = quo/16;
                }
                for (j = i-1; j>0; j--)
                fprintf(fw, "%c", hexadec[j]);  //prints hex to file
                ch = fgetc(fr); 
            }
            else if (ch == 10){
                printf("\n");
                fputs("\n", fw);
                ch = fgetc(fr);
            }
            else{
                fprintf("%c", ch);
                
                outchar = ch-16; //substract character dec value from 16
                quo = outchar; 
                while(quo!=0)//converts outchar to hexadecimal
                {
                temp = quo%16;
                if (temp<10)
                temp = temp + 48; else
                temp = temp + 55;
                hexadec[i++]=temp;
                quo = quo/16;
                ch = fgetc(fr);
                }
                for (j = i-1; j>0; j--)
                fprintf(fw, "%c", hexadec[j]);  //prints hex to file
                ch = fgetc(fr); 
            }
            ch = fgetc(fr);
        }

            

    fclose(fr);
    fclose(fw);
    return 0;
}
