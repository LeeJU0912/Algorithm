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

using namespace std;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;

    cin >> n;

    vector<int> v;

    v.push_back(1);
    v.push_back(3);

    for (int i = 2; i < n; i++) {
        v.push_back((v[i - 1] + v[i - 2] * 2) % 10007);
    }

    cout << v[n - 1];

    return 0;
}