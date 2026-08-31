1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
14        int minDistance = INT_MAX;
15        int maxDistance = -1;
16
17        ListNode* prev = head;
18        ListNode* curr = head->next;
19
20        int pos = 1;
21        int lastCritical = -1;
22        int firstCritical = -1;
23
24        while(curr->next != NULL){
25            if((curr->val > prev->val && curr->val > curr->next->val)||
26               (curr->val < prev->val && curr->val < curr->next->val)){
27
28                if(firstCritical == -1) {
29                    firstCritical = pos;
30                }
31
32                if(lastCritical != -1){
33                    minDistance = min(minDistance, pos-lastCritical);
34                }
35                lastCritical = pos;
36               }
37            prev = curr;
38            curr = curr->next;
39            pos++;
40
41        }
42         if (firstCritical == -1 || firstCritical == lastCritical) {
43            return {-1, -1};
44        }
45
46        maxDistance = lastCritical - firstCritical;
47
48        return {minDistance, maxDistance};
49
50        
51    }
52};