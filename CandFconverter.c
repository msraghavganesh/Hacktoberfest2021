#include<stdio.h>  
                   int main()   
                   {   
                        float num;
                        char val;
                        printf("Enter F if the value is in Fahrenheit or enter C if the value is in Celcius:"); 
                        scanf("%c", &val);
                        printf("Enter temperature value:");
                        scanf("%f", &num); 
                        switch(val){
                            case 'C':
                            printf("The temperature in Fahrenheit is: %.2f°F", (((num*9)/5)+32));
                            break;
                            case 'F':
                            printf("The temperature in Celcius is: %.2f°C", (((num-32)*5)/9));
                            break;
                            default:
                            printf("Error! enter the correct letter");

                        }
                   
                       return 0;  
    }