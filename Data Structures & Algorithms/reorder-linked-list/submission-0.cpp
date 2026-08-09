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
private:
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode* newHead = head;
        if (head->next) {
            newHead = reverseList(head->next);
            head->next->next = head;
        }
        head->next = nullptr;

        return newHead;
    }
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return ;
        ListNode* slow = head ;
        ListNode* fast = head ;

        while(fast && fast->next){
            slow = slow->next ;
            fast = fast->next->next ;
        }
        ListNode* list2 = slow->next ;
        slow->next = nullptr ;
        list2 = reverseList(list2) ;

        ListNode* ptr1 = head ;

        while(list2){
            ListNode* temp1 = ptr1->next ;
            ptr1->next = list2 ;
            ListNode* temp2 = list2->next ;
            list2->next = temp1 ;
            ptr1 = temp1 ;
            list2 = temp2 ;
        }
        
    }
};
