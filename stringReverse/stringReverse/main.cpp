//
//  main.cpp
//  stringReverse
//
/**
 描述
 接受一个只包含小写字母的字符串，然后输出该字符串反转后的字符串。（字符串长度不超过1000）

 输入描述：
 输入一行，为一个只包含小写字母的字符串。

 输出描述：
 输出该字符串反转后的字符串。

 示例1
 输入：
 abcd
 复制
 输出：
 dcba
 */
//  Created by gmy on 2023/7/30.
//

#include <iostream>
using namespace std;

//int main() {
//    string str;
//    cin >> str;
//    int index = str.length() - 1;
//    while (index >= 0) {
//        cout << str[index];
//        index--;
//    }
//    cout << endl;
//}
// 64 位输出请用 printf("%lld")

string reverseString(string &str) {
    string str1 = string(str);
    size_t length = str1.length();
    size_t l = 0, r = length - 1;
    while (l <= r) {
        swap(str1[l], str1[r]);
        l++;
        r--;
    }
    return str1;
}

int main() {
    string str;
    cin >> str;
    cout << reverseString(str) << endl;
}
