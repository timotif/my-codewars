nums = [-10000, -10000]

def findClosestNumber(nums):
    closest = nums[0];
    for n in nums:
        if abs(n) < abs(closest):
            closest = n
        elif abs(n) == abs(closest):
            if n > closest:
                closest = n
    return closest

print(findClosestNumber(nums))

