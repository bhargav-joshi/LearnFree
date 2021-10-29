class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if not lists: return 
        result=[]
        for i in lists:
            while i:
                result.append(i.val)
                i=i.next
        if not result: return
        result.sort()
        head=ListNode(result.pop(0))
        m=head
        while result:
            m.next=ListNode(result.pop(0))
            m=m.next
        return head
