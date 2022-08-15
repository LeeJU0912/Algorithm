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

using namespace std;

int N;
int ans[100001];
vector<pair<int, int>> v;
vector<int> LIS;
vector<int> OUT;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({ a , b });
    }

    sort(v.begin(), v.end());

    LIS.push_back(v[0].second);

    for (int i = 1; i < N; i++) {
        if (LIS.back() < v[i].second) {
            LIS.push_back(v[i].second);
            ans[i] = LIS.size() - 1;
        }
        else {
            int idx = lower_bound(LIS.begin(), LIS.end(), v[i].second) - LIS.begin();
            LIS[idx] = v[i].second;
            ans[i] = idx;
        }
    }

    int temp = LIS.size();

    cout << N - temp << '\n';

    temp--;

    for (int i = N - 1; i >= 0; i--) {
        if (ans[i] == temp) {
            temp--;
            continue;
        }
        OUT.push_back(v[i].first);
    }

    for (int i = OUT.size() - 1; i >= 0; i--) {
        cout << OUT[i] << '\n';
    }
    
    return 0;
}