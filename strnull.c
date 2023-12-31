#include <stdio.h>
#include <string.h>

// Функция для проверки, является ли строка t окончанием строки s
int strend(char *s, char *t) {
    int len_s = strlen(s); // Длина строки s
    int len_t = strlen(t); // Длина строки t
    
    // Если длина строки s меньше длины строки t, то t не может быть окончанием s
    if (len_s < len_t) {
        return 0;
    }
    
    char *start_s = s + (len_s - len_t); // Указатель на начало окончания s, равное длине строки s минус длина строки t
    
    // Сравниваем окончание s с t
    return strcmp(start_s, t) == 0;
}

int main() {
    char s[100]; // Первая строка
    char t[100]; // Вторая строка
    
    printf("Введите первую строку: ");
    fgets(s, sizeof(s), stdin); // Считываем первую строку
    
    printf("Введите вторую строку: ");
    fgets(t, sizeof(t), stdin); // Считываем вторую строку
    
    // Удаление символа новой строки, если он присутствует
    if (s[strlen(s) - 1] == '\n') {
        s[strlen(s) - 1] = '\0';
    }
    if (t[strlen(t) - 1] == '\n') {
        t[strlen(t) - 1] = '\0';
    }
    
    int result = strend(s, t); // Проверяем, является ли t окончанием s
    
    // Выводим результат
    if (result) {
        printf("Вторая строка является окончанием первой строки.\n");
    } else {
        printf("Вторая строка не является окончанием первой строки.\n");
    }
    
    return 0;
}
