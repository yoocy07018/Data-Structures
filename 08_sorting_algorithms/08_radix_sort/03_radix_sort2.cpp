//基数排序代码实现  从小到大排序  正整数和负数
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
        vecs.resize(20);//前面十个放负数，后面十个放正数
        for(int j=0;j<size;j++) {
            //得到当前元素第i个位置的数字
            int index=arr[j]%mod/dev+10;//-8变成2，-3变成7，这样可以让-8放在-3的前面
            //负数为0-9 正数加十变成了10-19
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
    arr[9]=-123;
    arr[6]=-3;
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