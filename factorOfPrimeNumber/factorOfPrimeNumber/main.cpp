//
//  main.cpp
//  factorOfPrimeNumber
//
/**
 描述
 功能:输入一个正整数，按照从小到大的顺序输出它的所有质因子（重复的也要列举）（如180的质因子为2 2 3 3 5 ）


 数据范围：
 1
 ≤
 �
 ≤
 2
 ×
 1
 0
 9
 +
 14
  
 1≤n≤2×10
 9
  +14
 输入描述：
 输入一个整数

 输出描述：
 按照从小到大的顺序输出它的所有质数的因子，以空格隔开。

 示例1
 输入：
 180
 复制
 输出：
 2 2 3 3 5
 */
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
