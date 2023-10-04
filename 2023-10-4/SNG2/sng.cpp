# include <iostream>

const int NLIM = 5e6;
long long prime[NLIM + 3] = {0};
long long prjit[NLIM + 3] = {0};
long long cache[NLIM + 3] = {0};
int prptr = 0;

using namespace std;

inline void factor(int lim)
{
  for (long long i = 2; i <= lim; ++i) {
    if (!prime[i]) {
      prjit[prptr++] = i;
      cache[i] = 1;
    }
    for (int n = 0; n < prptr; ++n) {
      if (i * prjit[n] > lim) break;
      prime[i * prjit[n]] = 1;
      cache[i * prjit[n]] = cache[i] + 1;
      if (i % prjit[n] == 0) break;
    }
  }
}

inline void catjit(int bdr)
{
  for (int x = 1; x <= bdr; ++x)
    cache[x] = cache[x - 1] + cache[x];
}

int main()
{
  ios::sync_with_stdio(false);
	cin.tie(nullptr);

  factor(NLIM + 1);
  catjit(NLIM);

  int t = 0;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << cache[a] - cache[b] << "\n";
  }

  return 0;
}
