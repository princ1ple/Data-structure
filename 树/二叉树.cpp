#include<iostream>
#include<stack>
using namespace std;

template <typename T>
struct BinTreeNode
{
    /* data */
    T data; //节点存储的数值
    BinTreeNode<T> *lchild, *rchild; //左右子树
    //无参构造函数
    BinTreeNode() : lchild(NULL), rchild(NULL){}
    //有参构造函数
    BinTreeNode(T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL) : data(x), lchild(l), rchild(r) {}
};

template <typename T>
class BinTree
{
public:
    //构造函数
    BinTree(): root(NULL) {}
    //指定结束标志的构造函数
    BinTree(T value): root(NULL), Refvalue(value) {}
    //析构函数
    ~BinTree();
    //拷贝构造函数，拷贝构造二叉树（前序遍历的应用）
    BinTree(BinTree<T> &s);

    //使用广义表构建二叉树，以‘#’字符代表结束
    void CreateBinTree();
    //前序遍历创建二叉树，以‘#’字符代表空节点
    void CreateBinTree_Preorder();
    //前序、中序遍历创建二叉树
    void CreateBinTree_Pre_Inorder(const char *pre, const char *in);
    //后序和中序遍历创建二叉树
    void CreateBinTree_Post_Inorder(const char *post, const char *in);

    //先序遍历（递归）
    void Preorder();
    //中序遍历（递归）
    void Inorder();
    //后序遍历（递归）
    void Postorder();
    //先序遍历（非递归）
    void PreOrder_no();
    //中序遍历（非递归）
    void Inorder_no();
    //后序遍历（非递归）
    void Postorder_no();
    //层次遍历（非递归）
    void Levelorder();

    BinTreeNode<T> *getRoot();
    BinTreeNode<T> *Parent(BinTreeNode < T * current);
protected:
};
template <typename T>
void BinTree<T>::CreateBinTree()
{
    stack<BinTreeNode<T> *> s;
    BT = NULL;
    BinTreeNode<T> *p = NULL;
    BinTreeNode<T> *t = NULL;
    int k = 0;
    T ch;
    cin >> ch;
    while(ch!=RefValue)
    {
        switch (ch)
        {
        case '(':
            s.push(p);
            k = 1;
            break;
        case ')':
            s.pop();
            break;
        case ',':
            k = 2;
            break;
        default:
            p = new BinTreeNode<T>(ch);
            if(!BT)
                BT = p;
            else if(k==1)
            {
                t = s.top();
                t->lchild = p;
            }
            else if(k==2){
                t = s.top();
                t->rchild = p;
            }
            break;
        }
    }
}
int main()
{
    return 0;
}