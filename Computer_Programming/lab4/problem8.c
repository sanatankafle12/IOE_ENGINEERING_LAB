 //Write a program that prompts the user to enter any integer from 1 to 7 and displays the corresponding day of the week.

 #include <stdio.h>


 int main()
 {
     int n;
     printf("Enter the number: ");
     scanf("%d",&n);
     switch (n)
     {
     case 1:
         printf("Sunday");
         break;
    
         case 2:
         printf("Monday");
         break;

    case 3:
         printf("Tuesday");
         break;

    case 4:
         printf("Wednesday");
         break;

    case 5:
         printf("Thursday");
         break;

    case 6:
         printf("Driday");
         break;

    case 7:
         printf("Satday");
         break;
     
    default:
        printf("enter number between 1 and 7");
         break;
     }
     return 0;
 }