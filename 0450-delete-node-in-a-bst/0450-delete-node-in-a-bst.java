class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        if(root==null){
            return null;
        }
        if(root.val==key){
            return helper(root);
        }
        TreeNode dummy = root;
        while(root!=null){
            if(root.val>key){
                if(root.left!=null && root.left.val==key){
                   root.left =  helper(root.left);
                }
                else{
                    root=root.left;
                }
            }
            else{
                if(root.right!=null && root.right.val==key){
                    root.right = helper(root.right);
                }
                else{
                    root=root.right;
                }
            }
        }
        return dummy;
    }
    static TreeNode helper(TreeNode root){
        if(root.left==null){
            return root.right;
        }
        if(root.right==null){
            return root.left;
        }
        TreeNode rightchildren = root.right;
        TreeNode lastright = findlastright(root.left);
        lastright.right = rightchildren;
        return root.left;


    }
    static TreeNode findlastright(TreeNode root){
        if(root.right==null){
            return root;
        }
        return findlastright(root.right);
    }
}