//函数模板类外定义
#include <iostream>
using namespace std;
template<class T>
class DynamicArray {
private:
    T* elements;
    int size;
public:
    DynamicArray(int n);//第一步保留声明
    ~DynamicArray();
    T& operator[](int index);
    void update(int index,T value);//更新第index个索引的元素，把他的值改成value
};
//构造函数的类外实现
template<class T>//第五步模板参数列表声明
DynamicArray<T>::DynamicArray(int n):size(n) {//第二步先拷贝声明DynamicArray(int n)：，第三步再加上作用域DynamicArray<T>::，
    elements=new T[n];//第四步再进行拷贝实现size(n)和后面的 elements=new T[n];//第六步指定虚拟类型<T>
}
//析构函数的类外实现
template<class T>
DynamicArray<T>::~DynamicArray() {
    delete[] elements;
}
//成员函数的类外实现
template<class T>
T& DynamicArray<T>:: operator[](int index) {
    return elements[index];
}
//空函数的类外实现
template<class T>
void DynamicArray<T>::update(int index,T value) {
        elements[index]=value;
    }
int main() {
    DynamicArray<char> dac(100);
    dac[56]='h';
    dac.update(56,'u');
    cout << dac[56] << endl;

    return 0;
}