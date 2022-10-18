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
long long A[1000000];
long long B, C;
long long ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> B >> C;

    for (int i = 0; i < N; i++) {
        A[i] -= B;
    }
    ans = N;

    for (int i = 0; i < N; i++) {
        if (A[i] <= 0) continue;
        if (A[i] % C == 0) {
            ans += A[i] / C;
        }
        else {
            ans += A[i] / C + 1;
        }
    }

    cout << ans;

    return 0;
}