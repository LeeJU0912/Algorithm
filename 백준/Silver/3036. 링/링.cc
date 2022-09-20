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

using namespace std;

int N;
int a[100];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < N; i++) {
        int x, y;
        x = a[0] * 2 / gcd(a[0] * 2, a[i] * 2);
        y = a[i] * 2 / gcd(a[0] * 2, a[i] * 2);

        cout << x << "/" << y << '\n';
    }


    return 0;
}