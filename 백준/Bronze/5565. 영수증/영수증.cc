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

int ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int hap;

    cin >> hap;

    int book;
    int hap2 = 0;

    for (int i = 0; i < 9; i++) {
        cin >> book;
        hap2 += book;
    }

    cout << hap - hap2;

    return 0;
}