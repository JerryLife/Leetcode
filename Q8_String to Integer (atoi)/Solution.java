/*
* Question 8 : String to Integer (atoi)
* Submission date : 2017/4/1
* Passed cases : 1047/1047
* Runtime : 49ms
* Copyright © 2017/4/1 by Jerry_Life
 */
import java.math.BigInteger;

public class Solution {
    public int myAtoi(String str) {
        try {
            String str1 = str.trim();
            String str_rst = null;
            int len = str1.length();
            int i;
            for (i = 0; i < len; i++){
                char c = str1.charAt(i);
                if (!((c >= '0' && c <= '9') || c == '-' || c == '+')){
                    str_rst = str1.substring(0, i);
                    break;
                }
            }
            if (i == len)
                str_rst = str1;
            BigInteger rst = new BigInteger(str_rst);
            if (rst.compareTo(new BigInteger("2147483647")) == 1)
                return 2147483647;
            else if (rst.compareTo(new BigInteger("-2147483648")) == -1)
                return -2147483648;
            else
                return rst.intValue();
        }catch (NumberFormatException e){
            return 0;
        }
    }
}

/*********** Debug Code ********************
import java.math.BigInteger;
import java.util.Scanner;   //Only for debug

public class Solution {
    private static int myAtoi(String str) {
        try {
            String str1 = str.trim();
            String str_rst = null;
            int len = str1.length();
            int i;
            for (i = 0; i < len; i++)
                if (!((str1.charAt(i) >= '0' && str1.charAt(i) <= '9') ||
                        str1.charAt(i) == '-' || str1.charAt(i) == '+')){
                    str_rst = str1.substring(0, i);
                    break;
                }
            if (i == len)
                str_rst = str1;
            BigInteger rst = new BigInteger(str_rst);
            if (rst.compareTo(new BigInteger("2147483647")) == 1)
                return 2147483647;
            else if (rst.compareTo(new BigInteger("-2147483648")) == -1)
                return -2147483648;
            else
                return rst.intValue();
        }catch (NumberFormatException e){
            return 0;
        }
    }

    //Only for debug
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        String str = in.next();
        System.out.println(myAtoi(str));
        return;
    }
}
 ************************************/