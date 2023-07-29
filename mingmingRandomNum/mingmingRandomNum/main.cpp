//
//  main.cpp
//  mingmingRandomNum
//
//  Created by gmy on 2023/7/29.
//

#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
//    vector<int> nums;
    map<int, bool> numMap;
    while (N > 0) {
        int n;
        cin >> n;
//        nums.push_back(n);
        numMap[n] = true;
        N--;
    }
    // map 遍历
    for(pair<int, bool> kv: numMap) {
        cout << kv.first << endl;
    }
    
    
    return 0;
}
