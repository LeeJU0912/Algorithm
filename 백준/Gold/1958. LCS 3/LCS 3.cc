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
string s3;
int LCS[101][101][101];

vector<char> v;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> s1;
    cin >> s2;
    cin >> s3;

    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            for (int k = 1; k <= s3.length(); k++) {
                if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
                    LCS[i][j][k] = LCS[i - 1][j - 1][k - 1] + 1;
                }
                else {
                    LCS[i][j][k] = max(LCS[i - 1][j][k], max(LCS[i][j - 1][k], LCS[i][j][k - 1]));
                }
            }
        }
    }


    cout << LCS[s1.length()][s2.length()][s3.length()] << '\n';

    return 0;
}