class TreeNode {
	int val;
	TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class SubtreeOfAnotherTree_572 {
public boolean isSame(TreeNode s, TreeNode t)
    {
        if (s==null && t==null)
            return true;
        else if (s==null || t==null)
            return false;
        else if ( s.val == t.val )
        {
            return isSame(s.left, t.left) && isSame(s.right, t.right);
        }
        else
            return false;
    }

    public boolean isMySubTree(TreeNode s, TreeNode t)
    {
        if (s == null)
            return false;
        if (isSame(s, t))
            return true;
        return isMySubTree(s.left, t) || isMySubTree(s.right, t);
    }

    public boolean isSubtree(TreeNode s, TreeNode t) {
        if (s == null || t == null)
            return true;
        
       return isMySubTree(s, t) || isMySubTree(t, s);
    }
    public static void main(String[] args)
    {

    }

}	// LowestCommonAncestorOfBST_235

