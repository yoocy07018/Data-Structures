//奇偶数调整问题
//整形数组，把偶数放到数组左边，奇数放右边
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void AdjustArray(int arr[],int size) {
    int* p=arr;
    int* q=arr+size-1;
    while(p<q) {
        //p->奇数
        if((*p & 0x1) == 0) {
            p++;
            continue;
        } 
        //q->偶数
        if((*q & 0x1) == 1) {
            q--;
            continue;
        }
        //交换
        int tmp=*p;
        *p=*q;
        *q=tmp;
        p++;
        q--;
    }
}
int main() {
    int arr[10]={0};
    srand(time(0));
    for(int i=0;i<10;i++) {
        arr[i] = rand() % 100;
    }
    for(int v:arr) {
        cout<<v<<" ";
    }
    cout<<endl;
    AdjustArray(arr,10);
    for(int v:arr) {
        cout<<v<<" ";
    }
    cout<<endl;
}