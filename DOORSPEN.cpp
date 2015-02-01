#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
struct P {
  int x, y;
} at, bt;
typedef vector<P> vp;
inline int cross() {
  return at.x*bt.y-at.y*bt.x;
}
int cmpx(const P &a,const P &b) {
  return a.x < b.x;
}
inline int ccw(P &a,P& b,P& c) {
  at = (P){b.x-a.x,b.y-a.y};
  bt = (P){c.x-a.x,c.y-a.y};
  if(cross() > 0) return 1;
  if(cross() < 0) return 2;
  return 0;
}
vp u, l;
void andrewScan(vp &polys,P *ps,int n) {
  u.clear(); l.clear();
  polys.clear();
  if(n < 3) return ;
  sort(ps,ps+n,cmpx);
  u.pb(ps[0]);
  u.pb(ps[1]);
  l.pb(ps[n-1]);
  l.pb(ps[n-2]);
  for(int i = 2;i < n;i++) {
    for(int j = u.size();j >= 2 && ccw(u[j-2],u[j-1],ps[i]) != 2;j--)
      u.pop_back();
    u.pb(ps[i]);
  }
  for(int i = n-3;i >= 0;i--) {
    for(int j = l.size();j >= 2 && ccw(l[j-2],l[j-1],ps[i]) != 2;j--)
      l.pop_back();
    l.pb(ps[i]);
  }
  polys = l;
  for(int i = 1;i < u.size()-1;i++) polys.pb(u[i]);
}
P ds[2000], ps[2000];
int geti() {
  char ch; int ret;
  while((ch=getchar())<'0'||ch>'9') ;
  ret = ch-'0';
  while((ch=getchar())>='0'&&ch<='9') ret = ret*10+ch-'0';
  return ret;
}
vp chds, chps;
int main() {
  int D, nP;
  int cnt[2][3];
  int tcase = 0;
  int x1, x2, y1, y2;
  chds.reserve(2000);
  chps.reserve(2000);
  u.reserve(2000);
  l.reserve(2000);
  while(1) {
    D = geti(); nP = geti();
    if(D == 0 && nP == 0) break;
    for(int i = 0;i < D;i++) {
      x1 = geti(); y1 = geti(); x2 = geti(); y2 = geti();
      ds[i*4] = (P){x1,y1};
      ds[i*4+1] = (P){x1,y2};
      ds[i*4+2] = (P){x2,y1};
      ds[i*4+3] = (P){x2,y2};
    }
    for(int i = 0;i < nP;i++) {
      x1 = geti(); y1 = geti(); x2 = geti(); y2 = geti();
      ps[i*4] = (P){x1,y1};
      ps[i*4+1] = (P){x1,y2};
      ps[i*4+2] = (P){x2,y1};
      ps[i*4+3] = (P){x2,y2};
    }
    andrewScan(chds,ds,4*D);
    andrewScan(chps,ps,4*nP);
    bool ok = 0;
    for(int i = 0;i < chds.size();i++) {
      for(int j = 0;j < chps.size();j++) {
        memset(cnt,0,sizeof cnt);
        for(int k = 0;k < 4*D;k++)
cnt[0][ccw(chds[i],chps[j],ds[k])]++;
        for(int k = 0;k < 4*nP;k++)
            cnt[1][ccw(chds[i],chps[j],ps[k])]++;
        if(((cnt[1][1]&&!cnt[1][2]&&cnt[0][2]&&!cnt[0][1]) ||
(!cnt[1][1]&&cnt[1][2]&&!cnt[0][2]&cnt[0][1]) ) && (cnt[1][0]==1&&cnt[0][0]==1)) {
ok = 1; goto ANSWERING;
        }
      }
    }
    ANSWERING:
    printf("Case %d: ",++tcase);
    if(ok) puts("It is possible to separate the two groups of vendors.");
    else puts("It is not possible to separate the two groups of vendors.");
    puts("");
  }
  return 0;
}
