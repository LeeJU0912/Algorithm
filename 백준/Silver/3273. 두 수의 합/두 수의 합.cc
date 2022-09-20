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

using namespace std;

int N;
int a[100000];
int ans;
int counter;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cin >> ans;

    sort(a, a + N);
    
    int point = N - 1;
    for (int i = 0; i < point; i++) {
        if (a[i] + a[point] < ans) continue;
        for (int j = point; j >= i + 1; j--) {
            if (a[i] + a[j] < ans) break;
            if (a[i] + a[j] == ans) {
                counter++;
                point = j;
                break;
            }
        }
    }

    cout << counter;

    return 0;
}