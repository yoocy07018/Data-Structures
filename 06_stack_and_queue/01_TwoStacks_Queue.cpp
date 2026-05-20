//两个栈实现一个队列
#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
public:
    MyQueue() {

    }
    void push(int x) {
        s1.push(x);
    }
    int pop() {//出栈（找到对头元素并出栈）
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val=s2.top();
        s2.pop();
        return val;
    }
    int peek(){//查看对头元素
       if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top(); 
    }
    /** 判空：只有当两个栈都为空时，队列才算空 */
    bool empty() {
        return s1.empty() && s2.empty();
    }
private:
    stack<int> s1;//不需要初始化
    stack<int> s2;//不需要初始化
};
/*
int main() {
    int arr[] = {12, 4, 56, 7, 89};
    MyQueue que;

    cout << "--- 开始入队 ---" << endl;
    for (int v : arr) {
        cout << "Push: " << v << endl;
        que.push(v);
    }

    cout << "\n--- 测试出队和查看 ---" << endl;
    // 预期队头是 12
    cout << "当前队头 (peek): " << que.peek() << endl; 
    
    // 预期出队顺序: 12, 4
    cout << "出队 (pop): " << que.pop() << endl;
    cout << "出队 (pop): " << que.pop() << endl;

    cout << "现在的队头: " << que.peek() << endl; // 预期是 56

    cout << "\n--- 清空队列 ---" << endl;
    while (!que.empty()) {
        cout << "Pop: " << que.pop() << endl;
    }

    return 0;
}
*/
int main() {
    MyQueue que;
    int n;
    cout << "请输入要入队的元素个数: ";
    cin >> n;

    cout << "请依次输入 " << n << " 个整数：" << endl;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;      // 从键盘读取
        que.push(val);   // 存入队列
    }
    cout << "\n--- 手动输入完成，开始出队测试 ---" << endl;
    while (!que.empty()) {
        cout << "出队: " << que.pop() << endl;
    }

    return 0;
}