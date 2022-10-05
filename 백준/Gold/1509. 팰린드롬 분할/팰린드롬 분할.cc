#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <tuple>
#include <functional>
#include <map>
#include <set>
#include <cstring>
#include <array>
#include <climits>
#include <cstdlib>
#include <utility>
#include <regex>
#include <numeric>
#include <cctype>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <typeinfo>
#include <cstdlib>
#include <unordered_map>
#include <cfloat>

using namespace std;

string s;
bool dp[2501][2501];
int result[2501];

void isPalindrome() {
    for (int i = 2; i < s.length(); i++) { // 문자열 간격 (3개 문자열 팰린드롬 확인부터 시작)
        for (int j = 1; j < s.length() - i; j++) { // 문자열 시작 지점
            if (s[j] == s[j + i] && dp[j + 1][j + i - 1]) { // 가장 끝 문자가 같고, 그 안에 문자열이 팰린드롬이면 새로운 문자열도 팰린드롬이다.
                dp[j][j + i] = dp[j + i][j] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> s;
    s = ' ' + s;

    // 길이 1은 무조건 팰린드롬
    for (int i = 1; i <= s.length(); i++) {
        dp[i][i] = true;
    }

    // 길이 2는 서로 같다면 무조건 팰린드롬
    for (int i = 1; i <= s.length(); i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = dp[i + 1][i] = true;
        }
    }

    // 길이 3 이상 팰린드롬 구하기
    isPalindrome();

    for (int i = 1; i <= s.length(); i++) {
        for (int j = 1; j <= i; j++) {
            if (dp[i][j]) {
                if (result[i] == 0 || result[i] > result[j - 1] + 1) {
                    result[i] = result[j - 1] + 1;
                }
            }
        }
    }

    cout << result[s.length() - 1];

    return 0;
}