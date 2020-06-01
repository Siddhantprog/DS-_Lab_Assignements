#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node
{
    char *key;
    struct node *left,*right;
}*root;
void inorder(struct node *node)
{
    if(node!=NULL)
    {
        inorder(node->left);
        printf("%s\n",node->key);
        inorder(node->right);
    }
}
struct node *insert(struct node *node,char key1[],int n)
{
    int i,j,k;
    struct node *newnode=NULL;
    if(node==NULL)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->key=(char *)malloc(n*sizeof(char));
        for(i=0;key1[i]!='\0';i++)
        {
            newnode->key[i]=key1[i];
        }
        newnode->key[i]='\0';
        newnode->left=newnode->right=NULL;
        return newnode;
    }
    for(k=0,j=0;key1[k]!='\0'&&node->key[j]!=0;k++,j++)
    {
        if(key1[k]!=node->key[j])
        {
            if(key1[k]<node->key[j])
            {
                node->left=insert(node->left,key1,n);
                break;
            }
            else
            {
                node->right=insert(node->right,key1,n);
                break;
            }
        }
    }
    return node;
}
int main()
{   struct node *root=NULL;
    root = insert(root,"Arthi",sizeof("Arthi"));
    insert(root,"Christy",sizeof("Christy"));
    insert(root,"Dorothy",sizeof("Dorothy"));
    insert(root,"Fraser",sizeof("Fraser"));
    insert(root,"Eliza",sizeof("Eliza"));
    insert(root,"David",sizeof("David"));
    inorder(root);
    return 0;
}
