//两个队列实现一个栈
#include <iostream>
#include <queue>
using namespace std;
class MyStack{
public:
    MyStack() {
        //因为q1和q2是指针所有要开辟新空间
        q1=new queue<int>;
        q2=new queue<int>;
    }
    ~MyStack() {
        delete q1;
        delete q2;
        q1=nullptr;
        q2=nullptr;
    }
    void push(int x) {
        // 1. 把新元素放入当前的“空队列” q1
        q1->push(x); //因为q1和q2是指针，所有要用->
        // 2. 把“主队列” q2 中的所有元素依次倒入 q1
        // 这样新来的 x 就排在了队列的最前面（实现了后进先出）
        while(!q2->empty()) {
            q1->push(q2->front());
            q2->pop();
        }
        // 3. 交换指针：让 q2 重新变回存储数据的“主队列”，q1 变回“空队列”
        queue<int> *p=q1;
        q1=q2;
        q2=p;
    }
    int pop() {//移除并返回栈顶元素
        int val=q2->front();
        q2->pop();
        return val;
    }
    int top() {//返回栈顶元素
        return q2->front();
    }
    bool empty() {//如果栈是空返回true
        return q2->empty();
    }
private:
    queue<int> *q1;//指向空队列
    //定义成指针是为了在进行q1和q2进行交换时减小复杂度，
    //因为定义成指针只会交换头节点的地址即把q1和q2名字交换一下，不然就会进行一个一个的交换
    queue<int> *q2;
};
int main() {
    MyStack st;
    int val;

    cout << "--- 两个队列实现一个栈 ---" << endl;
    cout << "请输入整数入栈（输入 -1 结束输入）：" << endl;

    // 手动键盘输入逻辑
    while (cin >> val && val != -1) {
        st.push(val);
    }

    if (st.empty()) {
        cout << "栈为空，程序退出。" << endl;
        return 0;
    }

    cout << "\n当前栈顶元素 (top): " << st.top() << endl;

    cout << "\n--- 开始自动出栈 (LIFO 顺序) ---" << endl;
    while (!st.empty()) {
        cout << "出栈: " << st.pop() << endl;
    }

    return 0;
}