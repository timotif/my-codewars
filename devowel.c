#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char *disemvowel(const char *str)
{
    int len = strlen(str);
    char *output = malloc((len+1) * sizeof(char));
    int counter = 0;
    for (int i = 0; i < len; i++)
    {
        char ch = tolower(str[i]); 
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            continue;
        else
        {
            output[counter] = str[i];
            counter++;
        }
    }
    output[counter] = '\0';
    return output;
}

int main(void)
{
    printf("%s\n", disemvowel("You're fucking a loser!"));
}