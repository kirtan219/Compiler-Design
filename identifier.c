#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Array of C reserved keywords
const char* keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
    "else", "enum", "extern", "float", "for", "goto", "if", "inline", "int", "long",
    "register", "restrict", "return", "short", "signed", "sizeof", "static", "struct",
    "switch", "typedef", "union", "unsigned", "void", "volatile", "while", "_Alignas",
    "_Alignof", "_Atomic", "_Bool", "_Complex", "_Generic", "_Imaginary", "_Noreturn",
    "_Static_assert", "_Thread_local"
};

// Function to check if a string is a C keyword
int isKeyword(const char *str) {
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a string is a valid identifier
int isValidIdentifier(const char *str) {
    // Check if the first character is a letter or underscore
    if (!(isalpha(str[0]) || str[0] == '_')) {
        return 0;
    }

    // Check remaining characters: letters, digits, or underscores
    for (int i = 1; str[i] != '\0'; i++) {
        if (!(isalnum(str[i]) || str[i] == '_')) {
            return 0;
        }
    }

    // Check if the string is a keyword
    if (isKeyword(str)) {
        return 0;
    }

    return 1;
}

int main() {
    char identifier[100];

    printf("Enter an identifier: ");
    scanf("%s", identifier);

    if (isValidIdentifier(identifier)) {
        printf("'%s' is a valid identifier.\n", identifier);
    } else {
        printf("'%s' is not a valid identifier.\n", identifier);
    }

    return 0;
}
