
#include <stdio.h>

void traverse(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

int insert_at(int a[], int *n, int capacity, int index, int value) {
    if (*n >= capacity || index > *n) return -1; 
    for (int i = *n; i > index; i--) a[i] = a[i - 1];
    a[index] = value;
    (*n)++;
    return 0;
}

int delete_at(int a[], int *n, int index) {
    if (*n == 0 || index >= *n) return -1; 
    for (int i = index; i < *n - 1; i++) a[i] = a[i + 1];
    (*n)--;
    return 0;
}

int main() {
    int a[10] = {1, 2, 3, 4, 5};
    int n = 5, capacity = 10;

    printf("Initial: "); traverse(a, n);

    insert_at(a, &n, capacity, 2, 99);
    printf("After insert 99 at index 2: "); traverse(a, n);

    delete_at(a, &n, 4);
    printf("After delete at index 4: "); traverse(a, n);

    return 0;
}
