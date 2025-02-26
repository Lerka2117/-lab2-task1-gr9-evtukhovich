#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPerfectSquare(int num) {
  int sqrtNum = (int)sqrt(num);
  return (sqrtNum * sqrtNum == num);
}

typedef struct {
  char Name[50];
  char FAC[50];
  char SPEC[50];
  char GROUP[10];
  int YEAR;
  int MONTH;
  int DAY;
} PERSON;

int compareDates(const void *a, const void *b) {
  PERSON *personA = (PERSON *)a;
  PERSON *personB = (PERSON *)b;

  if (personA->YEAR != personB->YEAR)
    return personA->YEAR - personB->YEAR;
  if (personA->MONTH != personB->MONTH)
    return personA->MONTH - personB->MONTH;
  return personA->DAY - personB->DAY;
}

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

  return compareDates(personA, personB);
}

int main() {
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

  PERSON VUZ[10];

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

  qsort(VUZ, 10, sizeof(PERSON), compareDates);
  qsort(VUZ, 10, sizeof(PERSON), compareAll);

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