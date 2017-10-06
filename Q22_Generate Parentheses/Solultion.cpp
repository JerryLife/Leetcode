#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        addParen(ans ,"", n, n);
        return ans;
    }

private:
    void addParen(vector<string> &oriVec, const string &str, int l, int r){
        // reach the leaf
        if (r == 0)
            oriVec.push_back(str);
        if (l > 0)
            addParen(oriVec, str+"(", l-1, r);
        if (l < r)
            addParen(oriVec, str+")", l, r-1);
    }
};

int main(){
    Solution sol;
    vector<string> ans;
    ans = sol.generateParenthesis(3);
    return 0;
}