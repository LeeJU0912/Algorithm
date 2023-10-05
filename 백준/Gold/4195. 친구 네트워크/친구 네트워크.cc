#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

map<string, int> mp;

int parent[200001];
int ans[200001];

int find_parent(int a) {
    if (parent[a] == a) return a;
    else return parent[a] = find_parent(parent[a]);
}

int Union(int a, int b) {
    int parent_a = find_parent(a);
    int parent_b = find_parent(b);

    if (parent_a != parent_b) {
        parent[parent_b] = parent_a;
        ans[parent_a] += ans[parent_b];
    }

    return ans[parent_a];
}

int main() {
    FastIO

    int T;
    cin >> T;

    while(T--) {
        mp.clear();
        for (int i = 1; i <= 200000; i++) {
            parent[i] = i;
            ans[i] = 1;
        }

        int F;
        cin >> F;

        int person_counter = 1;

        for (int i = 0; i < F; i++) {
            string a, b;
            cin >> a >> b;

            int idx_a, idx_b;

            if (mp.find(a) == mp.end()) {
                mp.insert({a, person_counter});
                person_counter++;
            }
            idx_a = mp[a];

            if (mp.find(b) == mp.end()) {
                mp.insert({b, person_counter});
                person_counter++;
            }
            idx_b = mp[b];

            cout << Union(idx_a, idx_b) << '\n';
        }



    }

    return 0;
}