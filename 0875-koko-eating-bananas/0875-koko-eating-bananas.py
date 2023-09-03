class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        maximum = 0
        for p in piles:
            if p > maximum:
                maximum = p
        
        low, high = 1, maximum
        while low < high:
            mid = (low + high) // 2
            counter = 0
            for p in piles:
                counter = counter - (p // -mid)
            if counter > h:
                low = mid + 1
            else:
                high = mid
        
        return high