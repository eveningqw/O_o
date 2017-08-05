# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef unsigned long long ull;

const int N = (int)1e5 + 7;
const int inf = (int)1e9 + 7;

int x;
vector < int > all;

int main(){
  while(~scanf("%d", &x)){
    if(x){
      all.push_back(x);
    } else{
      break;
    }
  }
  sort(all.begin(), all.end());
  for(int i = 0; i + 2 < (int)all.size(); ++i){
    if(all[i] + all[i + 1] > all[i + 2]){
      printf("%d %d %d\n", all[i], all[i + 1], all[i + 2]);
      return 0;
    }
  }
  printf("NIE\n");
  return 0;
}
