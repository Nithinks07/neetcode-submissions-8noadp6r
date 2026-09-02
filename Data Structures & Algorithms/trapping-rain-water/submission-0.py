class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        suffix =[0]*(n+1)
        for i in range(n-1,-1,-1):
            suffix[i] = max(suffix[i+1],height[i])
        prefix = 0 
        ans = 0 
        for i in range(n):
            prefix = max(prefix,height[i])
            minLen = min(prefix,suffix[i])
            ans += minLen - height[i]
        
        return ans 