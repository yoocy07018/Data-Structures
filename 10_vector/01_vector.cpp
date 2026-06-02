/*
1.你之前手写动态数组（顺序表）时，类内部通常是用这三个变量来管理的：

    int* data; （指向数组头部的裸指针）

    int size; （记录当前存了几个数据）

    int capacity; （记录数组最大能装几个数据）

2.标准库的 std::vector 底层思路和你的完全一致，但它做得更彻底、更具数学美感——它内部不存任何 int 类型的计数变量，而是直接使用了三个“裸指针”来管理整片连续内存。

在标准库源码中（不同编译器命名略有不同，但本质等价），这三个指针分别是：

    _First （或 start）：指向动态数组的第一个元素。

    _Last （或 finish）：指向当前最后一个有效元素的“后面那一个位置”。

    _End （或 end_of_storage）：指向整块动态内存的最末尾边界。

3.指针算术（指针相减等于元素个数），它的底层源码其实长这样：

size() 的底层实现：size()=_Last - _First（当前有效元素的个数）

capacity() 的底层实现：capacity() =_End - _First（整块内存最多能容纳的元素个数）

empty() 的底层实现：empty() = (_First==_Last)（如果两个指针指向同一个地方，说明一个元素都没有）

4.std::vector<int> vec

当你调用 vec.begin() 时，vector 内部其实就是直接把 _First 指针包装成迭代器丢给你。

当你调用 vec.end() 时，vector 内部其实就是直接把 _Last 指针包装成迭代器丢给你
*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
    // 1. 创建一个初始容量(capacity)为 3 的 vector 
    // 此时里面没有元素，size = 0
    std::vector<int> vec;
    vec.reserve(3); // 预留 3 个格子的空间

    std::cout << "=== 刚初始化，一个元素都没有 ===" << std::endl;
    // 模拟底层的 _Last - _First
    std::cout << "size (Last - First)     = " << vec.end() - vec.begin() << std::endl;
    // 模拟底层的 _End - _First（由于标准库没公开 _End，我们用 capacity() 代替距离）
    std::cout << "capacity (End - First) = " << vec.capacity() << std::endl;
    std::cout << "是否为空(First == Last)?  = " << (vec.begin() == vec.end() ? "true" : "false") << std::endl;

    // 2. 塞入第一个元素
    std::cout << "\n=== 塞入元素 10 ===" << std::endl;
    vec.push_back(10);
    // 此时 _First 没动，_Last 往后挪了 1 个 int 的距离
    std::cout << "size (Last - First)     = " << vec.end() - vec.begin() << std::endl;
    std::cout << "capacity (End - First) = " << vec.capacity() << std::endl;

    // 3. 塞满它！塞入 20 和 30
    std::cout << "\n=== 塞满容器（塞入 20 和 30） ===" << std::endl;
    vec.push_back(20);
    vec.push_back(30);
    // 此时 _Last 已经退到了和 _End 重合的位置！
    std::cout << "size (Last - First)     = " << vec.end() - vec.begin() << std::endl;
    std::cout << "capacity (End - First) = " << vec.capacity() << std::endl;
    std::cout << "警告：此时 _Last == _End，内存已满！再塞就要触发扩容搬家了！" << std::endl;

    return 0;
}