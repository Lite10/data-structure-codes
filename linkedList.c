
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* create(int x) {
    Node *n = malloc(sizeof(Node));
    n->data = x; n->prev = n->next = NULL;
    return n;
}

void insert(Node **head, int x) { 
    Node *n = create(x);
    if (!*head) { *head = n; return; }
    Node *cur = *head;
    while (cur->next) cur = cur->next;
    cur->next = n; n->prev = cur;
}

void traverse(Node *head) {
    for (Node *cur = head; cur; cur = cur->next) printf("%d ", cur->data);
    printf("\n");
}

Node* search(Node *head, int x) {
    for (Node *cur = head; cur; cur = cur->next)
        if (cur->data == x) return cur;
    return NULL;
}

void delete(Node **head, int x) {
    Node *cur = search(*head, x);
    if (!cur) return;
    if (cur->prev) cur->prev->next = cur->next; else *head = cur->next;
    if (cur->next) cur->next->prev = cur->prev;
    free(cur);
}

int main() {
    Node *head = NULL;
    insert(&head, 10); insert(&head, 20); insert(&head, 30);
    printf("List: "); traverse(head);

    Node *f = search(head, 20);
    printf("Search 20: %s\n", f ? "Found" : "Not Found");

    delete(&head, 20);
    printf("After delete 20: "); traverse(head);
    return 0;
}
