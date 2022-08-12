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

using namespace std;

string s1;
string s2;
int DP[41][41];
vector<char> v;

void solve(int x, int y) {
    if (x == 0 || y == 0) return;

    if (DP[x][y] == DP[x - 1][y]) {
        solve(x - 1, y);
    }
    else if (DP[x][y] == DP[x][y - 1]) {
        solve(x, y - 1);
    }
    else {
        v.push_back(s1[x - 1]);
        solve(x - 1, y - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> s1;
    cin >> s2;

    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            else {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }
    
    solve(s1.length(), s2.length());

    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i];
    }

    return 0;
}