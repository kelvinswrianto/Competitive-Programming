#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char locLang[40];
    char forLang[40];
    int height;
    struct node *left;
    struct node *right;
};

int max(int a, int b){
    return (a < b) ? b : a;
}

int getHeight(struct node *localRoot){
    if(localRoot == NULL) return 0;
    return localRoot->height;
}

int getBalFactor(struct node *localRoot){
    if(localRoot == NULL) return 0;
    return getHeight(localRoot->left) - getHeight(localRoot->right);
}

struct node *newNode(struct node *inp){
    struct node *nNode = (struct node *)malloc(sizeof(struct node));
    nNode->left = NULL;
    nNode->right = NULL;
    nNode->height = 1;
    strcpy(nNode->forLang, inp->forLang);
    strcpy(nNode->locLang, inp->locLang);

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
    int bfact = getBalFactor(localRoot);
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
char *search(struct node *localRoot, char forLang[]){
    static char key[40];
    if(localRoot == NULL) return (char *)"eh";
    if(strcmp(localRoot->forLang, forLang) < 0){
        strcpy(key, search(localRoot->right, forLang));
    }
    else if(strcmp(localRoot->forLang, forLang) > 0){
        strcpy(key, search(localRoot->left, forLang));
    }
    else{
        return localRoot->locLang;
    }
    return key;
}
struct node *insertVal(struct  node *localRoot, struct node *inp){
    if(localRoot == NULL) return newNode(inp);
    if(strcmp(localRoot->forLang, inp->forLang) < 0){
        localRoot->right = insertVal(localRoot->right, inp);
    }
    else if(strcmp(localRoot->forLang, inp->forLang) > 0){
        localRoot->left = insertVal(localRoot->left, inp);
    }
    else{
        return localRoot;
    }
    return reBalance(localRoot);
}


void inOrder(struct node *localRoot){
    if(localRoot != NULL){
        inOrder(localRoot->left);
        printf(" %s-%s ", localRoot->locLang, localRoot->forLang);
        inOrder(localRoot->right);
    }
}

int main(){
    struct node *root = NULL;
    struct node *inp = (struct node *)malloc(sizeof(struct node));
    char inpStr[50];
    while(scanf("%[^\n]s", inpStr)){
        fflush(stdin);
        if(strcmp(inpStr, "") == 0) break;
        sscanf(inpStr, "%s %s", inp->locLang, inp->forLang);
        root = insertVal(root, inp);
    }
    while(scanf("%s", inpStr)!=EOF){
        strcpy(inpStr, search(root, (char *)inpStr));
        printf("%s\n", inpStr);
    }

    return 0;
}
