
class LRUCache {
public:
    
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        
        node( int key , int val)
        {
            this->key = key;
            this->val=val;
            this->next=NULL;
            this->prev=NULL;
            
        }
    };

    unordered_map<int,node*>mp;
    int capacity;
   
//two dummy nodes to keep track starting and ending point of list  
    node * head = new node(0,0);
    node * tail = new node(0,0);
    

    
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head->next=tail;
        tail->prev= head;
        
    }
    
// function to help a node in the next to head [can say front of our list]
    void insert ( node* currnode)
    {
        currnode->next = head->next;                      // adding node in next of head (front of our cache)
        head->next->prev = currnode;
        head->next= currnode;
        currnode->prev= head;
        mp[currnode->key]=currnode;                       //update map accordingly
    }
    
   
// function to remove a node 
    void remove(node* currnode)
    {
        mp.erase(currnode->key);
        currnode->next->prev =currnode->prev;
        currnode->prev->next=currnode->next;
       
    }
  
  
    int get(int key) 
    {
       // if key is not present than return -1;
        if(mp.find(key)==mp.end())
        {
            return -1;
        }
        //if key is present , than update the node and return the value associated with the key
        // for update first we remove the node and then add at start of list with the help of insert function
        node *currnode = mp[key];
        remove(currnode);
        insert(currnode);
        return currnode->val;
        
    }
    
    void put(int key, int value)
    {
       //if key is already present than we have to update it 
       // similiary we first remove and then add node in front with the help of insert helper 
        if(mp.find(key)!=mp.end())
        {
            remove(mp[key]);
        }
        
        // if size is full then we have to remove the least recently used node
        if(mp.size()==capacity)
        {
            remove(tail->prev);
        }
        insert(new node(key,value));
        
    }
};