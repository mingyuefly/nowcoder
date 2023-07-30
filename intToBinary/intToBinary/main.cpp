//
//  main.cpp
//  intToBinary
//
/**
 描述
 输入一个 int 型的正整数，计算出该 int 型数据在内存中存储时 1 的个数。
 
 数据范围：保证在 32 位整型数字范围内
 输入描述：
 输入一个整数（int类型）
 
 输出描述：
 这个数转换成2进制后，输出1的个数
 
 示例1
 输入：
 5
 复制
 输出：
 2
 复制
 示例2
 输入：
 0
 复制
 输出：
 0
 */
//  Created by gmy on 2023/7/30.
//

#include <iostream>
#include <bitset>
using namespace std;

// 位运算
//int main() {
//    int a;
//    cin >> a;
//    int count = 0;
//    while (a > 0) {
//        if ((a & 1) == 1) {
//            count++;
//        }
//        a >>= 1;
//    }
//    cout << count << endl;
//}
// 64 位输出请用 printf("%lld")

//
//int main() {
//    int n;
//    cin >> n;
//    int m = 0;
//    while(n)
//    {
//        // 对2取余，类似于求十进制各位数字
//        m += n % 2;
//        n /= 2;
//    }
//    cout << m << endl;
//}

int main(){
    int n;
    cin >> n;
    bitset<32> b(n);
    cout << b.count() << endl;
}
