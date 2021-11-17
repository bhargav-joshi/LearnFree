// Link to the question in leetcode
// https://leetcode.com/problems/add-two-numbers/




class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    ListNode p1 = l1;
        ListNode p2 = l2;
        
        ListNode p3 = null; // Pointer for the result list
        ListNode head = null; // Head Pointer for the result list
        
        int carry = 0;
        while(p1 != null || p2 != null || carry > 0) {
            
            int v1 = 0;
            int v2 = 0;
            
            // Get current digit value from list 1 then shift the pointer
            if(p1 != null) {
                v1 = p1.val;
                p1 = p1.next;
            }
            
            // Get current digit value from list 2 then shift the pointer
            if(p2 != null) {
                v2 = p2.val;
                p2 = p2.next;
            }
            
            // Add digits and the previous carry then calculate the digit and carry
            int sum = v1 + v2 + carry;
            int currentVal = sum % 10;
            carry = sum / 10;
            
			// Handle first digit
            if(p3 == null) {
                p3 = new ListNode(currentVal);
                head = p3;
            }
            else {
                p3.next = new ListNode(currentVal);
                p3 = p3.next;
            }
            
        }
        
        return head;
    }
}
