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

string N;
int chk[10];
int ans = 1;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N.length(); i++) {
        if (N[i] == '6') {
            if (chk[6] == ans) {
                if (chk[9] != ans) {
                    chk[9]++;
                }
                else {
                    chk[6]++;
                    ans++;
                }
            }
            else {
                chk[6]++;
            }
        }
        else if (N[i] == '9') {
            if (chk[9] == ans) {
                if (chk[6] != ans) {
                    chk[6]++;
                }
                else {
                    chk[9]++;
                    ans++;
                }
            }
            else {
                chk[9]++;
            }
        }
        else {
            if (chk[N[i] - '0'] == ans) {
                chk[N[i] - '0']++;
                ans++;
            }
            else {
                chk[N[i] - '0']++;
            }
        }
    }

    cout << ans;

    return 0;
}