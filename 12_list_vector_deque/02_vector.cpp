//关于vector的题目
/*
【题目背景】
你正在为一款车载记录仪编写一段高频数据接收程序。
系统每秒钟会通过 push_back() 塞入几十万个 int 类型的传感器数据。
此时遇到了一个严重的技术故障：由于 vector 频繁触发“扩容大搬家”，
导致系统出现了严重的卡顿（丢包现象）。

【提问】
在不改变容器类型（必须用 vector）的前提下，
你在初始化这个 vector 时，应该调用哪一个 API 来
彻底消灭这种扩容大搬家带来的卡顿？为什么它能解决问题？
*/
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int get_value() {
    return rand()%101;
}
int main() {
    vector<int> sensor;
    sensor.reserve(500000);//reserve()预留空间
    for(int i=0;i<500000;i++) {
        sensor.push_back(get_value());
    }
    return 0;
}