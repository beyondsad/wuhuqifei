#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 对两个大整数进行相加
vector<int> add(const vector<int>& num1, const vector<int>& num2) {
    int carry = 0;
    int len1 = num1.size(), len2 = num2.size();
    int maxLen = max(len1, len2);
    vector<int> result(maxLen, 0);

    for (int i = 0; i < maxLen; ++i) {
        int digit1 = (i < len1) ? num1[i] : 0;
        int digit2 = (i < len2) ? num2[i] : 0;
        int sum = digit1 + digit2 + carry;
        result[i] = sum % 10;
        carry = sum / 10;
    }

    if (carry > 0) {
        result.push_back(carry);
    }

    return result;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        string strA, strB;
        cin >> strA >> strB;

        // 将字符串表示的大整数转换为向量表示
        vector<int> num1, num2;
        for (int i = strA.size() - 1; i >= 0; --i) {
            num1.push_back(strA[i] - '0');
        }
        for (int i = strB.size() - 1; i >= 0; --i) {
            num2.push_back(strB[i] - '0');
        }

        // 计算大整数的和
        vector<int> sum = add(num1, num2);

        // 输出结果
        cout << "Case " << t << ":" << endl;
        cout << strA << " + " << strB << " = ";
        for (int i = sum.size() - 1; i >= 0; --i) {
            cout << sum[i];
        }
        cout << endl;

        // 输出测试用例之间的空行
        if (t != T) cout << endl;
    }
    return 0;
}

