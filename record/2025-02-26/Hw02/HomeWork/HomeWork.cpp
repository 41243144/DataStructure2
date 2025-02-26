/* 
    2.  請寫一完整程式測試講義中
        (1)  計算  Binary tree 之節點數 
        (2)  計算 Binary tree 之高度
        (3)  計算  Binary tree  之  leaf nodes  個數
        (4)  做  Binary tree  之  copy
        (5)  判斷給定之兩個二元樹是否相等等功能
*/

//Tree.cpp 
//demonstrates binary search tree
#include <iostream>
#include <stack>
using namespace std;
////////////////////////////////////////////////////////////////
class Node
{
public:
    int iData;                //data item (key)
    double dData;             //data item
    Node* pLeftChild;         //this node's left child
    Node* pRightChild;        //this node's right child
    //-------------------------------------------------------------
                                    //constructor
    Node() : iData(0), dData(0.0), pLeftChild(NULL),
        pRightChild(NULL)
    {
    }
    //-------------------------------------------------------------
    ~Node()                   //destructor
    {
        cout << "X-" << iData << " ";
    }
    //-------------------------------------------------------------
    void displayNode()        //display ourself: {75, 7.5}
    {
        cout << '{' << iData << ", " << dData << "} ";
    }
};  //end class Node
////////////////////////////////////////////////////////////////
class Tree
{
private:
    Node* pRoot;              //first node of tree
    //-------------------------------------------------------------
public:
    Tree() : pRoot(NULL)         //constructor
    {
    }
    //-------------------------------------------------------------
    Node* getRoot() {
        return pRoot;
    }
    void updateRoot(Node* t) {
        pRoot = t;
    }
    //-------------------------------------------------------------
    Node* find(int key)          //find node with given key
    {                         //(assumes non-empty tree)
        Node* pCurrent = pRoot;             //start at root
        while (pCurrent->iData != key)       //while no match,
        {
            if (key < pCurrent->iData)        //go left?
                pCurrent = pCurrent->pLeftChild;
            else                             //or go right?
                pCurrent = pCurrent->pRightChild;
            if (pCurrent == NULL)             //if no child,
                return NULL;                  //didn't find it
        }
        return pCurrent;                    //found it
    }  //end find()
    //-------------------------------------------------------------
    void insert(int id, double dd) //insert new node
    {
        Node* pNewNode = new Node;          //make new node
        pNewNode->iData = id;               //insert data
        pNewNode->dData = dd;
        if (pRoot == NULL)                     //no node in root
            pRoot = pNewNode;
        else                                //root occupied
        {
            Node* pCurrent = pRoot;          //start at root
            Node* pParent;
            while (true)                      //(exits internally)
            {
                pParent = pCurrent;
                if (id < pCurrent->iData)      //go left?
                {
                    pCurrent = pCurrent->pLeftChild;
                    if (pCurrent == NULL)       //if end of the line,
                    {                       //insert on left
                        pParent->pLeftChild = pNewNode;
                        return;
                    }
                }  //end if go left
                else                          //or go right?
                {
                    pCurrent = pCurrent->pRightChild;
                    if (pCurrent == NULL)       //if end of the line
                    {                       //insert on right
                        pParent->pRightChild = pNewNode;
                        return;
                    }
                }  //end else go right
            }  //end while
        }  //end else not root
    }  //end insert()
    //-------------------------------------------------------------
    void traverse(int traverseType)
    {
        switch (traverseType)
        {
        case 1: cout << "\nPreorder traversal: ";
            preOrder(pRoot);
            break;
        case 2: cout << "\nInorder traversal:  ";
            inOrder(pRoot);
            break;
        case 3: cout << "\nPostorder traversal: ";
            postOrder(pRoot);
            break;
        }
        cout << endl;
    }
    //-------------------------------------------------------------
    void preOrder(Node* pLocalRoot)
    {
        if (pLocalRoot != NULL)
        {
            cout << pLocalRoot->iData << " ";    //display node
            preOrder(pLocalRoot->pLeftChild);    //left child
            preOrder(pLocalRoot->pRightChild);   //right child
        }
    }
    //-------------------------------------------------------------
    void inOrder(Node* pLocalRoot)
    {
        if (pLocalRoot != NULL)
        {
            inOrder(pLocalRoot->pLeftChild);     //left child
            cout << pLocalRoot->iData << " ";    //display node
            inOrder(pLocalRoot->pRightChild);    //right child
        }
    }
    //-------------------------------------------------------------
    void postOrder(Node* pLocalRoot)
    {
        if (pLocalRoot != NULL)
        {
            postOrder(pLocalRoot->pLeftChild);   //left child
            postOrder(pLocalRoot->pRightChild);  //right child
            cout << pLocalRoot->iData << " ";    //display node
        }
    }
    //-------------------------------------------------------------
    void displayTree()
    {
        stack<Node*> globalStack;
        globalStack.push(pRoot);
        int nBlanks = 32;
        bool isRowEmpty = false;

        while (isRowEmpty == false)
        {
            stack<Node*> localStack;
            isRowEmpty = true;

            for (int j = 0; j < nBlanks; j++)
                cout << ' ';

            while (globalStack.empty() == false)
            {
                Node* temp = globalStack.top();
                globalStack.pop();
                if (temp != NULL)
                {
                    cout << temp->iData;
                    localStack.push(temp->pLeftChild);
                    localStack.push(temp->pRightChild);

                    if (temp->pLeftChild != NULL ||
                        temp->pRightChild != NULL)
                        isRowEmpty = false;
                }
                else
                {
                    cout << "--";
                    localStack.push(NULL);
                    localStack.push(NULL);
                }
                for (int j = 0; j < nBlanks * 2 - 2; j++)
                    cout << ' ';
            }  //end while globalStack not empty
            cout << endl;
            nBlanks /= 2;
            while (localStack.empty() == false)
            {
                globalStack.push(localStack.top());
                localStack.pop();
            }
        }  //end while isRowEmpty is false
    }  //end displayTree()
//-------------------------------------------------------------
    void destroy()                         //deletes all nodes
    {
        destroyRec(pRoot);
    }              //start at root
//-------------------------------------------------------------
    void destroyRec(Node* pLocalRoot)      //delete nodes in
    {                                   //   this subtree
        if (pLocalRoot != NULL)
        {                                //uses postOrder
            destroyRec(pLocalRoot->pLeftChild);  //left subtree
            destroyRec(pLocalRoot->pRightChild); //right subtree
            delete pLocalRoot;               //delete this node
        }
    }

