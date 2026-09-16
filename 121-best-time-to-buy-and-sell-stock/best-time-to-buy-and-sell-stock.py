class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        mi=prices[0]
        dif=0
        for num in prices:
            mi = min(num,mi)
            dif = max(dif, num-mi)
        return dif
        