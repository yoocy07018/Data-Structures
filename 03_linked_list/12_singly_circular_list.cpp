//单向循环链表
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class CircleLink {
public:
    CircleLink() {
        head=new Node();
        tail=head;
        head->next=head;
    }
    ~CircleLink() {
        Node *p=head->next;
        while(p!=head) {
            head->next=p->next;
            delete p;
            p=head->next;
        }
        delete head;  
    }
public:
    //尾插法   O(1)
    void InsertTail(int val) {
        Node *node=new Node(val);
        node->next=tail->next;//node->next=head;
        tail->next=node;
        tail=node;//更新tail指针指向尾节点
    }
    //头插法
    void InsertHead(int val) {
        Node *node=new Node(val);
        node->next=head->next;
        head->next=node;
        if(node->next==head) {
        //如果只有虚指针，那么尾节点是指向head(头节点)，要将他往后移到node
            tail=node;
        }
    }
    //删除节点
    void Remove(int val) {
        Node* q=head;
        Node* p=head->next;
        while(p!=head) {
            if(p->data==val) {
                //找到删除节点
                q->next=p->next;
                
                if(p==tail) {
                    tail=q;
                }
                delete p;
                return;

            }
            else {
                q=p;
                p=p->next;
            }
        }
    }
    //查询
    bool Find(int val) {
        Node* p=head->next;
        while(p!=head) {
            if(p->data==val) {
                return true;
            }
            p=p->next;
        }
        return false;
    }
    void Show() {
        Node* p=head->next;
        while(p!=head) {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
private:
    struct Node {
        Node(int val=0): data(val),next(nullptr) {}
        int data;
        Node* next;
    };
    Node* head;//指向头节点
    Node* tail;//指向末尾节点
};
int main() {
    CircleLink clink;
    srand(time(NULL));
    for(int i=0;i<10;i++) {
        clink.InsertTail(rand()%100);
    }
    clink.InsertTail(200);
    clink.Show();
    clink.Remove(200);
    clink.Show();


}