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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int TC;

    cin >> TC;

    for (int i = 0; i < TC; i++) {
        int M, N, x, y;
        int check = false;

        cin >> M >> N >> x >> y;

        x -= 1;
        y -= 1;

        for (int j = x; j < (M * N); j += M) {
            if (j % N == y) {
                cout << j + 1 << '\n';
                check = 1;
                break;
            }
        }
        if (!check) {
            cout << "-1" << '\n';
        }
    }

    return 0;
}