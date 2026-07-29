class Solution {
public:
int timer=1;
void dfs(int node,int par ,vector<int> &vis,vector<vector<int>> &critical_edges,
vector<int> &low,vector<int> &ins_time,vector<vector<int>> &adj_list){
ins_time[node]=timer++;
low[node]=ins_time[node];
vis[node]=1;

for(int child:adj_list[node]){
    if(child==par) continue;

    if(!vis[child]){
        dfs(child,node,vis,critical_edges,low,ins_time,adj_list);

         low[node]=min(low[node],low[child]);
        if(low[child]>ins_time[node]){
          critical_edges.push_back({node,child});
        }
    }
          else{
         low[node]=min(low[node],low[child]);
        }
    }
}

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj_list(n);

        for(vector<int> edge:connections){
        int first_node=edge[0],second_node=edge[1];

        adj_list[first_node].push_back(second_node);
        adj_list[second_node].push_back(first_node);
        }

        vector<int> vis(n,0),ins_time(n,0);
        vector<int> low(n,INT_MAX);
        vector<vector<int>> critical_edges;
        dfs(0,-1,vis,critical_edges,low,ins_time,adj_list);

        return critical_edges;
    }
};