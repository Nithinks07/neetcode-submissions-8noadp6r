class Node {
public : 
    int key ;
    int val ;
    Node* prev ;
    Node* next ;

    Node(int key, int val){
        this->key = key ;
        this->val = val ;
        prev = nullptr ;
        next = nullptr ;
    } 
} ;

class LRUCache {
private:
    int cap ;
    Node* head ;
    Node* tail ;
    unordered_map<int,Node*> cache ;

    void moveFront(Node* node){
        node->prev->next = node->next ;
        node->next->prev = node->prev ;
        addFront(node) ; 
    }

    void addFront(Node* node){
        Node* temp = head->next ;
        head->next = node ;

        node->prev = head ;
        temp->prev = node ;

        node->next = temp ;
    }

    void removeEnd(){
        Node* temp = tail->prev ;
        cache.erase(temp->key) ;
        tail->prev = temp->prev ;
        temp->prev->next = tail ;
        delete temp ;
    }

public:
    LRUCache(int capacity) {
        cap = capacity ;
        head = new Node(-1,-1) ;
        tail = new Node(-1,-1) ;
        head->next = tail ;
        tail->prev = head ;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            moveFront(cache[key]) ;
            return cache[key]->val ;
        }
        return -1 ;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            Node* node = cache[key] ;
            node->val = value ;
            moveFront(node) ;
        } else {
            if(cache.size()==cap){
                removeEnd() ;
            }
            Node* node = new Node(key,value) ;
            cache[key] = node ;
            addFront(node) ;
        }
    }
};
