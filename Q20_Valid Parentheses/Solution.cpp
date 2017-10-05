class Solution {
public:
    bool isValid(string s) {
        stack<char> token;
        for (char c: s){
            switch (c){
                case '(':
                case '[':
                case '{':   token.push(c); break;
                case ')':
                    if (!token.empty() && token.top() == '(')
                        token.pop();
                    else return false;
                    break;
                case ']':
                    if (!token.empty() && token.top() == '[')
                        token.pop();
                    else return false;
                    break;
                case '}':
                    if (!token.empty() && token.top() == '{')
                        token.pop();
                    else return false;
                    break;
            }
        }
        return token.empty();
    }
};