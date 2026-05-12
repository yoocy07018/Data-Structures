//单链表逆序
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Node
{
    Node(int val=0) : data(val),next(nullptr){}
    int data;
    Node* next;
};
class Clink{
public:
    Clink(){
        head=new Node();
    }
    ~Clink() {
        //节点的释放
        Node*p = head;
        while (p!=nullptr) {
            head=head->next;
            delete p;
            p=head;
        }
        head=nullptr;
    }
public:
    void InsertTail(int val){//尾插法

        Node* p=head;
        while(p->next!=nullptr) {
            p=p->next;
        }
        Node* node = new Node(val);
        p->next=node;

    }
    void Show() {//链表打印
        Node* p = head->next; 
        cout << "当前链表的数据是: ";
        while (p != nullptr) {
            cout << p->data << " -> ";
            p = p->next;              
        }
        cout << "null" << endl; 
    }
private:
    Node* head;
    friend void ReverseLink(Clink &link);
};
void ReverseLink(Clink &link) {//c接口写法，c++写法是把这个函数写到类里面
    Node* head=link.head;//原数组的头节点
    Node* p=head->next;//原数组第一个数
    if(p==nullptr) {//如果一开始就是空的，直接结束
        return;
    }
    head->next=nullptr;//先把head的下一个接口断开
    while (p!=nullptr)
    {
        Node* q=p->next;//数组的第二个数
        //p指针指向的节点进行头插
        p->next=head->next;//第一个数与第二个数断开，第一个数后面变成空
        head->next=p;//头节点的下一个节点变成第一个数
        p=q;//p指针往后继续循环
    }
}
int main() {
    Clink link;
    srand(time(0));
    for(int i=0;i<10;i++) {
        int val = rand()%100;
        link.InsertTail(val);
    }
    link.Show();
    ReverseLink(link);
    link.Show();
}
