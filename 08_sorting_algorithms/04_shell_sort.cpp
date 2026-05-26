//希尔排序代码  平均时间复杂度 ；O(n^1.3)   空间复杂度 ：O(1)   稳定性 ：不稳定
#include <iostream>
#include <time.h>
using namespace std;
void ShellSort(int arr[],int size) {
    for(int gap=size/2;gap>0;gap/=2) {
        for(int i=gap;i<size;i++) {
            int val=arr[i];
            int j=i-gap;
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