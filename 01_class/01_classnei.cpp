//函数模板类内定义
#include <iostream>
using namespace std;
template<class T>
class DynamicArray {
private:
    T* elements;
    int size;
public:
    DynamicArray(int n):size(n) {//构造函数
        elements=new T[n];
    }
    ~DynamicArray() {//析构函数
        delete[] elements;
    }
    T& operator[](int index) {//成员函数
        return elements[index];
    }
    //更新第index个索引的元素，把他的值改成value
    void update(int index,T value) {
        elements[index]=value;
    }
};
int main() {
    DynamicArray<char> dac(100);
    dac[56]='h';
    dac.update(56,'u');
    cout << dac[56] << endl;

    return 0;
}