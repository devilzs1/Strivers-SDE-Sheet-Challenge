/*****************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

******************************************************/

bool check(BinaryTreeNode<int> *first, BinaryTreeNode<int> *second)
{
    if (first == NULL && second == NULL)
        return true;
    if ((first == NULL && second != NULL) || (first != NULL && second == NULL))
        return false;
    if (first->data != second->data)
        return false;

    return (check(first->left, second->right), check(first->right, second->left));
}

bool isSymmetric(BinaryTreeNode<int> *root)
{
    // Write your code here.
    return check(root, root);
}