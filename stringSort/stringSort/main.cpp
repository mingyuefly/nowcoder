//
//  main.cpp
//  stringSort
//
/**
 描述
 给定 n 个字符串，请对 n 个字符串按照字典序排列。

 数据范围：
 1
 ≤
 �
 ≤
 1000
  
 1≤n≤1000  ，字符串长度满足
 1
 ≤
 �
 �
 �
 ≤
 100
  
 1≤len≤100
 输入描述：
 输入第一行为一个正整数n(1≤n≤1000),下面n行为n个字符串(字符串长度≤100),字符串中只含有大小写字母。
 输出描述：
 数据输出n行，输出结果为按照字典序排列的字符串。
 示例1
 输入：
 9
 cap
 to
 cat
 card
 two
 too
 up
 boat
 boot
 复制
 输出：
 boat
 boot
 cap
 card
 cat
 to
 too
 two
 up
 */
//  Created by gmy on 2023/7/30.
//

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

// 使用c++中有序map特性
//vector<string> dicSortString(const vector<string> &strs) {
//    vector<string> sortStrs;
//    map<string, int> stringMaps;
//    for (string str : strs) {
//        stringMaps[str]++;
//    }
//    for(pair<string, int> pair : stringMaps) {
//        for (int i = 0; i < pair.second; i++) {
//            sortStrs.push_back(pair.first);
//        }
//    }
//    return sortStrs;
//}

vector<string> dicSortString(const vector<string> &strs) {
    vector<string> sortStrs;
    multiset<string> stringSets;
    for (string str : strs) {
        stringSets.insert(str);
    }
    for (string str : stringSets) {
        sortStrs.push_back(str);
    }
    return sortStrs;
}

int main() {
    int N;
    cin >> N;
    vector<string> strs;
    while (N > 0) {
        string str;
        cin >> str;
        strs.push_back(str);
        N--;
    }
    vector<string> sortStrs = dicSortString(strs);
    for(string str : sortStrs) {
        cout << str << endl;
    }

}
// 64 位输出请用 printf("%lld")

// 使用c++中库函数sort
//int main() {
//    int N;
//    cin >> N;
//    vector<string> strs;
//    while (N > 0) {
//        string str;
//        cin >> str;
//        strs.push_back(str);
//        N--;
//    }
//    sort(strs.begin(), strs.end());
//    for(string str : strs) {
//        cout << str << endl;
//    }
//}

// 直接使用c++中字符串比较
//int main() {
//    int N;
//    cin >> N;
//    vector<string> strs;
//    int tmpN = N;
//    while (tmpN > 0) {
//        string str;
//        cin >> str;
//        strs.push_back(str);
//        tmpN--;
//    }
//    for (int i = 1; i < N; i++) {
//        for(int j = i; j > 0 && strs[j] < strs[j - 1]; j--) {
//            swap(strs[j], strs[j - 1]);
//        }
//    }
//    for(string str : strs) {
//        cout << str << endl;
//    }
//}
