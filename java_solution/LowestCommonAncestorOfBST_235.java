class TreeNode {
	int val;
	TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class LowestCommonAncestorOfBST_235 {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if ((root.val-p.val)*(root.val-q.val)<=0)
        	return root;
        else if (root.val>p.val && root.val>q.val)
        	return lowestCommonAncestor(root.left, p, q);
        else
    		return lowestCommonAncestor(root.right, p, q);
    }

    public static void main(String[] args) 
    {
        LowestCommonAncestorOfBST_235 test;
    }
}	// LowestCommonAncestorOfBST_235

