#include<bits/stdc++.h>
#define pb push_back
#define sz 100
using namespace std;

struct node{
    int val;
    node *left,*right;
    node(){}
    node(int x)
    {
        val=x;
        left=right=NULL;
    }
}*root;

int height(node *cur)
{
    if(cur==NULL)
        return 0;
    int l=height(cur->left);
    int r=height(cur->right);
    return 1+max(l,r);
}
int BF(node *cur)
{
    return height(cur->left)-height(cur->right);
}

node* rr_rotation(node *cur)
{
    node *temp;
    temp=cur->right;
    cur->right=temp->left;
    temp->left=cur;
    return temp;
}

node* ll_rotation(node *cur)
{
    node *temp;
    temp=cur->left;
    cur->left=temp->right;
    temp->right=cur;
    return temp;
}

node* lr_rotation(node *cur)
{
    cur->left=rr_rotation(cur->left);
    return ll_rotation(cur);
}
node* rl_rotation(node *cur)
{
    cur->right=ll_rotation(cur->right);
    return rr_rotation(cur);
}

node* balance(node *cur)
{
    int bf=BF(cur);
    if(bf>1)
    {
        if(BF(cur->left)>0)
            cur=ll_rotation(cur);
        else
            cur=lr_rotation(cur);
    }
    else if(bf< -1)
    {
        if(BF(cur->right)<0)
            cur=rr_rotation(cur);
        else
            cur=rl_rotation(cur);
    }

    return cur;
}
node* Insert(node *cur,int x)
{
    if(cur==NULL)
        cur=new node(x);
    else if(cur->val > x)
    {
        cur->left=Insert(cur->left,x);
        cur=balance(cur);
    }
    else
    {
        cur->right=Insert(cur->right,x);
        cur=balance(cur);
    }
    return cur;
}

int main()
{
    root=NULL;
    root=Insert(root,12);

}

