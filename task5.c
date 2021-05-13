#include <stdio.h>
#include <math.h>


int get_n() {
  int n;
  do {
    printf("\nВведіть число n: ");
    scanf("%d", &n);
  } while (n < 1);
  return n;
}
void get_arr(float * arr, int n) {
  printf("\nВведіть %d дійсних чисел:\n", n);
  for (int i=0; i<n; i++) {
    printf("Введіть %d число: ", i+1);
    scanf("%f", &arr[i]);
  }
}
int check_correct(float *arr, int n) {
  for (int i=0; i<n; i++) {
    if (arr[i] < 0) {
      return 0;
    }
  }
  return 1;
}
float calculation(float *arr, int n) {
  float l = 0;
  for (int i=0; i<n; i++) {
    l += sqrt(arr[i]);
  }
  return l;
}
void print_result(float l) {
  printf("\n*****");
  printf("Pезультати");
  printf("*****\n");
  printf("Відповідь: ");
  printf("%.2f", l);
}
int main() {
  int method, counter = 0, age;
  printf("\nЩо будемо робити ?\n");
  printf("*******************************************\n");
  printf("Запустити програму - 1\n");
  printf("Вийти з програми - 2\n");
  printf("*******************************************\n");
  while(1) {
    if (counter == 0) {
      printf("\nВвести: ");
      scanf("%d", &method);
      counter += 1;
    }
    else {
      printf("\n\nВи можете спробувати ще раз - 1 || вийти з програми - 2\n");
      printf("Ввести: ");
      scanf("%d", &method);
    }
    if (method == 1) {
      //Введення
      int n = get_n();
      float arr[n];
      get_arr(arr, n);
      // Перевірка на коректність даних
      int var = check_correct(arr, n);
      if (var == 1) {
        // Обчислення
        float l = calculation(arr, n);
        //Виведення
        print_result(l);
      }
      else {
        printf("\nВи ввели некорентні дані (виконується добування кореня з від'ємного числа)\n");
        printf("Спробуйте ще раз...");
      }
    }
    else {
      break;
    }
  }
  return 0;
}