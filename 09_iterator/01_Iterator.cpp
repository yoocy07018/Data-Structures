//迭代器(iterator)知识点
/*
一.  什么是迭代器？
迭代器是一个**“包装了指针的对象”**。它的行为故意模仿得和裸指针一模一样。

不管底层是数组、链表还是树，每种容器都会在内部自带一个专属的迭代器。这个迭代器通过运算符重载，实现了以下统一伪装：

   模仿指针 *it：执行“解引用”，就能拿到它当前指向的元素。

   模仿指针 ++it：执行“自增”，就能自动挪到下一个元素（如果是数组，内部就是指针 +1；如果是链表，内部就是偷偷执行了 p = p->next）。

   模仿指针 it != end：用来判断是否遍历到了尽头。


二.在 STL 中，所有容器都提供两个核心成员函数：

begin()：返回指向第一个元素的迭代器。

end()：返回指向最后一个元素后面那个虚无位置的迭代器（数学上的开区间截断点）。
*/
#include <iostream>
#include <list> // 引入双向链表头文件
using namespace std;
int main() {
    // 1. 创建一个双向链表对象（变量），并用 {10, 20, 30} 进行列表初始化
    // 此时 myList 是一个对象，里面有 3 个节点
    std::list<int> myList = {10, 20, 30};

    std::cout << "--- 开始使用传统长语法遍历链表 ---" << std::endl;

    // 2. 这里的 it 是一个变量（迭代器对象）
    // myList.begin() 是调用成员函数，拿到指向第一个节点的迭代器并赋给 it
    // myList.end()   是调用成员函数，拿到指向末尾后面虚无位置的迭代器，作为结束条件
    // ++it           每次循环让 it 变量指向下一个节点
    for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
        
        // *it 是利用运算符重载，像指针一样解引用，打印当前节点里的数据
        std::cout << "节点数据: " << *it << std::endl; 
    }

    std::cout << "\n--- 开始使用现代 C++ 的 auto 偷懒写法 ---" << std::endl;

    // 3. 这里的 auto 会被编译器自动推导为 std::list<int>::iterator
    // 代码清爽了很多，但底层的变量逻辑和上面完全一模一样
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << "节点数据(auto): " << *it << std::endl;
    }

    return 0;
}