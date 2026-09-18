class Solution:
    def largestRectangleArea(self, nums: list[int]) -> int:
        mx=0
        n=len(nums)
        s=[]
        for i in range(n+1):
            cur=0 if i==n else nums[i]
            while s and (i==n or nums[s[-1]]>=cur):
                h=nums[s.pop()]
                if not s:
                    w=i
                else:
                    w=i-s[-1]-1
                mx=max(mx,w*h)
            s.append(i)
        return mx

                
            

        