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
#include <list>

using namespace std;

int N;
int board[21][21];
bool hap[21];
int ans = INT_MAX;

void solve(int idx, int counter) {

    if (idx == N && counter < N / 2) return;
    if (counter == N / 2) {
        int temp = 0;
        int temp2 = 0;
        for (int i = 1; i <= N; i++) {
            if (hap[i]) {
                for (int j = 1; j <= N; j++) {
                    if (hap[j]) {
                        temp += board[i][j];
                    }
                }
            }
            else {
                for (int j = 1; j <= N; j++) {
                    if (!hap[j]) {
                        temp2 += board[i][j];
                    }
                }
            }
        }
        ans = min(ans, abs(temp - temp2));
        return;
    }



    for (int i = idx + 1; i <= N; i++) {
        hap[i] = true;
        solve(i, counter + 1);
        hap[i] = false;
    }



}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= N / 2 + 1; i++) {
        hap[i] = true;
        solve(i, 1);
        hap[i] = false;
    }

    cout << ans;


    return 0;
}