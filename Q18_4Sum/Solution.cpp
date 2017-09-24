//
// Created by HUSTW on 2017/9/23.
//

#include <algorithm>
#include "iostream"
#include "vector"
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4)
            return {};
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-3; i++){
            for (int j = i+1; j < nums.size()-2; j++){
                int l = j + 1;
                int r = nums.size()-1;
                while (l < r){
                    int dist = nums[i] + nums[j] + nums[l] + nums[r] - target;
                    if (dist == 0){
                        vector<int> tmp = {nums[i], nums[j], nums[l], nums[r]};
                        ans.insert(ans.end(), tmp);
                        l++;
                        r--;
                    }
                    else if (dist > 0)
                        r--;
                    else // (dist < 0)
                        l++;
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};


int main(){
    Solution sol;
    vector<vector<int>> ans;
    vector<int> nums = {1,0,-1,0,-2,2};
    ans = sol.fourSum(nums, 0);
    for (auto i: ans){
        for (auto j: i)
            cout << j << ' ';
        cout << endl;
    }
    return 0;
}