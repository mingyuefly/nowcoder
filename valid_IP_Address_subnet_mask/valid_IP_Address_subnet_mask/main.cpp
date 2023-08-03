//
//  main.cpp
//  valid_IP_Address_subnet_mask
//
/**
 描述
 请解析IP地址和对应的掩码，进行分类识别。要求按照A/B/C/D/E类地址归类，不合法的地址和掩码单独归类。
 
 所有的IP地址划分为 A,B,C,D,E五类
 
 A类地址从1.0.0.0到126.255.255.255;
 
 B类地址从128.0.0.0到191.255.255.255;
 
 C类地址从192.0.0.0到223.255.255.255;
 
 D类地址从224.0.0.0到239.255.255.255；
 
 E类地址从240.0.0.0到255.255.255.255
 
 
 私网IP范围是：
 
 从10.0.0.0到10.255.255.255
 
 从172.16.0.0到172.31.255.255
 
 从192.168.0.0到192.168.255.255
 
 
 子网掩码为二进制下前面是连续的1，然后全是0。（例如：255.255.255.32就是一个非法的掩码）
 （注意二进制下全是1或者全是0均为非法子网掩码）
 
 注意：
 1. 类似于【0.*.*.*】和【127.*.*.*】的IP地址不属于上述输入的任意一类，也不属于不合法ip地址，计数时请忽略
 2. 私有IP地址和A,B,C,D,E类地址是不冲突的
 
 输入描述：
 多行字符串。每行一个IP地址和掩码，用~隔开。
 
 请参考帖子https://www.nowcoder.com/discuss/276处理循环输入的问题。
 输出描述：
 统计A、B、C、D、E、错误IP地址或错误掩码、私有IP的个数，之间以空格隔开。
 
 示例1
 输入：
 10.70.44.68~255.254.255.0
 1.0.0.1~255.0.0.0
 192.168.0.2~255.255.255.0
 19..0.~255.255.255.0
 复制
 输出：
 1 0 1 0 0 2 1
 复制
 说明：
 10.70.44.68~255.254.255.0的子网掩码非法，19..0.~255.255.255.0的IP地址非法，所以错误IP地址或错误掩码的计数为2；
 1.0.0.1~255.0.0.0是无误的A类地址；
 192.168.0.2~255.255.255.0是无误的C类地址且是私有IP；
 所以最终的结果为1 0 1 0 0 2 1
 示例2
 输入：
 0.201.56.50~255.255.111.255
 127.201.56.50~255.255.111.255
 复制
 输出：
 0 0 0 0 0 0 0
 复制
 说明：
 类似于【0.*.*.*】和【127.*.*.*】的IP地址不属于上述输入的任意一类，也不属于不合法ip地址，计数时请忽略
 */
//  Created by gmy on 2023/8/3.
//



#include <iostream>
#include <vector>
#include<sstream>

using namespace std;