    //-------------------------------------------------------------
     //*******
    // (1)  計算  Binary tree 之節點數 
    int Calculate_Node_number()
    {
        return Node_number(pRoot);
    }
    int Node_number(Node* t) {
        if (t == nullptr) {
            return 0;
        }
        return Node_number(t->pLeftChild) + Node_number(t->pRightChild) + 1;
        
    }
    // (2)  計算 Binary tree 之高度
    int Calculate_Tree_Height()
    {
        return Tree_Height(pRoot, 0);
    }
    // BST heifht
    int Tree_Height(Node* t, int hight) {
        if (t == nullptr) return hight;
        return max(Tree_Height(t->pLeftChild, hight + 1), Tree_Height(t->pRightChild, hight + 1));
    }
    // (3)  計算  Binary tree  之  leaf nodes  個數
    int Calculate_Leaf_Node() {
        return Leaf_Node(pRoot);
    }
    int Leaf_Node(Node* t) {
        if (t == nullptr) return 0;
        else if (t->pLeftChild == nullptr && t->pRightChild == nullptr) {
            return 1;
        }
        return Leaf_Node(t->pLeftChild) + Leaf_Node(t->pRightChild);
    }

    // (4)  做  Binary tree  之  copy
    Node* Copy_Tree(Node* t) {
        if (t == nullptr) return nullptr;
        Node* newTreeNode = new Node;
        newTreeNode->iData = t->iData;
        newTreeNode->dData = t->dData;

        newTreeNode->pLeftChild = Copy_Tree(t->pLeftChild);
        newTreeNode->pRightChild = Copy_Tree(t->pRightChild);
        return newTreeNode;
    }
    // (5)  判斷給定之兩個二元樹是否相等等功能
    bool Judge_Equal(Node* t) {
        return isEqual(pRoot, t);
    }

