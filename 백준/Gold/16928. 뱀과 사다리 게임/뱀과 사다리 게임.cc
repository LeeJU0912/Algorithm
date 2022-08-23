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

int N, M;
int leap[107];
bool visited[107];

void solve(int start) {
    queue<pair<int, int>> q;
    q.push({ start, 0 });
    visited[start] = true;

    while(!q.empty()) {
        int num = q.front().first;
        int counter = q.front().second;



        q.pop();

        for (int i = 1; i <= 6; i++) {
            int next = num + i;
            if (next == 100) {
                cout << counter + 1;
                return;
            }
            else if (next < 100) {
                if (leap[next]) {
                    next = leap[next];
                }
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({ next, counter + 1 });
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N + M; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        leap[temp1] = temp2;
    }
    
    solve(1);

    return 0;
}