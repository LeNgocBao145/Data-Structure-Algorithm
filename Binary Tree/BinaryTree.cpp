#include <iostream>
#include <math.h>
#include <algorithm>
#include <fstream>

using namespace std;

struct TreeNode{
    int data;
    TreeNode* pLeft;
    TreeNode* pRight;
};

TreeNode* createNode(int data)
{
    TreeNode* newNode = new TreeNode;

    newNode->data = data;
    newNode->pLeft = NULL;
    newNode->pRight = NULL;

    return newNode;
}

void addTreeNode(TreeNode* &root, int data)
{
    TreeNode* newNode = createNode(data);

    if(root == NULL)
    {
        root = newNode;
        return;
    }

    if(data > root->data)
    {
        addTreeNode(root->pRight, data);
    }else if(data < root->data)
    {
        addTreeNode(root->pLeft, data);
    }else
    {
        return;
    }
}

void printNLR(TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }

    cout << root->data << " ";

    
    printNLR(root->pLeft);

    printNLR(root->pRight);

}

void printNRL(TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }

    cout << root->data << " ";

    printNRL(root->pRight);
    
    printNRL(root->pLeft);

}

//Duyet cay nhi phan de xuat ra thu tu tu be den lon
void printLNR(TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }

    // if(root->pLeft != NULL)
    // {
        printLNR(root->pLeft);
    //}
    
    cout << root->data << " ";

    printLNR(root->pRight);

}

void printRNL(TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }

    printRNL(root->pRight);
    
    cout << root->data << " ";

    printRNL(root->pLeft);
}

void printLRN(TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }

    printLRN(root->pLeft);

    printLRN(root->pRight);
    
    cout << root->data << " ";
}

void printRLN(TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }

    printRLN(root->pRight);

    printRLN(root->pLeft);

    cout << root->data << " ";
}

//Dem so luong so nguyen to trong cay nhi phan tim kiem

bool isPrime(int n)
{
    if(n < 2)
    {
        return false;
    }

    for(int i = 2; i < sqrt(n); i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }

    return true;
}

void printPrime(TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }

    if(isPrime(root->data))
    {
        cout << root->data << " ";
    }

    printPrime(root->pLeft);
    printPrime(root->pRight);

}

//Tim kiem tren cay nhi phan

TreeNode* binarySearch(TreeNode* root, int val)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->data == val)
    {
        return root;
    }

    if(val < root->data)
    {
        binarySearch(root->pLeft, val);
    }else if(val > root->data)
    {
        binarySearch(root->pRight, val);
    }

}

//Node lá là node không tồn tại cây con trái và cây con phải

void findNode(TreeNode* root, int& one, int& two, int& none)
{
    if(root == NULL)
    {
        return;
    }

    if(root->pLeft != NULL && root->pRight != NULL)
    {
        two++;
        findNode(root->pLeft, one, two, none);
        findNode(root->pRight, one, two, none);

    }else if((root->pLeft == NULL && root->pRight != NULL) || (root->pLeft != NULL && root->pRight == NULL))
    {
        one++;

        if(root->pLeft == NULL)
        {
            findNode(root->pRight, one, two, none);

        }else if(root->pRight == NULL)
        {
            findNode(root->pLeft, one, two, none);

        }
    }else
    {
        none++;
    }
}

void print(TreeNode* root)
{
    int two = 0;
    int one = 0;
    int none = 0;

    findNode(root, one, two, none);

    cout << "Node has 1 branch: " << one << endl;
    cout << "Node has 2 branches: " << two << endl;
    cout << "Node has no branch: " << none << endl;

}

int main()
{
    fstream file;

    file.open("input.txt");


    TreeNode* root = NULL;

    int n;
     
    file >> n;

    char c;
    //cin >> n;

    for(int i = 1; i <= n; i++)
    {
        int x;
        file >> x >> c;
        addTreeNode(root, x);
    }

    file.close();

    // int x;

    // cin >> x;

    // TreeNode* mystery = binarySearch(root, x);

    // if(mystery == NULL)
    // {
    //     cout << "Phan tu khong ton tai!" << endl;
    // }
    // else
    // cout << mystery->data << endl;

    printNLR(root);

    return 0;
}