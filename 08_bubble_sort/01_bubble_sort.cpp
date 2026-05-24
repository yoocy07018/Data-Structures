#include <iostream>
#include <time.h>
using namespace std;
void BubbleSort(int arr[],int size) {
    for(int i=0;i<size-1;i++) {
        bool flag=false;//如果数组在循环还没有结束的时候已经排好序了，可以直接结束循环
        for(int j=0;j<size-1-i;j++) {
            if(arr[j]>arr[j+1]) {
                int tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
                flag=true;
            }
        }
        if(!flag) {
            return;
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
    BubbleSort(arr,10);
    for(int v:arr) {
        cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}