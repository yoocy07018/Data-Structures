//递归
//int 类型只能储存到12的阶乘，long long类型也只能储存到20的阶乘
//如果要算100的阶乘可以用数组模拟手工乘法来计算高精度阶乘
/*
#include <iostream>
#include <vector>
using namespace std;

// 高精度阶乘计算
void factorial(int n) {
    if (n < 0) {
        cout << "Error: Negative input" << endl;
        return;
    }
    
    vector<int> result;
    result.push_back(1); // 初始化为 1
    
    for (int i = 2; i <= n; i++) {
        int carry = 0; // 进位
        for (int j = 0; j < result.size(); j++) {
            int prod = result[j] * i + carry;
            result[j] = prod % 10; // 当前位保留个位数
            carry = prod / 10;     // 剩下的进位
        }
        // 处理最高位的进位
        while (carry > 0) {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }
    
    // 逆序输出数组（因为个位存在索引 0 的位置）
    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }
    cout << endl;
}

int main() {
    cout << "3! = ";
    factorial(3);
    
    cout << "100! = ";
    factorial(100);
    
    return 0;
}
*/
#include <iostream>
using namespace std;
int func1(int n) {
    if(n==0||n==1) {
        return 1;
    }
    else {
        return n*func1(n-1);
    }
}
int main() {
    cout<<func1(3)<<endl;
    return 0;
}