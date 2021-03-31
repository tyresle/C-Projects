#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TranTiffanyStrongPasswordDetector.h"
#define MAX 100

int main() {
    menu();
    return 0;
}
int menu() {
    int selection;
    puts("-----------------------------------------------------------\nWelcome to StrongPasswordDetector. "
         "Would you like to...\n-----------------------------------------------------------");
    printf("%s\n%s", "1: Test your password strength.", "2. Generate a strong password.\n\n");

    scanf("%i", &selection);
    if (selection ==1) {
        puts("Testing your password strength...");
        testPass();//if user chooses 1st option, will go to test password function
    }
    else if (selection == 2) {
        puts("Generating a strong password...");
        suggestNew();//if user chooses 2nd option, will go to suggest new password function
    }
    else {
        while (selection!=1&&selection!=2) {//if user enters anything other than 1 or 2, will prompt them to reenter
            puts("Please select option 1 or 2!");
            menu();
            scanf("%i", &selection);
        }
    }
    return 0;
}
int testPass() {
    char userPass[MAX];//create user input array with a max size of 100
    int digit=0;
    int capital=0;
    int special=0;

    puts("Enter the password you want to test:\n");
    scanf("%s", userPass);

    printf("%s%lu%s","The length of your password is ", strlen(userPass) , " characters. ");//strlen will return the amount of characters
    //in user input

   for(int i = 0; i<strlen(userPass); i++) {
       if(userPass[i]>='0'&& userPass[i]<='9') {
           digit++;//increment digit if it is found in user input
       }
       else if(userPass[i]>='A' && userPass[i]<='Z') {
           capital++;//increment capital letters if it is found
       }
       else if(userPass[i]>='a' && userPass[i]<= 'z'){
       }
       else {
           special++;//for every other case, increment special characters
       }
   }
   printf("%s%d%s%s%d%s%s%d%s", "\nYou have ", digit, " digits in your password. \n", "You have ",capital," capital letters in your password.\n",
           "You have ", special, " special characters in your password.\n\n\n");

   //will print out "Your password is strong" if user satisfies the password requirements, otherwise whatever they are missing will
   //be printed out
   if (strlen(userPass) >= 11 && digit>= 2 && capital >=2 && special>=1) {
       puts("Your password is strong!");
   }
   if (strlen(userPass)<11) {
       puts("Consider adding more characters to your password, the recommended amount is 11 characters.");
   }
   if (digit<2) {
       puts("Consider adding more digits to your password, the recommended amount is 2 digits.");
   }
   if (capital<2) {
       puts("Consider adding more capital letters to your password, the recommended amount is 2 capital letters.");
   }
   if (special<1) {
       puts("Consider adding a special character to your password, the recommended amount is at least 1 special character.");
   }

    menuReturn();//calls back to menu
    return 0;
}
int menuReturn() {
    int returnMenu;
    puts("\n\nReturn to menu?");
    puts("1: Yes\n2: No");
    scanf("%i", &returnMenu);
    if (returnMenu==1) {//will return to menu if user chooses 1
        menu();
    }
    else if(returnMenu==2) {//exits the code if user chooses 2
    }
    else {
        puts("Please enter 1 or 2!");//prompts the user to enter 1 or 2
    }
    return 0;
}
int suggestNew() {
    char newPass[12];//password will be 11 characters long
    static const char punct_set[] = "~!@#$%^&*()_+";

    for (int i = 0; i < 3; i++) {//this for loop will set the password to have at least 3 letters, 3 numbers, and 3 capital letters.
        int number = rand()%10;
        char letter = 'a' + (rand()%26);
        char capLetter = 'A' + (rand()%26);
        newPass[i+1] = letter;
        newPass[i+2] = number;
        newPass[i+3] = capLetter;
        printf("%c%i%c", newPass[i+1], newPass[i+2], newPass[i+3]);//prints out the first 9 generated characters
    }//the other 2 will be generated separately
    newPass[10] = punct_set[rand()%(sizeof punct_set - 1)];//generates a special character from the array of special characters
    newPass[11] = 33 + rand()%94;//random character that isn't a whitespace
    printf("%c%c", newPass[10],newPass[11]);


    menuReturn();

    return 0;
}
