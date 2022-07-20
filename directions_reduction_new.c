#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// arr: directions to reduce, sz: size of arr, lg size of returned array
// function result will be freed

/* online solution: https://www.codewars.com/kata/reviews/5852cbecb1e9d3b3680000a0/groups/5a9f9556c87770e8e7002369 */

char **dirReduc(char **arr, int sz, int *lg)
{
    // your code
    char **tmp = (char **)malloc(sizeof(char *) * sz);
    for (int i = 0; i < sz; i++)
    {
        // tmp[i] = malloc(sizeof(char) * 6);
        tmp[i] = "\0";
    }
    *lg = 0;
    int j = 0;
    int i = 0;
    for (int i = 0; i < sz; i++)
    {
        while (j > 0 && !*tmp[j])
        {
            printf("rewind ");
            j--;
        }
        printf("j: %d\n", j);
        printf("\nbegin i = %d j = %d lg = %d\n", i, j, *lg);
        if ((strcmp(arr[i], "NORTH") == 0 && strcmp(tmp[j], "SOUTH") == 0) ||
            (strcmp(arr[i], "SOUTH") == 0 && strcmp(tmp[j], "NORTH") == 0) ||
            (strcmp(arr[i], "EAST") == 0 && strcmp(tmp[j], "WEST") == 0) ||
            (strcmp(arr[i], "WEST") == 0 && strcmp(tmp[j], "EAST") == 0))
        {
            printf("opposite_dir %s %s i = %d j = %d\n", arr[i], tmp[j], i, j);
            tmp[j] = "";
            if (*lg > 0)
                *lg -= 1;
            continue;
        }
        if (*tmp[j])
        {
            printf("the str %s exists\n", tmp[j]);
            j++;
            printf("Allocating memory for tmp[%d]\n", j);
            tmp[j] = malloc(sizeof(char) * 6);
            *lg += 1;
            strcpy(tmp[j], arr[i]);
        }
        else
        {
            printf("the str doesn't exists\n");
            printf("Allocating memory for tmp[%d]\n", j);
            tmp[j] = malloc(sizeof(char) * 6);
            printf("overwriting %s\n", tmp[j]);
            *lg += 1;
            strcpy(tmp[j], arr[i]);
        }
        printf("%s %s\n", arr[i], tmp[j]);
        printf("end i = %d j = %d lg = %d\n", i, j, *lg);
    }
    printf("i = %d j = %d\n", i, j);
    printf("*lg = %d\n", *lg);
    char **ans = (char**)malloc(sizeof(char*) * (*lg));
    for (int i = 0; i < *lg; i++)
    {
        ans[i] = malloc(sizeof(char) * 6);
        strcpy(ans[i], tmp[i]);
        free(tmp[i]);
    }
    free(tmp);
    for (int i = 0; i < *lg; i++)
        printf("%s ", ans[i]);
    printf("\n");
    return (ans);
}

int main(void)
{
    char *arr[] = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};
    //char *arr[] = {"NORTH", "WEST", "SOUTH", "EAST", "NORTH", "WEST", "SOUTH", "EAST", "SOUTH", "NORTH"};
    //char *arr[] = {"NORTH", "WEST", "SOUTH", "EAST"};
    int lg;
    dirReduc(arr, 7, &lg);
}