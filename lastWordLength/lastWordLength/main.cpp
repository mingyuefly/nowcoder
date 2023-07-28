//
//  main.cpp
//  lastWordLength
//
/**
 描述
 计算字符串最后一个单词的长度，单词以空格隔开，字符串长度小于5000。（注：字符串末尾不以空格为结尾）
 输入描述：
 输入一行，代表要计算的字符串，非空，长度小于5000。
 
 输出描述：
 输出一个整数，表示输入字符串最后一个单词的长度。
 
 示例1
 输入：
 hello nowcoder
 复制
 输出：
 8
 复制
 说明：
 最后一个单词为nowcoder，长度为8
 */
//  Created by gmy on 2023/7/28.
//

#include <iostream>

using namespace std;

int lastWordLength(string str) {
    vector<string> ans;
    string tmpString;
    for (char c : str) {
        if (c == ' ') {
            ans.push_back(std::move(tmpString));
            tmpString.clear();
        } else {
            tmpString += c;
        }
    }
    
    return (int)tmpString.length();
}

int lastWordLength1(string s) {
    int ans = 0, i = (int)s.length()-1;
    while(i >= 0 && s[i] != ' ')
    {
        i--;
        ans++;
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    //    cout << lastWordLength("hello world") << endl;
    string str;
    // 输入一行字符串
    getline(cin, str);
    cout << lastWordLength1(str) << endl;
    
    
    //    int a, b;
    //    while (cin >> a >> b) { // 注意 while 处理多个 case
    //        cout << a + b << endl;
    //    }
    return 0;
}
