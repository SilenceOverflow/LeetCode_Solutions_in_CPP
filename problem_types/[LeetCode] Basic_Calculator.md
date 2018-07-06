### Basic Calculator

主要牵涉到的知识有：String/Stack/Recursion

主要题有：
- 224. Basic Calculator [H]
	- " ", "(", ")", "+", "-"
- 227. Basic Calculator II [M]
	- " ", "+", "-", "*", "/"
- 772. Basic Calculator III [H]
	- " ", "(", ")", "+", "-", "*", "/"
- 770. Basic Calculator IV [H]

大致的pipeline：
1. 先处理数字；
2. 在处理括号 -- recursion
3. 最后处理加减乘除操作

Template:

```C++
class Solution {
public:
    int calculate(string s) {
        int res = 0, curRes = 0, num = 0, n = s.size();
        char op = '+';
        
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                num = num * 10 + c - '0';
            }
            else if (c == '(') {
                int j = i, cnt = 0;
                for (; i < n; i++) {
                    if (s[i] == '(') cnt++;
                    if (s[i] == ')') cnt--;
                    if (cnt == 0) break;
                }
                num = calculate(s.substr(j+1, i-j-1));
            }
            if (c == '+' || c == '-' || c == '*' || c == '/' || i == n-1) {
                // update curRes with the last operation stored
                if (op == '+') {curRes += num;}
                if (op == '-') {curRes -= num;}
                if (op == '*') {curRes *= num;}
                if (op == '/') {curRes /= num;}
                if (c == '+' || c == '-' || i == n-1) {
                    res += curRes;
                    curRes = 0;
                }
                op = c;
                num = 0;
            }
        }
        return res;
    }
};

```


Template to get the sub expression in parenthesis:

```C++
if (c == '(') {
    int j = i, cnt = 0;
    for (; i < n; i++) {
        if (s[i] == '(') cnt++;
        if (s[i] == ')') cnt--;
        if (cnt == 0) break;
    }   
num = calculate(s.substr(j+1, i-j-1));
```