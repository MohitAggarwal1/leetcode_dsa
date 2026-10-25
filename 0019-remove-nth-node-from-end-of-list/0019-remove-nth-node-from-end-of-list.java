class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // Handle single node list
        if (head.next == null) return null;
        
        ListNode ptr = head;
        ListNode temp = head;
        
        // Move ptr forward n times to create the gap
        int i = 1;
        while (i <= n) {
            ptr = ptr.next; 
            i++;
        }
        
        // If ptr becomes null, we need to remove the head
        if (ptr == null) return head.next;
        
        // Move both until ptr reaches the last node
        while (ptr.next != null) {
            ptr = ptr.next;
            temp = temp.next;
        } 
        
        // Skip the nth node from the end
        if (temp.next != null) {
            temp.next = temp.next.next;
        }
        
        return head;
    }
}