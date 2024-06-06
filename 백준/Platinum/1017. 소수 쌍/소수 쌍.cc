#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;
bool is_sosu[2001];
bool visited[50];
int node[50];

bool solve(int idx) {
    if (visited[idx]) return false;
    visited[idx] = true;
    
    int one = save[idx];
    for (int i = 0; i < N; i++) {
        int two = save[i];
        
        if (is_sosu[one + two]) continue;
        if (node[i] == -1 || solve(node[i])) {
            node[i] = idx;
            return true;
        }
    }
    
    return false;
}

int main() {
    FastIO

    is_sosu[1] = true;
    for (int i = 2; i <= sqrt(2000); i++) {
        if (is_sosu[i]) continue;
        for (int j = 2; i * j <= 2000; j++) {
            is_sosu[i * j] = true;
        }
    }
    
    cin >> N;
    save = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    vector<int> ans;
    for (int i = 1; i < N; i++) {
        if (is_sosu[save[0] + save[i]]) continue;
        memset(node, -1, sizeof(node));
        node[0] = i;
        node[i] = 0;

        for (int j = 1; j < N; j++) {
            if (i == j) continue;

            memset(visited, false, sizeof(visited));
            visited[0] = true;
            visited[i] = true;
            solve(j);
        }
        
        bool chk = false;
        for (int k = 0; k < N; k++) {
            if (node[k] == -1) {
                chk = true;
                break;
            }
        }
        if (!chk) {
            ans.push_back(save[i]);
        }
    }
    
    if (ans.empty()) {
        cout << -1;
    }
    else {
        sort(ans.begin(), ans.end());
        for (auto& i : ans) {
            cout << i << ' ';
        }
    }

    return 0;
}