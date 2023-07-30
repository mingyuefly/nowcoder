//
//  main.cpp
//  sentenceReverse
//
/**
 描述
 将一个英文语句以单词为单位逆序排放。例如“I am a boy”，逆序排放后为“boy a am I”

 所有单词之间用一个空格隔开，语句中除了英文字母外，不再包含其他字符

 数据范围：输入的字符串长度满足
 1
 ≤
 �
 ≤
 1000
  
 1≤n≤1000

 注意本题有多组输入
 输入描述：
 输入一个英文语句，每个单词用空格隔开。保证输入只包含空格和字母。

 输出描述：
 得到逆序的句子

 示例1
 输入：
 I am a boy
 复制
 输出：
 boy a am I
 复制
 示例2
 输入：
 nowcoder
 复制
 输出：
 nowcoder
 */
//  Created by gmy on 2023/7/30.
//

#include <iostream>
#include <vector>

using namespace std;

//int main() {
//    string str;
//    getline(cin, str);
//    int length = str.length();
//    vector<string> strs;
//    string tmpS = "";
//    for(char ch : str) {
//        if (ch == ' ') {
//            strs.push_back(tmpS);
//            tmpS.clear();
//        } else {
//            tmpS += ch;
//        }
//    }
//    strs.push_back(tmpS);
//    while (!strs.empty()) {
//        cout << strs.back() << " ";
//        strs.pop_back();
//    }
//    cout << endl;
//}
// 64 位输出请用 printf("%lld")

int main(){
    string str,newstr("");
    getline(cin,str);
    int j = str.length();
    for(int i = str.length() - 1; i >= 0; i--){
        if(str[i] == ' '){
            newstr += str.substr(i + 1,j - 1 - i);
            newstr += ' ';
            j = i;
        }
        if(i == 0)
            newstr += str.substr(0,j);
    }
    cout << newstr << endl;
    return 0;
}
