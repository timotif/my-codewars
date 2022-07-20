#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool solution(const char *string, const char *ending)
{
    int len_str = strlen(string);
    int len_end = strlen(ending);
    int offset = len_str - len_end;
    if (len_str < len_end)
        return false;
    for (int j = len_end - 1; j >= 0; j--)
    {
        printf("Comparing %c and %c\n", string[offset + j], ending[j]);
        if (string[offset + j] != ending[j])
            return false;
    }
    return true;
}

int main(void)
{
    char *string = "ails";
    char *ending = "fails";
    if (solution(string, ending))
        printf("True");
    else
        printf("False");
}