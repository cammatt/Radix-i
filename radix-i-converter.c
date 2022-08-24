#include <stdio.h>
#include <math.h>
#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Cameron Matthew"
#define YEAR "2022"


void Dec2RadixI(int dec_in, int radix){

    int no_of_digits = floor((log(dec_in))/(log(radix)));
    int i;

    for(i=0; i<=no_of_digits; i++){

        int max_value = pow(radix, no_of_digits-i);
        int multiplier;
        multiplier=floor(dec_in/max_value);
        dec_in-=(multiplier*max_value);

        if(multiplier<=9){
            printf("%d", multiplier);
        }
        else{
            int ascii_value=multiplier+55;
            printf("%c", ascii_value);
                
            }
        }
        
        printf("\n");
    }


int main(void){
    int dec_in=0;
    int radix=2;

    printf("*****************************\n %s \nWritten by: %s \nDate: %s\n*****************************\n", TITLE, AUTHOR, YEAR);
    
    while((dec_in>=0)&(radix>=2)){
        printf("Enter a decimal number: ");
        scanf("%d", &dec_in);
        double log_dec=log2(dec_in);

        if(dec_in>=0){
        printf("The number you have entered is %d\n", dec_in);
        printf("Enter a radix for the converter between 2 and 16: ");
        scanf("%d", &radix);
        if ((radix>=2)&(radix<=16)){
        printf("The radix you have entered is %d\n", radix);
        printf("The log2 of the number is %.2f\n", log_dec);
        printf("The integer result of the number divided by %d is %d\n", radix, (dec_in/radix));
        printf("The remainder is %d\n", (dec_in%radix));
        Dec2RadixI(dec_in, radix);
        }
        else{
            printf("The radix you entered in not within the permitted range.\n");
        }
        }
        else{
            printf("EXIT");
            return -1;}
    }
    return 0;
}
