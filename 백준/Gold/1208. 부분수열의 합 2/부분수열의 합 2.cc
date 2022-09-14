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

using namespace std;

int N, S;
int num_list[40];
int half;
map<int, int> mp;

long long ans;

void dfsLeft(int idx, int sum) { // 오른쪽 꺼를 구해서
    if (idx == half){
        mp[sum]++;
        return;
    }
    dfsLeft(idx + 1, sum);
    dfsLeft(idx + 1, sum + num_list[idx]);
}

void dfsRight(int idx, int sum) { // 왼쪽꺼 합을 구해서 전체에서 왼쪽합 뺀 값이 오른쪽에서 한번 구해졌다면 가져다 쓴다
    if (idx == N) {
        ans += mp[S - sum];
        return;
    }
    dfsRight(idx + 1, sum);
    dfsRight(idx + 1, sum + num_list[idx]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> num_list[i];
    }

    half = N / 2;
    dfsLeft(0, 0); // 0 ~ half - 1 까지 탐색
    dfsRight(half, 0); // half ~ N - 1 까지 탐색

    if (S == 0) ans--;
    cout << ans;

    return 0;
}