#include <iostream>
#include <vector>
#include <algorithm>


struct e {
    int a, b, l;
};

int rank[1010], parent[1010];
int max = 0;

bool cmp(e a, e b) {
    return a.l < b.l;
}

int find(int x) {  // bad function, because his name not show his actions
    if (x != parent[x]) parent[x] = find(parent[x]);

    return parent[x];
}

int main() {
    int n, m;

    std::cin >> n >> m;
    std::vector<e> v;

    for (int i = 0; i < m; ++i) {
        int a, b, l;
        std::cin >> a >> b >> l;
        v.push_back({a - 1, b - 1, l});
    }

    std::sort(v.begin(), v.end(), cmp);

    for (int i = 1; i <= n; i++) {
        rank[i] = 0;
        parent[i] = i; // map to self
    }

    for (int i = 0; i < m; ++i) {
        int n1 = v[i].a;
        int n2 = v[i].b;

        if (find(n1) != find(n2)) {
            if (v[i].l > max) {
                max = v[i].l;
            }
            v[i].l *= -1; // put mark for cout in the end

            int x = find(n1);
            int y = find(n2);
            if (rank[x] > rank[y]) parent[y] = x;
            else {
                parent[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }

    std::cout << max << "\n" << n - 1 << "\n";

    for (int j = 0; j < m; ++j) {
        if (v[j].l < 0) {	// print marked edges
            std::cout << v[j].a + 1 << " " << v[j].b + 1 << "\n";
        }
    }
    return 0;
}
