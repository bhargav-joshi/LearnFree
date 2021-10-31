#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node{
    int val;
    Node* right;
    Node* left;
    int height;
}*root=NULL;

int nodeheight(Node* root){
    int hl,hr;

    hl=root && root->left?root->left->height:-1;
    hr=root && root->right?root->right->height:-1;

    return hl>hr?hl+1:hr+1;
}
int BalanceFactor(Node* root){
    int hl,hr;
    hl=root && root->left?root->left->height:0;
    hr=root && root->right?root->right->height:0;

    return hl-hr;
}
Node* LLrotation(Node* p){
    Node* pl=p->left;
    Node* plr =pl->right;
    pl->right=p;
    p->left=plr;

    p->height=nodeheight(p);
    pl->height=nodeheight(pl);

    if(root==p)
        root=pl;
    return pl;
}
Node* RRrotation(Node* p){
    Node* pr=p->right;
    Node* prl=pr->left;

    p->right=prl;
    pr->left=p;

    p->height=nodeheight(p);
    pr->height=nodeheight(pr);

    if(root==pr)
        root=pr;
    return pr;
}
Node* LRRotation(Node* p){
    struct Node *pl=p->left;
    struct Node *plr=pl->right;

    pl->right=plr->left;
    p->left=plr->right;

    plr->left=pl;
    plr->right=p;

    pl->height=nodeheight(pl);
    p->height=nodeheight(p);
    plr->height=nodeheight(plr);

    if(root==p)
        root=plr;
    return plr;
}
Node* RLRotation(Node* p){
    Node* pr=p->right;
    Node* prl=pr->left;

    pr->left=prl->right;
    p->right=prl->left;
    prl->left=p;
    prl->right=pr;

    pr->height=nodeheight(pr);
    p->height=nodeheight(p);
    prl->height=nodeheight(prl);

    if(root==p)
        root=prl;
    return prl;
}
Node* insert(Node* root, int val){
    if(root==NULL){
        root=malloc(sizeof(Node));
        root->val=val;
        root->left=root->right=NULL;
        root->height=0;
    }
    else if(val<root->val)
        root->left=insert(root->left,val);
    else if(val>root->val)
        root->right=insert(root->right,val);

    root->height=nodeheight(root);

    if(BalanceFactor(root)==2 && BalanceFactor(root->left)==1)
        return LLrotation(root);
    else if(BalanceFactor(root)==2 && BalanceFactor(root->left)==-1)
        return LRRotation(root);
    else if(BalanceFactor(root)==-2 && BalanceFactor(root->right)==-1)
        return RRrotation(root);
    else if(BalanceFactor(root)==-2 && BalanceFactor(root->right)==1)
        return RLRotation(root);
    
    return root;
}
void preorder(Node* p){
    if(p){
        printf("%d ",p->val);
        preorder(p->left);
        preorder(p->right);
    }
}
int main()
{
    int n,val;
    printf("Enter number of elements to be inserted in tree :");
    scanf("%d",&n);

    printf("Enter the values of the tree : \n");
    for(int i=0;i<n;i++){
       scanf("%d",&val);
       root=insert(root,val);
    }
    preorder(root);
    return 0;
}
