//移除元素问题  定义一个数组和一个数val 如果数组里面找到了val就删除并且输出最后的数组长度
#include <iostream>
using namespace std;
int removeElement(int* nums,int numsSize,int val) {
    int* p=nums;
    int* q=nums+numsSize-1;
    while(p<=q) {
        //q 找到不等于val的元素
        if(*q==val) {
            q--;
            continue;
        }
        if(*p==val) {
            *p=*q;
            q--;
        }
        else {
            p++;
        }
    }
    return p-nums;
}
int main() {
    int arr[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2; 
    int size = sizeof(arr) / sizeof(arr[0]);
    //sizeof(arr)：求整个数组的总大小
    //由于数组里有 8 个 int，每个 int 占 4 字节，所以 sizeof(arr) 为32个字节
    //arr[0] 就是数组的第一个元素，它是一个 int，所以占用 4 个字节。
    cout << "原始数组: ";
    for(int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
    
    int newLen = removeElement(arr, size, val);
    
    cout << "新数组长度: " << newLen << endl;
    cout << "处理后数组(有效部分): ";
    for(int i = 0; i < newLen; i++) cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}