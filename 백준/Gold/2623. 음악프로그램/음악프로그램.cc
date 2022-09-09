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

using namespace std;

int N, M;
vector<int> go[1001];
int degree[1001];

vector<int> v;

void topologySort() {
    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        v.push_back(now);

        for (int i = 0; i < go[now].size(); i++) {
            int next = go[now][i];
            if (--degree[next] == 0) q.push(next);
        }
    }
    if (v.size() < N) {
        cout << 0;
    }
    else {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    while(M--) {
        int temp;
        int temp2[1001];
        cin >> temp;
        for (int i = 0; i < temp; i++) {
            cin >> temp2[i];
        }
        for (int i = 0; i < temp - 1; i++) {
            go[temp2[i]].push_back(temp2[i + 1]);
            degree[temp2[i + 1]]++;
        }
    }

    topologySort();

    return 0;
}