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



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int X;

    cin >> X;

    int N;

    cin >> N;

    int sum = 0;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        sum += a * b;
    }

    if (X == sum) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    return 0;
}