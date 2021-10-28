 vector <int> zigZagTraversal(Node* root)
    {
        //just do level order traversal and add reverse array if flag is false else add the array 
       deque<Node*>q;
        q.push_back(root);
        vector<int>v;
        v.push_back(root->data);
       int  flag=1;
       
        while(!q.empty()){
            int n=q.size();
         
            for(int i=0;i<n;i++)
            {
                
               if(!flag) {
                  Node* temp=q.back();
                q.pop_back();
                if (temp->left) {
                    q.push_front(temp->left);
                    v.push_back(temp->left->data);
                }
                if (temp->right) {
                    q.push_front(temp->right);
                    v.push_back(temp->right->data);
                }
               }
               else {
                  Node* temp = q.front();
                q.pop_front();
                if (temp->right) {
                    q.push_back(temp->right);
                    v.push_back(temp->right->data);
                }
                if (temp->left) {
                    q.push_back(temp->left);
                    v.push_back(temp->left->data);
                }
               }
               
            }flag=1-flag;
            
        }
       
        return v;
    }
