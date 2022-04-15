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

using namespace std;

int numlist[1000001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int i;

	int a, b;

	cin >> a >> b;
	cin.ignore();

    for (i = 2; i <= b; i++) {
        numlist[i] = i;
    }
    for (int i = 2; i <= sqrt(b); i++) {
        if (numlist[i] == 0)
            continue;
        for (int j = i + i; j <= b; j += i) {
            numlist[j] = 0;
        }
    }
    for (int i = a; i <= b; i++) {
        if (numlist[i] != 0) {
            cout << numlist[i] << '\n';
        }
    }
	return 0;
}