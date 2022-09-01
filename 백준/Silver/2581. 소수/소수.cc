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

using namespace std;

int M, N;

int number[10001];
int mini = 0;
int sum;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> M >> N;

    number[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (!number[i]) {
            for (int j = 2; i * j <= N; j++) {
                number[i * j] = 1;
            }
        }
    }
    for (int i = M; i <= N; i++) {

        if (!number[i]) {
            if (!mini) {
                mini = i;
            }
            sum += i;
        }
    }

    if(!sum) {
        cout << -1;
        return 0;
    }
    cout << sum << '\n';
    cout << mini;

    return 0;
}