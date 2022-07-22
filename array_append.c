#include <stdio.h>

void printArray(int a[], int s);
void arrayAppend (int *p, int a[], int size, int n);
void printPoint(int *p, int size);

int main(void)
{
    int array[] = {3, 4, 5};
    int size = sizeof(array)/sizeof(array[0]);
    printArray(array, size);
    int new_array[size+1];
    arrayAppend(new_array, array, size+1, 8);
    printArray(new_array, 4);
    // printPoint(new_array, 4);
}

void printPoint(int *p, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%i ", *(p + i));
    }
    printf("\n");
}

void printArray(int a[], int s)
{
    for (int i = 0; i < s; i++)
    {
        printf("%i ", a[i]);
    }
        printf("\n");
}

void arrayAppend (int *p, int a[], int size, int n)
{
    for (int i = 0; i < size; i++)
    {
        // printf("I'm storing tht value %i in the address %p\n", a[i], *(p+i));
        *(p+i) = a[i];
    } 
    *(p+size-1) = n;
}