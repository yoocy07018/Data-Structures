//逆波兰表达式求解

/*
逆波兰表达式（Reverse Polish Notation，简称 RPN），也叫后缀表达式。
它最大的优点就是完全不需要括号，计算机利用一个简单的栈就能毫无歧义地算出结果。
1.遇到数字直接入栈
2.遇到符号，出栈两个
3.运算两个数字，把结果入栈
*/
#include <iostream>
#include <stack>
#include <vector>
/*
vector 就是普通数组的“终极进化版”：
自动扩容： 你不需要指定大小。一直往里塞数据，
它如果满了，会在底层自动申请更大的空间，把数据搬过
*/
#include <string>
#include <sstream> //可以把string line = "2 1 + 3 *";变成"2" "1" "+" "3"
/*遇到空格会自动切断并且停下来，所以可以用>>来拿数据
string line = "2 1 + 3 *"; // 这是那根没切的香肠
stringstream ss(line);     // 创造一台机器叫 ss，把香肠塞进去
string token;
ss >> token; // 机器启动，切下一块，装进 token 里。此时 token 变成了 "2"
ss >> token; // 再启动一次，token 变成了 "1"
ss >> token; // 再启动一次，token 变成了 "+"
结合 while 循环的全自动化提取
while (ss >> token) {
    tokens.push_back(token); // 切出来一块，就丢进你的 tokens 数组里
}
*/
using namespace std;
class  Solution  
{
public:
    int calc(int left,int right,char sign) {
        switch(sign) {
            case '+':
            return left+right;
            case '-':
            return left-right;
            case '*':
            return left*right;
            case '/':
            return left/right;
        }
        throw "";
    }
    int evalRPN(vector<string>& tokens) {
        //vector<string>（食材容器）： vector 是 C++ 里的动态数组（就像一个能自动变长变短的盒子）。
        //<string> 表示这个盒子里装的全是字符串。
        stack<int> intStack;
        for(string &str: tokens) {//每次传入一个字符串，如13 size！=1并且str[0]='1',不是字符串进入else分支
            //如果是-11，size!=1, str[0]='-',
            if(str.size()==1&&//str.size()==1,为了防止遇到负数，str[0]被认为是'-'
            (str[0]=='+'||str[0]=='-'
            ||str[0]=='*'||str[0]=='/')) 
            {
                //遇到运算符了，开始运算
                int right =intStack.top();
                intStack.pop();
                int left=intStack.top();
                intStack.pop();
                intStack.push(calc(left,right,str[0]));//str[0]为+-*/中的一个
                /*
                第一步：提取出数学符号
                char sign = str[0];                  
                第二步：把左操作数、右操作数和符号扔进 calc 函数，算出结果
                int result = calc(left, right, sign); 
                第三步：把计算出来的新结果压回栈里
                intStack.push(result);
                */
            }
            else {
                //遇到数字,直接入数字栈
                //string=>int  用stoi stol
                //int => string to_string()(括号里面可以放int double bool char 都可以)
                intStack.push(stoi(str));
            }
        }
        return intStack.top();
    }

};
/*{//写法一  ：自己定义好的写法
int main() 
    Solution sol;

    // 测试用例 1: (2 + 1) * 3 = 9
    // 逆波兰表示: 2 1 + 3 *
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    cout << "测试用例 1 结果: " << sol.evalRPN(tokens1) << " (预期: 9)" << endl;

    // 测试用例 2: 4 + (13 / 5) = 6
    // 逆波兰表示: 4 13 5 / +
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    cout << "测试用例 2 结果: " << sol.evalRPN(tokens2) << " (预期: 6)" << endl;

    // 测试用例 3: ((10 * (6 / ((9 - 3) * -11))) + 17) + 5 = 22
    // 逆波兰表示: 10 6 9 3 - -11 * / * 17 + 5 +
    vector<string> tokens3 = {"10", "6", "9", "3", "-", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << "测试用例 3 结果: " << sol.evalRPN(tokens3) << " (预期: 22)" << endl;

    return 0;
}

*/
int main() {
    //写法二  ：键盘输入字符  要先引入头文件  #include <sstream> 
    Solution sol;
    
    cout << "欢迎使用逆波兰计算器！" << endl;
    cout << "请输入逆波兰表达式 (用空格分隔每个数字和符号，例如: 2 1 + 3 *):" << endl;
    
    string line;
    // 1. 获取用户输入的整行内容
    if (getline(cin, line)) {
        /*
        出场武器 getline： 这是一个超级大网。
        getline(cin, line) 的意思是：“从控制台（cin）把用户敲击键盘的所有内容，不管有没有空格，统统用网捞起来，直到用户按下回车键为止。
        然后把捞上来的这一长串东西，全部塞进 line 这个字符串里。”
        那个 if 是干嘛的？ 这是为了安全。意思是：“如果成功捞到了用户输入的数据，我们再进到括号里开始处理。”
        */
        vector<string> tokens;// 准备一个大号保鲜盒，用来装最终切好的小肉块
        string token;           // 准备一个小碟子，用来临时接切下来的一块肉
        
        // 2. 把这一整行字符串，扔进“字符串流”这台碎肉机里
        stringstream ss(line);
        /*
        stringstream 其实非常“懒”。
        当你把 line 塞给它时，它根本不去提前切分，而是原样照抄，
        存成了一排连续的字符内存，并在最前面放了一个“读取指针”。
        在内存里，ss 的真实样子是这样的（每个字符挨在一起）：
        [指针] -> '1' '2' '3' ' ' '4' '5' ' ' '+'
        */
        
        // 3. 碎肉机按空格自动切分，把切出来的每一块丢进 tokens 数组
        //真正执行“切分”动作的是 >>（提取运算符）这个符号
        //执行一次while循环 此时，ss 内部的模样变成了：
        //'3' ' ' [指针] -> '4' '5' ' ' '+'
        while (ss >> token) {
            tokens.push_back(token);
        }
        /*
        总结：
        ss（机器） 只是一个老老实实保存完整原话、并帮你记住“读到哪里了（指针）”的容器。
        >>（刀） 才是真正具备“遇到空格就切分”魔法的工具。
        */
        // 4. 调用你写的算法进行计算
        int result = sol.evalRPN(tokens);
        cout << "计算结果: " << result << endl;
    }

    return 0;
}
