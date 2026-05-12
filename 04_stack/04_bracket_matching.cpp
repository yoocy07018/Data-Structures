//括号匹配问题
#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> cs;
        for(char ch:s) {
            if(ch=='('||ch=='['||ch=='{') {//如果是左括号
                cs.push(ch);
            }
            else {
                if(cs.empty()) {
                    return false;
                }
                //遇到右括号
                char cmp=cs.top();
                cs.pop();
                if((ch==')'&&cmp!='(')
                    ||(ch==']'&&cmp!='[')
                    ||(ch=='}'&&cmp!='{')) 
                    {
                        return false;
                    }
            }
        }
        return cs.empty();//可能存在有多余的左括号或者右括号，如果为空返回true，如果不为空返回false
    }
};
int main() {
    Solution sol;
    
    // 测试几个用例
    string test1 = "{[()]}"; // 应该输出 1 (true)
    string test2 = "{[(])}"; // 应该输出 0 (false)
    string test3 = "{}";     // 应该输出 1 (true)

    cout << "测试用例 1: " << sol.isValid(test1) << endl;
    cout << "测试用例 2: " << sol.isValid(test2) << endl;
    cout << "测试用例 3: " << sol.isValid(test3) << endl;

    return 0;
}