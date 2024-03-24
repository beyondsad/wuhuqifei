//在输入的字符串里找到最大的质数子串                                           
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// 判断一个数是否是质数
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    string digits;
    while (cin >> digits) {
        string maxPrimeSubstr;
        int maxLen = 0;
        // 遍历所有可能的子串
        for (int i = 0; i < digits.length(); ++i) {
            for (int len = 1; len <= 4 && i + len <= digits.length(); ++len) {
                string substr = digits.substr(i, len);
                int num = stoi(substr);
                // 判断子串是否是质数
                if (isPrime(num) && len > maxLen) {
                    maxLen = len;
                    maxPrimeSubstr = substr;
                }
            }
        }
        cout << maxPrimeSubstr << endl;
    }
    return 0;
}
