// Author: Murilo Ferreira

#include <stdio.h>
#include <math.h>

// Method 1: Using iterative multiplication
int binaryToDecimalUsingMultiplier(int binary) {
    int decimal = 0;
    int multiplier = 1;
    while (binary != 0) {
        decimal += (binary % 10) * multiplier;
        binary /= 10;
        multiplier *= 2;
    }
    return decimal;
}

// Method 2: Using pow function
int binaryToDecimalUsingPow(long long binary) {
    int decimal = 0, i = 0, remainder;
    while (binary != 0) {
        remainder = binary % 10;
        binary /= 10;
        decimal += remainder * pow(2, i);
        ++i;
    }
    return decimal;
}

void displayMenu() {
    printf("\n==========================\n");
    printf("Choose a conversion method:\n");
    printf("1. Iterative multiplication\n");
    printf("2. Pow function\n");
    printf("3. Exit\n");
    printf("==========================\n\n");
}

int validateBinaryInput(long long binary) {
    while (binary != 0) {
        if (binary % 10 > 1) {
            return 0;
        }
        binary /= 10;
    }
    return 1;
}

int main() {
    int choice;
    long long binary;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting program. Goodbye!\n");
            break;
        }

        printf("Enter a binary number: ");
        scanf("%lld", &binary);

        if (!validateBinaryInput(binary)) {
            printf("Invalid binary number. Please enter a valid binary number (only 0s and 1s).\n\n");
            continue;
        }

        if (choice == 1) {
            printf("Using iterative multiplication: %lld in binary = %d in decimal\n", binary, binaryToDecimalUsingMultiplier((int)binary));
        } else if (choice == 2) {
            printf("Using pow function: %lld in binary = %d in decimal\n", binary, binaryToDecimalUsingPow(binary));
        } else {
            printf("Invalid choice. Please select 1, 2, or 3.\n");
        }

        printf("\n");
    }

    return 0;
}
