/**
 * Created by HUSTW on 2017/7/2.
 */


class Solution {
    public double findMedianSortedArrays(int[] oriNums1, int[] oriNums2) {
        int m, n;
        m = oriNums1.length;
        n = oriNums2.length;
        if (m > n) {    // swap two arrays, ensure nums1 is longer
            int[] tmp = oriNums1; oriNums1 = oriNums2; oriNums2 = tmp;
            int t = m; m = n; n = t;
        }
        int i, j;
        int left_max = -1, right_min = -1;
        int m_begin = 1, m_end = m+1;
        int[] nums1 = new int[m+2];
        int[] nums2 = new int[n+2];
        nums1[0] = nums1[0] = Integer.MIN_VALUE;
        nums1[m+1] = nums2[m+1] = Integer.MAX_VALUE;
        for (int k = 0; k < oriNums1.length; k++)
            nums1[k+1] = oriNums1[k];
        for (int k = 0; k < oriNums2.length; k++)
            nums2[k+1] = oriNums2[k];
        while (m_begin <= m_end) {
            i = (m_end + m_begin) / 2;
            j = (m + n + 4) / 2 - i;
            if (nums1[i - 1] > nums2[j]) m_end = i - 1;
            else if (nums2[j - 1] > nums1[i]) m_begin = i + 1;
            else {
                left_max = Integer.max(nums1[i - 1], nums2[j - 1]);
                right_min = Integer.min(nums1[i], nums2[j]);
                break;
            }
        }
        if ((m + n) / 2 * 2 != m + n) return right_min;
        else return (left_max + right_min) / 2.0;
    }
}

// for test
public class Main {
    public static void main(String[] args){
        Solution solution = new Solution();
        int[] a = {4, 5, 9};
        int[] b = {6, 7, 8};
        System.out.println(solution.findMedianSortedArrays(a, b));
    }
}