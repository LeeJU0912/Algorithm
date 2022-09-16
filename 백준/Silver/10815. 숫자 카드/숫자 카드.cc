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
#include <iomanip>
#include <bitset>

using namespace std;

int N, M;
int numbers[500000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    sort(numbers, numbers + N);

    cin >> M;

    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        if (binary_search(numbers, numbers + N, temp)) {
            cout << 1 << ' ';
        }
        else {
            cout << 0 << ' ';
        }
    }

    return 0;
}