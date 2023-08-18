class Solution(object):
    def containsDuplicate(self, nums):
        used = set()
        
        for x in nums:
            if x in used:
                return True
            used.add(x)
        return False