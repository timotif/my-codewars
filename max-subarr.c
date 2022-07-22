#include <stdio.h>

int maxSubArray(int* nums, int numsSize);

int main(void)
{
    int numbers[] = {-2, -3, -1};
    int size = sizeof(numbers)/sizeof(numbers[0]);
    printf("%i\n", maxSubArray(numbers, size));
}

int maxSubArray(int* nums, int numsSize)
{
    int curr_sum = 0;
    int best_sum = nums[0];
    for (int i = 0; i < numsSize; i++)
    {
        curr_sum += nums[i];
        if (best_sum < curr_sum)
            best_sum = curr_sum;
        if (curr_sum < 0)
            curr_sum = 0;
    }
    return best_sum;
}
