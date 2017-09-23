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
    vector<string> letterCombinations(string digits) {
        int flag = 0;
        vector<string> ans;
        vector<string> map_table = {
                "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        if (digits.empty())
            ans = {};
        else if (digits[0] == '0' || digits[1] == '1')
            flag = 1;
        else if (digits.size() == 1){
            for (auto c: map_table[digits[0] - '2'])
                ans.emplace_back(string{c});
        }
        else {
            int index = digits[0] - '2';
            ans = letterCombinations(digits.substr(1, digits.size()-1));
            vector<string> result;
            for (auto c: map_table[index]){
                vector<string> tmp = ans;
                for (string &s: tmp) {
                    s.insert(0, string{c});
                }
                result.insert(result.end(), tmp.begin(), tmp.end());
            }
            ans = result;
        }

        if (flag)
            return {};
        else
            return ans;
    }
};


int main(){
    Solution sol;
    vector<string> ans;
    ans = sol.letterCombinations("94");
    for (auto str: ans)
        cout << str << endl;
    return 0;
}