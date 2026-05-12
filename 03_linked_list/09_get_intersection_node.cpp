//判断两个列表是否相交，如果相交，返回相交节点值
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Node {
    Node(int val = 0) : data(val),next(nullptr) {}
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
    void InsertHead(int val) {
        Node* node=new Node(val);
        node->next=head->next;
        head->next=node;
    }
    void DeleteOne(int val) {
        Node* p=head->next;
        Node* q=head;
        while(p!=nullptr) {
            if(p->data==val) {
                q->next=p->next;
                delete p;
                return;
            }
            else {
                q=p;
                p=p->next;
            }
        }
    }
    
    void Show() {
        Node* p=head->next;
        while(p!=nullptr){
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
    
private:
    Node* head;
};
bool IsLinkHasHasMerge(Node* head1,Node* head2,int& val) {
    int cnt1=0,cnt2=0;//计算两个链表的长度
    Node* p=head1->next;
    Node* q=head2->next;
    while(p!=nullptr) {
        cnt1++;
        p=p->next;
    }
    while(q!=nullptr) {
        cnt2++;
        q=q->next;
    }
    p=head1;
    q=head2;
    if(cnt1>cnt2) {
        //第一个链表长，所有p指针要先往前走两个长度差值（使p和q到相交节点的距离相等），才能和q一起循环往前走
        int offset=cnt1-cnt2;
        while(offset-->0) {
            p=p->next;
        }
    }
    else {
        //第二个链表长
        int offset=cnt2-cnt1;
        while(offset-->0) {
            q=q->next;
        }
    }
    while(p!=nullptr&&q!=nullptr) {
        if(p==q) {
            val=p->data;
            return true;
        }
        p=p->next;
        q=q->next;
    }
    return false;
}
int main() {
    Node head1;
    Node n1(25),n2(67),n3(32),n4(18);
    head1.next=&n1;
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    Node head2;
    Node n5(25);
    head2.next=&n5;
    n5.next=&n3;
    int val;
    if(IsLinkHasHasMerge(&head1,&head2,val)) {
        cout<<"链表相交，相交节点是："<<val<<endl;
    }
}