/**
 * Created by HUSTW on 2017/7/2.
 */
import com.sun.org.apache.bcel.internal.generic.INEG;
import jdk.internal.org.objectweb.asm.tree.InnerClassNode;

import java.lang.Math;

class Solution {
    public int divide(int dividend, int divisor) {
        if (dividend == -2147483648 && divisor == -1) return Integer.MAX_VALUE;
        if (dividend == -2147483648 && divisor == 1) return -2147483648;
        boolean sym = (dividend >= 0) ^ (divisor >= 0);
        long lDividend = Math.abs((long)dividend);
        long lDivisor = Math.abs((long)divisor);
        long tmp, rst;
        int ans = 0;
        while (lDividend > 0) {
            tmp = lDivisor;
            rst = 1;
            while (lDividend >= tmp) {
                tmp <<= 1;
                rst <<= 1;
            }
            tmp >>= 1;
            rst >>= 1;
            ans += rst;
            lDividend -= tmp;
        }
        if (sym) return -ans;
        else return ans;
    }
}


public class Main {
    public static void main(String[] args){
        Solution solution = new Solution();
        System.out.println(solution.divide(-2147483648, 2));
        System.out.println(solution.divide(14442, 2));
    }
}