//堆排序算法原理和代码输出
#include <iostream>
#include <time.h>
using namespace std;
//每一次下沉调整 时间复杂度为O(n*logn)  空间复杂度为O(1)
//堆的下沉调整(大根堆)  小的数下沉
void siftDown(int arr[],int i,int size) {
    int val=arr[i];
    while(i<size/2) {
        int child=2*i+1;
        if(child+1<size&&arr[child+1]>arr[child]) {
            child=child+1;
        } 
        if(arr[child]>val) {
            arr[i]=arr[child];
            i=child;
        }
        else {
            break;
        }
    }
    arr[i]=val;
}
//堆排序
void HeapSort(int arr[],int size) {
    int n=size-1;
    //从第一个非叶子节点  该循环得到大根堆
    for(int i=(n-1)/2;i>=0;i--) {
        siftDown(arr,i,size);
    }
    //把堆顶元素和末尾元素进行交换，从堆顶开始进行下沉操作（每一次都把最大的元素放到最后）
    //该循环得到了小根堆
    for(int i=n;i>=0;i--) {
        int tmp=arr[0];
        arr[0]=arr[i];
        arr[i]=tmp;
        //把第一个元素进行下沉调整，让其变成大根堆
        siftDown(arr,0,i);//第三个参数，参与调整的元素个数（最后一个元素不进行比较 下沉操作，因为i=size-1,siftDown中size=i）
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
    HeapSort(arr,10);
    for(int v:arr) {
        cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}