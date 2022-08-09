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

vector<pair<double, double>> v;

double ans;

int N;

void solve (int counter) {
    if (counter == N) {
        return;
    }

    ans += ((v[counter - 1].first - v[0].first) * (v[counter].second - v[0].second) - (v[counter].first - v[0].first) * (v[counter - 1].second - v[0].second)) / 2;
    solve(counter + 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);



    cin >> N;

    for (int i = 0; i < N; i++) {
        double x, y;
        cin >> x >> y;
        v.push_back({ x, y });
    }

    solve(2);

    cout << fixed;
    cout.precision(1);
    cout << abs(ans);

    return 0;
}