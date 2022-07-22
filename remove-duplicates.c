#include <stdio.h>

void printArray(int a[], int s);
int removeDuplicates(int* nums, int numsSize);

int main(void)
{
    int numbers[] = {0,0,1,1,1,2,2,3,3,4};
    int size = sizeof(numbers)/sizeof(numbers[0]);
    // slide_arr(numbers, size, 3);
    printf("k = %i\n", removeDuplicates(numbers, size));
    printArray(numbers, size);
}

int removeDuplicates(int* nums, int numsSize)
{
    int counter = 0; 
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != nums[i + 1])
        {
            counter++;
        }
        nums[counter] = nums[i+1];
        printf("%i\t%i\t", i, counter);
        printArray(nums, numsSize);
    }
    return counter;
}

void printArray(int a[], int s)
{
    for (int i = 0; i < s; i++)
    {
        printf("%i ", a[i]);
    }
        printf("\n");
}