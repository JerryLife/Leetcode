class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """

        length = len(s)
        L = [[0] * length for i in range(length)]
        s_rev = s[::-1]
        ans_len = 0
        ans = []
        for i in range(length):
            for j in range(length):
                if s[i] == s_rev[j]:
                    if i == 0 or j == 0:
                        L[i][j] = 1
                    else:
                        L[i][j] = L[i-1][j-1] + 1

                    # check if the string is available
                    if L[i][j] > ans_len and i+j-L[i][j]+2 == length:
                        ans_len = L[i][j]
                        ans = s[i-ans_len+1: i+1]

        return ans
