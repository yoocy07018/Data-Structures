//希尔排序代码  平均时间复杂度 ；O(n^1.3)   空间复杂度 ：O(1)   稳定性 ：不稳定
/*
希尔排序 (Shell Sort) 简介
希尔排序是插入排序的一种高阶、更高效的改进版本，也称为缩小增量排序。
它巧妙地突破了插入排序“每次只能相邻交换，导致小元素从最后端移动到最前端非常缓慢”的瓶颈。

它的核心思想是：

设定一个步长（Gap），将整个数组按照这个步长分成若干个子序列。

对每个子序列分别进行插入排序。

缩小步长（通常是减半），再次重新分组并进行插入排序。

当步长缩小为 1 时，整个数组就相当于进行了一次普通的插入排序。但此时数组已经“宏观上有序”，普通插入排序需要移动的元素极少，因此效率极高。
*/
#include <iostream>
#include <time.h>
using namespace std;
void ShellSort(int arr[],int size) {
    // 外层循环：控制步长（Gap），初始为数组长度的一半，每次减半，直到步长为 1
    for(int gap=size/2;gap>0;gap/=2) {
        // 中层循环：从第 gap 个元素开始，逐个对其所在的组进行插入排序
        for(int i=gap;i<size;i++) {
            int val=arr[i];
            int j=i-gap;
            // 内层循环：在当前元素所在的子序列中，从后向前扫描
            // 注意这里的步长是 gap 而不是 1
            for(;j>=0;j-=gap) {
                if(arr[j]<=val) {
                    break;
                }
                arr[j+gap]=arr[j];
            }
            arr[j+gap]=val; 
        }  
    }
    
}
int main(){
    int arr[10];
    srand(time(NULL));
    for(int i=0;i<10;i++) {
        arr[i]=rand()%100+1;
    }
    for(int v:arr) {
        cout<<v<<" ";
    }
    cout<<endl;
    ShellSort(arr,10);
    for(int v:arr) {
        cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}