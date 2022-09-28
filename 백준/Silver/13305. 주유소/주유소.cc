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
#include <sstream>
#include <typeinfo>
#include <cstdlib>
#include <unordered_map>
#include <cfloat>

using namespace std;

int N;
long long oil[100000];
long long road[100000];
long long ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        cin >> road[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> oil[i];
    }

    int i = 0;

    while(i != N - 1) {
        long long road_sum = road[i];
        for (int j = i + 1; j < N; j++) {
            if (oil[j] < oil[i]) {
                ans += oil[i] * road_sum;
                road_sum = 0;
                i = j;
                break;
            }
            if (j == N - 1) {
                ans += oil[i] * road_sum;
                i = j;
                break;
            }
            road_sum += road[j];
        }
    }

    cout << ans;

    return 0;
}