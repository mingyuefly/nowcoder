//
//  main.cpp
//  factorOfPrimeNumber
//
//  Created by gmy on 2023/7/29.
//

#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;
    int i;
    int num1 = num;
    for (i = 2; i * i <= num1; i++) {
        if (num1 % i == 0) {
            cout << i << " ";
            num1 /= i;
            i = 1;//循环结束，从2开始重新循环
        }
    }
    // num1和i相等
    cout << num1 << endl;
}



//int main() {
//    // 在nowcoder上超时
//    int num;
//    cin >> num;
//    int i;
//    int num1 = num;
//    for (i = 2; i < num1; i++) {
//        while (num1 % i == 0) {
//            num1 /= i;
//            cout << i << " ";
//        }
//    }
//    // i可能和num1相等
//    if (i > 2 && num1 % i == 0) {
//        cout << i << " ";
//    }
//    cout << endl;
//}
