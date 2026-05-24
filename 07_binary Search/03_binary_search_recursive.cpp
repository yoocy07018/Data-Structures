//二分搜索递归代码
#include <iostream>
using namespace std;
int BinarySearch(int arr[],int i,int j, int val) {
    if(i>j) {
        return -1;
    }
    int mid=(i+j)/2;
    if(arr[mid]==val) {
        return mid;
    }
    else if(arr[mid]>val) {
        return BinarySearch(arr,i,mid-1,val);
    }
    else {
        return BinarySearch(arr,mid+1,j,val);
    }
}
int main() {
    int arr[]={12,23,34,45,56,67,78,89,100};
    int size=sizeof arr / sizeof arr[0];
    int i=0;
    int j=size-1;
    cout<<BinarySearch(arr,i,j,34)<<endl;
    cout<<BinarySearch(arr,i,j,56)<<endl;
    cout<<BinarySearch(arr,i,j,45)<<endl;
    cout<<BinarySearch(arr,i,j,89)<<endl;
    cout<<BinarySearch(arr,i,j,13)<<endl;
    return 0;
}