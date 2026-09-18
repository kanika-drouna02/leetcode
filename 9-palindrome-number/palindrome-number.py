class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0:
            return False
        rev=0
        n=x
        while n:
            q=n%10
            rev= rev*10 + q
            n//=10

        if rev==x: return True
        else : return False

        
        
        