#include <stdio.h>
#include <math.h>
#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Cameron Matthew"
#define YEAR "2022"


void Dec2RadixI(int dec_in, int radix){

    int no_of_digits = floor((log(dec_in))/(log(radix)));       //the number of digits in the converted value is actually ceil(log(base radix)(dec_in)) but since we have the code to start its count at 0 and the value is used to find the max value less that the dec_in value, we rounded down. Used log laws to get log(base radix)(dec_in)
    int i;

    for(i=0; i<=no_of_digits; i++){     //iterating for each digit in the radix converted number

        int max_value = pow(radix, no_of_digits-i);     //max value when the radix is raised to the power of the ith digit considered (read from the LHS)
        int multiplier;
        multiplier=floor(dec_in/max_value);     //number of times this max value fits into the number considered, rounded down
        dec_in-=(multiplier*max_value);     //updated dec_in number, subtracting the rounded multiplier*max_value each iteration

        if(multiplier<=9){      //check to see whether a letter is required
            printf("%d", multiplier);
        }
        else{
            int ascii_value=multiplier+55;      //conversion to ASCII value that corresponds with the appropriate letter to be printed as a char
            printf("%c", ascii_value);
                
            }
        }
        
        printf("\n");
    }


int main(void){
    int dec_in=0;
    int radix=0;

    printf("*****************************\n%s \nWritten by: %s \nDate: %s\n*****************************\n", TITLE, AUTHOR, YEAR);
    
    while(dec_in>=0){      //Creating a loop to allow the code to repeat as long as the user enters a positive number
        printf("Enter a decimal number: ");
        scanf("%d", &dec_in);   //receiving the decimal input from the user
        double log_dec=log2(dec_in);

        if(dec_in>=0){         //check to see if the decimal input is above zero
        printf("The number you have entered is %d\n", dec_in);      //feeding the decimal input back to the user
        printf("Enter a radix for the converter between 2 and 16: ");
        scanf("%d", &radix);        //receiving the radix input from the user
        if ((radix>=2)&(radix<=16)){        //check to see whether the radix falls within the specified range
        printf("The radix you have entered is %d\n", radix);
        printf("The log2 of the number is %.2f\n", log_dec);
        printf("The integer result of the number divided by %d is %d\n", radix, (dec_in/radix));
        printf("The remainder is %d\n", (dec_in%radix));
        Dec2RadixI(dec_in, radix);      //running the Dec2RadixI function
        }
        else if(radix<0){       //if radix is<0, the user exits
            printf("EXIT");
            return -1;}
        else{       //if the radix does not fall within the permitted range but is still >=0, allows the user to try again
            printf("The radix you entered in not within the permitted range.\n");
        }
        }
        else{
            printf("EXIT");
            return -1;}
    }
    return 0;
}

