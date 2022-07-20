#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool is_pangram(const char *str_in) {
    // Create array
    char alphabet[26] = {0};
    //  Populate alphabet
    int i = 0;
    for (i = 0; i < 26; i++)
    {
        alphabet[i] = i + 97;
        // printf("%c\t", alphabet[i]);
    }
    int len = strlen(str_in);
    // Looping through the chars of the str_in
    for (int j = 0; j < len; j++)
    {   
        // Finding the alphabetical position of the lowercase version of the character
        int position = tolower(str_in[j]) - 97;
        // printf("%c\t%i\t%i\n", str_in[j], position, (int) alphabet[position]);
        // If the position is positive (and hence part of the ASCII table) and the current char is == to the one in the alphabet array, turn the one in the alphabet to 0
        if (position >= 0 && tolower(str_in[j]) == (int) alphabet[position])
        {
            // printf("Switching %c in position %i\n", alphabet[position], position);
            alphabet[position] = 0;
        }
        // printf("Already switched\n");
    }
    // If in the array there's a char different from 0 it means it wasn't encountered in the string and therefore the check fails
    for (i = 0; i < 26; i++)
    {
        // printf("%c\t", alphabet[i]);
        if (alphabet[i] != 0)
            return false;
    }
    return true;
}

int main(void)
{
    char *string = "The quick brown fox jumps over the lazy dog";
    if (is_pangram(string))
        printf("True\n");
    else
        printf("False\n");
}