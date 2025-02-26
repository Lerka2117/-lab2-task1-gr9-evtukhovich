/* main.c */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция для проверки, является ли число полным квадратом
int isPerfectSquare(int num) {
  int sqrtNum = (int)sqrt(num);
  return (sqrtNum * sqrtNum == num);
}

// Структура PERSON
typedef struct {
  char Name[50];
  char FAC[50];
  char SPEC[50];
  char GROUP[10];
  int YEAR;
  int MONTH;
  int DAY;
} PERSON;

// Функция для сравнения дат (для сортировки)
int compareDates(PERSON a, PERSON b) {
  if (a.YEAR != b.YEAR)
    return a.YEAR - b.YEAR;
  if (a.MONTH != b.MONTH)
    return a.MONTH - b.MONTH;
  return a.DAY - b.DAY;
}

// Функция для сравнения строк (для сортировки по фамилиям)
int compareNames(const void *a, const void *b) {
  return strcmp(((PERSON *)a)->Name, ((PERSON *)b)->Name);
}

// Функция для сравнения по факультету, специальности, группе и дате
int compareAll(const void *a, const void *b) {
  PERSON *personA = (PERSON *)a;
  PERSON *personB = (PERSON *)b;

  int facCompare = strcmp(personA->FAC, personB->FAC);
  if (facCompare != 0)
    return facCompare;

  int specCompare = strcmp(personA->SPEC, personB->SPEC);
  if (specCompare != 0)
    return specCompare;

  int groupCompare = strcmp(personA->GROUP, personB->GROUP);
  if (groupCompare != 0)
    return groupCompare;

  return compareDates(*personA, *personB);
}

int main() {
  // Задача 1: Вывод чисел, не являющихся полными квадратами
  int n;
  printf("Введите размерность массива: ");
  scanf("%d", &n);

  int *arr = (int *)malloc(n * sizeof(int));
  printf("Введите элементы массива:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Числа, не являющиеся полными квадратами:\n");
  for (int i = 0; i < n; i++) {
    if (!isPerfectSquare(arr[i])) {
      printf("%d ", arr[i]);
    }
  }
  printf("\n");

  free(arr);

  // Задача 2: Работа со структурой PERSON
  PERSON VUZ[10];

  // Ввод данных
  printf("\nВведите данные о студентах:\n");
  for (int i = 0; i < 10; i++) {
    printf("Студент %d:\n", i + 1);
    printf("Фамилия и инициалы: ");
    scanf(" %[^\n]", VUZ[i].Name);
    printf("Факультет: ");
    scanf(" %[^\n]", VUZ[i].FAC);
    printf("Специальность: ");
    scanf(" %[^\n]", VUZ[i].SPEC);
    printf("Группа: ");
    scanf(" %[^\n]", VUZ[i].GROUP);
    printf("Дата поступления (год месяц день): ");
    scanf("%d %d %d", &VUZ[i].YEAR, &VUZ[i].MONTH, &VUZ[i].DAY);
  }

  // Сортировка по дате поступления
  qsort(VUZ, 10, sizeof(PERSON), compareDates);

  // Сортировка по факультету, специальности, группе и дате
  qsort(VUZ, 10, sizeof(PERSON), compareAll);

  // Вывод отсортированных данных
  printf("\nОтсортированные данные о студентах:\n");
  for (int i = 0; i < 10; i++) {
    printf("Фамилия: %s\n", VUZ[i].Name);
    printf("Факультет: %s\n", VUZ[i].FAC);
    printf("Специальность: %s\n", VUZ[i].SPEC);
    printf("Группа: %s\n", VUZ[i].GROUP);
    printf("Дата поступления: %d-%02d-%02d\n\n", VUZ[i].YEAR, VUZ[i].MONTH,
           VUZ[i].DAY);
  }

  return 0;
}