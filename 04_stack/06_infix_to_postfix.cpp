/*逆波兰表达式中缀转后缀表达式理论讲解
1. 遇到数字，直接输出
2. 遇到符号 ： 
a.栈为空，符号直接入栈
b.如果是（，直接入栈
c.用当前符号和栈顶符号比较其优先级
   当前符号>栈顶符号，当前符号直接入栈，结束，
   当前符号<=栈顶符号 栈顶符号出栈并输出，继续比较
        继续比较会遇到两个异常问题
        a.把栈里面的符号出完了
        b.遇到）要一直出栈，直到遇到（为止
*/

//逆波兰表达式中缀转后缀表达式代码输出
#include <iostream>
#include <stack>
#include <string>
using namespace std;
//比较符号优先级
bool Priority (char ch,char topch) {
    if((ch=='*'||ch=='/') && (topch=='+'||topch=='-')) {
        return true;
    }
    if(topch=='(' && ch!=')') {
        return true;
    }
    return false;
}
string MiddleToEndExpr(string expr) {
    string result;//用来存储中缀转后缀之后的字符
    stack<char> s;//用来存运算符
    for(char ch:expr) {
        if(ch>='0'&&ch<='9') { 
            result.push_back(ch);

        }
        else{
            for(;;) {//当topch先级大时，topch出栈，并且此时的ch要和下一个新的topch进行比较，所以要写一个循环
                //处理符号
                if(s.empty()||ch=='(') {
                    s.push(ch);
                    break;
                }
                //比较当前符号ch和栈顶元素top的优先级
                char topch=s.top();//stack<char> s的栈顶元素
                //Priority: true ch>topch(ch优先级较高)   false  ch<=topch
                if(Priority(ch,topch)) {
                    s.push(ch);
                    break;//优先级如果是ch大，那么不需要循环比较，因为ch要入栈
                }
                else {
                    s.pop();
                    if(topch=='(') {//如果遇到），与支出占，直到遇到（；
                        break;
                    }
                    result.push_back(topch);
                }
            }
        }
    }
    //如果符号栈里面还残留符号，直接输出到后缀表达式里面
    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }
    return result;
}
int main() {
    cout<<MiddleToEndExpr("(1+2)*(3+4)")<<endl;
    cout<<MiddleToEndExpr("2+(4+6)/2+6/3")<<endl;
    return 0;
}