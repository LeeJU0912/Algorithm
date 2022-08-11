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
int prime[4000001];
int cursor1, cursor2;
long long sum[4000001];
int counter;

vector<int> v;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 2; i <= sqrt( 4000000); i++) {
        if (prime[i] == 1) continue;
        for (int j = 2; j * i <= 4000000; j++) {
            prime[j * i] = 1;
        }
    }
    for (int i = 2; i <= 4000000; i++) {
        if (prime[i] == 0) {
            v.push_back(i);
        }
    }

    for (int i = 1; i <= v.size(); i++) {
        sum[i] = sum[i - 1] + v[i - 1];
    }

    cursor1 = 1;
    cursor2 = 1;

    while (cursor1 <= cursor2) {

        long long hap = sum[cursor2] - sum[cursor1 - 1];
        if (hap > N) {
            cursor1++;
        }
        else if (hap < N) {
            cursor2++;
        }
        else {
            counter++;
            cursor2++;
            if (cursor2 == v.size()) {
                counter++;
                break;
            }
        }

    }

    cout << counter;

    return 0;
}