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

vector<int> A;
vector<int> B;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    int temp;
    int ans = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        A.push_back(temp);
    }

    for (int i = 0; i < N; i++) {
        cin >> temp;
        B.push_back(temp);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());

    for (int i = 0; i < N; i++) {
        ans += A[i] * B[i];
    }

    cout << ans;

    return 0;
}