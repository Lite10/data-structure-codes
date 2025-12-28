
#include <stdio.h>

int main() {
    int tree[15];
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &tree[i]);

    printf("\nTree in array form:\n");
    for (int i = 0; i < n; i++) printf("%d ", tree[i]);
    printf("\n");

    printf("\nParent -> Left, Right:\n");
    for (int i = 0; i < n; i++) {
        int left = 2*i+1, right = 2*i+2;
        printf("%d -> ", tree[i]);
        if (left < n) printf("%d ", tree[left]);
        if (right < n) printf("%d", tree[right]);
        printf("\n");
    }
    return 0;
}
