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

int N, K;
int A[500001];
int counter;
int ans;

void merge(int a, int b, int c) {
    int tmp[500001];

    int i = a;
    int j = b + 1;
    int t = 1;

    while (i <= b && j <= c) {
        if (A[i] <= A[j]) {
            tmp[t++] = A[i++];
        }
        else {
            tmp[t++] = A[j++];
        }
    }
    while (i <= b) {
        tmp[t++] = A[i++];
    }
    while (j <= c) {
        tmp[t++] = A[j++];
    }
    i = a;
    t = 1;
    while (i <= c) {
        counter++;
        if (counter == K) ans = tmp[t];
        A[i++] = tmp[t++];
    }
}

void merge_sort(int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;

        merge_sort(start, mid);
        merge_sort(mid + 1, end);
        merge(start, mid, end);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    merge_sort(1, N);


    if (ans) {
        cout << ans;
    }
    else {
        cout << -1;
    }

    return 0;
}