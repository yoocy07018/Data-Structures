//双向链表核心讲解
#include <iostream>
using namespace std;
struct Node
{
    Node(int val=0) 
    : data(val)
    ,next(nullptr)
    ,pre(nullptr)
    {}
    int data;//数据域
    Node* next;//指向下一个节点
    Node* pre;//指向前一个节点
};
//双向链表
class DoubleLink {
public:
    DoubleLink() {
        head=new Node();
    }
    ~DoubleLink() {
        Node* p=head;
        while(p!=nullptr) {
            head=head->next;
            delete p;
            p=head;
        }
    }
public:
    //头插法
    void InsertHead (int val) {
        Node* node=new Node(val);
        node->next=head->next;
        node->pre=head;
        if(head->next!=nullptr) {
            head->next->pre=node;
        }
        head->next=node;
    }
    //尾插法
    void InsertTail (int val) {
        Node* p=head;
        while(p->next!=nullptr) {
            p=p->next;
        }
        //p指针指向末尾节点
        Node* node=new Node(val);
        node->pre=p;
        p->next=node;
    }
    //节点删除
    void Remove(int val) {
        Node* p=head->next;
        while(p!=nullptr) {
            if(p->data==val){
                //删除p指向的节点
                p->pre->next=p->next;
                if(p->next!=nullptr) {
                    p->next->pre=p->pre;
                }
                delete p;
                return;
            }
            else {
                p=p->next;
            }  
        }
    }
    //删除多个节点
    void Removes(int val) {
        Node* p=head->next;
        while(p!=nullptr) {
            if(p->data==val){
                //删除p指向的节点
                p->pre->next=p->next;
                if(p->next!=nullptr) {
                    p->next->pre=p->pre;
                }
                Node* next_=p->next;
                delete p;
                p=next_;
            }
            else {
                p=p->next;
            }  
        }
    }
    //节点搜索
    bool Find(int val) {
        Node* p=head->next;
        while(p!=nullptr) {
            if(p->data==val) {
                return true;
            }
            else {
                p=p->next;
            }
        }
        return false;
    }
    //链表节点输出
    void Show() {
        Node *p=head->next;
        while(p!=nullptr) {
            cout << p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
private:
    Node* head;//指向头节点 
};
int main() {
    DoubleLink dlink;
    dlink.InsertTail(20);
    dlink.InsertTail(90);
    dlink.InsertTail(78);
    dlink.InsertTail(32);
    dlink.InsertTail(7);
    dlink.InsertTail(90);
    dlink.Show();
    dlink.InsertHead(200);
    dlink.Show();
    dlink.Remove(200);
    dlink.Show();
    dlink.Removes(90);
    dlink.Show();
}


