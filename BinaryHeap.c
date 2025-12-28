
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
    int is_min; 
} Heap;

static int cmp(Heap *h, int a, int b) {
    return h->is_min ? (a < b) : (a > b);
}

Heap heap_create(size_t capacity, int is_min) {
    Heap h;
    h.data = (int*)malloc(capacity * sizeof(int));
    h.size = 0;
    h.capacity = capacity;
    h.is_min = is_min;
    return h;
}

void heap_free(Heap *h) {
    free(h->data);
    h->data = NULL;
    h->size = h->capacity = 0;
}

static void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

static void sift_up(Heap *h, size_t i) {
    while (i > 0) {
        size_t p = (i - 1) / 2;
        if (cmp(h, h->data[i], h->data[p])) { swap(&h->data[i], &h->data[p]); i = p; }
        else break;
    }
}

static void sift_down(Heap *h, size_t i) {
    for (;;) {
        size_t l = 2*i + 1, r = 2*i + 2, best = i;
        if (l < h->size && cmp(h, h->data[l], h->data[best])) best = l;
        if (r < h->size && cmp(h, h->data[r], h->data[best])) best = r;
        if (best != i) { swap(&h->data[i], &h->data[best]); i = best; }
        else break;
    }
}

int heap_push(Heap *h, int x) {
    if (h->size == h->capacity) return -1;
    h->data[h->size] = x;
    sift_up(h, h->size);
    h->size++;
    return 0;
}

int heap_peek(const Heap *h, int *out) {
    if (h->size == 0) return -1;
    *out = h->data[0];
    return 0;
}

int heap_pop(Heap *h, int *out) {
    if (h->size == 0) return -1;
    if (out) *out = h->data[0];
    h->data[0] = h->data[h->size - 1];
    h->size--;
    if (h->size) sift_down(h, 0);
    return 0;
}

void heap_build(Heap *h, const int *arr, size_t n) {
    if (n > h->capacity) n = h->capacity;
    for (size_t i = 0; i < n; ++i) h->data[i] = arr[i];
    h->size = n;
    if (h->size == 0) return;
    for (ssize_t i = (ssize_t)(h->size/2) - 1; i >= 0; --i) sift_down(h, (size_t)i);
}


int main(void) {
    int arr[] = {5, 3, 8, 1, 7, 9, 2};
    size_t n = sizeof(arr)/sizeof(arr[0]);

    Heap minH = heap_create(32, 1);
    Heap maxH = heap_create(32, 0);

    heap_build(&minH, arr, n);
    heap_build(&maxH, arr, n);

    printf("Min-Heap pops: ");
    while (minH.size) { int x; heap_pop(&minH, &x); printf("%d ", x); }
    printf("\n");

    printf("Max-Heap pops: ");
    while (maxH.size) { int x; heap_pop(&maxH, &x); printf("%d ", x); }
    printf("\n");

    heap_free(&minH);
    heap_free(&maxH);
    return 0;
}

