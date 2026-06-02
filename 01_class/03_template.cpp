//类模板基础
#include <iostream>
using namespace std;
// 1. 定义一个类模板
template <typename T>
class MyArray {
private:
    T* data;         // 动态数组的头指针，类型是 T*
    int size;        // 当前存了多少个元素
    int capacity;    // 数组的最大容量

public:
    // 构造函数：接收一个容量参数
    MyArray(int cap) {
        capacity = cap;
        size = 0;
        data = new T[capacity]; // 根据类型 T，动态开辟对应大小的内存
        std::cout << "【构造函数】成功创建了一个容量为 " << capacity << " 的动态数组！" << std::endl;
    }

    // 析构函数：释放内存
    ~MyArray() {
        delete[] data;          // 释放动态内存
        std::cout << "【析构函数】动态数组内存已释放。" << std::endl;
    }

    // 尾插法添加元素
    void push_back(const T& val) {
        if (size >= capacity) {
            std::cout << "数组已满，无法插入！" << std::endl;
            return;
        }
        data[size] = val;       // 把元素存入数组
        size++;                 // 计数加 1
    }

    // 打印数组所有元素
    void print() const {
        std::cout << "数组内容: ";
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

// 2. 主函数测试
int main() {
    std::cout << "--- 开始测试 int 类型的模板数组 ---" << std::endl;
    // 这就是你问的那句话：
    // 编译器看到 <int>，就会在后台生成一个把所有 T 替换为 int 的类，然后调用构造函数传入 10
    MyArray<int> intArray(10); 
    
    intArray.push_back(100);
    intArray.push_back(200);
    intArray.push_back(300);
    intArray.print();

    std::cout << "\n--- 开始测试 double 类型的模板数组 ---" << std::endl;
    // 同样的图纸，换成 <double> 材料，编译器又在后台生成了一个全新的 double 版本的类
    MyArray<double> doubleArray(5); 
    
    doubleArray.push_back(3.14);
    doubleArray.push_back(1.59);
    doubleArray.print();

    std::cout << "\n--- main 函数即将结束，对象准备析构 ---" << std::endl;
    return 0;
}