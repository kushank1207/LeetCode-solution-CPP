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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        
        ListNode* head = NULL; 
        
        
        if(list1->val <= list2->val) {
            head = list1;
            list1 = list1->next;
        }
        else {
            head = list2;
            list2 = head->next;
        }
        
        ListNode* temp = head;
        while(list1 && list2) {
            if(list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
            }
            
        }
        
        if(list1)
            temp->next = list1;
        if(list2)
            temp->next = list2;
        return head;
        
        // if(list1 == NULL)
        //     return list2;
        // else if(list2 == NULL)
        //     return list1;
        // else if(list1->val <= list2->val) {
        //     list1->next = mergeTwoLists(list1->next, list2);
        //     return list1;
        // } else {
        //     list2->next = mergeTwoLists(list1, list2->next);
        //     return list2;
        // }
        
    }
};