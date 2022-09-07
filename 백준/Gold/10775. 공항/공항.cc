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

int G, P;
int counter;
int parent[100001];

int Find_parent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find_parent(parent[x]);
}

void Union(int x, int y) {
    int x_parent = Find_parent(x);
    int y_parent = Find_parent(y);
    if (x_parent != y_parent) {
        parent[y_parent] = x_parent;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> G >> P;

    for (int i = 1; i <= G; i++) {
        parent[i] = i;
    }

    while(P--) {
        int temp;
        cin >> temp;

        if (Find_parent(temp) == 0) break;
        else {
            counter++;
            Union(Find_parent(temp) - 1, Find_parent(temp));
        }
    }

    cout << counter;

    return 0;
}