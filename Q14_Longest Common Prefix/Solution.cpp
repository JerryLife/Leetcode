class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp;
        if (strs.empty())
            return lcp;
        try {
            for (int i = 0; ; i++){
                char mark = strs[0][i];
                for (string str: strs){
                    if (mark != str[i])
                        return lcp;
                }
                lcp.string::append(1, mark);
            }
        } catch (exception err){
            return lcp;
        }
    }
};