class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;

        for (int i = 0; i < tokens.size(); i++) {
            int sign = 1, operand = 0;
            char c = tokens[i][0];
            if (c == '+') {
                int y = stack.back();
                stack.pop_back();
                int x = stack.back();
                stack.pop_back();
                stack.push_back(x + y);  
            } else if (c == '*') {
                int y = stack.back();
                stack.pop_back();
                int x = stack.back();
                stack.pop_back();
                stack.push_back(x * y);
            } else if (c == '/') {
                int y = stack.back();
                stack.pop_back();
                int x = stack.back();
                stack.pop_back();
                stack.push_back(x / y);
            } else if (c == '-' && tokens[i].size() == 1) {
                int y = stack.back();
                stack.pop_back();
                int x = stack.back();
                stack.pop_back();
                stack.push_back(x - y);
            } else {
                for (char p : tokens[i]) {
                    if (p == '-') sign = -1;    
                    else operand = operand * 10 + int(p - '0');
                }
                stack.push_back(operand * sign);
            }
        }

        return stack.back();
    }
};