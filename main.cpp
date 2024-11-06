#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;
using vb = vector<bool>;

ll N;
vl A, dp;
vb checked;

ll solve(ll f) {
  if (f == N - 2) {
    return max(A[N - 2] + A[N - 1], A[N - 2] * A[N - 1]);
  }

  if (!checked[f]) {
    dp[f] = max(A[f] + solve(f + 1), A[f] * A[f + 1] + solve(f + 2));
    checked[f] = true;
  }

  return dp[f];
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> N;
  A = vl(N);
  for (auto&& a : A) cin >> a;

  if (N == 1) {
    cout << A[0];
    return 0;
  }
  sort(A.begin(), A.end());

  dp = vl(N);
  checked = vb(N, false);

  dp[N - 1] = A[N - 1];
  checked[N - 1] = true;

  const auto& ans = solve(0);
  cout << ans;

  return 0;
}