#include <iostream>
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

	int i, g;

	int a, b;
	int counter;
	
	cin >> a >> b;
	cin.ignore();

    // 1. 배열을 생성하여 초기화한다.
    for (i = 2; i <= b; i++) {
        numlist[i] = i;
    }

    // 2. 2부터 시작해서 특정 수의 배수에 해당하는 수를 모두 지운다.
    // (지울 때 자기자신은 지우지 않고, 이미 지워진 수는 건너뛴다.)
    for (int i = 2; i <= b; i++) {
        if (numlist[i] == 0) continue; // 이미 지워진 수라면 건너뛰기

        // 이미 지워진 숫자가 아니라면, 그 배수부터 출발하여, 가능한 모든 숫자 지우기
        for (int j = 2 * i; j <= b; j += i) {
            numlist[j] = 0;
        }
    }

    // 3. 2부터 시작하여 남아있는 수를 모두 출력한다.
    for (int i = a; i <= b; i++) {
        if (numlist[i] != 0) {
            cout << numlist[i] << '\n';
        }
    }
	
	return 0;
}