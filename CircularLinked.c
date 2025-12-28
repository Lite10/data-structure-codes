
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* create(int x){ Node* n=malloc(sizeof(Node)); n->data=x; n->next=NULL; return n; }

void insert(Node **head,int x){
    Node* n=create(x);
    if(!*head){ *head=n; n->next=n; return; }
    Node* cur=*head; while(cur->next!=*head) cur=cur->next;
    cur->next=n; n->next=*head;
}

void traverse(Node* head){
    if(!head){ printf("[empty]\n"); return; }
    Node* cur=head; do{ printf("%d ",cur->data); cur=cur->next; }while(cur!=head);
    printf("\n");
}

Node* search(Node* head,int x){
    if(!head) return NULL;
    Node* cur=head; do{ if(cur->data==x) return cur; cur=cur->next; }while(cur!=head);
    return NULL;
}

void delete(Node **head,int x){
    if(!*head) return;
    Node *cur=*head,*prev=NULL;
    do{ if(cur->data==x) break; prev=cur; cur=cur->next; }while(cur!=*head);
    if(cur->data!=x) return;
    if(cur==*head && cur->next==*head){ free(cur); *head=NULL; return; }
    if(cur==*head){ Node* tail=*head; while(tail->next!=*head) tail=tail->next;
        *head=cur->next; tail->next=*head; }
    else prev->next=cur->next;
    free(cur);
}

int main(){
    Node* head=NULL;
    insert(&head,10); insert(&head,20); insert(&head,30);
    traverse(head);
    printf("Search 20: %s\n", search(head,20)?"Found":"Not Found");
    delete(&head,10); traverse(head);
    delete(&head,30); traverse(head);
    return 0;
}
