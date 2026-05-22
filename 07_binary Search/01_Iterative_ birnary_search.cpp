//二分法搜索算法非递归讲解
#include <iostream>
using namespace std;
int BinarySearch(int arr[],int size,int val) {
    int first =0;
    int last=size-1;
    while(first<=last) {
        int mid=(first+last)/2;
        if(val==arr[mid]) {
            return mid;
        }
        else if(arr[mid]>val) {
            last=mid-1;
        }
        else {
            first=mid+1;
        }
    }
    return -1;
}
int main() {
    int arr[]={12,23,34,45,56,67,78,89,100};
    int size=sizeof arr / sizeof arr[0];
    cout<<BinarySearch(arr,size,34)<<endl;
    cout<<BinarySearch(arr,size,56)<<endl;
    cout<<BinarySearch(arr,size,45)<<endl;
    cout<<BinarySearch(arr,size,89)<<endl;
    cout<<BinarySearch(arr,size,13)<<endl;
    return 0;
}