/*
* Question 32 : Longest Valid Parentheses
* Submission date : 2017/4/23
* Passed cases : 229/229
* Runtime : 25ms
* Copyright © 2017/4/23 by Jerry_Life
 */
import java.util.Stack;

public class Solution {
    private static int longestValidParentheses(String s) {
        int len = s.length();
        int start = -1;
        Stack<Integer> lParam = new Stack<>();
        lParam.push(new Integer(-1));
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (s.charAt(i) == '(') {
                lParam.push(i);
            } else {
                if (lParam.peek() == start) {
                    lParam.pop();
                    lParam.push(i);
                    start = i;
                } else {
                    lParam.pop();
                    int tmp = i - lParam.peek();
                    if (tmp > ans)
                        ans = tmp;
                }
            }
        }
        return ans;
    }
}

/* //debug
import java.util.Scanner;
import java.util.Stack;

public class Solution {

    private static int longestValidParentheses(String s) {
        int len = s.length();
        int start = -1;
        Stack<Integer> lParam = new Stack<>();
        lParam.push(new Integer(-1));
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (s.charAt(i) == '(') {
                lParam.push(i);
            } else {
                if (lParam.peek() == start) {
                    lParam.pop();
                    lParam.push(i);
                    start = i;
                } else {
                    lParam.pop();
                    int tmp = i - lParam.peek();
                    if (tmp > ans)
                        ans = tmp;
                }
            }
        }
        return ans;
    }

    //Only for debug
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        String str = in.next();
        System.out.println(longestValidParentheses(str));
        return;
    }
}
*/