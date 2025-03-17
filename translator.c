#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *input;  // Input expression
char currentToken;  // Current character being processed

// Forward declarations
void expression();
void term();
void factor();

// Function to get the next character from input
void nextToken() {
    currentToken = *input++;
}

// Error handling
void error() {
    printf("Syntax Error\n");
    exit(1);
}

// Parsing and translation functions
void expression() {
    term(); // Parse the first term

    while (currentToken == '+' || currentToken == '-') {
        char op = currentToken;  // Store the operator
        nextToken();
        term();  // Parse the next term
        printf("%c ", op);  // Output operator in postfix notation
    }
}

void term() {
    factor();  // Parse the first factor

    while (currentToken == '*' || currentToken == '/') {
        char op = currentToken;  // Store the operator
        nextToken();
        factor();  // Parse the next factor
        printf("%c ", op);  // Output operator in postfix notation
    }
}

void factor() {
    if (isdigit(currentToken)) {
        printf("%c ", currentToken);  // Output number in postfix notation
        nextToken();
    } else if (currentToken == '(') {
        nextToken();  // Skip '('
        expression();  // Parse the inner expression
        if (currentToken == ')') {
            nextToken();  // Skip ')'
        } else {
            error();
        }
    } else {
        error();
    }
}

int main() {
    // Sample input expression
    input = "2+3*4";
    nextToken();  // Initialize the first token

    expression();  // Start parsing and translation

    if (currentToken != '\0') {
        error();  // Input not fully consumed, indicating an error
    }

    printf("\n");
    return 0;
}
