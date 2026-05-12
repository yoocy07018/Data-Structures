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
    void InsertHead(int val) {//头插法
        Node* node=new Node(val);
        node->next=head->next;
        head->next=node;
    }
    void Delete(int val) {//删除指定元素
        Node* p=head->next;
        Node* q=head;
        while(p!=nullptr) {
            if(p->data==val) {
                q->next=p->next;
                delete p;
                return;
            }
            q=p;
            p=p->next;
        }
    }
    void RemoveAll(int val) {//删除多个指定元素
        Node* p=head->next;
        Node* q=head;
        while(p!=nullptr) {
            if(p->data==val) {
                q->next=p->next;
                delete p;
                p=q->next;
            }
            else{
                q=p;
                p=p->next;
            }
        }
    }
    bool find(int val) {//寻找元素
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
};
int main() {
    Clink link;
    srand(time(0));
    for(int i=0;i<10;i++) {
        int val=rand()%100;
        link.InsertHead(val);
        cout<<val<<" ";
    }
    cout<<endl;
    link.InsertTail(23);
    link.InsertHead(23);
    link.InsertHead(23);
    link.Show();
    link.RemoveAll(23);
    link.Show();

    return 0;
}