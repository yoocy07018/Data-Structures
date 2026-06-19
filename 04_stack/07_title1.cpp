/*
 第 2 题：多重括号的错位拦截
 1. ACM 模式题目描述【输入描述】输入包含多组测试数据。
 第一行输入一个正整数 $T$，表示有 $T$ 组括号序列需要检验。
 接下来的 $T$ 行，每行输入一个只包含 (、)、[、]、{、} 的字符串
 （长度不超过 1000）。【输出描述】对于每组测试数据，
 如果该括号序列合法，输出 Yes；否则输出 No。每组输出独占一行。

 【样例输入】
 Plaintext3
{[()]}
([)]
(([]

【样例输出】
Plaintext
Yes
No
No
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
	int t;
	string s;
	cin >> t;
	vector<string> str;
	for (int i = 0; i < t; i++) {
		cin >> s;
		str.push_back(s);
	}
	for (int i = 0; i < t; i++) {
		int a = str[i].length();
		stack<char> st;
		bool is_valid = true;
		for (int j = 0; j < a; j++) {
			if (str[i][j] == '{' || str[i][j] == '(' || str[i][j] == '[') {
				st.push(str[i][j]);
			}
			else {
				if (!st.empty()) {
					char b = st.top();
					if ((str[i][j] == '}' && b == '{') || (str[i][j] == ')' && b == '(') || (str[i][j] == ']' && b == '[')) {
						st.pop();
					}
					else {
						is_valid = false;
						break;
					}
				}
				else {
					is_valid = false;
					break;
				}
			}
		}
		if (is_valid == false) {
			cout << "NO" << endl;
		}
		else {
			if (st.empty()) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl; 
			}
		}
	}
	return 0;
}