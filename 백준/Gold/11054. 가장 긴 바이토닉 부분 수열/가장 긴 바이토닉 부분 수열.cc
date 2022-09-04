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

using namespace std;

int N;
vector<int> v;
int ans;
bool down;
int length[1001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    for (int i = 0; i < N; i++) {
        length[i] = 1;
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                length[i] = max(length[i], length[j] + 1);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] > v[i]) {
                length[i] = max(length[i], length[j] + 1);
            }
        }
    }

    cout << *max_element(length, length + N);

    return 0;
}