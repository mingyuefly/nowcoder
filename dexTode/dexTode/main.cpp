//
//  main.cpp
//  dexTode
//
/**
 描述
 写出一个程序，接受一个十六进制的数，输出该数值的十进制表示。

 数据范围：保证结果在
 1
 ≤
 �
 ≤
 2
 31
 −
 1
  
 1≤n≤2
 31
  −1
 输入描述：
 输入一个十六进制的数值字符串。

 输出描述：
 输出该数值的十进制字符串。不同组的测试用例用\n隔开。

 示例1
 输入：
 0xAA
 复制
 输出：
 170
 复制

 */
//  Created by gmy on 2023/7/29.
//

#include <iostream>
#include "ctype.h"
using namespace std;

int main() {
    string hexString;
    cin >> hexString;
    string numString = hexString.substr(2, hexString.length() - 2);
    int num = 0;
//    for(char c : numString) {
//        int cNum = 0;
//        if ((int)c <= 57 && (int)c >= 48) {
//            cNum = (int)c - 48;
//        } else {
//            cNum = (int)c - 55;
//        }
//        num = num * 16 + cNum;
//    }
    for(char c : numString) {
        int cNum = 0;
        if (c <= 'F' && c >= 'A') {
            cNum = (int)c - 55;
        } else {
            cNum = (int)c - 48;
        }
        num = num * 16 + cNum;
    }
    cout << to_string(num) << endl;
}
