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

using namespace std;

int N;
int temp;
int LCS[100001];
int IDX[100001];
vector<int> LIS;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        IDX[temp] = i;
    }
    for (int i = 0; i < N; i++) {
        cin >> temp;
        LCS[i] = IDX[temp];
    }

    LIS.push_back(LCS[0]);

    for (int i = 1; i < N; i++) {
        if (LIS.back() < LCS[i]) {
            LIS.push_back(LCS[i]);
        }
        else {
            int idx = lower_bound(LIS.begin(), LIS.end(), LCS[i]) - LIS.begin();
            LIS[idx] = LCS[i];
        }
    }

    cout << LIS.size();

    return 0;
}