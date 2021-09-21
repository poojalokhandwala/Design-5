// Time Complexity : O(N)
// Space Complexity :O(N)
// Did this code successfully run on Leetcode : yes
// Any problem you faced while coding this : no

class Solution {
public:
    unordered_map<Node*, Node*> map;
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return head;
        Node* curr = head;
        Node* copyHead = clone(head);
        map.insert({head, copyHead});
        while(curr != NULL){
            Node* copyNext = clone(curr->next);
            Node* copyRandom = clone(curr->random);
            copyHead->next = copyNext;
            copyHead->random = copyRandom;
            copyHead = copyHead->next;
            curr = curr->next;
        }
        return map[head];
    }
    
    Node* clone(Node* node){
        if(node == NULL)
            return node;
        if(map.find(node) != map.end())
            return map[node];
        Node* copyNode = new Node (node->val);
        map.insert({node, copyNode});
        return copyNode;
    }
};

// Time Complexity : O(N)
// Space Complexity :O(1)
// Did this code successfully run on Leetcode : yes
// Any problem you faced while coding this : no

class Solution {
public:
    //unordered_map<Node*, Node*> map;
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return head;
        //step 1 : creating the copy and joining them
        Node* curr = head;
        while(curr != NULL){
            Node* currCopy = new Node (curr->val);
            currCopy->next = curr->next;
            curr->next = currCopy;
            curr = curr->next->next;
        }
        //step 2 : setting the random pointers
        curr = head;
        while(curr != NULL)
        {
            if(curr->random != NULL)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        //step-3 : splitting the lists;
        curr = head;
        Node* copyHead = curr->next;
        Node* currCopy = curr->next;
        while(curr != NULL){
            curr->next = curr->next->next;
            if(currCopy->next != NULL)
                currCopy->next = currCopy->next->next;
            curr = curr->next;
            currCopy = currCopy->next;
        }
        return copyHead;
    }
};