// 方法1
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
//bool isSubnetMask(string mask) {
//    vector<string> subMasks = split(mask, '.');
//    if (subMasks.size() != 4) {
//        return false;
//    }
//    vector<int> subMaskNums;
//    for (string str : subMasks) {
//        int a = stoi(str);
//        subMaskNums.push_back(a);
//    }
//    if (subMaskNums.size() != 4) {
//        return false;
//    }
//    bool signal = false;
//    for (int i = 0; i < 4; i++) {
//        int sub = subMaskNums[i];
//        if (i == 0 && sub != 255) {
//            // 首位不是255
//            return false;
//        }
//        if ((sub != 255) && (sub != 0)) {
//            return false;
//        }
//        if (sub == 0) {
//            signal = true;
//        }
//        if (signal && sub == 255) {
//            return false;
//        }
//        if (i == 3 && sub == 255) {
//            // 全是255
//            return false;
//        }
//    }
//    return true;
//}
//
//bool isIP(string ipString) {
//    vector<string> subIPs = split(ipString, '.');
//    if (subIPs.size() != 4) {
//        return false;
//    }
//    vector<int> subIPNums;
//    for (string str : subIPs) {
//        int a = stoi(str);
//        if (a > 255 || a < 0) {
//            return false;
//        }
//        subIPNums.push_back(a);
//    }
//    if (subIPNums[0] == 127) {
//        // 127
//        return false;
//    }
//    return true;
//}
//
//char classifyIp(string ipString) {
//    vector<string> subIPs = split(ipString, '.');
//    if (subIPs.size() != 4) {
//        return 'f';
//    }
//    vector<int> subIPNums;
//    for (string str : subIPs) {
//        int a = stoi(str);
//        if (a > 255 || a < 0) {
//            return 'f';
//        }
//        subIPNums.push_back(a);
//    }
//    if (subIPNums[0] == 127) {
//        // 127
//        return 'f';
//    }
//    int first = subIPNums[0];
//    if (first >= 1 && first <= 126) {
//        return 'a';
//    }
//    if (first >= 128 && first <= 191) {
//        return 'b';
//    }
//    if (first >= 192 && first <= 223) {
//        return 'c';
//    }
//    if (first >= 224 && first <= 239) {
//        return 'd';
//    }
//    if (first >= 240 && first <= 255) {
//        return 'e';
//    }
//    return 'e';
//}
//
//bool isPrivateIP(string ipString) {
//    vector<string> subIPs = split(ipString, '.');
//    if (subIPs.size() != 4) {
//        return false;
//    }
//    vector<int> subIPNums;
//    for (string str : subIPs) {
//        int a = stoi(str);
//        if (a > 255 || a < 0) {
//            return false;
//        }
//        subIPNums.push_back(a);
//    }
//    if (subIPNums[0] == 127) {
//        // 127
//        return false;
//    }
//    int first = subIPNums[0];
//    if (first == 10) {
//        return true;
//    }
//    int second = subIPNums[1];
//    if (first == 172 && (second <= 31 && second >= 16)) {
//        return true;
//    }
//    if (first == 192 && second == 168) {
//        return true;
//    }
//    return false;
//}
//
//int main() {
//    int a = 0, b = 0, c = 0, d = 0, e = 0, err = 0, privateIP = 0;
//    string input;
//    while (getline(cin, input)) {
//        vector<string> ipAndMask = split(input, '~');
//        string ip = ipAndMask[0];
//        string mask = ipAndMask[1];
//        if (!isSubnetMask(mask)) {
//            // 子网掩码错误
//            err++;
//        } else {
//            if (!isIP(ip)) {
//                err++;
//            } else {
//                char res = classifyIp(ip);
//                switch (res) {
//                    case 'a':
//                        a++;
//                        break;
//                    case 'b':
//                        b++;
//                        break;
//                    case 'c':
//                        c++;
//                        break;
//                    case 'd':
//                        d++;
//                        break;
//                    case 'e':
//                        e++;
//                        break;
//                }
//                if (isPrivateIP(ip)) {
//                    privateIP++;
//                }
//            }
//        }
//        cout << endl;
//        cout << a << " " << b << " " << c << " " << d << " " << e << " " << err << " " << privateIP << endl;
//    }
//    cout << a << " " << b << " " << c << " " << d << " " << e << " " << err << " " << privateIP << endl;
//}
// 64 位输出请用 printf("%lld")


// 方法2
//bool judge_ip(string ip){
//    int j = 0;
//    istringstream iss(ip);
//    string seg;
//    while(getline(iss,seg,'.'))
//        if(++j > 4 || seg.empty() || stoi(seg) > 255)
//            return false;
//    return j == 4;
//}
//
//bool is_private(string ip){
//    istringstream iss(ip);
//    string seg;
//    vector<int> v;
//    while(getline(iss,seg,'.')) v.push_back(stoi(seg));
//    if(v[0] == 10) return true;
//    if(v[0] == 172 && (v[1] >= 16 && v[1] <= 31)) return true;
//    if(v[0] == 192 && v[1] == 168) return true;
//    return false;
//}
//
//bool is_mask(string ip){
//    istringstream iss(ip);
//    string seg;
//    unsigned b = 0;
//    while(getline(iss,seg,'.')) b = (b << 8) + stoi(seg);
//    if(!b) return false;
//    b = ~b + 1;
//    if(b == 1) return false;
//    if((b & (b-1)) == 0) return true;
//    return false;
//}
//
//int main(){
//    string input;
//    int a = 0,b = 0,c = 0,d = 0,e = 0,err = 0,p = 0;
//    while(cin >> input){
//        istringstream is(input);
//        string add;
//        vector<string> v;
//        while(getline(is,add,'~')) v.push_back(add);
//        if(!judge_ip(v[1]) || !is_mask(v[1])) err++;
//        else{
//            if(!judge_ip(v[0])) err++;
//            else{
//                int first = stoi(v[0].substr(0,v[0].find_first_of('.')));
//                if(is_private(v[0])) p++;
//                if(first > 0 && first <127) a++;
//                else if(first > 127 && first <192) b++;
//                else if(first > 191 && first <224) c++;
//                else if(first > 223 && first <240) d++;
//                else if(first > 239 && first <256) e++;
//            }
//        }
//    }
//    cout << a << " " << b << " " << c << " " << d << " " << e << " " << err << " " << p << endl;
//    return 0;
//}


