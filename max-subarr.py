def max_subarray(nums):
    """Find the largest sum of any contiguous subarray."""
    current_sum = 0
    best_sum = nums[0]
    for x in nums:
        current_sum += x
        if best_sum < current_sum:
            best_sum = current_sum
        if current_sum < 0:
            current_sum = 0
    return best_sum

print(max_subarray([-1, -3]))