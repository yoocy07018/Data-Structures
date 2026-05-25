//选择排序
//特点：每次在剩下的元素中选择值最小的元素，和当前元素进行交换
//缺点：相较于冒泡排序，交换次数少了，但是比较的次数依然很多
#include <iostream>
#include <time.h>
using namespace std;
void ChoiceSort(int arr[],int size) {
    for(int i=0;i<size-1;i++) {
        int k=i;
        for(int j=i+1;j<size;j++) {
            if(arr[j]<arr[k]) {
                k=j;
            }
        }
        if(k!=i) {
            int temp=arr[i];
            arr[i]=arr[k];
            arr[k]=temp;
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
    ChoiceSort(arr,10);
    for(int v:arr) {
        cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}