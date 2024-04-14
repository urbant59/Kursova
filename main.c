#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Генерує випадковий пароль заданої довжини
void generatePassword(int length) {
    // Символи, які можуть входити в пароль
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int charsetLength = sizeof(charset) - 1;

    // Генеруємо випадкові символи та виводимо їх
    for (int i = 0; i < length; ++i) {
        int index = rand() % charsetLength;
        putchar(charset[index]);
    }
    putchar('\n');
}

// Виведення інформації про програму
void displayInfo() {
    printf("\n=== Password Generator Info ===\n");
    printf("Made by Ivan Zolotuhin\n");
    printf("Program was made for generating safe passwords for home usage\n");
    printf("2024\n");
}

int main() {
    int numPasswords, passwordLength;
    char choice;

    do {
        // Вивід меню
        printf("\n=== Password Generator ===\n");
        printf("1. Start\n");
        printf("2. Info\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                // Ввід кількості та довжини паролів
                printf("\nEnter the number of passwords: ");
                if (scanf("%d", &numPasswords) != 1 || numPasswords < 1) {
                    printf("Error: Invalid input. Please enter a positive integer.\n");
                    break;
                }
                printf("Enter the length of the passwords (max 30): ");
                if (scanf("%d", &passwordLength) != 1 || passwordLength < 1 || passwordLength > 30) {
                    printf("Error: Invalid input. Please enter a positive integer not exceeding 30.\n");
                    break;
                }

                // Ініціалізація генератора випадкових чисел
                srand(time(NULL));

                // Генеруємо паролі
                printf("\nGenerated Passwords:\n");
                for (int i = 0; i < numPasswords; ++i) {
                    generatePassword(passwordLength);
                }
                break;
            case '2':
                // Виведення інформації про програму
                displayInfo();
                break;
            case '3':
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please enter 1, 2 or 3.\n");
                break;
        }
    } while (choice != '3');

    return 0;
}
