/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val,Node _left,Node _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {

    Node prev;

    public Node treeToDoublyList(Node root) {
        if(root == null){
            return null;
        }

        // Convert the left subtree.
        Node leftHead = treeToDoublyList(root.left);
        if(prev != null){
            prev.right =root;
            root.left=prev;
        }

        // Set the root node as the previously accessed node.
        prev = root;

        // Convert the right subtree.
        Node rightHead = treeToDoublyList(root.right);
        if(rightHead != null){
            root.right=rightHead;
            rightHead.left=root;
        }

        // Build the link between the head node and the tail node.
        Node head = leftHead == null?root:leftHead;
        head.left=prev;
        prev.right=head;
        return head;
    }
}