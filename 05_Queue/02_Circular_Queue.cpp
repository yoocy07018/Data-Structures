//环形队列代码讲解
/*
判空： front == rear（头尾指向同一个位置）。

判满： (rear + 1) % cap == front。

注意： 这里的逻辑会空出一个位置不存数据。
这是为了区分“空”和“满”，否则当头尾相遇时，你无法判断是存满了还是一个没存。
*/
#include <iostream>
using namespace std;
class Queue {
public:
    Queue(int size=10)
        : cap(size)
        , front(0)
        , rear(0)
        , size(0)
    {
        pQue=new int[cap];//创建一个数组
    }
    ~Queue() {
        delete[]pQue;
        pQue=nullptr;
    }
public:
    //入队
    void push(int val) {
        if((rear+1)%cap==front) {
            expand(2*cap);
        }
        pQue[rear]=val;
        rear=(rear+1)%cap;
        //size++;
    }
    //出队
    void pop() {
        if(front==rear) {//数组为空
            throw "queue is empty!";
        }
        front =(front+1)%cap;
        //逻辑重点：出队并不需要真正删除数组里的值，只需要让 front 往后走一步，
        //原来位置的数据就被逻辑上视为“无效”了，因为front前面的位置会默认为空位置，
        //下次 rear 绕回来时会直接覆盖它。
        //size--;
    }
    //对头元素
    int getfront() const {
        if(front==rear) {//数组为空
            throw "queue is empty!";
        }
        return pQue[front];
    }
    //队尾元素
    int getback() const{
        if(front==rear) {//数组为空
            throw "queue is empty!";
        }
        return pQue[(rear-1+cap)%cap];
    }
    //对空
    bool empty() const {
        return front==rear;
    }
    //队列元素的个数
    int getsize() {
        //return size;   O(1)
        //遍历一遍统计队列元素个数  O(n)
        for(int i=front;i!=rear;i=(i+1)%cap) {
            size++;
        }
        return size;
    }
private:
    //扩容接口
    void expand(int size) {
        int* p=new int[size];
        int i=0;// i 是新数组 p 的下标，从 0 开始
        int j=front;// j 是旧数组 pQue 的下标，从当前的队头开始
        for(; j!=rear; i++,j=(j+1)%cap) {
            //旧数组中的数据可能分布在 数组下标：[0] [1] [2] [3] [4]
            //                      数据分布：D3, D4, (空), D1, D2
            //这样的回绕顺序
            //搬移后，在新数组 p 中，它们会被按顺序存放成D1, D2, D3, D4, (空)
            p[i] = pQue[j];
        }
        delete[]pQue;
        pQue=p;
        cap=size;
        front=0;
        rear=i;//i是先赋值在进行加一操作
    }

private:
    int* pQue;//用来指向堆上的内存
    int cap;//表示空间容量
    int front;//对头
    int rear;//队尾，rear为末尾元素的后一位，每次给rear放一个元素时，rear都要往后走一步
    int size;//列队元素个数
};
int main() {
    int arr[]={12,4,56,7,89,31,53,75};
    Queue que;
    for(int v : arr) {
        que.push(v);
    }
    cout<<que.getfront()<<endl;
    cout<<que.getback()<<endl;
    que.push(100);
    que.push(200);
    que.push(300);
    cout<<que.getfront()<<endl;
    cout<<que.getback()<<endl;
    while(!que.empty()) {
        cout<<que.getfront()<<" "<<que.getback()<<endl;
        que.pop();
    }
    return 0;
}
