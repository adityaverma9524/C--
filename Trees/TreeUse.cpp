#include <iostream>
#include <queue>
#include "TreeNode Class.h"
using namespace std;

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter num of children of " << front->data << endl;
        int numChild;
        cin >> numChild;

        for(int i = 0; i < numChild; i++) {
            int childData;
            cout << "Enter " << i << "th child of" << front->data << endl;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child); 
            pendingNodes.push(child);
        }
    }
    return root;
}

TreeNode<int>* takeInput() {
    int rootData;
    cout << "Enter Data" << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter No. of Children of " << rootData << endl;
    cin >> n;
    for(int i = 0; i < n; i++) {
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int>* root) {

    if(root == NULL) {
        return;
    }

    queue<TreeNode<int>*> pendingNodes;

    cout << root->data << ":";
    for(int i = 0; i < root->children.size(); i++) {
        cout << root->children[i]->data << ",";
        pendingNodes.push(root->children[i]);
    }
    cout << endl;

    while(pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout << front->data << ":";
        for(int i = 0; i < front->children.size(); i++) {
            cout << front->children[i]->data << ",";
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }

    /*for(int i = 0; i < root->children.size(); i++) {
        printTree(root->children[i]);
    }
    */
}

int numNodes(TreeNode<int>* root) {
    if(root == NULL) {
        return 0;
    }
    
    int ans = 1;
    for(int i = 0; i < root->children.size(); i++) {
        ans += numNodes(root->children[i]);
    }
    return ans;
}

int heightOfTree(TreeNode<int>* root) {
    queue<int> heights;
    for(int i = 0; i < root->children.size(); i++) {
        int ans = heightOfTree(root->children[i]);
        heights.push(ans);
    }

    int max = 0;
    while(heights.size() != 0) {
        int front = heights.front();
        heights.pop();
        if(front > max) {
            max = front;
        }
    }
    return max + 1;
}

void printAtLevelK(TreeNode<int>* root, int k) {
    if(root == NULL) {
        return;
    }
    
    if(k == 0) {
        cout << root->data << endl;
        return;
    }

    for(int i = 0; i < root->children.size(); i++) {
        printAtLevelK(root->children[i], k - 1);
    }
}

int numOfLeafNodes(TreeNode<int>* root) {
    if(root == NULL) {
        return 0;
    }

    if(root->children.size() == 0) {
        return 1;
    }
    
    int ans = 0;
    for(int i = 0; i < root->children.size(); i++) {
        ans += numOfLeafNodes(root->children[i]);
    }
    return ans;
}

void preOrder(TreeNode<int>* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    for(int i = 0; i < root->children.size(); i++) {
        preOrder(root->children[i]);
    }
}

void postOrder(TreeNode<int>* root) {
    if(root == NULL) {
        return;
    }

    for(int i =0; i < root->children.size(); i++) {
        postOrder(root->children[i]);
    }
    cout << root->data << " ";
}

void deleteTree(TreeNode<int>* root) {
    for(int i = 0; i < root->children.size(); i++) {
        deleteTree(root->children[i]);
    }
    delete root;
}

void getSecondLargestNode_Helper(TreeNode<int>* root, TreeNode<int>* &largest, TreeNode<int>* &SecondLargest) {
    if(root->data > largest->data) {
        SecondLargest = largest;
        largest = root;
    } else if(SecondLargest == NULL && (root->data < largest->data)) {
        SecondLargest = root;
    } else if((root->data < largest->data) && (root->data > SecondLargest->data)) {
        SecondLargest = root;
    }

    for(int i = 0; i < root->children.size(); i++) {
        getSecondLargestNode_Helper(root->children[i], largest, SecondLargest);
    }
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    if(root == NULL) {
        return NULL;
    }

    TreeNode<int>* largest = root;
    TreeNode<int>* secondLargest = NULL;

    for(int i = 0; i < root->children.size(); i++) {
        getSecondLargestNode_Helper(root->children[i], largest, secondLargest);
    }

    return secondLargest;
}

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main() {
    /*TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);
    root->children.push_back(node1);
    root->children.push_back(node2);
    printTree(root);
    */
    TreeNode<int>* root = takeInputLevelWise();
    printTree(root);
    TreeNode<int>* ans = getSecondLargestNode(root);
    cout << ans->data << endl;
    /*cout << "No. of nodes : " << numNodes(root) << endl;
    cout << "Height of tree : " << heightOfTree(root) << endl;
    printAtLevelK(root, 3);
    
    cout << "No. of Leaf Nodes : " << numOfLeafNodes(root) << endl;
     */
    
    //preOrder(root);
    //postOrder(root);
    
     //TODO delete the tree
    delete root;               // TreeNode Class Destructor deletes the children
    //deleteTree(root);
}