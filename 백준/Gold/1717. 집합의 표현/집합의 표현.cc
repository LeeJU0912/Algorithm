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
int parent[1000001];



int Find_parent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find_parent(parent[x]);
}

int Find(int x, int y) {
    x = Find_parent(x);
    y = Find_parent(y);
    if (x == y) return 1;
    else return 0;
}

void Union(int x, int y) {
    x = Find_parent(x);
    y = Find_parent(y);
    if (x < y) parent[y] = x;
    else parent[x] = y;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    while(M--) {
        int a, b, c;
        cin >> a >> b >> c;

        if (!a) {
            Union(b, c);
        }
        else {
            if (Find(b, c)) {
                cout << "YES" << '\n';
            }
            else {
                cout << "NO" << '\n';
            }
        }
    }

    return 0;
}