#include <stdio.h>
#include <stdlib.h>

struct treenode{
    struct treenode* ln;
    struct treenode* rn;
    int data;
};

typedef struct treenode Treenode;
typedef Treenode* treenodeptr;

typedef struct{
    treenodeptr root;
    int size;
}BinaryTree;


//initial function
void insert(BinaryTree*, int);
void insert_R(treenodeptr*, int);
void print_inorder_R(treenodeptr); // inorder left to right (increasing)
void print_preorder_R(treenodeptr); // preorder itself first then go left
void print_postorder_R(treenodeptr); // postorder child first
void print_rotate(treenodeptr); //retate 90 degree

//implementing function
void print_inorder_R(treenodeptr movingPtr){
    if(movingPtr!=NULL) // when call and movingPtr point to NULL -> do second line (print what it pointed to)
    { //if not childe
        print_inorder_R(movingPtr->ln); //when input Ptr is null the function is end , then go down and do second line
        printf("%d ", movingPtr->data); 
        print_inorder_R(movingPtr->rn);
    }
}

void print_preorder_R(treenodeptr movingPtr){
    if(movingPtr!=NULL) // when call and movingPtr point to NULL -> do second line (print what it pointed to)
    { //if not childe
        printf("%d ", movingPtr->data); 
        print_preorder_R(movingPtr->ln); //when input Ptr is null the function is end , then go down and do second line
        print_preorder_R(movingPtr->rn);
    }
}

void print_postorder_R(treenodeptr movingPtr){
    if(movingPtr!=NULL) // when call and movingPtr point to NULL -> do second line (print what it pointed to)
    { //if not childe
        print_postorder_R(movingPtr->ln); //when input Ptr is null the function is end , then go down and do second line
        print_postorder_R(movingPtr->rn);
        printf("%d ", movingPtr->data); 
    }
}


void insert(BinaryTree* BTptr, int input)
{
    int insert_flag = 0;
    treenodeptr temp = (treenodeptr) malloc (sizeof(Treenode));
    // initial treenode
    temp->ln = NULL; // no child 
    temp->rn = NULL; // no child
    temp->data = input; // store input number into "temp" node

    
    
    if(!BTptr->root)
    {//if it's the first node
        BTptr->root = temp;
    }
    
    else
    {//if not first node
        treenodeptr childcheck = BTptr -> root; //childcheck start from root
        
        //insert child "temp"
        while(!insert_flag)//when until -> flag = 1
        {
            // temp->data = 10
            if(temp->data > childcheck->data)
            { // more -> go right
                if(childcheck->rn == NULL)
                { // if right is available -> insert
                    childcheck->rn = temp;
                    insert_flag = 1;
                }
                else
                { // if right not available
                    childcheck = childcheck->rn;
                }
            }
            else
            { // less or equal <- go left
                if(childcheck->ln == NULL)
                { // if left is available -> insert
                    childcheck->ln = temp;
                    insert_flag = 1;
                }
                else
                { // if left not available
                    childcheck = childcheck->ln;
                }
            }
        }
    }
    

    // increase size of Binary tree <-> doesn't need size (for now)
    // BTptr->size++;
}

void insert_R(treenodeptr* movingptr, int input)
{
    if((*movingptr) == NULL)
    { //if where "movingptr" pointed to is avaiable -> insert

        // malloc where movingptr pointed to <-> put* infront
        (*movingptr) = (treenodeptr) malloc (sizeof(Treenode));
        
        if((*movingptr)) // malloc error proof *very important
        {
            //initial tree node
            (*movingptr)->ln = NULL; // set ptr to NULL
            (*movingptr)->rn = NULL; // for safety
            (*movingptr)->data = input; // store into node
            //printf("inserted %d\n", input); check if inserted
        }        

    }
    else
    { // if NULL -> move movingptr then create recursion (moved, value)
        if(input > ((*movingptr)->data))
        {
            insert_R(&(*movingptr)->rn, input);
        }
        else 
        {
            insert_R(&(*movingptr)->ln, input);
        }
    }
    
}

void print_rotate(treenodeptr movingPtr){

}