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

string N;
int zero;
long long sum;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N.length(); i++) {
        if (N[i] == '0') {
            zero = 1;
        }
        else {
            sum += N[i] - '0';
        }
    }

    if (!zero || sum % 3 != 0) {
        cout << -1;
    }
    else {
        sort(N.begin(), N.end(), greater<>());
        cout << N;
    }

    return 0;
}