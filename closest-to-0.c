#include <stdio.h>

int findClosestNumber(int* nums, int numsSize);
int abs(int n);

int main(void)
{
    int nums[] = {-100000,-100000};
    int size = sizeof(nums)/sizeof(nums[0]);
    printf("%i\n", findClosestNumber(nums, size));
}

int findClosestNumber(int* nums, int numsSize)
{
    int closest = nums[0];
    for (int i = 0; i < numsSize; i++)
    {
        if (abs(nums[i]) < abs(closest))
            closest = nums[i];
        else if (abs(nums[i]) == abs(closest))
            if (nums[i] > closest)
                closest = nums[i];
    }
    return closest;
}

int abs(int n)
{
if (n < 0)
    return -n;
else
    return n;
}
