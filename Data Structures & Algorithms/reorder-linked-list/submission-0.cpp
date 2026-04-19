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
    void reorderList(ListNode* head) {
       ListNode* slow = head;
       ListNode* fast = head;
       while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
       }
       ListNode* second = slow->next;
       slow->next = nullptr;
       ListNode* press = second;
       ListNode* temp = second;
       ListNode* prev = nullptr;
       while(temp != nullptr){
        press = temp->next;
        temp->next = prev;
        prev = temp;
        temp = press;
       }
       ListNode* first = head;
       ListNode* secondhalf = prev;
       while(secondhalf){
        ListNode* t1 = first->next;
        ListNode* t2 = secondhalf->next;

        first->next = secondhalf;
        secondhalf->next = t1;

        first = t1;
        secondhalf = t2;
       }
    }
};
