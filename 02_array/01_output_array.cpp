//数组代码输出
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
//数组实现
class Array {
public:
    Array(int size = 10): mCur(0), mCap(size) {//默认参数 (size = 10)：如果你创建对象时不指定大小（如 Array arr;），它默认分配 10 个单位的内存。
        mpArr = new int[mCap]();
        //()：这个小括号非常关键，它会对申请到的内存进行值初始化（对于 int 来说，就是全部初始化为 0）。如果不加这个括号，内存里的值将是随机的垃圾值。
    }
    ~Array() {
        delete[] mpArr;
        mpArr = nullptr;//置空指针  显式置空可以防止在析构逻辑还没跑完时误触脏指针。
    }
public:
    //末尾增加元素
    void push_back(int val) {
        if (mCur == mCap) {
            expand(2*mCap);//扩容
        }
        mpArr[mCur++]=val;
    }
    //末尾删除元素
    void pop_back() {
        if (mCur == 0) {
            return;//返回类型是 void（空） return： 相当于“提前结束”
        }
        mCur--;
    }
    //按位置增加元素
    void insert(int pos,int val) {
        if(pos < 0 || pos > mCur) {
            return;
        }
        if(mCur == mCap) {
            expand(2 * mCap);
        }
        //移动元素
        for(int i = mCur-1; i >= pos; i--) {
            mpArr[i+1] = mpArr[i];
        }
        mpArr[pos] = val;
        mCur++;
    }
    //按位置删除
    void erase(int pos) {
        if(pos < 0 || pos >= mCur) {
            return;
        }
        for(int i = pos+1;i < mCur; i++) {
            mpArr[i-1] = mpArr[i];
        }
        mCur--;
    }
    //元素查询
    int find(int val) {
        for(int i = 0;i < mCur; i++) {
            if(mpArr[i] == val) {
                return i;
            }
        }
        return -1;
    }
    //打印数据
    void show()const {
        for(int i = 0; i < mCur; i++) {
            cout << mpArr[i] << " ";
        }
        cout << endl;
    }
private:
    //内部数组扩容接口
    void expand(int size) {
        int* p = new int[size];
        memcpy(p,mpArr,sizeof(int) * mCap);
        //动作：把旧地皮（mpArr）上的所有数据，原封不动地复制到新地皮（p）上。
        //关键点：sizeof(int) * mCap 计算的是旧数据一共占了多少字节。
        delete[]mpArr;//动作：把旧的地皮还给系统。
        mpArr = p;
        mCap = size;
    }
private:
    int* mpArr;//指向可扩容的大小可变的数组内存
    int mCap;//数组的容量
    int mCur;//数组有效元素个数
};
int main() {
    Array arr;
    srand(time(0));//设置随机数种子，不会输入数据，
    for(int i = 0; i < 10; i++) {
        arr.push_back(rand() % 100);
        //rand() % 100 — 生成 0-99 的随机数
        //rand()：生成一个很大的随机整数。
        //% 100：取余数运算。任何数除以 100，余数一定在 0 到 99 之间。
        //目的：让生成的数字好看一点、小一点，方便打印输出查看。
    }
    arr.show();
    arr.pop_back();
    arr.show();

    arr.insert(0,100);
    arr.show();

    arr.insert(10,200);
    arr.show();

    int pos=arr.find(100);
    if(pos !=-1) {
        arr.erase(pos);
        arr.show();
    }
}
