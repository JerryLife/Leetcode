//
// Created by HUSTW on 2017/9/22.
//

#include <algorithm>
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int min_dist = INT32_MAX;
        for (int i = 0; i < nums.size()-2; i++){
            int l = i+1;
            int r = nums.size()-1;
            while (l < r){
                int dist = nums[i] + nums[l] + nums[r] - target;
                if (abs(dist) < abs(min_dist))
                    min_dist = dist;
                if (dist < 0)
                    l++;
                else if (dist > 0)
                    r--;
                else    // dist == 0
                    return target;
            }
        }
        return target + min_dist;
    }
};


int main(){
    Solution sol;
    vector<int> vs = {-4, -1, 2, 1};
    int ans = sol.threeSumClosest(vs, 1);
    cout << ans << endl;
    return 0;
}