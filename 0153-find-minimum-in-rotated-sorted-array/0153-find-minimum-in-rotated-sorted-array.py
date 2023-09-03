class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        low, high = 0, n-1
        
        while low < high - 1:
            mid = (low + high) // 2
            if nums[mid] < nums[n-1]:
                high = mid
            else:
                low = mid
        
        return min(nums[low], nums[high])