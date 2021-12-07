#include<iostream>
#include<vector>
#include<string>
#include<limits.h>
#include<algorithm>
#include<numeric>
#include<unordered_set>
#include<unordered_map>
#include<cmath>
using namespace std;
/*

给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
*/

/*
优化竖式

其实在相乘或者相加计算过程的每一位，我们可以考虑先不去满10进位，等到计算完所有的相乘结果以后，
最终将其加到一块，再去满10进位 ，最后的结果和普通竖式 一样，但却可以大大简化我们的模拟过程。(如下图所示)


具体过程如下：
1、长度是n和长度是m的数字相乘，最多只有n + m位，为了方便计算，将num1和num2反向存储到A[]和B[]中，即位数低的在数组前面，且开一个大小是n + m的C[]存储计算后的答案。
2、两个数相乘时，将A[i] * B[j]的结果累加到C[i + j]中，最后C[i + j]表示i + j这个位数的值是C[i + j](如上图所示)
3、由于C[]数组中的某些位数字可能是大于等于10的，我们从0枚举到n + m - 1，进行满10进位， 将所有位的值全部变成个位数。
4、最后将C[]数组反转输出。
细节：

最终得到的数组C[]的高位可能包含前导0，因此在反转之前要先去除高位前导0。

*/
class Solution {
 public:
  string multiply(string num1, string num2) {
    vector<int> A, B;
    int n = num1.size(), m = num2.size();
    //将数字反向存储
    for (int i = n - 1; i >= 0; i --) {
      A.push_back(num1[i] - '0');  //反向存贮
    }
    for (int i = m - 1; i >= 0; i --) {
      B.push_back(num2[i] - '0');
    }
    vector<int> C(n + m);
    for (int i = 0; i < n; i ++)
      for (int j = 0; j < m; j ++) {
        C[i + j] += A[i] * B[j];
      }
    //每个位置相乘后的乘积存储起来
    int t = 0;  //存贮进位
    for (int i = 0; i < C.size(); i ++) {
      t += C[i];
      C[i] = t % 10;
      t /= 10;
    }
    int k = C.size() - 1;
    while (k > 0 && !C[k]) {
      k -- ;  //去除前导0
    }
    string res;
    while (k >= 0) {
      res += C[k -- ] + '0';  //反转
    }
    return res;
  }
};

int main() {
  int n = 101;
  string num1 = "123";
  string num2 = "134";
  Solution app;
  string ans = app.multiply(num1, num2);
  cout << ans << endl;
  return 0;
}