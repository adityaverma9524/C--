#include <iostream>
#include <queue>
#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include "BinaryTreeNode.h"
#include "BinarySearchTree.h"
using namespace std;

BinaryTreeNode<int>* takeInputLevelWise() {
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0) {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if(leftChildData != -1) {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if(rightChildData != -1) {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTreeLevelWise(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return;
    }

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0) {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout << front->data << ":";
        if(front->left != NULL) {
            cout << "L" << front->left->data;
            pendingNodes.push(front->left);
        }
        if(front->right != NULL) {
            cout << "R" << front->right->data;
            pendingNodes.push(front->right);
        }
        cout << endl;   
    }
}

void printTree(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << ":";  
    if(root->left != NULL) {
        cout << "L" << root->left->data;
    }

    if(root->right != NULL) {
        cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode(rootData);
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

int numNodes(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return 0;
    }

    return 1 + numNodes(root->left) + numNodes(root->right);    
}

void inorder(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

BinaryTreeNode<int>* BuildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE) {
    if(inS > inE) {
        return NULL;
    }

    int rootData = pre[preS];
    int rootIndex = -1;
    for(int i = inS; i <= inE; i++) {
        if(in[i] == rootData) {
            rootIndex = i;
            break;
        }
    }

    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPreS = preS + 1;
    int lPreE = lInE - lInS + lPreS;
    int rPreS = lPreE + 1;
    int rPreE = preE;
    int rInS = rootIndex + 1;
    int rInE = inE;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = BuildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right = BuildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
    return root;
}

BinaryTreeNode<int>* BuildTree(int* in, int* pre, int size) {
    return BuildTreeHelper(in, pre, 0, size - 1, 0, size - 1);
}

int height(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}

int diameter(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return 0;
    }

    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1, max(option2, option3));
}

pair<int, int> heightDiameter(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);
    int lh = leftAns.first;
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));

    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

int minimum(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return INT_MAX;
    }

    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

int maximum(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return INT_MIN;
    }

    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

bool isBST(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return true;
    }

    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
    return output;
}

class IsBSTReturn {
  public:  
    bool isBST;
    int minimum;
    int maximum;
};

IsBSTReturn isBST2(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        IsBSTReturn output;
        output.isBST = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }

    IsBSTReturn leftOutput = isBST2(root->left);
    IsBSTReturn rightOutput = isBST2(root->right);
    int minimum = min(root->data, min(leftOutput.minimum, rightOutput.minimum));
    int maximum = max(root->data, max(leftOutput.maximum, rightOutput.maximum));
    bool isBSTFinal = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) &&
     leftOutput.isBST && rightOutput.isBST;
    IsBSTReturn output;
    output.isBST = isBSTFinal;
    output.minimum = minimum;
    output.maximum = maximum;
    return output;
}

bool isBST3(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX) {
    if(root == NULL) {
        return true;
    }

    if(root->data < min || root->data > max) {
        return false;
    }

    bool isLeftOK = isBST3(root->left);
    bool isRightOk = isBST3(root->right);
    return isLeftOK && isRightOk;
}

vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data) {
    if(root == NULL) {
        return NULL;
    }

    if(root->data == data) {
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int>* leftOutput = getRootToNodePath(root->left, data);
    if(leftOutput != NULL) {
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int>* rightOutput = getRootToNodePath(root->right, data);
    if(rightOutput != NULL) {
        rightOutput->push_back(root->data);
        return rightOutput;
    } else {
        return NULL;
    }
}

int main() {
    /*BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
    root->left = node1;
    root->right = node2;
    */

    /*int in[] = {4,2,5,1,8,6,9,3,7};
    int pre[] = {1,2,4,5,3,6,8,9,7};
    BinaryTreeNode<int>* root = BuildTree(in, pre, 9);
    cout << "Num of nodes : " << numNodes(root) << endl;
    inorder(root);
    */

    /*BinaryTreeNode<int>* root = takeInputLevelWise();
    printTreeLevelWise(root);
    vector<int>* output = getRootToNodePath(root, 8);
    for(int i = 0; i < output->size(); i++) {
        cout << output->at(i) << endl;
    }

    delete output;

    /*cout << isBST(root) << endl;
    cout << isBST3(root) << endl;

    /*IsBSTReturn output = isBST2(root);
    cout << "isBST : " << output.isBST << endl;

    /*cout << "Height : " << height(root) << endl;
    cout << "Diameter : " << diameter(root) << endl;

    /*pair<int, int> p = heightDiameter(root);
    cout << "Height : " << p.first << endl;
    cout << "Diameter : " << p.second  << endl;

    delete root;
    */
    BST b;
    b.insert(5);
    b.insert(6);
    b.printTree();
}