class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """

        maxA = 0
        s, t = 0, len(height)-1
        while s != t:
            area = min(height[s], height[t]) * (t-s)

            # update maxA
            if area > maxA:
                maxA = area

            # move the lower side to the middle
            if height[s] < height[t]:
                s += 1
            else:
                t -= 1
        return maxA

sol = Solution()
print(sol.maxArea([1,2,2,5,9,6,3,566]))
