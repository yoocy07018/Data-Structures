//链式栈
#include <iostream>
using namespace std;
struct Node
    {
        Node(int val=0) : data(val), next(nullptr) {
        }
        int data;
        Node* next;
    };
class LinkStack{
public:
    LinkStack() : head(new Node()), size(0) {}
    ~LinkStack() {
        Node* p=head;
        while(p!=nullptr) {
            head=head->next;

            delete p;
            p=head;
        }
    }
public:
    //入栈 O(1) 在链表头节点后面 ，第一个特效节点的位置，当作栈顶位置
    void push(int val) {
        Node* node=new Node(val);
        node->next=head->next;
        head->next=node;
        size++;
    }
    //出栈 O(1)
    void pop() {
        if (head->next==nullptr) {
            throw "stack is empty!";
        }
            Node* p=head->next;
            head->next=p->next;
            delete p;
            size--;
    }
    //获取栈顶元素
    int top() const {
        if (head->next == nullptr) 
            throw "stack is empty!";
        return head->next->data;
        
    }
    //判空
    bool empty() const {
        return head->next==nullptr;
    }
    //返回栈元素个数 遍历一遍链表，记录节点个数 O(n)   
    //想达到O(1)的操作 可增加一个成员变量 来记录元素个数
    int Size() const {
        return size;
    }
private:
    
    Node* head;
    int size;
};
int main() {
    int arr[]={12,4,56,7,89,31,53,75};
    LinkStack s;
    for(int v : arr) {
        s.push(v);
    }
    cout<<s.Size()<<endl;
    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
}