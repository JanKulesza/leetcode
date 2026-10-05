class Solution:
    def separateDigits(self, nums: list[int]) -> list[int]:
        for i, num in enumerate(nums):
            while num >= 10:
                nums.insert(i + 1, num % 10)
                num //= 10
            nums[i] = num
        return nums
