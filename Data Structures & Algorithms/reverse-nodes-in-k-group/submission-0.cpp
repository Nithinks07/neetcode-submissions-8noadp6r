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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0,head) ;
        ListNode* gPrev = dummy ;

        while(true){
            ListNode* kth = getKth(gPrev,k) ;
            if(!kth) break ;
            ListNode* gNext = kth->next ;

            ListNode* prev = gNext ;
            ListNode* cur = gPrev->next ;
            while(cur!=gNext){
                ListNode* tmp = cur->next ;
                cur->next = prev ;
                prev = cur ;
                cur = tmp ;
            }
            ListNode* tmp = gPrev->next ;
            gPrev->next = kth ;
            gPrev = tmp ;
        }
        return dummy->next ;
    }
    ListNode* getKth(ListNode* cur, int k){
        while(cur && k>0){
            cur = cur->next ;
            k-- ;
        }
        return cur ;
    }
};
