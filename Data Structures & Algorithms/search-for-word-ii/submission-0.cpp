class TrieNode{
public:
    TrieNode* children[26] ;
    int idx ;
    int refs ;

    TrieNode(){
        for(int i=0;i<26;i++)
            children[i] = nullptr ;
        
        idx = -1 ;
        refs = 0 ;
    }

    void addWord(const string& word, int i){
        TrieNode* cur = this ;
        cur->refs++ ;
        for(char c:word){
            int ind = c-'a' ;
            if(!cur->children[ind])
                cur->children[ind] = new TrieNode() ;
            
            cur = cur->children[ind] ;
            cur->refs++ ;
        }
        cur->idx = i ;
    }
} ;


class Solution {
private:
    int ROWS ;
    int COLS ;
    vector<string> res ;
    int dir[4][2] = {
        {1,0},{-1,0},{0,1},{0,-1}
    } ;

    int dfs(auto& board, TrieNode* node, int r, int c, auto& words){
        
        if(
            r<0 || r>=ROWS || c<0 || c>=COLS ||
            board[r][c]=='*' || !node->children[board[r][c]-'a']
        )
            return 0 ;
        

        char temp = board[r][c] ;
        board[r][c] = '*' ;
        TrieNode* prev = node ;
        node = node->children[temp-'a'] ;
        int found = 0 ;
        if(node->idx!=-1){
            res.push_back(words[node->idx]) ;
            node->idx = -1 ;
            found++ ;
        }

        for(auto& d:dir){
            found += dfs(board,node,r+d[0],c+d[1],words) ; 
        }

        board[r][c] = temp ;
        node->refs -= found;

        if(!node->refs){
            prev->children[temp-'a'] = nullptr ;
        }

        return found ;

    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        ROWS = board.size() ;
        COLS = board[0].size() ;
        TrieNode* root = new TrieNode() ;
        for(int i=0;i<words.size();i++)
            root->addWord(words[i],i) ;
        
        for(int r=0;r<ROWS;r++){
            for(int c=0;c<COLS;c++){
                root->refs -= dfs(board,root,r,c,words) ;
            }
        }

        return res ;
    }
};
