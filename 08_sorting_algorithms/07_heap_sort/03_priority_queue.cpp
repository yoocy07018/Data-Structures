//基于堆的优先级队列代码实现
#include <iostream>
#include <functional>
#include <cstring>
#include <stdlib.h>
#include <time.h>// 必须引入此头文件才能使用 memcpy
using namespace std;
//优先级队列实现  priority_queue
class PriorityQueue {//默认大根堆
public:
    using Comp=function<bool(int,int)>;
    //定义了一个名为 Comp 的类型，这个类型可以接收任何“传入两个整数，返回一个布尔值”的函数或对象。
    PriorityQueue (int cap=20,Comp comp=greater<int>())//greater默认是比较大于
        : size_(0)
        , cap_(cap)
        , comp_(comp)
    {
        que_=new int[cap_];
    }
    PriorityQueue (Comp comp)//greater默认是比较大于
        :size_(0)
        ,cap_(20)//直接默认大小为20，这样可以不用传空间大小的参数
        ,comp_(comp)
    {
        que_=new int[cap_];
    }
    ~PriorityQueue() {
        delete[]que_;
        que_=nullptr;
    }
public:
    //入堆操作
    void push(int val) {
        //判断扩容
        if(size_==cap_) {
            int* p=new int[2*cap_];
            memcpy(p,que_,cap_*sizeof(int));//处理的数字可以直接使用c的内存函数memcpy
            delete[]que_;
            que_=p;
            cap_*=2;
        }
        if(size_==0) {
            //只有一个元素，不用进行堆的上浮调整
            que_[size_]=val;
        }
        else {
            //堆里面有多个元素，需要进行上浮调整
            siftUp(size_,val);//把val放在末尾
        }
        size_++;//多了一个元素，size要加一
    }
    //出堆操作
    void pop() {
        if(size_==0) {
            throw "container is empty!";
        }
        size_--;
        if(size_>0) {
            //删除堆顶元素，还有剩余的元素，要进行堆的下沉操作
            siftDown(0,que_[size_]);//把最后一个元素放到0号位
        }
    }
    //判空
    bool empty() const {return size_==0;}
    //找堆顶元素
    int top() const {
        if(size_==0) {
            throw "container is empty!";
        }
        else {
            return que_[0];
        }
    }
    //求元素个数
    int size() const {return size_;}
private:
    //入堆上浮调整
    void siftUp(int i,int val) {
        while(i>0) {//最多计算到根节点（0号位）
            int father=(i-1)/2;
            if(comp_(val,que_[father])) {
                que_[i]=que_[father];
                i=father;
            }
            else {
                break;
            }
        }
        //把val放到i的位置
        que_[i]=val;
    }
    //出堆下沉调整
    void siftDown(int i,int val) {
        //i下沉不能超过最后一个有孩子的节点
        while(i<size_/2) {//等同于i<=(size_-1-1)/2
            int child=2*i+1;//第i个节点的左孩子
            if(child+1<size_&&comp_(que_[child+1],que_[child])) {
                //如果i节点右孩子的值大于左孩子，child记录右孩子的值
                child=child+1;
            }
            if(comp_(que_[child],val)) {
                que_[i]=que_[child];
                i=child;
            }
            else {
                break;//已经满足堆的性质，提前结束
            }
        }
        que_[i]=val;
    }
private:
    int *que_;//指向动态扩容的数组
    int size_;//数组元素个数
    int cap_;//数组的总空间大小
    Comp comp_;//比较器对象
};
int main(){
    PriorityQueue que;//基于大根堆实现的优先级队列
    srand(time(NULL));
    for(int i=0;i<10;i++) {
        que.push(rand()%100);
    }
    while(!que.empty()) {
       cout<<que.top()<<" ";
       que.pop(); 
    }
    cout<<endl;
}