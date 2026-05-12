//循环链表中的约瑟夫环问题
//n 个人围成一圈，从第 k 个人开始报数，每报到m 就让数到m的那个人出列（从链表中删除该节点）。
//然后从下一个人重新开始报数，直到所有人出列。输出人的出列顺序。
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Node {
    Node(int val = 0) : data(val),next(nullptr) {}
    int data;
    Node* next;
};
//约瑟夫环问题
void Joseph(Node* head,int k,int m) {//指向第一个节点，不带头节点的单向循环链表
    Node* p=head;
    Node* q=head;
    //从第k个人开始报数
    for(int i=1;i<k;i++) {
        q=p;
        p=p->next;
    }
    //p->第k个人
    for(;;) {//等价于while(true)死循环的一种写法
        for(int i=1;i<m;i++) {
            q=p;
            p=p->next;
        }
        //删除p指向的节点
        cout<<p->data<<" ";
        if(p==q) {
            delete p;
            break;
        }
        q->next=p->next;
        delete p;
        p=q->next;
    }
}
int main() {
    Node* head=new Node(1);
    Node* n2=new Node(2);
    Node* n3=new Node(3);
    Node* n4=new Node(4);
    Node* n5=new Node(5);
    Node* n6=new Node(6);
    Node* n7=new Node(7);
    Node* n8=new Node(8);
    head->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;
    n6->next=n7;
    n7->next=n8;
    n8->next=head;
    Joseph(head,1,3);
}