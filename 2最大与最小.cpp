//输入m,n为输入m个数字，判断n个连续的数字的和的最大值，最小值
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
int m,n,num;
  while(cin>>m>>n){
  int max=-1000;
    int min=99999;
   vector<int> res;
    int f=0;
    int sum=0;
    for (int i = 0; i < m; ++i) {
            cin >> num;
            res.push_back(num);
            if (i < n) {
                sum += num; 
            }
        }
    max=sum;
    min=sum;
    for (int i = n; i < m + n; ++i) {
            sum += res[i % m];
            sum -= res[f];
            f = (f + 1) % m;
            if (sum > max) max = sum;
            if (sum < min) min = sum;
        }
    cout<<"Max"<<"="<<max<<endl;
    cout<<"Min"<<"="<<min<<endl;
  }

  return 0;
}
