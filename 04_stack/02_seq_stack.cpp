//顺序栈代码讲解（可扩容）
#include <iostream>
using namespace std;
class SeqStack {
public:
    SeqStack(int size=10)//默认申请 size 大小的空间
    :mtop(0)//表示栈目前是空的
    ,mcap(size)
    {
       mpStack=new int[mcap]; 
    }
    ~SeqStack() {
        delete[]mpStack;
        mpStack=nullptr;
    }
public:
    //入栈
    void push(int val) {
        if(mtop==mcap) {// 检查是否满了
            //扩容
            expand(2*mcap);
        }
        mpStack[mtop++]=val;//先赋值再进行加一操作
        //mpStack[mtop] = val;   第一步：在当前的 mtop 下标处存入数据
       //mtop = mtop + 1;       第二步：存完后，把 mtop 往后挪一位
    }
    //出栈
    void pop() {
        if(mtop==0)
            throw "stack is empty!";
        mtop--;// 仅仅是把指针往下移动一位
    }
    //获取栈顶元素
    int top() const {
        if(mtop==0) 
            throw "stack is empty!";
        return mpStack[mtop-1];
    }
    //栈空
    bool empty() const {
        return mtop==0;
    }
    //元素个数
    int size() const {return mtop;}
private:
    void expand(int size) {
        int* p=new int[size];
        //在 C++ 中使用 memcpy 有一个前提：存储的必须是“平凡类型”
        //比如 int, float, char 或者不包含指针/虚函数的简单结构体。
        memcpy(p,mpStack,mtop*sizeof(int));//也可以用for循环 memcpy是简单的浅拷贝
        //for(int i = 0; i < mtop; ++i) {
            //p[i] = mpStack[i];
        //}
        //p: 目的地。数据要考到哪里去。
        //mpStack: 源头。数据从哪里拷贝过来。
        //mtop * sizeof(int): 拷贝多少字节（Byte）
        //memcpy 的第三个参数单位是字节，而不是“元素的个数”。
        delete[]mpStack;
        mpStack=p;
        mcap=size;
    }
private:
    int* mpStack;// 指向动态分配数组的指针，存放具体的元素
    int mtop;//栈顶位置 它总是指向下一个可以存放数据的位置
    int mcap;//栈空间大小 即当前数组最多能存多少数
};
int main() {
    int arr[]={12,4,56,7,89,31,53,75};
    SeqStack s;
    for(int v : arr) {
        //这是 C++11 标准引入的新语法，专门用于遍历容器（如数组、std::vector、std::list 等）。
        //语法结构： for (元素类型 变量名 : 容器名)。
        //小技巧： 如果数组里的元素很大（比如是很长的字符串），
        //为了提高效率，通常写成 for(const auto &v : arr)，这样可以避免拷贝。
        s.push(v);
    }
    while(!s.empty()) {//不为空
        cout<<s.top()<<" ";
        s.pop();
    }
    //循环出栈：
    //只要 empty() 是 false（不为空），就继续。
    //先 top() 打印最上面的数（最后进去的 75 会先被看到）。
    //再 pop() 挪动指针。
    //结果： 打印出来的顺序和 arr 刚好相反。
}
/*
for(const auto &v : arr)
这里的 arr 是一个 int 数组。编译器看到你在遍历一个存放 int 的数组，它就会自动把 auto 替换成 int。
使用 auto 的好处是：代码简洁： 如果容器的类型非常复杂（比如 std::vector<std::shared_ptr<MyClass>>），写 auto 能省去一大串长单词。
易于维护： 如果以后你把数组类型从 int 改成了 double，循环这里的代码一行都不用改，auto 会自动适应新类型。
2. 拆解 const auto &
v这里的写法包含了三个知识点，建议组合在一起记：
auto： 自动推导类型（在这里推导为 int）。
& (引用)：如果不加 &，程序会把数组里的每个数字拷贝一份给 v。
加上 &，v 就像是数组元素的“别名”，直接指向原数据，省去了拷贝的开销，速度更快。
const (常量)：
告诉编译器：“我只打算读取 v 的值，不打算修改它”。这能防止你在循环里不小心改掉了原数组的数据，增加代码安全性。
3. 直观对比假设 arr 是一个 int 数组，这三种写法的效果是一样的，但层次不同：
写法编译器                 |    眼中的样子     |         性能与安全
for(int v : arr)          | 拷贝每个 int      |        有拷贝开销
for(auto &v : arr)        |直接引用原数据     | 高效，但 v 可以修改原数据
for(const auto &v : arr)  |只读引用原数据     |  最高效、最安全（推荐做法）
4. 形象比喻int v：你复印了书里的一页带回家看。
auto &v：你直接去图书馆看那一页，而且你带了橡皮擦，可以改上面的字。
const auto &v：你直接去图书馆看那一页，但图书馆管理员不准你带笔，你只能看，不能改。
*/