#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int KEY;
    int height;
    char word[10];

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

struct node *newNode(int NEWKEY, char WORD[]){
    struct node *nNode = (struct node *)malloc(sizeof(struct node));
    nNode->KEY = NEWKEY;
    strcpy(nNode->word, WORD);
    nNode->height = 1;
    nNode->left = NULL;
    nNode->right= NULL;

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

struct node *insertVal(struct  node *localRoot, int NEWKEY, char WORD[]){
    if(localRoot == NULL) return newNode(NEWKEY, WORD);
    if(strcmp(localRoot->word, WORD) < 0){
        localRoot->right = insertVal(localRoot->right, NEWKEY, WORD);
    }
    else if(strcmp(localRoot->word, WORD) > 0){
        localRoot->left = insertVal(localRoot->left, NEWKEY, WORD);
    }
    else{
        return localRoot;
    }
    return reBalance(localRoot);
}

void inOrder(struct node *localRoot){
    if(localRoot != NULL){
        inOrder(localRoot->left);
        printf(" %d-%s ", localRoot->KEY, localRoot->word);
        inOrder(localRoot->right);
    }
}
int search(struct node *localRoot, char WORD[]){
    int key;
    if(localRoot == NULL) return NULL;
    if(strcmp(localRoot->word, WORD) < 0){
        key = search(localRoot->right, WORD);
    }
    else if(strcmp(localRoot->word, WORD) > 0){
        key = search(localRoot->left, WORD);
    }
    else{
        return localRoot->KEY;
    }
    return key;
}
int main(){
    struct node *root = NULL;
    char str[6];
    int counter;
    counter = 0;


    str[0] = '\0';
    str[1] = '\0';
    str[2] = '\0';
    str[3] = '\0';
    str[4] = '\0';
    for(char i='a'; i<='z'; i++){
        counter++;
        str[0] = i;
        root = insertVal(root, counter, str);
    }
    str[0] = '\0';
    str[1] = '\0';
    str[2] = '\0';
    str[3] = '\0';
    str[4] = '\0';

    for(char i='a'; i<='z'; i++){
        for(char j=i+1; j<='z'; j++){
            counter++;
            str[0]=i;
            str[1]=j;
            root = insertVal(root, counter, str);
        }
    }
    str[0] = '\0';
    str[1] = '\0';
    str[2] = '\0';
    str[3] = '\0';
    str[4] = '\0';
    for(char i='a'; i<='z'; i++){
        for(char j=i+1; j<='z'; j++){
            for(char k=j+1; k<='z'; k++){
                counter++;
                str[0]=i;
                str[1]=j;
                str[2]=k;
                root = insertVal(root, counter, str);
            }
        }
    }
    str[0] = '\0';
    str[1] = '\0';
    str[2] = '\0';
    str[3] = '\0';
    str[4] = '\0';
    for(char i='a'; i<='z'; i++){
        for(char j=i+1; j<='z'; j++){
            for(char k=j+1; k<='z'; k++){
                for(char l=k+1; l<='z'; l++){
                    counter++; 
                    str[0]=i;
                    str[1]=j;
                    str[2]=k;
                    str[3]=l;
                    root = insertVal(root, counter, str);
                }
            }
        }
    }
    str[0] = '\0';
    str[1] = '\0';
    str[2] = '\0';
    str[3] = '\0';
    str[4] = '\0';
    str[5] = '\0';
    for(char i='a'; i<='z'; i++){
        for(char j=i+1; j<='z'; j++){
            for(char k=j+1; k<='z'; k++){
                for(char l=k+1; l<='z'; l++){
                    for(char m=l+1; m<='z'; m++){
                        counter++;
                        str[0]=i;
                        str[1]=j;
                        str[2]=k;
                        str[3]=l;
                        str[4]=m;
                        root = insertVal(root, counter, str);
                    }
                }
            }
        }
    }
    str[0] = '\0';
    str[1] = '\0';
    str[2] = '\0';
    str[3] = '\0';
    str[4] = '\0';
    int min;
    bool status;
    while(scanf("%s", str) != EOF){
        min = 'a'-1;
        status = true;
        for(int i=0; i<strlen(str);i++){
            if(str[i] > min){
                min = str[i];
            }
            else{
                status = false;
                break;
            }
        }

        if(status == true) printf("%d\n", search(root, str));
        else if(status == false){
            printf("0\n");
        }
    }
    

    return 0;
}