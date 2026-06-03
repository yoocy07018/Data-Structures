//手写模板化极简 Vector
#include <iostream>
using namespace std;
template <typename T>
class MyVector {
private:
    T* first;           // 指向数组第一个元素
    T* last;            // 指向最后一个有效元素的后面
    T* end_of_storage;  // 指向整块动态内存的最末尾边界

public:
    // 1. 默认构造函数：一开始什么都没有，全部初始化为空指针
    MyVector() : first(nullptr), last(nullptr), end_of_storage(nullptr) {}

    // 2. 析构函数：释放内存
    ~MyVector() {
        if (first != nullptr) {
            delete[] first; // 一口气释放整块连续内存
        }
    }

    // 3. 大小获取：利用指针算术，Last - First 得到元素个数
    int size() const {
        return last - first;
    }

    // 4. 容量获取：End - First 得到最大格子数
    int capacity() const {
        return end_of_storage - first;
    }

    // 5. 【核心填空：尾插与自动扩容】
    void push_back(const T& val) {
        // 情况 A：内存满了（或者刚初始化，三个指针都是 nullptr）
        if (last == end_of_storage) {
            
            // 计算新容量：如果原本容量是 0，则新容量设为 1；否则翻倍扩容
            int old_cap = capacity();
            int new_cap = (old_cap == 0) ? 1 : old_cap * 2;

            // 第一步：开辟新家（创建一块大小为 new_cap 的全新 T 类型数组）
            // 提示：T* new_data = new T[new_cap];
            // 【你需要填空的地方】
            //表示一个动态数组
            T* new_data=new T[new_cap]; 

            // 第二步：搬运老家具（把老家 first 到 last 之间的数据拷贝到新家）
            // 提示：可以用一个 for 循环，把旧数组的值一个个赋给新数组
            int current_size = size(); // 记录当前手里的元素个数
            // 【你需要填空的地方】
            for(int i=0;i<current_size;i++) {
                *(new_data+i)=*(first+i);
                //也可以写成new_data[i] = first[i];
            }

            // 第三步：强拆老房子（释放旧的内存，防止内存泄漏）
            // 提示：delete[] first;
            // 【你需要填空的地方】
            delete[]first;


            // 第四步：重新调整三大指针的站位，指向新家
            // 提示：
            // first 指向新家的开头
            // last 指向新家数据末尾（即 first + current_size）
            // end_of_storage 指向新家的绝对边界（即 first + new_cap）
            // 【你需要填空的地方】
            first=new_data;
            last=first + current_size;
            end_of_storage=first + new_cap;
        }

        // 情况 B：内存绝对够用，直接在 last 位置安全写入
        // 提示：把 val 赋值给 *last，然后让 last 指针往后挪一格
        // 【你需要填空的地方】
        *last=val;
        last++;
        
    }

    // 6. 打印函数（帮你写好了，方便测试）
    void print() const {
        std::cout << "size: " << size() << ", cap: " << capacity() << " -> 内容: ";
        for (T* p = first; p != last; ++p) {
            std::cout << *p << " ";
        }
        std::cout << std::endl;
    }
};