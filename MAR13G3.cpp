# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef unsigned long long ull;

const int N = int(5e5) + 5;
const int inf = (int)1e9 + 7;

string a, b;
int dp[N], ndp[N];
int ans[N][26];


vector < int > pf(string s){
  vector < int > p((int)s.size());
  for(int i = 1; i < (int)p.size(); ++i){

    int j = p[i - 1];
    while(j > 0 && s[j] != s[i]){
      j = p[j - 1];
    }
    if(s[i] == s[j]){
      ++j;
    }
    p[i] = j;
  }

  return p;
}

int main(){
	freopen("necklace.in", "r", stdin);
	freopen("necklace.out", "w", stdout);
	cin >> b >> a;
	// dp[len][val] = min_number of characters to remove to get p[i] = val
	b = a + '#' + b;

  vector < int > p = pf(a + '#');

  for(int i = 0; i <= (int)a.size(); ++i){
    for(int j = 0; j < 26; ++j){
      if(i < (int)a.size() && a[i] - 'a' == j){
        ans[i][j] = i + 1;
      } else if(i){
        ans[i][j] = ans[p[i - 1]][j];
      }
    }
  }
  for(int j = 0; j <= (int)a.size(); ++j){
		dp[j] = ndp[j] = inf;
	}
	dp[0] = 0;
	for(int i = (int)a.size() + 1; i < (int)b.size(); ++i){
		for(int j = 0; j < (int)a.size(); ++j){
			if(dp[j] == inf){
				continue;
			}
			ndp[j] = min(ndp[j], dp[j] + 1);
			assert(ans[j][b[i] - 'a'] <= (int)a.size());
			ndp[ans[j][b[i] - 'a']] = min(ndp[ans[j][b[i] - 'a']], dp[j]);
		}
		for(int j = 0; j <= (int)a.size(); ++j){
			dp[j] = ndp[j];
			ndp[j] = inf;
		}
	}
	int ans = inf;
	for(int i = 0; i < (int)a.size(); ++i){
		ans = min(ans, dp[i]);
	}
	cout << ans;
  return 0;
}
