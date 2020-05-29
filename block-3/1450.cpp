#include <iostream>
#include <vector>

using namespace std;

struct edge {
    int a, b, w;
};

vector<edge> v;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        v.push_back({a - 1, b - 1, w});
    }

    int s, f;

    cin >> s >> f;
    s--;
    f--;

    vector<int> dArray(510, -1);

    dArray[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (dArray[v[j].a] != -1 && dArray[v[j].b] < dArray[v[j].a] + v[j].w) {
                dArray[v[j].b] = dArray[v[j].a] + v[j].w;
            }
        }
    }

    if (dArray[f] != -1) {
        cout << dArray[f];
    } else {
        cout << "No solution";
    }

    return 0;
}
