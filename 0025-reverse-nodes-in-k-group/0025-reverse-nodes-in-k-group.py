# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if k == 1: 
            return head
        counter = 0
        previous = None
        current = it = head
        firstTime = True
        
        while it != None:
            it = it.next
            counter = counter + 1
            if counter == k:
                newPrevious = current
                lastPrevious = previous
                while current != it:
                    aux = current.next
                    current.next = previous
                    previous = current
                    current = aux
                if firstTime:
                    firstTime = False
                    head = previous
                else:
                    lastPrevious.next = previous
                previous = newPrevious
                counter = 0
                
        if current != None:
            previous.next = current
        else:
            previous.next = None
            
        return head