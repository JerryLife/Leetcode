class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """

        if not p and not s:
            return True
        elif p:
            # check length
            if len(p) <= 1:
                if len(s) == len(p) == 1 and (s[0] == p[0] or p[0] == '.'):
                    return True
                else:
                    return False
            if p[1] == '*':
                if not s:
                    return self.isMatch(s[:], p[2:])
                if p[0] == '.' or p[0] == s[0]:
                    return self.isMatch(s[:], p[2:]) or self.isMatch(s[1:], p[:])
                else:
                    return self.isMatch(s[:], p[2:])
            else:
                if len(s) == 0:
                    return False
                if p[0] == '.' or p[0] == s[0]:
                    return self.isMatch(s[1:], p[1:])
                else:
                    return False
        else:
            return False


sol = Solution()
print(sol.isMatch("aaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*a*c"))