//归并排序算法
/*
# 二路归并排序 (Merge Sort)

初始序列: 62 99 38 75 81 40 51 60 14 36
寻找中点: int mid = (0 + 9) / 2 = 4

                                0                               9
                             +-------------------------------------+
             [最终归并结果]    | 14 36 38 40 51 60 62 75 81 99       |（每一次排序都要开辟额外的内存空间，把两个小段有序序列，合并成大段有序序列）
                             +-------------------------------------+
                                   /                     \
      (↖ ↗ 红色箭头代表           /                       \
       自底向上的合并过程)      i 0           4         j 5           9
                             38 62 75 81 99             14 36 40 51 60
                               /         \                 /          \
                              /           \               /            \
                            i 0    2    j 3   4         i 5    7     j 8   9
                         +----------+   +-------+      +----------+   +-------+
                         | 38 62 99 |   | 75 81 |      | 40 51 60 |   | 14 36 |
                         +----------+   +-------+      +----------+   +-------+
                           /      \       /   \          /      \       /   \
                          /        \     /     \        /        \     /     \
                        i 0  1   j 2    3       4     i 5  6   j 7    8       9
                       +-------+ +----+ +----+ +----+ +-------+ +----+ +----+ +----+
                       | 62 99 | | 38 | | 75 | | 81 | | 40 51 | | 60 | | 14 | | 36 |
                       +-------+ +----+ +----+ +----+ +-------+ +----+ +----+ +----+
                         /   \
                       (62) (99)

图解说明：
1. 顶部的 mid = 4 决定了第一次分解的边界：左半部分是 [0~4]，右半部分是 [5~9]。
2. 方框 [ ] 代表已经排好序的子序列。
3. 字母 i 和 j 代表在执行“合并 (Merge)”操作时，指向左、右两个有序子数组起始位置的遍历指针。
*/
#include <iostream>
#include <time.h>
using namespace std;
//归并过程函数
void Merge(int arr[],int l,int m,int r) {//m表示中间值 即mid
    int* p=new int[r-l+1];
    int idx=0;
    int i=l;
    int j=m+1;
    while(i<=m&&j<=r) {
        if(arr[i]<=arr[j]) {
            p[idx++]=arr[i++];
        }
        else {
            p[idx++]=arr[j++];
        }
    }
    while(i<=m) {
        p[idx++]=arr[i++];
    }
    while(j<=r) {
        p[idx++]=arr[j++];
    }
    //再把合并好的大段有序的结果 拷贝到原始arr数组[l,r]区间内
    for(i=l,j=0;i<=r;i++,j++) {
        arr[i]=p[j];
    }
    delete[]p;
}
//归并排序递归接口
void MergrSort(int arr[],int begin,int end) {
    //递归结束条件
    if(begin>=end) {
        return;
    }
    int mid=(begin+end)/2;
    //先递
    MergrSort(arr,begin,mid);
    MergrSort(arr,mid+1,end);
    //再归并 [begin,mid]  [mid+1,end] 把两个小段有序的序列，合并成一个大的有序的序列
    Merge(arr,begin,mid,end);
}
//归并排序
void MergrSort(int arr[],int size) {
    //要封装一个归并排序递归接口
    MergrSort(arr,0,size-1);
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
    MergrSort(arr,10);
    for(int v:arr) {
        cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}