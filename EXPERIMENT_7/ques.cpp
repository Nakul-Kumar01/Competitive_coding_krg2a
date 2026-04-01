class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>arr[n];

        for(auto x : flights) arr[x[0]].push_back({x[1],x[2]});

        vector<int>dis(n,INT_MAX);
        dis[src]=0;

        queue<pair<int,int>>q;
        q.push({src,0});
        k++;
int ans = INT_MAX;
        while(!q.empty() && k--){
            int nn = q.size();

            while(nn--){
                auto [node,cost] = q.front();
                q.pop();
                for(auto [nei,wt] : arr[node]){
                    if(nei == dst){
                         ans = min(ans,cost+wt);
                         continue;
                    }
                    if(dis[nei] > cost+wt){
                    q.push({nei,cost+wt});
                    dis[nei] = cost+wt;
                    }
                }
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};