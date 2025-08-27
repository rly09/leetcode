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
    ListNode* reverseLinkedList(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp != nullptr){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev; // new head after reversal
    }

    ListNode* findKthNode(ListNode* temp, int k){
        k -= 1;
        while(temp != nullptr && k > 0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = nullptr;

        while(temp != nullptr){
            ListNode* kthNode = findKthNode(temp, k);
            if(kthNode == nullptr){ // not enough nodes
                if(prevNode) prevNode->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = nullptr;

            ListNode* newHead = reverseLinkedList(temp);

            if(temp == head) head = newHead;
            else prevNode->next = newHead;

            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};