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

int N;
vector<int> v;
int point1;
int point2;
int ans = INT_MAX;

void solve(int cursor1, int cursor2) {
    if (cursor2 - cursor1 == 0) return;
    if (abs(v[cursor1] + v[cursor2]) <= abs(ans)) {
        ans = v[cursor1] + v[cursor2];
        point1 = cursor1;
        point2 = cursor2;
    }
    if (v[cursor1] + v[cursor2] == 0) {
        point1 = cursor1;
        point2 = cursor2;
        return;
    }

    if (v[cursor1] + v[cursor2] < 0) solve(cursor1 + 1, cursor2);
    if (v[cursor1] + v[cursor2] > 0) solve(cursor1, cursor2 - 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    point2 = v.size() - 1;

    solve(0, point2);

    cout << v[point1] << ' ' << v[point2];

    return 0;
}