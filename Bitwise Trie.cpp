class Solution {
public:
struct Node{
   Node *links[2];
    
   void put(int bit){
    links[bit]=new Node();
   }
    Node* get(int bit){
        return links[bit];
    }
    };

class Trie{
public :Node* root;

public :Trie(){
    root=new Node();
}
public: void insert(int num){
    Node *node=root;
    for(int bit=31;bit>=0;bit--){
        int cur_bit=(num>>bit)&1;
        // tells whether current bit is 0 or 1
        if(!node->get(cur_bit)) node->put(cur_bit);
        node=node->get(cur_bit);
    }
}

int find_max(int num){
Node *node=root;
int ans=0;
for(int bit=31;bit>=0;bit--){
    int cur_bit=(num>>bit)&1;
    int req_bit=cur_bit^1;
    if(node->get(req_bit)){
        node=node->get(req_bit);
        ans+=(1<<bit);
    }
    else{
       node=node->get(cur_bit);
    }
    }
    return ans;
}
};