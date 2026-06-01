//基数排序代码实现  从小到大排序  正整数
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
using namespace std;
void RadixSort(int arr[],int size) {
    int maxData=arr[0];
    for(int i=1;i<size;i++) {
        if(maxData<arr[i]) {
            maxData=arr[i];
        }
    }
    int len=to_string(maxData).size();//得到maxData的长度
    vector<vector<int>> vecs;
    int mod=10;
    int dev=1;
    for(int i=0;i<len;mod*=10,dev*=10,i++) {
        vecs.resize(10);//10个桶
        for(int j=0;j<size;j++) {
            //得到当前元素第i个位置的数字
            int index=arr[j]%mod/dev;
            vecs[index].push_back(arr[j]);
        }
        //依次遍历所有的桶，把元素拷贝回原始的数组当中
        int idx=0;
        for(auto vec:vecs) {
            for(int v:vec) {
                arr[idx++]=v;
            }
        }
        vecs.clear();
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
    RadixSort(arr,10);
    for(int v:arr) {
        cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}