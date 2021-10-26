/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
     public List<List<Integer>> levelOrder(TreeNode root) {
       Queue<TreeNode> q = new LinkedList<>(); // queue to store the nodes
        q.add(root);
      List<List<Integer>> res = new ArrayList<>();
        
    if(root == null) return res;
        while(q.size()!= 0){
            List<Integer> branch = new ArrayList<>(); //it stores the root.val at every level
            int size = q.size();
            for(int i=0;i<size;i++){
                root = q.remove();
                branch.add(root.val);
                if(root.left != null) q.add(root.left); //checks to the left if it is not null, it adds to the queue
                if(root.right != null)  q.add(root.right);//checks to the right if it is not null, it adds to the queue
            }
            res.add(new ArrayList<>(branch));
        }
        return res;
    }
}
