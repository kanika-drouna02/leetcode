class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        cnt=0
        preSum=0
        mp=defaultdict(int)
        mp[0]=1
        for num in nums:
            preSum+=num
            remove=preSum-k
            cnt+=mp[remove]
            mp[preSum]+=1
        return cnt
        