// 方法3
int main(){
    string mstr;
    //计数变量
    int Aaddress = 0;
    int Baddress = 0;
    int Caddress = 0;
    int Daddress = 0;
    int Eaddress = 0;
    int ErrorIpOrMask = 0;
    int PrivateIP = 0;
    while (getline(cin, mstr)){//循环处理多个字符串
        //**************************************************************************************//
        //获取两个字符串 ， IP地址和子网掩码
        int len = mstr.length();//单个字符串的长度
        int Middle = mstr.find('~'); //查找 ~ 的位置
        string strIp = mstr.substr(0, Middle);//存放单个字符串Ip地址部分//stringA.substr(int startIndex, int needLength)
        string strMask = mstr.substr(Middle + 1, len - Middle- 1 );//存放单个字符串子网掩码部分

        //**************************************************************************************//
        //排除0.*.*.* 和127.*.*.* 的IP地址
        int ipPoint1 = strIp.find('.');
        string ip1 = strIp.substr(0, ipPoint1);
        if(ip1 == "0" || ip1 == "127"){
            continue;
        }

        //**************************************************************************************//
        //判断子网掩码是否正确
        int maskPoint1 = strMask.find( '.' );//查找子网掩码中第1个点
        string mask1 = strMask.substr(0, maskPoint1);
        if( mask1 == "" || stoi(mask1) > 255 ){ //不能为空位
            ErrorIpOrMask++;
            continue;
        }
        bitset<8> bMask1(stoi(mask1)); //将字符串形式的数字转为整型后，获取其8位二进制值

        int maskPoint2 = strMask.find( '.' , maskPoint1 + 1);//从maskPoint1 + 1位置开始，查找子网掩码中第2个点
        string mask2 = strMask.substr(maskPoint1 + 1 , maskPoint2 - maskPoint1 - 1 );
        if( mask2 == "" || stoi(mask2) > 255 ){ //不能为空位
            ErrorIpOrMask++;
            continue;
        }
        bitset<8> bMask2(stoi(mask2));

        int maskPoint3 = strMask.find( '.' ,maskPoint2 + 1);//查找子网掩码中第一个点
        string mask3 = strMask.substr(maskPoint2 + 1, maskPoint3 - maskPoint2 -1 );
        if( mask3 == "" || stoi(mask3) > 255 ){ //不能为空位
            ErrorIpOrMask++;
            continue;
        }
        bitset<8> bMask3(stoi(mask3));

        string mask4 = strMask.substr(maskPoint3+1 , strMask.length() - maskPoint3 -1 );
        if( mask4 == "" || stoi(mask4) > 255 ){ //不能为空位
            ErrorIpOrMask++;
            continue;
        }
        bitset<8> bMask4(stoi(mask4));

        //子网掩码 全0非法 ， 全1 非法
        if(bMask1.count() + bMask2.count() + bMask3.count() + bMask4.count() == 32 ||
          bMask1.count()+ bMask2.count() + bMask3.count() + bMask4.count() == 0){
            ErrorIpOrMask++;
            continue;
        }
        int vMask[32] = {0};//将二进制的子网掩码放入整型数组vMask，用于判断子网掩码中的连续1
        for(int i = 0 ; i< 32 ;i++){
            if(i>=0 && i<= 7){
                vMask[i] = bMask1[7 - i];
            }
            else if(i>=8 && i<= 15){
                vMask[i] = bMask2[ 7 - i + 8];
            }
            else if(i>=16 && i <= 23){
                vMask[i] = bMask3[7 - i+ 16];
            }
            else if(i>=24 && i< 31){
                vMask[i] = bMask4[7- i + 24];
            }
        }

        bool ErrorContinue = false; //判断是否存在连续的1 ，不连续1非法 i,j 双指针判断
        for(int i = 0 , j = 1 ; j < 32 ;  ){
            if(vMask[i] == 0 && vMask[j] == 1){ //对一串子网掩码而言，出现 ****01***即是非法的掩码
                ErrorContinue = true;
                break;
            }
            i++;
            j++;
        }
        if(ErrorContinue){
            ErrorIpOrMask++;
            continue;
        }

        //**********************************************************************************//
        //判断IP地址是否正确
        if(ip1 == "" || stoi(ip1) > 255 ){
            ErrorIpOrMask++;
            continue;
        }

        int ipPoint2 = strIp.find('.' , ipPoint1 +1 );
        string ip2 = strIp.substr(ipPoint1 + 1, ipPoint2 - ipPoint1 - 1);
        if(ip2 == "" || stoi(ip2) > 255){
            ErrorIpOrMask++;
            continue;
        }
        int ipPoint3 = strIp.find('.' , ipPoint2 +1 );
        string ip3 = strIp.substr(ipPoint2 + 1, ipPoint3 - ipPoint2 - 1);
        if(ip3 == "" || stoi(ip3) > 255){
            ErrorIpOrMask++;
            continue;
        }

        string ip4 = strIp.substr(ipPoint3 + 1 , strIp.length() - ipPoint3 - 1);
        if(ip4 == "" || stoi(ip4) > 255){
            ErrorIpOrMask++;
            continue;
        }

        //**************************************************************************************//
        //判断属于哪一类IP地址
        int judge1 = stoi(ip1);
        int judge2 =stoi(ip2);
        if(judge1 >= 1 && judge1 <=126){ // A 类
            Aaddress++;
            if(judge1 == 10){
                PrivateIP++;
            }
        }
        else if(judge1 >= 128 && judge1<= 191){ // B 类
            Baddress++;
            if(judge1 == 172 &&  judge2 >= 16 && judge2 <= 31){
                PrivateIP++;
            }
        }
        else if(judge1 >= 192 && judge1 <= 223){// C 类
            Caddress++;
            if(judge2 == 168){
                PrivateIP++;
            }
        }
        else if(judge1 >= 224 && judge1 <= 239){// D 类
            Daddress++;
        }
        else if(judge1 >= 240 && judge1 <= 255){// E 类
            Eaddress++;
        }

    }

    cout<<Aaddress<<" "<<Baddress<<" "<<Caddress<<" "<<Daddress<<" "<<Eaddress<<" "<<ErrorIpOrMask<<" "<<PrivateIP<<" "<<endl;
}


