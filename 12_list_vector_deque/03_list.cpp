//list
/*
【题目背景】
一个新手写了一段代码，目的是想把一个无序的 std::list 里的重复数字删掉
他写出了下面这行代码：

C++
// lst 是一个无序的双向链表，里面有 {3, 1, 2, 1, 3}
std::sort(lst.begin(), lst.end()); // 先排序，让相同的数挨在一起
lst.unique();                      // 调用去重 API
【提问】
这段代码能顺利通过编译并运行吗？
如果不能，请指出里面潜伏的致命雷点是什么？
应该如何正确修改？
*/
/*
全局的 std::sort() 骨子里用的是快速排序，
它要求传入的迭代器必须是最高级别的“随机访问迭代器”
（也就是能写 it + 3、能玩盲猜瞬移的容器，比如 vector 和 deque）。

但现在传入的是 lst.begin()。list 的底层是双向循环链表，
内存七零八落。它的迭代器根本不能写 + 号，只能一步一步 ++ 挪动。

这就叫“门不对、户不当”！全局 std::sort 强行去拉 list 的迭代器，
编译器在后台对对碰时发现类型完全对不上，
就会直接“掀桌子”，给你甩出几百行的红色报错。
*/
#include <iostream>
#include <list>
#include <algorithm>// 引入全局算法头文件（std::sort 在这里）
using namespace std;
void printlist(const list<int>& lst) {
    for(int val:lst) {
        cout<<val<<" ";
    }
    cout<<endl;
}
int main() {
    list<int> myList={3,1,2,1,3,1,5,2,4,4};
    printlist(myList);
    myList.sort();
    printlist(myList);
    myList.unique();//lst.unique() 这个 API 的底层逻辑非常单纯，
    //它只会挨个检查相邻的两个数是不是一样。如果一样，它就把后一个删掉
    printlist(myList);
}