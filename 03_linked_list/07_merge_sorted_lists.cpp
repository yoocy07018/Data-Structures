//合并两个有序的单链表
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
    friend void ReverseLink(Clink& clink);
    friend bool GetLaskKnode(Clink& link,int k,int& val);
    friend void MergeLink(Clink& link1,Clink& link2);
};
void ReverseLink(Clink& link) {
    Node* head=link.head;
    Node* p=head->next;
    Node* q=p->next;
    head->next=nullptr;
    if(p==nullptr) {
        return;
    }
    while(p!=nullptr) {
        p->next=head->next;
        head->next=p;
        p=q;
        q=q->next;
    }
}
bool GetLaskKnode(Clink& link,int k,int& val) {
    Node* head=link.head;
    Node* p=head;
    Node* q=head;
    if(k<1) {
        return false;
    }
    for(int i=0;i<k;i++) {
        p=p->next;
        if(p==nullptr) {
            return false;
        }
    }
    while(p!=nullptr) {
        q=q->next;
        p=p->next;
    }
    val=q->data;
    return true;
}
//合并两个链表 把第二个链表按从小到大的顺序排列进第一个列表
void MergeLink(Clink& link1,Clink& link2) {
    Node* p=link1.head->next;
    Node* q=link2.head->next;
    Node* last=link1.head;
    link2.head->next = nullptr;
    while(p!=nullptr&&q!=nullptr) {
        if(p->data<q->data) {
            last->next=p;
            p=p->next;
            last=last->next;
        }
        else {
            last->next=q;
            q=q->next;
            last=last->next;
        }
    }
    if(p!=nullptr) {
        last->next=p;
    }
    else {
        last->next=q;
    }
}
int main() {
    int arr[]={25,37,52,78,88,92,98,108};
    int brr[]={13,23,40,56,62,77,109};
    Clink link1;
    Clink link2;
    for(int v:arr) {
        link1.InsertTail(v);
    }
    for(int v:brr) {
        link2.InsertTail(v);
    }
    link1.Show();
    link2.Show();
    MergeLink(link1,link2);
    link1.Show();
    link2.Show();
}