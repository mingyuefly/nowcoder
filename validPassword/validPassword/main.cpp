//
//  main.cpp
//  validPassword
//
/**
 描述
 密码要求:
 
 1.长度超过8位
 
 2.包括大小写字母.数字.其它符号,以上四种至少三种
 
 3.不能有长度大于2的包含公共元素的子串重复 （注：其他符号不含空格或换行）
 
 数据范围：输入的字符串长度满足
 1
 ≤
 �
 ≤
 100
 
 1≤n≤100
 输入描述：
 一组字符串。
 
 输出描述：
 如果符合要求输出：OK，否则输出NG
 
 示例1
 输入：
 021Abc9000
 021Abc9Abc1
 021ABC9000
 021$bc9000
 复制
 输出：
 OK
 NG
 NG
 OK
 */
//  Created by gmy on 2023/8/4.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool hasEnoughKinds(string passwordStr) {
    map<string, bool> stringMap;
    for(char ch : passwordStr) {
        if (isdigit(ch)) {
            stringMap["hasNum"] = true;
        } else if (islower(ch)) {
            stringMap["hasLowercase"] = true;
        } else if (isupper(ch)) {
            stringMap["hasCapital"] = true;
        } else {
            stringMap["hasSpecialCharacter"] = true;
        }
        if (stringMap.size() >= 3) {
            return true;
        }
    }
    if (stringMap.size() >= 3) {
        return true;
    }
    return false;
}

// 题目要求是不能有重复大于长度2的子串，所以只要考虑有没有长度为3的重复子串即可
//bool hasRepeationStr(string passwordStr) {
//    size_t length = passwordStr.length();
//    int max_subStr_len = 3;
//    bool isFound = false;
//    for (int i = 0; i < length - max_subStr_len; i++) {
//        for(int j = i + max_subStr_len; j < length - max_subStr_len; j++) {
//            if (0 == passwordStr.compare(i, max_subStr_len, passwordStr, j, max_subStr_len)){
//                isFound = true;
//                break;
//            }
//        }
//    }
//    return !isFound;
//}

bool hasRepeationStr(string passwordStr) {
    size_t length = passwordStr.length();
    string tmpStr = "";
    unordered_set<string> sets;
    for (int i = 0; i < length - 2; i++) {
        tmpStr = passwordStr.substr(i, 3);
        if (sets.find(tmpStr) == sets.end()) {
            sets.insert(tmpStr);
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    string passwordStr;
    vector<string> valids;
    while (cin >> passwordStr) {
        if (passwordStr.length() <= 8) {
            valids.push_back("NG");
            continue;
        }
        if (!hasEnoughKinds(passwordStr)) {
            valids.push_back("NG");
            continue;
        }
        if (!hasRepeationStr(passwordStr)) {
            valids.push_back("NG");
            continue;
        }
        valids.push_back("OK");
    }
    for(string str : valids) {
        cout << str << endl;
    }
}
// 64 位输出请用 printf("%lld")
