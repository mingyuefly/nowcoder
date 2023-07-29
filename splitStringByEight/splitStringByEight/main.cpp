//
//  main.cpp
//  splitStringByEight
//
/**
 描述
 •输入一个字符串，请按长度为8拆分每个输入字符串并进行输出；

 •长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
 输入描述：
 连续输入字符串(每个字符串长度小于等于100)

 输出描述：
 依次输出所有分割后的长度为8的新字符串

 示例1
 输入：
 abc
 复制
 输出：
 abc00000
 复制

 */
//  Created by gmy on 2023/7/29.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string str;
    getline(cin, str);
    size_t count = str.length() / 8;
    size_t remainder = str.length() % 8;
    int begin = 0;
    while (count > 0) {
        cout << str.substr(begin, 8) << endl;
        begin += 8;
        count--;
    }
    if (remainder > 0) {
//        string tmpS = string(8 - remainder, '0');
//        string tmpS1 = str.substr(begin, remainder) += tmpS;
//        cout << tmpS1 << endl;
        cout << str.substr(begin, remainder) << string(8 - remainder, '0') << endl;
    }
    
    return 0;
}
