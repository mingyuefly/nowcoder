//
//  main.cpp
//  coordinateMove
//
//  Created by gmy on 2023/7/31.
//

#include <iostream>
#include <vector>
#include <set>
#include <regex>

using namespace std;

//int main() {
//    string str;
//    getline(cin, str);
//    vector<int> coordinate = vector<int>(2, 0);
//    vector<string> strs;
//    string tmpS;
//    for(char ch : str) {
//        if (ch == ';') {
//            strs.push_back(tmpS);
//            tmpS.clear();
//        } else {
//            tmpS += ch;
//        }
//    }
//    set<char> firstChs = {'A', 'D', 'W', 'S'};
//    for (string s : strs) {
////        if (s.length() == 0) {
////            // 字符串为空串
////            continue;
////        }
//        if (s.length() > 3 || s.length() <= 1) {
//            // 字符串太长或太短不合法
//            continue;
//        }
//        char direction;
//        if (!firstChs.count(s[0]) != 0) {
//            // 首字母不合法
//            continue;
//        } else {
//            direction = s[0];
//        }
//        int stride = 0;
//        if (s.length() == 2) {
//            // 字符串两位
//            if (!isdigit(s[1])) {
//                continue;
//            } else {
//                stride = (int)s[1] - 48;
//            }
//        } else {
//            // 字符串三位
//            if ((!isdigit(s[1]) || (!isdigit(s[2])))) {
//                // 第二位或第三位不是数字
//                continue;
//            } else {
//                stride = ((int)s[1] - 48) * 10 + ((int)s[2] - 48);
//            }
//        }
//        // 移动坐标
//        switch ((int)direction) {
//            case (int)'A':
//                coordinate[0] -= stride;
//                break;
//            case (int)'D':
//                coordinate[0] += stride;
//                break;
//            case (int)'W':
//                coordinate[1] += stride;
//                break;
//            case (int)'S':
//                coordinate[1] -= stride;
//                break;
//            default:
//                break;
//        }
//    }
//    cout << coordinate[0] << "," << coordinate[1] << endl;
//}
// 64 位输出请用 printf("%lld")

// 正则表达式求解
int main(){
    string s;
    getline(cin,s);
    int x = 0, y = 0;
    int j = 0;
    for(int i = 0;i < s.size(); ++i)
    {
        if(s[i] == ';')
        {
            string t = s.substr(j,i-j);
            regex pattern("^([ASWD]{1})(\\d{1,2})$");
            smatch result;
            bool flag=regex_match(t, result, pattern);
            if(flag)
            {
                if (result[1]=='A') x -= stoi(result[2]);
                else if(result[1]=='D') x += stoi(result[2]);
                else if(result[1]=='S') y -= stoi(result[2]);
                else if(result[1]=='W') y += stoi(result[2]);
            }
            while(i < s.size() && s[i+1] == ';') ++i;
            j = i + 1;
        }
    }
    cout << x << ',' << y <<endl;
}
