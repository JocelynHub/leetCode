//trie树
#define TRIE_MAX_CHAR_NUM 26

struct TrieNode{
    TrieNode *child[TRIE_MAX_CHAR_NUM];
    bool isEnd;
    TrieNode():isEnd(false){
        for(int i = 0;i<TRIE_MAX_CHAR_NUM;i++)
            child[i] = 0;
    }
};
void preOrder_trie(TrieNode *node,int layer){
    for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++)
    {
        if(node->child[i]){
            for (int j = 0; j < layer; j++)
            {
                printf("---");
            }
            printf("%c",i + 'a');

            if(node->child[i]->isEnd)
                printf("(end)");
            printf("\n");
            preOrder_trie(node->child[i],layer + 1);
            
        }
    }
}

//trie树获取全部单词
//思路：利用一个栈来存放单词的结果，如果碰到是结尾单词，就将当前栈中的结果作为一个单词结果；栈会是有个不断弹出的过程，如果整个弹空，表示这个子分支已经结束
//这个栈 用string来表示，可以直接用来表示最后的单词结果
void get_all_word_from_trie(TrieNode *node,string &word,vector<string> &wordList){
    for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++)
    {
        if(node->child[i]){
            word.push_back(i + 'a');
            if(node->child[i]->isEnd){
                //word.erase(node->child[i]);这里不能随便弹出，因为可能还有右分支会用到
                //这里可以确定的是这个肯定是个单词结果
                wordList.push_back(word);
            }
            //继续探寻
            get_all_word_from_trie(node->child[i],word,wordList);
            //word.erase(node->child[i]);//这个也不对
            word.erase(word.length()-1,1);
        }
    }
    
}

//Trie树的单词插入
//其实是将 单词拆开后放到这个树中
//将ptr指针指向root
//逐个遍历 待插入的字符串中的各个字符


class TrieNode{
public:
TrieNode(){}
~TrieNode(){
    for (int i = 0; i < _nodeVec.size(); i++)
    {
        delete _nodeVec[i];
    }
    
}
void insert(const char* word){
    TrieNode*ptr = &_root;
    while(*word){//这里需要加上*
        int pos = *word - 'a';
        if(!ptr->child[pos]){
            ptr->child[pos] = newNode();
        }
        ptr = ptr->child[pos];
        word++;//直接使用了搜元素代表指针
    }
    ptr->is_end = true;//遍历完成加上标志位
}
void search(const char* word){
    TrieNode *ptr = &_root;
    while(*word){
        int pos = *word - 'a';
        if(!ptr->child[pos]){
            return false;
        }
        ptr = ptr->child[pos];
        word++;//这个不能忘记，因为需要移动
    }
    return ptr->is_end;//这里也不是直接返回true或者直接返回false 因为需要看具体是否为结尾
}
//是否有这些前缀 
bool startWith(const char* prefix){
    TrieNode *ptr = &_root;
    while(*prefix){
        int pos = *prefix - 'a';
        if(!ptr->child[pos])
            return false;
        ptr = ptr->child[pos];
        prefix++;
    }
    return true;
}

private:
    TrieNode* newNode()
    {
        TrieNode *node = new TrieNode();
        _nodeVec.push_back(node);
        return node;
    }
    vector<TrieNode*> _nodeVec;
    TrieNode _root;
}

//如果存在ab.d的情况
bool search_trie(TrieNode *node,const char* word){
    //判断是否为单词结尾
    if(*word == '\n'){
        if(node->is_end)
            return true;
        return false;
    }
    if(*word == '.'){
        //这种情况可以去遍历所有的元素
        for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++)
        {
            if(node->child[i] && search_trie(node->child[i],word + 1))
                return true;
        }
        
    }
    else{//剩余的其他情况
        int pos = *word - 'a';
        if(node->child[pos] && search_trie(node->child[pos],word + 1))
            return true;

    }
    return false;
    
}

//547查询朋友圈数目
//图的深搜

void DFS_graph(int u,vector<vector<int>> &graph,vector<int> &visit){
    visit[u] = 1;
    for (int i = 0; i < graph.size(); i++)
    {
        if(visit[i] == 0 && graph[u][i] == 1){
            DFS_graph(i,graph,visit);
        }
    }
    
}
class Solution{
    public:
    int 67(vector<vector<int>> &M){
        vector<int> visit(M.size(),0);
        int count = 0;
        for (int i = 0; i < M.size(); i++)
        {
            if(visit[i] == 0){
                DFS_graph(i,M,visit);
                count++;
            }
        }
        return count;
    }
}


