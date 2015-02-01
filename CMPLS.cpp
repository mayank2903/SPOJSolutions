#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void expand(vector<int> & a, int k) {
  if (a.size() == 1) {
    for (int i = 0; i < k; i++) {
      a.push_back(a[0]);
    }
  } else {
    int n = a.size();
    vector<int> d(n - 1);
    for (int i = 0; i < n - 1; i++) {
      d[i] = a[i + 1] - a[i];
    }
    expand(d, k);
    for (int i = 0; i < k; i++) {
      a.push_back(a[n + i - 1] + d[n + i - 1]);
    }
  }
}
int main() {
  int ncase;
  cin >> ncase;
  while (ncase--) {
    int n, t;
    vector<int> a;
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
      int p;
      cin >> p;
      a.push_back(p);
    }
    expand(a, t);
    cout << a[n];
    for (int i = 1; i < t; i++)
      cout << " " << a[n + i];
    cout << endl;
  }
}
