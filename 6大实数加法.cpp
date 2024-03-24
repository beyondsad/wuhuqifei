#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 大数加法
vector<int> add(const vector<int>& A, const vector<int>& B) {
    int carry = 0;
    vector<int> sum;
    int i = A.size() - 1, j = B.size() - 1;
    
    while (i >= 0 || j >= 0 || carry) {
        if (i >= 0) {
            carry += A[i];
            i--;
        }
        if (j >= 0) {
            carry += B[j];
            j--;
        }
        sum.push_back(carry % 10);
        carry /= 10;
    }
    
    // 去除前导0
    while (sum.size() > 1 && sum.back() == 0) {
        sum.pop_back();
    }
    
    // 反转结果
    reverse(sum.begin(), sum.end());
    
    return sum;
}

// 字符串转换为向量
vector<int> strToVector(const string& s) {
    vector<int> v;
    for (char c : s) {
        if (isdigit(c)) {
            v.push_back(c - '0');
        }
    }
    return v;
}

// 向量转换为字符串
string vectorToStr(const vector<int>& v) {
    string s;
    for (int digit : v) {
        s.push_back(digit + '0');
    }
    return s;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string strA, strB;
        cin >> strA >> strB;
        
        vector<int> A = strToVector(strA);
        vector<int> B = strToVector(strB);
        
        vector<int> sum = add(A, B);
        
        cout << vectorToStr(sum) << endl;
    }
    return 0;
}
