/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0 ;
        ListNode* ptr = head ;
        while(ptr){
            cnt++ ;
            ptr = ptr->next ;
        }
        int ind = cnt - n ;
        if(ind<0)
            return nullptr ;
        
        if(ind==0)
            return head->next ;

        ListNode* prev = head ;

        while(ind>1){
            ind-- ;
            prev = prev->next ;
        }

        prev->next = prev->next->next ;

        return head ;


    }
};
