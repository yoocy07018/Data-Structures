/*
# 快速排序 (Quick Sort)

## 核心思想
选取一个基准数，把小于基准数的元素都调整到基准数的左边，把大于基准数的元素都调整到基准数的右边。然后对基准数左边和右边的序列继续进行这样的操作，直到整个序列变成有序的。

## 快排分割函数 (Partition)
**循环的条件：** `L < R`

**执行步骤：**
1. **选取基准数：** `val = arr[L]`
2. 从 `R` 开始往前找第一个 `< val` 的数字，放到 `L` 的地方，然后 `L++`
3. 从 `L` 开始往后找第一个 `> val` 的数字，放到 `R` 的地方，然后 `R--`
4. **重复上面的过程** (步骤2和3)，直到循环结束。

**终止操作：**
当 `L == R` 时：
`arr[L] = val;` (将基准数填回最终的相遇点)

## 执行流程图 (递归树)
以下是图片中以 `46` 为初始基准数的分割过程演示（带 `[]` 或标注的为当前子序列的基准数）：
          
```text           32 8 7 10 38 46 68 76 65 53
                              [46]
                           /        \
                          /          \
            10, 8, 7, [32], 38       53, 65, [68], 76
                 /       \                 /         \
                /         \               /           \
         7, 8, [10]       [38]         [53], 65      [76]
             /                             \
            /                               \
         [7], 8                             [65]
             \
              \
              [8]
*/
#include <iostream>
#include <time.h>
using namespace std;
//快排分割处理函数
int Partation(int arr[],int l,int r) {
    //记录基准数
    int val=arr[l];
    //一次快排处理  时间：O(n)*O(nlogn)   空间：O(logn) 递归的深度所占用的栈空间
    while(l<r) {
        while(l<r&&arr[r]>val) {
            r--;
        }
        if(l<r) {
            arr[l]=arr[r];
            l++;
        }
        while(l<r&&arr[l]<val) {
            l++;
        }
        if(l<r) {
            arr[r]=arr[l];
            r--;
        }
    }
    //l==r的位置，就是放基准数的位置
    arr[l]=val;
    return l;
}
//快排的递归接口
void QuickSort(int arr[],int begin,int end) {
    if(begin>=end) {
        return;
    }
    //在[brgin,end]区间的元素做一次快排分割处理
    int pos=Partation(arr,begin,end);
    //对基数的左边和右边的序列，再分别进行快排
    QuickSort(arr,begin,pos-1);
    QuickSort(arr,pos+1,end);
    
}
void QuickSort(int arr[],int size) {
    return QuickSort(arr,0,size-1);
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
    QuickSort(arr,10);
    for(int v:arr) {
        cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}