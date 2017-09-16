#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef int binary_tree_node_elem_t;

struct binary_tree_node_t 
{
    binary_tree_node_elem_t *left;
    binary_tree_node_elem_t *right;
    binary_tree_node_elem_t elem;
};

int visit(const binary_tree_node_t * node)
{
    printf("%d ", node->binary_tree_node_elem_t);
}

// 先序，递归
void pre_order_r(const binary_tree_node_t *root)
{
    if (root == NULL)
    {
        return;
    }

    visit(root);
    pre_order_r(root->left);
    pre_order_r(root->right);
}

// 中序，递归
void in_order_r(const binary_tree_node_t *root)
{
    if (root == NULL)
    {
        return;
    }

    in_order_r(root->left);
    visit(root)
    in_order_r(root->right);
}

// 后序，递归
void post_order_r(const binary_tree_node_t *root)
{
    if (root == NULL)
    {
        return;
    }

    post_order_r(root->left);
    post_order_r(root->right);
    visit(root);
}

// 先序，非递归
void pre_order(const binary_tree_node_t *root)
{
    binary_tree_node_t *p = root;
    stack<binary_tree_node_t *> s;
    
    if (p == NULL)
    {
        return;
    }

    s.push(p);

    while (!s.empyt())
    {
        p = s.top();
        s.pop();
        visit(p);

        if (p->right != NULL) s.push(p->right);
        if (p->left != NULL) s.push(p->left);
    }
}

// 中序，非递归
void in_order(const binary_tree_node_t *root)
{
    const binary_tree_node_t *p = root;
    stack<binary_tree_node_t *> s;

    while (!s.empty() || p != NULL)
    {
        if (p != NULL)
        {
            s.push(p);
            p = p->left;
        }
        else
        {
            p = s.top();
            s.pop();
            visit(p);
            p = p->right;
        }
    }
}

// 后序，非递归
void post_order(const binary_tree_node_t *root)
{
    binary_tree_node_t *p, *q;
    stack<binary_tree_node_t> s;
    p = root;

    do
    {
        while (p != NULL)
        {
            s.push(p);
            p = p->left;
        }

        while (!s.empty())
        {
            q = NULL;
            p = s.top();
            s.pop();
            if (p->right == q)
            {
                visit(p);
                q = p;
            }
            else
            {
                s.push(p);
                p = p->right;
            }
        }
        
    } while (!s.empty());
}

void level_order(const binary_tree_node_t *root)
{
    const binary_tree_node_t *p;
    queue<const binary_tree_node_t *> q;

    p = root;

    if (p != NULL) q.push(p);

    while (!q.empty())
    {
        p = q.front();
        q.pop();
        visit(p);

        if (p->left != NULL) q.push(p->left);
        if (p->right != NULL) q.push(p->right);
    }
}

int main()
{
    return 0;
}