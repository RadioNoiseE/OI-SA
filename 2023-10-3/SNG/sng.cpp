# include <iostream>

using namespace std;

/* factorial: obsolete tail recursing function |=>
 * int factorial(int num)
 * {
 *   if (num == 1)
 *     return 1;
 *   else
 *     return num * factorial(num - 1);
 * }
<=| */

int factor(int num)
{
  int fn = 0, tf = 2;

  while (tf <= num && num != 1){
    if (!(num % tf)) {
      ++fn;
      num = num / tf;
    } else {
      ++tf;
    }
  }

  return fn;
}

int main()
{
  ios::sync_with_stdio(false);
	cin.tie(nullptr);
  
  int t = 0;
  cin >> t;

  for (int cnt = 0; cnt < t; ++cnt) {
    int a, b, n, res = 0;
    cin >> a >> b;
    n = a - b;

    for (int ftn = 0; ftn < n; ++ftn)
      res = res + factor(a - ftn);

    cout << res << endl;
  }
}
