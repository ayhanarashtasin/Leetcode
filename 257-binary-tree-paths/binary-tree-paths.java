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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> pathlist = new ArrayList<String>();
        variouspathlist(root,pathlist,"");
        return pathlist;
    }
    public void variouspathlist(TreeNode root,List<String> pathlist,String path){
        if(root==null){
            return;
        }
        if(path.isEmpty()){
            path = Integer.toString(root.val);
        }
        else{
            path = path +"->"+root.val;
        }
        if(root.left==null && root.right==null){
            pathlist.add(path);
        }
        variouspathlist(root.left,pathlist,path);
        variouspathlist(root.right,pathlist,path);
        path = path.substring(0,path.length()-1);
    }
}