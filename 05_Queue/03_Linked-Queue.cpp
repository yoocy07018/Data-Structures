//链式列队代码实现
#include <iostream>
using namespace std;
class LinkQueue {
public:
    LinkQueue() {
        head=new Node();
        head->next=head;
        head->pre=head;
    }
    ~LinkQueue() {
        Node* p=head->next;
        while(p!=head) {
            head->next=p->next;
            p->next->pre=head;
            delete p;
            p=head->next;
        }
        delete head;
        head=nullptr;
    }
public:
    //入队
    void push(int val) {
        Node* node=new Node(val);
        node->next=head;
        node->pre=head->pre;
        head->pre->next=node;
        head->pre=node;
    }
    //出队
    void pop() {
        Node* p=head->next;
        head->next=p->next;
        p->next->pre=head;
        delete p;
    }
    //获取头元素
    int front() const {
        if(head->next==head) {
            throw"queue is empty!";
        }
        return head->next->data;
    }
    //获取尾元素
    int back() const {
        if(head->next==head) {
            throw"queue is empty!";
        }
        return head->pre->data;
    }
    //判空
    bool empty() const {
        return head->next==head;
    }
    struct Node
    {
        Node(int val=0) : data(val),next(nullptr),pre(nullptr) {}
        int data;
        Node* next;
        Node* pre;
    };
    
    Node* head;
};
int main() {
    int arr[]={12,4,56,7,89,31,53,75};
    LinkQueue que;
    for(int v : arr) {
        que.push(v);
    }
    cout<<que.front()<<endl;
    cout<<que.back()<<endl;
    que.push(100);
    que.push(200);
    que.push(300);
    cout<<que.front()<<endl;
    cout<<que.back()<<endl;
    while(!que.empty()) {
        cout<<que.front()<<" "<<que.back()<<endl;
        que.pop();
    }
    return 0;
}

