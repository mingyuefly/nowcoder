//
//  main.cpp
//  deRepeationNum
//
/**
 描述
 输入一个 int 型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。
 保证输入的整数最后一位不是 0 。

 数据范围：
 1
 ≤
 �
 ≤
 1
 0
 8
  
 1≤n≤10
 8
   
 输入描述：
 输入一个int型整数

 输出描述：
 按照从右向左的阅读顺序，返回一个不含重复数字的新的整数

 示例1
 输入：
 9876673
 复制
 输出：
 37689
 复制

 */
//  Created by gmy on 2023/7/29.
//

#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//int main() {
//    int num;
//    cin >> num;
//    unordered_map<int, bool> numsMap;
//    int resNum = 0;
//    while (num > 0) {
//        int num1 = num % 10;
//        num /= 10;
//        if (numsMap[num1]) {
//            continue;
//        } else {
//            numsMap[num1] = true;
//            resNum = resNum * 10 + num1;
//        }
//    }
//    cout << resNum << endl;
//}


//int main() {
//    int num;
//    cin >> num;
//    unordered_map<int, bool> numsMap;
//    int resNum = 0;
//    while (num > 0) {
//        int num1 = num % 10;
//        num /= 10;
//        if (numsMap[num1]) {
//            continue;
//        } else {
//            numsMap[num1] = true;
//            cout << num1;
//        }
//    }
//    cout << endl;
//}

int main() {
    int num;
    cin >> num;
    unordered_set<int> numsSet;
    while (num > 0) {
        int num1 = num % 10;
        num /= 10;
        // newcoder 编译失败：error: no member named 'contains' in 'std::unordered_set
//        if (numsSet.contains(num1)) {
//            continue;
//        } else {
//            numsSet.insert(num1);
//            cout << num1;
//        }
        
        if (numsSet.count(num1) != 0) {
            continue;
        } else {
            numsSet.insert(num1);
            cout << num1;
        }
    }
    cout << endl;
}

