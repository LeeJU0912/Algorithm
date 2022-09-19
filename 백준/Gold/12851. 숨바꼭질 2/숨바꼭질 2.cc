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

using namespace std;

int N, K;
int temp[300001];
int ans1 = INT_MAX;
int ans2;

void solve() {
    queue<pair<int, int>> q;

    q.push({N, 0});

    while(!q.empty()) {
        int now = q.front().first;
        int minute = q.front().second;
        q.pop();

        if (N < K) {
            if (now > K * 2) continue;
        }
        if (now < 0) continue;

        if (temp[now] != 0 && temp[now] < minute) continue;

        temp[now] = minute;

        if (now > K) {
            q.push({now - 1, minute + 1});
        }
        else if (now < K) {
            q.push({now - 1, minute + 1});
            q.push({now * 2, minute + 1});
            q.push({now + 1, minute + 1});
        }
        else {
            if (ans1 == minute) {
                ans2++;
            }
            else {
                ans1 = min(minute, ans1);
                ans2 = 1;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> K;

    solve();

    cout << ans1 << '\n';
    cout << ans2;

    return 0;
}