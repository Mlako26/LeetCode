class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        l, r = 0, 1
        best = 0
        while r < len(prices):
            best = max(best, prices[r] - prices[l])
            if prices[l] > prices[r]:
                l = r
                r = r + 1
            else:
                r = r + 1
        return best
                