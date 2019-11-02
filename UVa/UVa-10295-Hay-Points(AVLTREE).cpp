#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char JOB[30];
    long KEY;
    long height;

    struct node *left;
    struct node *right;
};

long max(long a, long b){
    return (a < b) ? b : a;
}

long getHeight(struct node *localRoot){
    if(localRoot == NULL) return 0;
    return localRoot->height;
}

long getBalFactor(struct node *localRoot){
    if(localRoot == NULL) return 0;
    return getHeight(localRoot->left) - getHeight(localRoot->right);
}

struct node *newNode(long NEWKEY, char NEWJOB[]){
    struct node *nNode = (struct node *)malloc(sizeof(struct node));
    nNode->KEY = NEWKEY;
    nNode->height = 1;
    nNode->left = NULL;
    nNode->right= NULL;
    strcpy(nNode->JOB, NEWJOB);
    return nNode;
}

struct node *leftRotate(struct node *x){
    struct node *y = x->right;
    struct node *B = y->left;

    //rotate
    y->left = x;
    x->right = B;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

struct node *rightRotate(struct node *y){
    struct node *x = y->left;
    struct node *B = x->right;

    x->right = y;
    y->left = B;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}


struct node *reBalance(struct node *localRoot){
    localRoot->height = max(getHeight(localRoot->left), getHeight(localRoot->right)) + 1;
    long bfact = getBalFactor(localRoot);
    if(bfact > 1 && getBalFactor(localRoot->left) < 0){
        localRoot->left = leftRotate(localRoot->left);
        return rightRotate(localRoot);
    }
    if(bfact > 1 && getBalFactor(localRoot->left) >= 0){
        return rightRotate(localRoot);
    }
    if(bfact < -1 && getBalFactor(localRoot->right) <= 0){
        return leftRotate(localRoot);
    }
    if(bfact < -1 && getBalFactor(localRoot->right) > 0){
        localRoot->right = rightRotate(localRoot->right);
        return leftRotate(localRoot);
    }
    return localRoot;
}

struct node *insertVal(struct  node *localRoot, long NEWKEY, char NEWJOB[]){
    if(localRoot == NULL) return newNode(NEWKEY, NEWJOB);
    if(strcmp(localRoot->JOB, NEWJOB) < 0){
        localRoot->right = insertVal(localRoot->right, NEWKEY, NEWJOB);
    }
    else if(strcmp(localRoot->JOB, NEWJOB) > 0){
        localRoot->left = insertVal(localRoot->left, NEWKEY, NEWJOB);
    }
    else{
        return localRoot;
    }
    return reBalance(localRoot);
}

long search(struct node *localRoot, char JOB[]){
    long key;
    if(localRoot == NULL) return NULL;
    if(strcmp(localRoot->JOB, JOB) < 0){
        key = search(localRoot->right, JOB);
    }
    else if(strcmp(localRoot->JOB, JOB) > 0){
        key = search(localRoot->left, JOB);
    }
    else{
        return localRoot->KEY;
    }
    return key;
}

int main(){
    struct node *root = NULL;
    
    long m, n, sum;
    long inpInt;
    char inpString[30];

    scanf("%ld %ld", &m, &n);
    for(long i=0; i<m; i++){
        scanf("%s %ld", inpString, &inpInt);
        root = insertVal(root, inpInt, (char *)inpString);
    }
    
    for(long i=0; i<n; i++){
        sum = 0;
        while(scanf("%s", inpString)){
            if(strcmp(inpString, ".") == 0){
                break;
            }
            sum += search(root, inpString);
        }
        printf("%ld\n", sum);
    }
    return 0;
}