/**
 225.240.129.203~255.110.255.255
 183.181.49.4~255.0.0.0
 172.177.113.45~255.0.0.0
 176.134.46.246~255.0.0.0
 153.63.21.56~255.255.58.255
 23.135.167.228~255.0.0.0
 204.58.47.149~255.0.0.0
 113.33.181.46~255.255.255.0
 73.245.52.119~255.255.154.0
 23.214.47.71~255.0.0.0
 139.124.188.91~255.255.255.100
 142.94.192.197~255.0.0.0
 53.173.252.202~255.0.0.0
 127.201.56.50~255.255.111.255
 118.251.84.111~255.0.0.0
 130.27.73.170~255.0.0.0
 253.237.54.56~255.86.0.0
 64.189.222.111~255.255.255.139
 148.77.44.147~255.0.0.0
 59.213.5.253~255.255.0.0
 3.52.119.131~255.255.0.0
 213.208.164.145~255.255.0.0
 24.22.21.206~255.255.90.255
 89.43.34.31~255.0.0.0
 9.64.214.75~255.0.0.0
 110.156.20.173~255.153.0.0
 71.183.242.53~255.255.0.0
 119.152.129.100~255.0.0.0
 38.187.119.201~255.0.0.0
 73.81.221.180~255.255.255.255
 73.198.13.199~255.0.15.0
 99.42.142.145~255.255.255.0
 196.121.115.160~255.0.0.0
 226.30.29.206~255.0.0.0
 244.248.31.171~255.255.255.255
 59.116.159.246~255.0.0.0
 121.124.37.157~255.0.0.226
 103.42.94.71~255.255.0.0
 125.88.217.249~255.255.74.255
 73.44.250.101~255.255.255.0
 */
/**
 牛客网上测试：
 这个用例在前两种方法中：
 预期输出：16 6 3 1 0 13 0
 实际输出：16 6 3 1 0 14 0
 第三种方法可以通过
 在我本地调试，三种方法结果都是16 6 3 1 0 14 0，我自己判断也是16 6 3 1 0 14 0，不清楚原因

 */
 
