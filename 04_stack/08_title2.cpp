/*
第 1 题：逆序输出的终极审判
1. ACM 模式题目描述【输入描述】输入包含多组测试数据。
第一行输入一个正整数 $T$，表示有 $T$ 组测试数据。接下来的 $T$ 行，
每行输入一个不含空格的字符串（长度不超过 100）。【
输出描述】
对于每组测试数据，输出该字符串逆序（反转）后的结果，每组输出独占一行。
【样例输入】
2
abcde
hello
【样例输出】
edcba
olleh
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    int t;
    string a;
    stack<char> ch;
    cin >> t;
    vector<string> pool;
    for (int i = 0; i < t; i++) {
        cin >> a;
        pool.push_back(a);
    }
    for (int i = 0; i < t; i++) {
        string b = pool.at(i);
        int c = b.length();
        for (int j = 0; j < c; j++) {
            ch.push(b[j]);
        }
        while (!ch.empty()) {
            char d = ch.top();
            ch.pop();
            cout << d;
        }
        cout << endl;
    }
    return 0;
}