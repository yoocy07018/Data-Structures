//单链表头插法
#include <iostream>
using namespace std;
struct Node {
    Node(int val=0) :data(val),next(nullptr) {}
    int data;
    Node* next;
};
class clink {
public:
    clink(){
        head=new Node();
    }
    ~clink() {
    }
public:
    void InsertHead(int val) {
        Node* node=new Node(val);
        node->next=head->next;
        head->next=node;
    }
private:
    Node* head;
};
