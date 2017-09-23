#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() < 3)
            return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; i++){
            if (i > 1)
                if (nums[i] == nums[i-1])
                    continue;
            int r = nums.size() - 1;
            int l = i + 1;
            while (l < r){
                if (nums[i] + nums[l] + nums[r] < 0)
                    l++;
                else if (nums[i] + nums[l] + nums[r] > 0)
                    r--;
                else {  // nums[i] + nums[l] + nums[r] == 0
                    vector<int> pair = {nums[i], nums[l], nums[r]};
                    ans.insert(ans.end(), pair);
                    l++;
                    r--;
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};