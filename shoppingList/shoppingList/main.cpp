//
//  main.cpp
//  shoppingList
//
/**
 描述
 王强决定把年终奖用于购物，他把想买的物品分为两类：主件与附件，附件是从属于某个主件的，下表就是一些主件与附件的例子：
 主件    附件
 电脑    打印机，扫描仪
 书柜    图书
 书桌    台灯，文具
 工作椅    无
 如果要买归类为附件的物品，必须先买该附件所属的主件，且每件物品只能购买一次。
 每个主件可以有 0 个、 1 个或 2 个附件。附件不再有从属于自己的附件。
 王强查到了每件物品的价格（都是 10 元的整数倍），而他只有 N 元的预算。除此之外，他给每件物品规定了一个重要度，用整数 1 ~ 5 表示。他希望在花费不超过 N 元的前提下，使自己的满意度达到最大。
 满意度是指所购买的每件物品的价格与重要度的乘积的总和，假设设第
 �
 i件物品的价格为
 �
 [
 �
 ]
 v[i]，重要度为
 �
 [
 �
 ]
 w[i]，共选中了
 �
 k件物品，编号依次为
 �
 1
 ,
 �
 2
 ,
 .
 .
 .
 ,
 �
 �
 j
 1
 ​
 ,j
 2
 ​
 ,...,j
 k
 ​
 ，则满意度为：
 �
 [
 �
 1
 ]
 ∗
 �
 [
 �
 1
 ]
 +
 �
 [
 �
 2
 ]
 ∗
 �
 [
 �
 2
 ]
 +
 …
 +
 �
 [
 �
 �
 ]
 ∗
 �
 [
 �
 �
 ]
 v[j
 1
 ​
 ]∗w[j
 1
 ​
 ]+v[j
 2
 ​
 ]∗w[j
 2
 ​
 ]+…+v[j
 k
 ​
 ]∗w[j
 k
 ​
 ]。（其中 * 为乘号）
 请你帮助王强计算可获得的最大的满意度。
 
 
 输入描述：
 输入的第 1 行，为两个正整数N，m，用一个空格隔开：
 
 （其中 N （ N<32000 ）表示总钱数， m （m <60 ）为可购买的物品的个数。）
 
 
 从第 2 行到第 m+1 行，第 j 行给出了编号为 j-1 的物品的基本数据，每行有 3 个非负整数 v p q
 
 
 （其中 v 表示该物品的价格（ v<10000 ）， p 表示该物品的重要度（ 1 ~ 5 ）， q 表示该物品是主件还是附件。如果 q=0 ，表示该物品为主件，如果 q>0 ，表示该物品为附件， q 是所属主件的编号）
 
 
 
 
 输出描述：
 输出一个正整数，为张强可以获得的最大的满意度。
 示例1
 输入：
 1000 5
 800 2 0
 400 5 1
 300 5 1
 400 3 0
 500 2 0
 复制
 输出：
 2200
 复制
 示例2
 输入：
 50 5
 20 3 5
 20 3 5
 10 3 0
 10 2 0
 10 1 0
 复制
 输出：
 130
 复制
 说明：
 由第1行可知总钱数N为50以及希望购买的物品个数m为5；
 第2和第3行的q为5，说明它们都是编号为5的物品的附件；
 第4~6行的q都为0，说明它们都是主件，它们的编号依次为3~5；
 所以物品的价格与重要度乘积的总和的最大值为10*1+20*3+20*3=130
 */
//  Created by gmy on 2023/7/30.
//

#include <iostream>
using namespace std;

int main() {
    int N, m;
    cin >> N >> m;
    // 由于价格是10的整数倍，处理一下以降低空间/时间复杂度
    N /= 10;
    // 条件约束：总物品总数小于60，可以直接确定数组长度为61
    vector<vector<int> > prices(61, vector<int>(3, 0));        // 价格
    vector<vector<int> > priceMultiplyPriority(61, vector<int>(3, 0));      // 重要程度
    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        // 两个条件约束：价格是10的倍数，每件物品只能够买一次（可以归约到0-1背包问题）
        a /= 10; b *= a;
        if (c == 0) {
            prices[i][0] = a; priceMultiplyPriority[i][0] = b;
        } else {
            if (prices[c][1] == 0) {
                prices[c][1] = a; priceMultiplyPriority[c][1] = b;
            } else {
                prices[c][2] = a; priceMultiplyPriority[c][2] = b;
            }
        }
    }
    // 使用分组背包
    vector<vector<int> > dp(m+1, vector<int>(N+1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= N; ++j) {
            int a = prices[i][0], b = priceMultiplyPriority[i][0];
            int c = prices[i][1], d = priceMultiplyPriority[i][1];
            int e = prices[i][2], f = priceMultiplyPriority[i][2];
            // 不选择配件 
            dp[i][j] = j >= a ? max(dp[i-1][j-a] + b, dp[i-1][j]) : dp[i-1][j];
            // 选择一个配件
            dp[i][j] = j >= (a+c) ? max(dp[i-1][j-a-c] + b + d, dp[i][j]) : dp[i][j];
            dp[i][j] = j >= (a+e) ? max(dp[i-1][j-a-e] + b + f, dp[i][j]) : dp[i][j];
            // 选择两个配件
            dp[i][j] = j >= (a+c+e) ? max(dp[i-1][j-a-c-e] + b + d + f, dp[i][j]) : dp[i][j];
        }
    }
    cout << dp[m][N] * 10 << endl;
}
// 64 位输出请用 printf("%lld")