//数组来实现并查集
class DisJointSet{
public:
    DisJointSet(int n){
        for (int i = 0; i < n; i++)
        {
            _id.push_back(i);//这个时候 每个元素就是一个集合
        }
        int find(int p){
            return _id[p];
        }
        void union_(int p,int q){
            int pid = find(p);
            int qid = find(q);
            if(pid == qid){
                return;//说明两个元素 在同一个集合中 不需要合并
            }
            else
            {
                for (int i = 0; i < _id.size(); i++)
                {
                    if(_id[i] == pid){
                        _id[i] = qid;//将所有属于pid集合的全部改为qid对应的集合
                    }
                }
                
            }
        }
    }
private:
vector<int> _id;
};

//并查集 查找算法
class DisJointSet{
public:
    DisJointSet(int n){
        for (int i = 0; i < n; i++)
        {//这个时候 每个元素就是一个集合
            _id.push_back(i);
            _size.push_back(1);
        }
    }
    int find(int p){
        while(p != _id[p]){//因为在向根节点寻找，只有当这个元素是根节点的时候，_id[p]才是它自己
            _id[p] = _id[_id[p]];//这个属于路径压缩
            p = _id[p];
        }
        return p;
    }
private:
    vector<int> _id;
    vector<int> _size;
}

//并查集 合并算法
class DisJointSet{
public:
    DisJointSet(int n){
        for (int i = 0; i < n; i++)
        {//这个时候 每个元素就是一个集合
            _id.push_back(i);
            _size.push_back(1);
        }
        _count = n;
    }
    void union_(int p,int q){
        int i = find(p);
        int j = find(q);
        if(i == j)
            return;
        if(_size[i] < _size[j]){
            _id[i] = j;
            _size[j] += _size[i];
        }
        else
        {
            _id[j] = i;//因为小规模向大规模合并，所以j小的情况下，j对应的父节点为i,并且将i对应的子集大小需要增加j的数目
            _size[i] += _size[j];
        }
        _count--;//总的子集数目要减少
        
    }
private:
    vector<int> _id;//表示当前节点的根节点
    vector<int> _size;//表示这个子集的大小
public:
    int _count;//表示子集的个数
}
class Solution{
public:
    int findCircleNum(vector<vector<int>> &M){
        DisJointSet disjoint_set(M.size());
        for (int i = 0; i < M.size(); i++)
        {
            for (int j = i + 1; j < M[i].size(); j++){
                if(M[i][j]){
                    disjoint_set.union_(i,j);
                }
            }
            
        }y
        return disjoint_set._count;
        
    }
}

//线段树的构造
void build_segment_tree(vector<int> &value,vector<int> &inputNum,int posId,int leftId,int rightId){
        if(leftId == rightId){//说明到了叶节点
            value[posId] = inputNum[left]
            return;
        }
        int mid = (leftId + rightId) / 2;
        build_segment_tree(value,inputNum,2*posId + 1,leftId,mid);
        build_segment_tree(value,inputNum,2*posId + 2,mid + 1,rightId);
        value[posId] = value[2*posId + 1] + value[2*posId + 2];
}
//线段树的求和
void sum_range_segment_tree(vector<int> &value,int posId,int leftId,int rightId,int qLeftId,int qRightId){
    if(qLeftId > rightId || qRight < leftId)
        return 0;//表示两个区间没有交集
    if(qLeftId <= leftId && qRightId >= rightId){//表示是个完全覆盖的情况
        return value[posId];
    }
    int mid  = (leftId + rightId) / 2;
    return sum_range_segment_tree(value,2*posId + 1,leftId,mid,qLeftId,qRightId) + sum_range_segment_tree(value,2*pos + 2,mid + 1,qLeftId,qRightId);
}

//线段树的更新
void update_segment_tree(vector<int> &value,int posId,int leftId,int rightId,int index,int newValue){
    if(leftId == rightId && leftId == index){//叶节点 并且 需要是对应的index（数组中的indexh）
        value[posId] = newValue;
        return;
    }
    int mid = (leftId + rightId) / 2;
    if(index <= mid){
        update_segment_tree(value,2*posId + 1,leftId,mid,index,newValue);
    }
    else{
        update_segment_tree(value,2*posId + 2,mid + 1,rightId,index,newValue);
    }
    value[pos] = value[2*pos + 1] + value[2*pos + 2];
}