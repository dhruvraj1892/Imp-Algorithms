struct Node{
    Node *links[26];
    bool flag=false;
 
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node *node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie{
    private: Node* root;
    public:
    Trie(){
        root=new Node();
    } 
    void insert(string word){
        Node *node=root;
        for(char c:word){
         if(!node->containsKey(c)) node->put(c,new Node());
        node= node->get(c);
        }
        node->setEnd();
    }

    bool search(string word){
        Node *node =root;
        for(char c:word){
        if(!node->containsKey(c)) return false;
        node=node->get(c);
        }
        return node->isEnd();
    }
};