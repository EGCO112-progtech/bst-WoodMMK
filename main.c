#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

void main(int argc, char **argv){
    
    //initial binary tree
    BinaryTree BT;
    BT.root = NULL;
    BT.size = 0;

    for(int i = 1; i<argc;i++){
        insert_R(&BT.root, atoi(argv[i]));
    }
    // printf("root is %d\n", BT.root->data);
    // if(BT.root->ln)printf("root's left is %d\n", BT.root->ln->data);
    // else printf("no left\n");
    // if(BT.root->rn)printf("root's right is %d\n", BT.root->rn->data);
    // else printf("no right\n");
    printf(">----------\n");
    printf("in-order is : ");
    print_inorder_R(BT.root);
    printf("\n>----------\n");

    printf("pre-order is : ");
    print_preorder_R(BT.root);
    printf("\n>----------\n");

    printf("post-order is : ");
    print_postorder_R(BT.root);
    printf("\n>----------\n");

    //printf("end main.c\n"); check if end

    //auto insert input into tree
    /*
    for(int i = 1; i<argc; i++)
    {
        
    }
    */

    // there's while loop in else to search for available node 

}