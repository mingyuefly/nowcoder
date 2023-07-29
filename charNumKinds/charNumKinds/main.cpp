//
//  main.cpp
//  charNumKinds
//
/**
 描述
 编写一个函数，计算字符串中含有的不同字符的个数。字符在 ASCII 码范围内( 0~127 ，包括 0 和 127 )，换行表示结束符，不算在字符里。不在范围内的不作统计。多个相同的字符只计算一次
 例如，对于字符串 abaca 而言，有 a、b、c 三种不同的字符，因此输出 3 。

 数据范围：
 1
 ≤
 �
 ≤
 500
  
 1≤n≤500
 输入描述：
 输入一行没有空格的字符串。

 输出描述：
 输出 输入字符串 中范围在(0~127，包括0和127)字符的种数。

 示例1
 输入：
 abc
 复制
 输出：
 3
 复制
 示例2
 输入：
 aaa
 复制
 输出：
 1
 */
//  Created by gmy on 2023/7/29.
//

#include <iostream>
#include <unordered_set>
using namespace std;

//int main() {
//    string str;
//    cin >> str;
//    unordered_set<char> charSet;
//    int count = 0;
//    for(char ch : str) {
//        if (charSet.count(ch) != 0) {
//            continue;
//        } else {
//            charSet.insert(ch);
//            count++;
//        }
//    }
//    cout << count << endl;
//}
// 64 位输出请用 printf("%lld")

int main() {
    string str;
    cin >> str;
    unordered_set<char> charSet;
    for(char ch : str) {
        charSet.insert(ch);
    }
    cout << charSet.size() << endl;
}
