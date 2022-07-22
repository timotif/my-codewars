#include <stdio.h>

int romanToInt(char * s);
int romanToIntArray(char * s);

int main(void)
{
    char *s = "LVIII";
    printf("The arabic for %s is %i\n", s, romanToIntArray(s));
}

int romanToInt(char * s)
{
    int i = 0;
    int sum = 0;
    int n = 0;
    while (*(s + i) != '\0')
    {
        char c = *(s + i);
        printf("Checking char %c\n", c);
        if (c == 'I')
        {
            n = 1;
            if (*(s + i + 1) == 'V' || *(s + i + 1) == 'X')
                n *= -1;
        }
        else if (c == 'V')
            n = 5;
        else if (c == 'X')
        {
            n = 10;
            if (*(s + i + 1) == 'L' || *(s + i + 1) == 'C')
                n *= -1;
        }
        else if (c == 'L')
            n = 50;
        else if (c == 'C')
        {
            n = 100;
            if (*(s + i + 1) == 'D' || *(s + i + 1) == 'M')
                n *= -1;
        }
        else if (c == 'D')
            n = 500;
        else if (c == 'M')
            n = 1000;
        else
            return -1;
        i++;
        sum += n;
    }
    return sum;
}

int romanToIntArray(char * s)
{
    int arr[100];
    arr['I'] = 1;
    arr['V'] = 5;
    arr['X'] = 10;
    arr['L'] = 50;
    arr['C'] = 100;
    arr['D'] = 500;
    arr['M'] = 1000;
    arr['\0'] = 0;
    int sum = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (arr[s[i]] < arr[s[i+1]])
            sum -= arr[s[i]];
        else
            sum += arr[s[i]];
    }
    return sum;
}