/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp ; // <old Node, newNode>

        Node* ptr = head ;
        Node* dummy = new Node(-1) ;
        Node* ptr2 = dummy ;
        while(ptr){
            ptr2->next = new Node(ptr->val) ;
            mp[ptr] = ptr2->next ;
            ptr = ptr->next ;
            ptr2 = ptr2->next ;
        }
        ptr2 = dummy ;
        ptr = head ;
        while(ptr){
            ptr2->next->random = mp[ptr->random] ;
            ptr = ptr->next ;
            ptr2 = ptr2->next ;
        }
        return dummy->next ;
    }
};
