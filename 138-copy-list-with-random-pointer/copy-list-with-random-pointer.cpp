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
    void insertNode(Node* head){
	    Node* temp = head;
	    while(temp!=NULL){
		    Node* copyNode = new Node(temp->val);
		    copyNode->next = temp->next;
		    temp->next = copyNode;
		    temp = temp->next->next;
	    }
    }

    void randomPointer(Node* head){
	    Node* temp = head;
	    while(temp!=NULL){
		    Node* copyNode = temp->next;
		    if(temp->random){
		    	copyNode->random=temp->random->next;
		    }
		    else{
		    	copyNode->random=NULL;
		    }
		    temp = temp->next->next;
	    }
    }

    Node* nextPointer(Node* head){
	    Node* temp = head;
	    Node* dNode = new Node(-1);
	    Node* res = dNode;
	    while(temp!=NULL){
		    res->next = temp->next;
		    res = res->next;
		    temp->next = temp->next->next;
		    temp = temp->next;
	    }
	    return dNode -> next;
    }

    Node* copyRandomList(Node* head) {
        insertNode(head);
	    randomPointer(head);
	    return nextPointer(head);
    }
};