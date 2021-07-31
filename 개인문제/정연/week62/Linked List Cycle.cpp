/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL)
            return false;
        
        unordered_map<ListNode*, bool> visited;
        
        while(true){
            if(visited.find(head) != visited.end()){
                return true;
            }            
            
            visited[head] = true;
            
            if(head -> next != NULL)
                head = head -> next;
            else
                return false;
        }
    }
};
