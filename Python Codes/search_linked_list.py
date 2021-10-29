''' Program to search an element in a linked list
    using an iterative approach '''

# Node class
class Node:
    
    # Init method to initialise the node object
    def __init__(self, data):
        self.data = data 
        self.next = None 

# Linked List class
class LinkedList:
    def __init__(self):
        self.head = None # Initialize head as None

    # This function insert a new node at the beginning of the linked list
    def add(self, new_data):
    
        # Creating a node
        node = Node(new_data)

        # Make next of new node as head
        node.next = self.head

        # Move the head so that it points
        # to new node 
        self.head = node

    # This Function checks whether the value ele present
    # in the linked list or not
    def search(self, ele):

        # Initialize current to head
        current = self.head

        while current != None:
            if current.data == ele:
                return True # ele found
            
            current = current.next
        
        return False # ele not found


# Driver Code
if __name__ == '__main__':

    # Create a list to test the code
    llst = LinkedList()
    llst.add(10);
    llst.add(14);
    llst.add(67);
    llst.add(21);

    if llst.search(15):
        print("Yes")
    else:
        print("No")

