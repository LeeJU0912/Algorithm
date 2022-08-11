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

int T;
int n;
int choose[100001];
int visited[100001];
int done[100001];
int cnt;

void solve(int start) {
    visited[start] = 1; // 방문 표시 남기기
    int next = choose[start]; // 다음 위치 알려주기

    if (!visited[next]) solve(next); // 만약 다음위치를 방문하지 않았다면, 다음위치로 출발
    else if (!done[next]) { // 만약 다음 위치를 방문해서 끝에 도달했다면
        for (int i = next; i != start; i = choose[i]) { // 다시 거꾸로 거슬러 돌아가면서 방문한 위치들 터치하기
            cnt++; // 터치한 위치들 총합
        }
        cnt++;
    }
    done[start] = 1; // 터치하면서 사이클 확정이니까 건들일 필요 없다는 표시 남기기
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> choose[i];
        }
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) solve(i); // 방문하지 않았을 경우 시도해보기
        }
        cout << n-cnt << '\n'; // 전체 - 사이클인 부분 빼기

        // 초기화
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        memset(done, 0, sizeof(done));
    }

    return 0;
}