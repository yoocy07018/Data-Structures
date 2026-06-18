//极简版 MyDeque 完整代码
#include <iostream>
using namespace std;
class MyDeque {
private:
    int** map;         // 中控大屏幕（二级指针，指向一排“卫星地址”）
    int map_size;      // 中控屏幕上总共有多少个格子
    
    int start_bucket;  // 目前正在使用的第一栋公寓的编号
    int start_index;   // 在第一栋公寓里，从第几个房间开始有人住
    
    int element_count; // 整个 deque 目前一共塞了多少个元素
    const int count_per_bucket = 4; // 🪵 核心硬核设定：每栋公寓（Buffer）只能住 4 个人

public:
    // 构造函数：初始化中控室
    MyDeque() {
        map_size = 5; // 假设中控大屏幕一共 5 个格子
        map = new int*[map_size];
        
        // 先把所有格子都设置为空指针（此时还没有盖任何公寓）
        for (int i = 0; i < map_size; i++) {
            map[i] = nullptr;
        }
        
        // 核心心机：默认从最中间（第 2 栋公寓）开始使用，给两端留出平等的退路
        start_bucket = 2;
        start_index = 0;
        element_count = 0;
        
        // 盖好这第一栋核心公寓
        map[start_bucket] = new int[count_per_bucket];
    }

    // 析构函数：强拆所有公寓，关闭中控室
    ~MyDeque() {
        for (int i = 0; i < map_size; i++) {
            if (map[i] != nullptr) {
                delete[] map[i]; // 炸毁公寓
            }
        }
        delete[] map; // 砸了中控室
    }

    // 1. 屁股后面插数据 (push_back)
    void push_back(int val) {
        // 算出当前最后一个人的绝对虚拟房间号
        int total_index = start_index + element_count;
        
        // 🌟 核心数学运算：除法算栋号，取余算房号！
        int bucket = start_bucket + (total_index / count_per_bucket);//哪一栋
        int index = total_index % count_per_bucket;//第几号房号
        
        // 如果发现算出来的这栋公寓还没盖（空指针），立马当场盖一栋
        if (map[bucket] == nullptr) {
            map[bucket] = new int[count_per_bucket];
        }
        
        // 精准入住
        map[bucket][index] = val;
        element_count++;
    }

    // 2. 🌟 核心通关技：方括号随机访问 [i]
    int operator[](int i) {
        // 计算目标元素在整个迷宫里的绝对虚拟房间号
        int total_index = start_index + i;
        
        // 🌟 再次展现黑客级数学盲猜：不需要循环查找，直接一步到位！
        int bucket = start_bucket + (total_index / count_per_bucket);
        int index = total_index % count_per_bucket;
        
        // 去那栋公寓的那个房间把人抓出来
        return map[bucket][index];
    }

    int size() const { return element_count; }

    // 打印当前的迷宫管理状态
    void print_status() {
        std::cout << "当前总人数: " << element_count << " -> 实际内容: ";
        for (int i = 0; i < element_count; i++) {
            std::cout << (*this)[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MyDeque dq;

    std::cout << "--- 连续 push_back 3 个数（填不满第一栋公寓） ---" << std::endl;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.print_status();

    std::cout << "\n--- 再 push_back 2 个数（第一栋满了，自动无痛开辟第二栋公寓） ---" << std::endl;
    dq.push_back(40); // 此时第一栋公寓（4个格子）彻底满了！
    dq.push_back(50); // 默默开辟新公寓，绝不触发老数据大搬家！
    dq.print_status();

    std::cout << "\n--- 测试 O(1) 随机访问功能 ---" << std::endl;
    std::cout << "下标为 1 的数（第一栋公寓里）: " << dq[1] << std::endl;
    std::cout << "下标为 4 的数（盲猜跨越到第二栋公寓里）: " << dq[4] << std::endl;

    return 0;
}