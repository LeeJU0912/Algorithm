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

using namespace std;

int N, M;
int parent[51];

vector<int> truth;
vector<vector<int>> party(51);

int Find(int x) {
    if (parent[x] == x) return x;
    return x = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    parent[x] = y;
}

int answer() {
    int res = M;
    for (const auto &people : party) {
        bool flag = false;
        for (const auto &person : people) {
            if (flag) break;
            for (const auto &know : truth) {
                if (Find(person) == Find(know)) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) res--;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    int truthSum;
    cin >> truthSum;

    int temp;
    for (int i = 0; i < truthSum; i++) {
        cin >> temp;
        truth.push_back(temp);
    }

    int partySum;
    int num, prev;
    for (int i = 0; i < M; i++) {
        cin >> partySum;
        for (int j = 0; j < partySum; j++) {
            if (j >= 1) {
                prev = num;
                cin >> num;
                Union(prev, num);
            }
            else {
                cin >> num;
            }
            party[i].push_back(num);
        }
    }

    cout << answer();

    return 0;
}