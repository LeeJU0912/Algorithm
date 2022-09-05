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
int parent[500000];


int Find_Parent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find_Parent(parent[x]);
}

int Find(int x, int y) {
    x = Find_Parent(x);
    y = Find_Parent(y);
    if (x == y) return 1;
    else return 0;
}

void Union(int x, int y) {
    x = Find_Parent(x);
    y = Find_Parent(y);
    if (x > y) {
        parent[x] = y;
    }
    else {
        parent[y] = x;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }

    int counter = 0;
    int a, b;

    while(M--) {
        cin >> a >> b;
        counter++;
        if (Find(a, b)) {
            cout << counter;
            return 0;
        }
        else {
            Union(a, b);
        }
    }

    cout << 0;

    return 0;
}