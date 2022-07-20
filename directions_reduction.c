#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// arr: directions to reduce, sz: size of arr, lg size of returned array
// function result will be freed
char** dirReduc(char** arr, int sz, int* lg) {
  // your code
  *lg = 0;
  // Initializing sums for the 2 axis
  int n_s = 0;
  int w_e = 0;
  int circle = 0;
  for (int i = 0; i < sz; i++)
{
  // printf("%d %s\n", i, arr[i]);
  if (i < sz - 3 && strcmp(arr[i], "NORTH") == 0 && strcmp(arr[i + 1], "WEST") == 0 && strcmp(arr[i + 2], "SOUTH") == 0 && strcmp(arr[i + 3], "EAST") == 0)
    circle += 1;
    if (strcmp(arr[i], "NORTH") == 0)
        n_s += 1;
    if (strcmp(arr[i], "SOUTH") == 0)
        n_s -= 1;
    if (strcmp(arr[i], "WEST") == 0)
        w_e -= 1;
    if (strcmp(arr[i], "EAST") == 0)
        w_e += 1;
}

*lg += (n_s < 0) ? -n_s : n_s;
*lg += (w_e < 0) ? -w_e : w_e;
for (int i = 0; i < circle; i++)
    {*lg += 4;}
printf("n_s = %d w_e = %d lg = %d circle = %d\n", n_s, w_e, *lg, circle);
char **ans = malloc(sizeof(char*) * (*lg));
int step;
int i = 0;
while (i < circle * 4)
{
    printf("circle = %d i = %d\n", circle, i);
    ans[i++] = "NORTH";
    ans[i++] = "WEST";
    ans[i++] = "SOUTH";
    ans[i++] = "EAST";
}
step = (n_s < 0) ? 1 : -1;
for (n_s = n_s; n_s != 0; n_s += step)
{
    printf("i = %d\n", i);
    // ans[i] = malloc(sizeof(char) * 6);
    printf("%s\n", (step == -1) ? "NORTH" : "SOUTH");
    ans[i] = (step == -1) ? "NORTH" : "SOUTH";
    i++;
}
step = (w_e < 0) ? 1 : -1;
for (w_e = w_e; w_e != 0; w_e += step)
{
    printf("i = %d\n", i);
    // ans[i] = malloc(sizeof(char) * 5);
    printf("%s\n", (step == -1) ? "EAST" : "WEST");
    ans[i] = (step == -1) ? "EAST" : "WEST";
    i++;
}
for (int i = 0; i < *lg; i++)
    printf("%s\t", ans[i]);
printf("\n");
  return ans;
}

int main(void)
{
    char *arr[] = {"NORTH", "WEST", "SOUTH", "EAST", "NORTH", "WEST", "SOUTH", "EAST", "SOUTH", "NORTH"};
    int lg = 1;
    dirReduc(arr, 10, &lg);
}