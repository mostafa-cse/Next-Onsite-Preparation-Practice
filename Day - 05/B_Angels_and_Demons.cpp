#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve () {
    int N;
    int Q;
    cin >> N >> Q;

    vector<tuple<int,int,int,int>> intervals(Q);
    for(int i = 0; i < Q; i++){
        int type;
        int s, x, D;
        cin >> type >> s >> x >> D;
        intervals[i] = make_tuple(type, s, x, D);
    }
    struct Event {
        int coord;
        int delta;
        bool operator<(Event const& o) const {
            return coord < o.coord;
        }
    };
    vector<Event> ev;
    ev.reserve(2*Q + 2);
    for(auto &it : intervals){
        int type; int s, x, D;
        tie(type, s, x, D) = it;
        int d = (type == 1 ? +D : -D);
        ev.push_back({ s,     d   });
        ev.push_back({ x+1,  -d   });
    }
    ev.push_back({ N+1, 0 });
    sort(ev.begin(), ev.end());

    vector<Event> events;
    events.reserve(ev.size());
    for(auto &e : ev){
        if(events.empty() || events.back().coord != e.coord){
            events.push_back(e);
        } else {
            events.back().delta += e.delta;
        }
    }

    auto survives = [&](int H)->bool {
        int currD = 0;   
        int currS = 0;   
        int prev  = 1;   
        for(auto &e : events){
            int x = e.coord;
            if(x > N+1) break;
            if(prev < x){
                int len = x - prev;
                int blockMin = (currD >= 0 ? currS : currS + currD * len);
                if(H + blockMin <= 0) return false;

                currS += currD * len;
                prev = x;
            }
            currD += e.delta;
        }
        return true;
    };

    int lo = 1, hi = (int)1e18, ans = hi;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(survives(mid)){
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";
}
int32_t main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
