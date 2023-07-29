//
//  main.cpp
//  intReverse
//
/**
 描述
 输入一个整数，将这个整数以字符串的形式逆序输出
 程序不考虑负数的情况，若数字含有0，则逆序形式也含有0，如输入为100，则输出为001


 数据范围：
 0
 ≤
 �
 ≤
 2
 30
 −
 1
  
 0≤n≤2
 30
  −1
 输入描述：
 输入一个int整数

 输出描述：
 将这个整数以字符串的形式逆序输出

 示例1
 输入：
 1516000
 复制
 输出：
 0006151
 复制
 示例2
 输入：
 0
 复制
 输出：
 0
 */
//  Created by gmy on 2023/7/30.
//

#include <iostream>
using namespace std;

//int main() {
//    int num;
//    cin >> num;
//    if (num == 0) {
//        cout << 0 << endl;
//        return 0;
//    }
//    while (num > 0) {
//        cout << num % 10;
//        num /= 10;
//    }
//    cout << endl;
//}
// 64 位输出请用 printf("%lld")

//int main() {
//    int num;
//    cin >> num;
//    do {
//        cout << num % 10;
//        num /= 10;
//    } while (num > 0);
//    cout << endl;
//}

int main(){
    string str;
    getline(cin, str);
    copy(str.rbegin(),str.rend(),ostreambuf_iterator<char>(cout));
}
