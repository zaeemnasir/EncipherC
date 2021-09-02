#include <stdio.h>
#include <string.h>

/*
 * Author: Muhammad Nasir
 * Title: Assignment 1 - Encipher & Decipher
 * Date: 10-June-2020
 * Description: This program enciphers a simple text using a word as an encryption key
 *
 * Letters a=0, b=1, c=2, d=3, e=4, f=5, g=6, h=7, i=8, j=9, k=10, l=11, n=12, m=13... z=25
 */

// Prototype - Function definition
void encipher(char userInput[], char userKey[]);
void decipher(char encMessage[], char userKey[]);

int main() {
    // Declaring variables
    char userKey[101];
    char userInput[101];

    //Ask user for the message and the key
    printf("Please enter a message(letters only!): ");
    scanf("%s", userInput);
    printf("Please an encryption key(letters only!): ");
    scanf("%s", userKey);
    printf("\n");

    //Call the Encipher function
    encipher(userInput, userKey);
    printf("\n");

    return 0;
}// End of Main()


void decipher (char encMessage[], char userKey[]){
    // Declaring variables
    char decMessage[101];//represents decrypted message
    int i;
    int k;
    char shift;

    // Loop through the message and key
    for( i=0, k=0; encMessage[i] != '\0'; ++i, ++k){
        if (userKey[k] == '\0'){// if userKey is smaller than message
            k = 0;
        }
        // Decipher using c = (m[i] - k[i]) % 26
        shift = ((encMessage[i]-'a') - (userKey[k]- 'a')) % 26;
        // If shift is less that 0, take it back to the first letter
        if (shift <0){
            shift += 26;
        }
        // Update letter back to ASCII position
        decMessage[i] = shift + 'a';
    }
    decMessage [strlen(encMessage)] = '\0';

    printf("****Decipher****\n");
    printf("Enc:     %s\n", encMessage);
    printf("Key:     %s\n", userKey);
    printf("Message: %s\n", decMessage);
}// End of Decipher()

void encipher(char userInput[], char userKey[]){
    int i;
    int k;
    char shift;
    char encMessage[101];// represents encrypted message

    // Loop through the userInput and key
    for (i=0, k=0; userInput[i] != '\0'; ++i, ++k){
        if(userKey[k] == '\0'){// if user key is small than message, start from begininng again
            k = 0;
        }
        // Encipher using the orginal formula
        shift = ((userInput[i] - 'a') + (userKey[k] - 'a')) % 26;

        // Update to ASCII position
        encMessage[i]= shift + 'a';
    }

    encMessage[strlen(userInput)]= '\0';

    // Print output
    printf("****Encipher****\n");
    printf("Message: %s\n", userInput);
    printf("Key:     %s\n", userKey);
    printf("Enc:     %s\n\n", encMessage);
    // Calling the decipher method
    decipher(encMessage, userKey);


}// End of Encipher()



