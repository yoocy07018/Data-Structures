//单链表求倒数第K个节点的值，用双指针写
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Node
{
    Node (int val =0) : data(val),next(nullptr){}
    int data;
    Node* next;
};
class Clink {
public:
    Clink() {
        head=new Node();
    }
    ~Clink() {
    }
public:
    void InsertTail(int val) {
        Node* p=head;
        while(p->next!=nullptr) {
            p=p->next;
        }
        Node* node=new Node(val);
        p->next=node;
    }
    void Show() {
        Node* p=head->next;
        if(p==nullptr) {
            return;
        }
        while(p!=nullptr) {
            cout<<p->data<<" ";
            p=p->next;
        }
    }
private:
    Node* head;
    friend void ReverseLink(Clink &link);
    friend bool GetLaskKnode(Clink& link,int k,int& val);
};
void ReverseLink(Clink &link) {
    Node* head=link.head;
    Node* p=head->next;
    if(p==nullptr) {
        return;
    }
    head->next=nullptr;
    while (p!=nullptr)
    {
        Node* q=p->next;
        p->next=head->next;
        head->next=p;
        p=q;
    }
}
bool GetLaskKnode(Clink& link,int k,int& val) {
    Node* head_=link.head;//方便调用链表头节点
    Node* pre=head_;//两个指针都指向头节点
    Node* p=head_;
    if(k<1) {
        return false;
    }
    for(int i=0;i<k;i++) {
        p=p->next;
        if(p==nullptr) {
            return false;
        }
    }
    //pre在头节点，p在正数第k个节点
    while(p!=nullptr) {
        pre=pre->next;
        p=p->next;
    }
    val=pre->data;
    return true;
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
    int k=3;
    int kval;
    if (GetLaskKnode(link,3,kval)) {//判断是不是找到了所求节点
        cout<<"倒数第"<<k<<"个节点的值："<<kval<<endl;
    }
}