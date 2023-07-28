//
//  main.cpp
//  charNums
//
/**
 描述
 写出一个程序，接受一个由字母、数字和空格组成的字符串，和一个字符，然后输出输入字符串中该字符的出现次数。（不区分大小写字母）

 数据范围：
 1
 ≤
 �
 ≤
 1000
  
 1≤n≤1000
 输入描述：
 第一行输入一个由字母、数字和空格组成的字符串，第二行输入一个字符（保证该字符不为空格）。

 输出描述：
 输出输入字符串中含有该字符的个数。（不区分大小写字母）

 示例1
 输入：
 ABCabc
 A
 复制
 输出：
 2
 */
//  Created by gmy on 2023/7/29.
//
// 解法1和解法2在牛客网上8 8 8  8A i i OOI              IIIaa用例过不去，不知道原因


#include <iostream>

using namespace std;

int charNums(string s, char c) {
    int count = 0;
    c = tolower(c);
    for(char c1 : s) {
        c1 = tolower(c1);
        if (c1 == c) {
            count++;
        }
    }
    return count;
}

int charNums1(string s, char ch) {
    int cnt=0;
    
    for(int i = 0; i<s.length();i++)
    {
        if(s[i]>='A' && s[i] <= 'Z')
        {
            if(s[i] == ch || s[i] == ch-32)
            {
                cnt++;
            }
        }
        else if(s[i]>='a' && s[i] <= 'z')
        {
            if(s[i] == ch || s[i]== ch+32)
            {
                cnt++;
            }
        }
        else if (s[i] == ch)
        {
            cnt++;
        }
    }
    return cnt;
}

int charNums2(string s, char ch) {
    unordered_map<char, size_t> unorderedMap;
    for(auto i : s) {
        ++unorderedMap[towlower(i)];
    }
    return unorderedMap[tolower(ch)];
}

int main(int argc, const char * argv[]) {
    
    string str;
    getline(cin, str);
    char c;
    cin>>c;
    cout << charNums2(str, c) << endl;
    
    //    8 8 8  8A i i OOI              IIIaa
    
    return 0;
}
