//单链表尾插法
#include <iostream>
using namespace std;
//节点类型
struct Node {
    Node(int data=0) :data_(data), next_(nullptr) {}
    int data_;
    Node* next_;
};
//单链表代码实现
class Clink {
public:
    Clink() {
        //给head_初始化指向头节点
        head_=new Node();
    }
    ~Clink() {
        //节点的释放
    }
public:
    //链表尾插法
    void InsertTail(int val) {
        //先找到当前链表的末尾节点
        Node* p=head_;
        while (p->next_ !=nullptr) {
        //p是局部变量，每一次都会重新变成头节点，所以要用while循环，每一次都要从头开始走，但是之前的节点通过下面三行代码已经连起来了。
            p=p->next_;
        }
        //生成新节点
        Node* node = new Node(val);
        //把新节点挂在尾节点的后面
        p->next_=node;
    }
    // ====== 我为你新增的：打印链表函数 ======
    void Print() {
        // 注意：打印时，我们不需要打印那个没用的虚拟头节点里的 0
        // 所以侦察兵 p 这次直接站在第一节【真实车厢】上！
        Node* p = head_->next_; 

        cout << "当前链表的数据是: ";
        // 只要 p 不是空的（还没走到铁轨尽头的外面），就一直打印
        while (p != nullptr) {
            cout << p->data_ << " -> "; // 打印当前车厢里的数字
            p = p->next_;               // 侦察兵往下一节车厢走
        }
        cout << "null" << endl; // 走到头了，打印个 null 收尾
    }
private:
    Node *head_;//指向链表的头节点
};
// ====== 你需要的 main 函数 ======
int main() {
    // 1. 雇佣一个管家（实例化对象）
    // 这句话一执行，Clink 里的构造函数就会启动，帮你造好那个虚拟头节点(车挡器)
    Clink myList; 

    // 2. 开始给管家下达指令，插入数据
    cout << "开始插入数据: 10, 20, 30..." << endl;
    myList.InsertTail(10);
    myList.InsertTail(20);
    myList.InsertTail(30);

    // 3. 让管家汇报当前的工作成果（打印出来看）
    myList.Print();

    // 4. 再插入一个数据试试
    cout << "\n再插入一个数字 99..." << endl;
    myList.InsertTail(99);
    myList.Print();

    return 0; // 程序完美结束
}
