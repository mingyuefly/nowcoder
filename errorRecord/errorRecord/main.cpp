//
//  main.cpp
//  errorRecord
//
/**
 描述
 开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。


 处理：


 1、 记录最多8条错误记录，循环记录，最后只用输出最后出现的八条错误记录。对相同的错误记录只记录一条，但是错误计数增加。最后一个斜杠后面的带后缀名的部分（保留最后16位）和行号完全匹配的记录才做算是“相同”的错误记录。
 2、 超过16个字符的文件名称，只记录文件的最后有效16个字符；
 3、 输入的文件可能带路径，记录文件名称不能带路径。也就是说，哪怕不同路径下的文件，如果它们的名字的后16个字符相同，也被视为相同的错误记录
 4、循环记录时，只以第一次出现的顺序为准，后面重复的不会更新它的出现时间，仍以第一次为准

 数据范围：错误记录数量满足
 1
 ≤
 �
 ≤
 100
  
 1≤n≤100  ，每条记录长度满足
 1
 ≤
 �
 �
 �
 ≤
 100
  
 1≤len≤100
 输入描述：
 每组只包含一个测试用例。一个测试用例包含一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。

 输出描述：
 将所有的记录统计并将结果输出，格式：文件名 代码行数 数目，一个空格隔开，如：

 示例1
 输入：
 D:\zwtymj\xccb\ljj\cqzlyaszjvlsjmkwoqijggmybr 645
 E:\je\rzuwnjvnuz 633
 C:\km\tgjwpb\gy\atl 637
 F:\weioj\hadd\connsh\rwyfvzsopsuiqjnr 647
 E:\ns\mfwj\wqkoki\eez 648
 D:\cfmwafhhgeyawnool 649
 E:\czt\opwip\osnll\c 637
 G:\nt\f 633
 F:\fop\ywzqaop 631
 F:\yay\jc\ywzqaop 631
 D:\zwtymj\xccb\ljj\cqzlyaszjvlsjmkwoqijggmybr 645
 复制
 输出：
 rzuwnjvnuz 633 1
 atl 637 1
 rwyfvzsopsuiqjnr 647 1
 eez 648 1
 fmwafhhgeyawnool 649 1
 c 637 1
 f 633 1
 ywzqaop 631 2
 复制
 说明：
 由于D:\cfmwafhhgeyawnool 649的文件名长度超过了16个字符，达到了17，所以第一个字符'c'应该被忽略。
 记录F:\fop\ywzqaop 631和F:\yay\jc\ywzqaop 631由于文件名和行号相同，因此被视为同一个错误记录，哪怕它们的路径是不同的。
 由于循环记录时，只以第一次出现的顺序为准，后面重复的不会更新它的出现时间，仍以第一次为准，所以D:\zwtymj\xccb\ljj\cqzlyaszjvlsjmkwoqijggmybr 645不会被记录。 (在做题时审题花了很长时间，就是这一句当时半天没明白)
 */
//  Created by gmy on 2023/8/3.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <map>

using namespace std;

//vector<string> split(string str, char div) {
//    vector<string> strs;
//    string tmpS = "";
//    for (char ch : str) {
//        if (ch == div) {
//            strs.push_back(tmpS);
//            tmpS.clear();
//        } else {
//            tmpS += ch;
//        }
//    }
//    if (str.length() > 0 && str[str.length() - 1] != div) {
//        strs.push_back(tmpS);
//    }
//    return strs;
//}
//
//int main() {
//    string str;
//    unordered_map<string, int> stringMaps;
//    vector<string> strings;
//    while (getline(cin, str)) {
//        vector<string> strs = split(str, '\\');
//        string targetStr = strs[strs.size() - 1];
//        vector<string> subTargetStrs = split(targetStr, ' ');
//        if (subTargetStrs[0].length() > 16) {
//            targetStr = subTargetStrs[0].substr(subTargetStrs[0].length() - 16, 16) + ' ' + subTargetStrs[1];
//        }
//        if (!stringMaps[targetStr]) {
//            strings.push_back(targetStr);
//        }
//        stringMaps[targetStr]++;
//    }
//    int j = strings.size() > 8 ? (strings.size() - 8) : 0;
//    for (int i = j; i < strings.size(); i++) {
//        cout << strings[i] << " " << stringMaps[strings[i]] << endl;
//    }
//}
// 64 位输出请用 printf("%lld")

// 使用queue比vector更好
int main() {
    string str;
    map<string, int> result;
    deque<string> deq;
    while (getline(cin, str)) {
        str = str.substr(str.find_last_of('\\') + 1); // 巧用find_last_of
        int pos = str.find_last_of(' ');
        if ( pos > 16) {
            str = str.substr(pos - 16);
        }
 
        if (result.find(str) == result.end()) deq.push_back(str);
        ++result[str];
        if (deq.size() > 8) deq.pop_front();
    }
    for (auto x : deq) {
        cout << x << " " << result[x] << endl;
    }
    return 0;
}