    bool isEqual(Node* t1, Node* t2) {
        if (t1 == nullptr && t2 == nullptr) {
            return true;
        }
        else if (t1->dData == t2->dData && t1->iData == t2->iData) {
            return isEqual(t1->pLeftChild, t2->pLeftChild) && isEqual(t1->pRightChild, t2->pRightChild);
        }
        else {
            return false;
        }
    }

    //************

};  //end class Tree
////////////////////////////////////////////////////////////////

int main()
{
    int value;
    char choice = '0';
    Node* found;
    Tree theTree;                          //create tree    

    theTree.insert(50, 5.0);               //insert nodes
    theTree.insert(25, 2.5);
    theTree.insert(75, 7.5);
    theTree.insert(12, 1.2);
    theTree.insert(37, 3.7);
    theTree.insert(43, 4.3);
    theTree.insert(30, 3.0);
    theTree.insert(33, 3.3);
    theTree.insert(87, 8.7);
    theTree.insert(93, 9.3);
    theTree.insert(97, 9.7);

    while (choice != 'q')                   //interact with user
    {                                   //until user types 'q'
        cout << "Enter first letter of " << endl;
        cout << "show(s)\ninsert(i)\nfind(f)\ntraverse(t)\nnode number(n)\nnode height(h)\nleaf nodes(l)\ncopy tree(c)\njudge equal(e)\nquit(q)\n";
        cin >> choice;
        cout << endl << endl;;
        switch (choice)
        {
        case 's':                        //show the tree
            theTree.displayTree();
            break;
        case 'i':                        //insert a node
            cout << "Enter value to insert: ";
            cin >> value;
            theTree.insert(value, value + 0.9);
            break;
        case 'f':                        //find a node
            cout << "Enter value to find: ";
            cin >> value;
            found = theTree.find(value);
            if (found != NULL)
            {
                cout << "Found: ";
                found->displayNode();
                cout << endl;
            }
            else
                cout << "Could not find " << value << endl;
            break;
        case 't':                        //traverse the tree
            cout << "Enter traverse type (1=preorder, "
                << "2=inorder, 3=postorder): ";
            cin >> value;
            theTree.traverse(value);
            break;
        case 'q':                        //quit the program
            theTree.destroy();
            cout << endl;
            break;
            //*******
        case 'n':                        //計算節點數
            cout << "The total node number of the binary tree is: ";
            cout << theTree.Calculate_Node_number() << endl;
            break;
        case 'h':                        //計算二元樹的高度
            cout << "The height of the binary tree is: ";
            cout << theTree.Calculate_Tree_Height() << endl;
            break;
        case 'l':                        //計算葉節點數
            cout << "The total leaf nodes in the binary tree is: ";
            cout << theTree.Calculate_Leaf_Node() << endl;
            break;
        case 'c':                        //複製二元樹
        {
            Tree newTree;
            newTree.updateRoot(theTree.Copy_Tree(theTree.getRoot()));
            cout << "A copy of the binary tree has been created." << endl;
            newTree.displayTree();
            break;
		}
        case 'e':                        //判斷兩個二元樹是否相等
        {
            int val;
            cout << "Enter value to find in the second tree to compare: ";
            cin >> val;
            Node* foundInSecondTree = theTree.find(val);
            if (foundInSecondTree != NULL) {
                if (theTree.Judge_Equal(foundInSecondTree)) {
                    cout << "The trees are equal." << endl;
                }
                else {
                    cout << "The trees are not equal." << endl;
                }
            }
            else {
                cout << "The node was not found in the second tree." << endl;
            }
            break;
		}
        default:
            cout << "Invalid entry\n";
        }  //end switch
        cout << "......................................................" << endl;
    }  //end while
    return 0;
}  //end main()

