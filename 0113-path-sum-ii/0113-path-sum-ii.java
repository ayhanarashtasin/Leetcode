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
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>>variouspath = new ArrayList<>();
        List<Integer>currentpath = new ArrayList<Integer>();
        pathsum(root,variouspath,currentpath,targetSum);
        return variouspath;
    }
    public void pathsum(TreeNode root,List<List<Integer>>variouspath,List<Integer>currentpath,int targetSum){
        if(root==null){
            return;
        }
        currentpath.add(root.val);
        if(root.left==null && root.right==null && targetSum-root.val==0){
            variouspath.add(new ArrayList<>(currentpath));
        }
        pathsum(root.left,variouspath,currentpath,targetSum-root.val);
        pathsum(root.right,variouspath,currentpath,targetSum-root.val);
        currentpath.remove(currentpath.size()-1);
    }
}