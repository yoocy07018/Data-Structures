//单链表是否存在环，找到环的入口；
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
bool IsLinkHasCircle(Node *head,int& val) {
    Node* fast=head;
    Node* slow=head;
    while(fast!=nullptr&&fast->next!=nullptr) {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) {//找到相遇点，保留一个指针不动，将另一个指针定义到头节点，然后再次进行循环，两个指针每次都走一步，直至相遇，相遇点即入口点
            //快慢指针再次遇见，链表存在环
            fast=head;
            while(fast!=slow) {
                slow=slow->next;
                fast=fast->next;
            }
            val=slow->data;
            return true;
        }
    }
    return false;
}
int main() {
    Node head;
    Node n1(25),n2(67),n3(32),n4(18);
    head.next=&n1;
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=&n2;
    int val;
    if(IsLinkHasCircle(&head,val)) {
        cout<<"链表存在环，环的入口节点是："<<val<<endl;
    }
}