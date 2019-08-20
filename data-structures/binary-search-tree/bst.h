class BST {
    private:
        struct node{
            int key;
            node *left;
            node *right;
        };
        node *root;
        void addLeafPrivate(int key, node *ptr);
        void printInOrderPrivate(node *ptr);
        void removeNodePrivate(int key,node *parent);
        void removeRootMatch();
        int findSmallestPrivate(node *ptr);
        void removeMatch(node *parent,node *match,bool left);//this bool indicates the relation between the parent and the match (if left child => true)

    public:
        BST();
        node *createLeaf(int key);
        void addLeaf(int key);
        void printInOrder();
        void removeNode(int key);
        int findSmallest();
}
