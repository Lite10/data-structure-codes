
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 256


int precedence(char op) {
    switch (op) {
        case '^': return 4;     
        case '*': case '/': return 3;
        case '+': case '-': return 2;
        default: return 0;
    }
}

// Right-associative for '^'
int is_right_associative(char op) {
    return op == '^';
}


int is_op(char c) {
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}

int main() {
    char infix[MAX];
    char output[MAX] = {0};
    char stack[MAX]; int top = -1;
    int out_len = 0;

    printf("Enter infix expression:\n");
    if (!fgets(infix, sizeof(infix), stdin)) return 1;


    infix[strcspn(infix, "\n")] = '\0';

    for (size_t i = 0; i < strlen(infix); ++i) {
        char c = infix[i];
        if (isspace((unsigned char)c)) continue;

        if (isdigit((unsigned char)c)) {
    
            while (isdigit((unsigned char)infix[i])) {
                output[out_len++] = infix[i++];
            }
            output[out_len++] = ' ';
            i--; 
        }
        else if (isalpha((unsigned char)c)) {

            output[out_len++] = c;
            output[out_len++] = ' ';
        }
        else if (c == '(') {
            stack[++top] = c;
        }
        else if (c == ')') {
            while (top >= 0 && stack[top] != '(') {
                output[out_len++] = stack[top--];
                output[out_len++] = ' ';
            }
            if (top >= 0 && stack[top] == '(') top--;
            else {
                fprintf(stderr, "Error: mismatched parentheses.\n");
                return 1;
            }
        }
        else if (is_op(c)) {
            while (top >= 0 && is_op(stack[top])) {
                int p1 = precedence(c);
                int p2 = precedence(stack[top]);
            
                if (p2 > p1 || (p2 == p1 && !is_right_associative(c))) {
                    output[out_len++] = stack[top--];
                    output[out_len++] = ' ';
                } else break;
            }
            stack[++top] = c;
        }
        else {
            fprintf(stderr, "Error: invalid character '%c'.\n", c);
            return 1;
        }
    }

    while (top >= 0) {
        if (stack[top] == '(' || stack[top] == ')') {
            fprintf(stderr, "Error: mismatched parentheses.\n");
            return 1;
        }
        output[out_len++] = stack[top--];
        output[out_len++] = ' ';
    }


    if (out_len > 0 && output[out_len - 1] == ' ') output[out_len - 1] = '\0';

    printf("Postfix: %s\n", output);
    return 0;
}

