//逆序字符串
#include <iostream>
#include <string.h>
using namespace std;
void reverse(char arr[],int size) {
    char* p=arr;
    char* q=arr+size-1;
    while(p<q) {
        char ch=*p;
        *p=*q;
        *q=ch;
        p++;
        q--;
    }
}
int main() {
    char arr[]="hello world";
    reverse(arr,strlen(arr));
    cout<<arr<<endl;
}
