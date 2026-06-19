/*
第 3 题：双栈拼装自动化队列
ACM 模式题目描述
【输入描述】
输入包含多组测试数据。第一行输入一个正整数 $N$，
表示接下来一共有 $N$ 条操作指令。接下来的 $N$ 行，
每行包含一条指令，指令格式只有以下两种：
1.PUSH x：表示将整数 $x$ 塞入队尾。
2.POP：表示将队头元素弹出，并在屏幕上打印这个被弹出的数字。
（数据保证当收到 POP 指令时，队列里一定有货，无需考虑空队列弹出）。
【输出描述】
对于每条 POP 指令，输出对应弹出的队头元素，独占一行
【样例输入】
5
PUSH 10
PUSH 20
POP
PUSH 30
POP
【样例输出】
10
20
*/

/*
在 C++ 里，cin >> 有一个非常固执的本能：它看到空格、换行符，就会瞬间把数据切断。

这就意味着，当键盘输入 PUSH 10 然后敲回车时：

第一声 cin >> op;：只会把空格前方的 "PUSH" 抓走，留着 10 还在键盘的缓冲区里排队。

此时，你的代码通过 if (op == "PUSH") 成功破案，知道了后面一定排着一个数字。

于是，你在 if 内部紧接着写第二声 cin >> value;：它就会把剩下的 10 稳稳地抓进一个整数变量里！
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
	int t,x;
	string op;
	cin >> t;
	stack<int> stack_in;
	stack<int> stack_out;
	for (int i = 0; i < t; i++) {
		cin >> op;
		if (op == "PUSH") {
			cin >> x;
			stack_in.push(x);
		}
		else if (op == "POP") {
			if (stack_out.empty()) {
				while (!stack_in.empty()) {
					stack_out.push(stack_in.top());
					stack_in.pop();
				}
			}
			int front_val = stack_out.top();
			stack_out.pop();
			cout << front_val << endl;
		}
	}
	return 0;
}