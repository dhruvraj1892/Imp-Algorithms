class TreeAncestor {
public:
    int n;
    static const int LOG = 1;
    vector<vector<int>> up;
    vector<int> depth;
    TreeAncestor(int n, vector<int>& parent,vector<int> &depth) {
         while((1<<LOG)<=n) LOG++;
        this->n = n;
        up.resize(n, vector<int>(LOG, -1));
        this->depth=depth;
        for(int i=0;i<n;i++) up[i][0]=parent[i];
      for(int j=1;j<LOG;j++){
        for(int i=0;i<n;i++){
            if(up[i][j-1]==-1) continue;
            up[i][j]=up[up[i][j-1]][j-1];
        }
      }
    }
    int getKthAncestor(int node, int k) {
        int anc = node;

        for (int j = 0; j < LOG ; j++) {
            if ((k >> j) & 1) {
                if(anc==-1) return -1;
                anc = up[anc][j];
            }
        }

        return anc;
    }

    int getLCA(int u,int v){
      if(depth[u]<depth[v]) swap(u,v);

      int diff=depth[u]-depth[v];

      for(int bit=0;bit<LOG;bit++){
        if((diff>>bit)&1){
          u=up[u][bit];
        }
      }
      if(u==v) return u;

      for(int bit=LOG-1;bit>=0;bit--){
      if(up[u][bit]!=up[v][bit]){
        u=up[u][bit];
        v=up[v][bit];
      }
      }
      return up[u][0];
    }
};
