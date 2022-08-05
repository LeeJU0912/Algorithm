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

using namespace std;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string s;

    cin >> s;

    int temp = 0;
    int ans = 0;

    bool flag = false;

    for (int i = 0; i <= s.size(); i++) {
        if (s[i] == '+' || s[i] == '-' || i == s.size()) {
            if (flag == false) {
                ans += temp;
                temp = 0;
            }
            else if (flag == true) {
                ans -= temp;
                temp = 0;
            }
            if (s[i] == '-') {
                flag = true;
            }
        }
        else {
            temp = 10 * temp;
            temp += s[i] - '0';
        }
    }

    cout << ans;

    return 0;
}