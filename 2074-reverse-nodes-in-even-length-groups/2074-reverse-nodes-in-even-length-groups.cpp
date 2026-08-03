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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* curr = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        int currS = 1;
        while(curr != nullptr){
            vector<int> A;
            for(int i = 0;i < currS;i++){
                if(curr){
                    A.push_back(curr->val);
                    curr = curr->next;
                }
                else{
                    break;
                }
            }
            int s = A.size();
            if(s % 2){
                for(int i = 0;i < s;i++){
                    ListNode* newNode = new ListNode(A[i]);
                    temp->next = newNode;
                    temp = temp->next;
                }
            }
            else{
                for(int i = s -1;i >= 0;i--){
                    ListNode* newNode = new ListNode(A[i]);
                    temp->next = newNode;
                    temp = temp->next;
                }
            }
            currS++;
        }
        return dummy->next;
    }
};


// ListNode* curr = head;
//         stack<ListNode*> st;
//         ListNode* dummy = new ListNode(0);
//         ListNode* temp = dummy;
//         int currS = 1;
//         while(curr != nullptr){
//             for(int i = 0;i < currS;i++){
//                 if(curr) {
//                     st.push(curr);
//                     curr = curr->next;
//                 } else {
//                     break;
//                 }
//             }
//             stack<ListNode*> out;
//             if(st.size() % 2 == 1){
//                 while(!st.empty()){
//                     out.push(st.top());
//                     st.pop();
//                 }
//             }
//             int s = st.empty() ? out.size() : st.size();

//             if(s % 2 == 1){
//                while(!out.empty()){
//                     ListNode* newNode = out.top();
//                     out.pop();
//                     temp->next = newNode;
//                     temp = temp->next;
//                }
//             }
//             else{
//               //  cout << "st->" << st.top()->val;
//               while(!st.empty()){
//                 ListNode* newNode = st.top();
//                 st.pop();
//                 temp->next = newNode;
//                 temp = temp->next;
//               }
//             }
//             currS++;
//         }
//         ListNode* result = dummy->next;
//         delete dummy;  
//         return result;