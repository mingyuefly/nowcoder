//
//  main.cpp
//  mergeTable
//
/**
 描述
 数据表记录包含表索引index和数值value（int范围的正整数），请对表索引相同的记录进行合并，即将相同索引的数值进行求和运算，输出按照index值升序进行输出。
 
 
 提示:
 0 <= index <= 11111111
 1 <= value <= 100000
 
 输入描述：
 先输入键值对的个数n（1 <= n <= 500）
 接下来n行每行输入成对的index和value值，以空格隔开
 
 输出描述：
 输出合并后的键值对（多行）
 
 示例1
 输入：
 4
 0 1
 0 2
 1 2
 3 4
 复制
 输出：
 0 3
 1 2
 3 4
 复制
 示例2
 输入：
 3
 0 1
 0 2
 8 9
 复制
 输出：
 0 3
 8 9
 */
//  Created by gmy on 2023/7/29.
//

#include <iostream>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;
    map<int, int> table;
    while (N > 0) {
        int index, value;
        cin >> index >> value;
        table[index] += value;
        N--;
    }
    for(pair<int, int> pair : table) {
        cout << pair.first << " " << pair.second << endl;
    }
}

//int main() {
//    int n;
//    cin>>n;    //输入键值对的个数
//    map<int, int> m;    //使用map容器，自带键值对数据结构
//    map<int, int>::iterator it;    //map类型的迭代器
//    for(int i=0;i<n;i++) {
//        int a,b;
//        cin>>a>>b;        //每行输入一个键值对
//        it = m.find(a);    //查找键a是否存在
//        if(it != m.end()) {    //如果存在，对键相同的单元的值部分进行求和；
//            m[a] = it->second + b;
//        }else {        //如果不存在生成新的键值对
//            m[a] = b;
//        }
//    }
//    for(it=m.begin();it!=m.end();it++) {    //遍历打印
//        cout<<it->first<<" "<<it->second<<endl;
//    }
//    return 0;
//}
