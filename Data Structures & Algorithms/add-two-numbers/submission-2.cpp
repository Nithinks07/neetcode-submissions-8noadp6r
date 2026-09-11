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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0 ;
        ListNode* dummy = new ListNode(-1) ;
        ListNode* ptr = dummy ;
        ListNode* ptr1 = l1 ;
        ListNode* ptr2 = l2 ;
        while(ptr1!=nullptr || ptr2!=nullptr){
            int num1 = 0 ;
            if(ptr1){
                num1 = ptr1->val ;
                ptr1 = ptr1->next ;
            }
            int num2 = 0 ;
            if(ptr2){
                num2 = ptr2->val ;
                ptr2 = ptr2->next ;
            }
            int sum = num1 + num2 + carry ;
            ptr->next = new ListNode(sum%10) ;
            carry = sum / 10 ;
            ptr = ptr->next ;
        }
      
        if(carry!=0) ptr->next = new ListNode(carry) ;
        return dummy->next ;
    }
};
