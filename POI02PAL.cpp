# include <bits/stdc++.h>

# define y1 asjkdkjsdjks
# define fi first
# define se second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;

const int N = int(2e5) + 5;
const int inf = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;

string a;
int d1[201], d2[201];
int p1[201], p2[201];

int palindrome(string x){
  return equal(x.begin(), x.end(), x.rbegin());
}

void restore(int n, int *p){
  if(p[n - 1] == -2){
    cout << "NIE\n";
    exit(0);
  }
  vector < int > id;
  int now = n - 1;
  while(true){
    id.push_back(now);
    if(now == -1){
      break;
    }
    now = p[now];
  }
  reverse(id.begin(), id.end());
  id.push_back(n - 1);
  for(int i = 0; i + 1 < (int)id.size(); ++i){
    for(int j = id[i] + 1; j <= id[i + 1]; ++j){
      cout << a[j];
    }
    cout << " ";
  }
  cout << "\n";
}

void solve_min(){
  int n = (int)a.size();
  for(int i = 0; i < n; ++i){
    d1[i] = inf;
    p1[i] = -2;
  }
  for(int i = 0; i < n; ++i){
    if(i % 2 == 1 && palindrome(a.substr(0, i + 1))){
      d1[i] = 1;
      p1[i] = -1;
    }
    if(d1[i] == inf){
      continue;
    }
    for(int j = i + 1; j < n; ++j){
      int len = j - i;
      if(len % 2 == 0 && palindrome(a.substr(i + 1, len))){
        if(d1[j] > d1[i] + 1){
          d1[j] = d1[i] + 1;
          p1[j] = i;
        }
      }
    }
  }
  restore(n, p1);
}

void solve_max(){
  int n = (int)a.size();
  for(int i = 0; i < n; ++i){
    d2[i] = -inf;
    p2[i] = -2;
  }
  for(int i = 0; i < n; ++i){
    if(i % 2 == 1 && palindrome(a.substr(0, i + 1))){
      if(d2[i] == -inf){
        d2[i] = 1;
        p2[i] = -1;
      }
    }
    if(d2[i] == -inf){
      continue;
    }
    for(int j = i + 1; j < n; ++j){
      int len = j - i;
      if(len % 2 == 0 && palindrome(a.substr(i + 1, len))){
        if(d2[j] < d2[i] + 1){
          d2[j] = d2[i] + 1;
          p2[j] = i;
        }
      }
    }
  }
  restore(n, p2);
}

int main(){
  cin >> a;
  solve_min();
  solve_max();
  return 0;
}
