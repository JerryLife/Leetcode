class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """

        thou = ['', 'M', 'MM', 'MMM']
        hund = ['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM']
        ten = ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC']
        one = ['', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX']
        return thou[num // 1000] + hund[(num % 1000) // 100] + ten[(num % 100) // 10] + one[(num % 10)]


sol = Solution()
print(sol.intToRoman(99))