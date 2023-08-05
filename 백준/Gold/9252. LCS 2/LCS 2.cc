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
int LCS[1001][1001];

vector<char> v;

void length(int x, int y) {
    if (x == 0 || y == 0) return;
    if (LCS[x][y] == LCS[x - 1][y]) {
        length(x - 1, y);
    }
    else if (LCS[x][y] == LCS[x][y - 1]) {
        length(x, y - 1);
    }
    else {
        v.push_back(s1[x - 1]);
        length(x - 1, y - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> s1;
    cin >> s2;

    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (i == 0 && j == 0) LCS[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1]) {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            }
            else {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }

    length(s1.size(), s2.size());


    cout << LCS[s1.size()][s2.size()] << '\n';

    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i];
    }

    return 0;
}