/*c) crie um programa que lê uma expressao logica infixa e exibe sua forma posfixa e seu valor. */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

void push(Stack *stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Erro: Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}

char pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Erro: Stack underflow\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

int precedence(char op) {
    if (op == '~') return 3;
    else if (op == '&') return 2;
    else if (op == '|') return 1;
    return 0;
}

int isOperator(char c) {
    return (c == '~' || c == '&' || c == '|');
}

void infixToPostfix(char *infix, char *postfix) {
    Stack stack;
    stack.top = -1;
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char symbol = infix[i];

        if (symbol == 'V' || symbol == 'F') {
            postfix[j++] = symbol;
        } else if (symbol == '(') {
            push(&stack, symbol);
        } else if (symbol == ')') {
            while (stack.top != -1 && stack.items[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            if (stack.top == -1) {
                printf("Erro: Expressão inválida\n");
                return;
            }
            pop(&stack);
        } else if (isOperator(symbol)) {
            while (stack.top != -1 && precedence(stack.items[stack.top]) >= precedence(symbol)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, symbol);
        }
        i++;
    }

    while (stack.top != -1) {
        if (stack.items[stack.top] == '(') {
            printf("Erro: Expressão inválida\n");
            return;
        }
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

int evaluatePostfix(char *postfix) {
    Stack stack;
    stack.top = -1;
    int i = 0;

    while (postfix[i] != '\0') {
        char symbol = postfix[i];

        if (symbol == 'V' || symbol == 'F') {
            push(&stack, symbol);
        } else if (symbol == '~') {
            char operand = pop(&stack);
            int result = (operand == 'V') ? 'F' : 'V';
            push(&stack, result);
        } else if (symbol == '&' || symbol == '|') {
            char operand2 = pop(&stack);
            char operand1 = pop(&stack);

            int result;
            if (symbol == '&') {
                result = (operand1 == 'V' && operand2 == 'V') ? 'V' : 'F';
            } else {
                result = (operand1 == 'V' || operand2 == 'V') ? 'V' : 'F';
            }
            push(&stack, result);
        }
        i++;
    }

    return stack.items[stack.top];
}

int main() {
    char infixExpression[MAX_SIZE];
    char postfixExpression[MAX_SIZE];

    printf("Digite a expressão lógica infixa: ");
    fgets(infixExpression, MAX_SIZE, stdin);

    infixToPostfix(infixExpression, postfixExpression);
    printf("Expressão posfixa: %s\n", postfixExpression);

    int value = evaluatePostfix(postfixExpression);
    printf("Valor da expressão: %c\n", value);

    return 0;
}