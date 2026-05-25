//插入排序 时间复杂度 ：最坏平均时间复杂度为 O(n^2)  最好： O(n)  空间 ：O(1)  稳定性 ： 稳定的
//如果数据趋于有序，那么插入排序是所有排序算法中，效率最高的
//在基础排序算法中，插入排序 > 冒泡排序 & 选择排序
#include <iostream>
#include <time.h>
using namespace std;
void InsertSort(int arr[],int size) {
    //第一种写法
    /*
    for(int i=1;i<size;i++) {
        int val=arr[i];
        int j=i-1;
        for(;j>=0;j--) {
            if(arr[j]<=val) {
                break;
            }
            arr[j+1]=arr[j];
        }
        arr[j+1]=val; 
    }  
    */
    //第二种写法
    for(int i=1;i<size;i++) {
        for(int j=i-1;j>=0;j--) {
            if(arr[j+1]<=arr[j]) {
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
            else {
                break;
            }
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
    InsertSort(arr,10);
    for(int v:arr) {
        cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}