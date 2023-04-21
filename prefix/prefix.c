//Write a program to evaluate prefix expression using Stacks.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for isdigit() function

// Define stack structure
struct stack {
    int top;
    int capacity;
    int* array;
};

// Create stack
struct stack* createStack(int capacity) {
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Check if stack is empty
int isEmpty(struct stack* stack) {
    return stack->top == -1;
}

// Check if stack is full
int isFull(struct stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Push element onto stack
void push(struct stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack is full\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Pop element from stack
int pop(struct stack* stack) {
    if (isEmpty(stack)) {
        //printf("Stack is empty\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Evaluate prefix expression
int evaluatePrefix(char* exp) {
    // Create stack
    struct stack* stack = createStack(strlen(exp));
    int i;

    // Start scanning from right to left
    for (i = strlen(exp) - 1; i >= 0; i--) {
        // If character is a digit, push it onto stack
        if (isdigit(exp[i])) {
            push(stack, exp[i] - '0');
        }
        // If character is an operator, pop two operands from stack,
        // perform the operation and push the result back onto stack
        else {
            int operand1 = pop(stack);
            int operand2 = pop(stack);
            switch (exp[i]) {
                case '+': push(stack, operand1 + operand2); break;
                case '-': push(stack, operand1 - operand2); break;
                case '*': push(stack, operand1 * operand2); break;
                case '/': push(stack, operand1 / operand2); break;
                case '%': push(stack, operand1 % operand2); break;
                case '^': push(stack, operand1 ^ operand2); break;
            }
        }
    }
    // Pop the final result from stack and return it
    return pop(stack);
}

int main() {
    char exp[100];
    printf("Enter the prefix expression: ");
    fgets(exp, sizeof(exp), stdin);
    int result = evaluatePrefix(exp);
    printf("Result: %d\n", result);
    return 0;
}
