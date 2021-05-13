#include <stdio.h>

int get_number(char*s) {
  int n;
  do {
    printf("\nВведіть число %s: ", s);
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

void sort(float *arr, int n) {
  for (int i=0; i<n-1; i++) {
    for(int j=0; j<n-i-1; j++) {
      if(arr[j] > arr[j+1]) {
        float var = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = var;
      }
    }
  }
}

void print_arr(float *arr, int n) {
  printf("{");
  for (int i=0; i<n; i++) {
    if (i == n-1) {
      printf("%.1f", arr[i]);
    }
    else {
      printf("%.1f, ", arr[i]);
    }
  }
  printf("}");
}

void find_fewer_k(float *arr1, float *arr2, int n, int k) {
  if (k > n) {
    printf("Введений некоректний k-елемент");
  }
  else {
    printf("\nk-елемент(%d) в першій послідовності: ", k);
    printf("%.1f\n", arr1[k-1]);
    printf("k-елемент(%d) в другій послідовності: ", k);
    printf("%.1f\n", arr2[k-1]);
    printf("\n*****");
    printf("Pезультати");
    printf("*****\n");

    if (arr1[k-1] < arr2[k-1]) {
      printf("k-елемент(%d) в першій послідовності менший", k);
    }
    else if (arr1[k-1] > arr2[k-1]) {
      printf("k-елемент(%d) в другій послідовності менший", k);
    }
    else {
      printf("k-елементи(%d) двох послідовностей рівні", k);
    }
  }
}
int main() {
  int method, counter = 0;

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
      int n = get_number("n");
      float arr1[n];
      float arr2[n];
      printf("\nВведення 1 послідовності чисел (a1, a2, ..., a(n))\n");
      get_arr(arr1, n);
      printf("\nВведення 2 послідовності чисел (b1, b2, ..., b(n))\n");
      get_arr(arr2, n);
      //Сортування
      sort(arr1, n);
      sort(arr2, n);
      // Виведення
      printf("\nВпорядкована за зростанням послідовность чисел (a1, a2, ..., a(n))\n");
      print_arr(arr1, n);
      printf("\n\nВпорядкована за зростанням послідовность чисел (b1, b2, ..., b(n))\n");
      print_arr(arr2, n);
      // Порівняння k-місця
      printf("\n");
      int k = get_number("k");
      find_fewer_k(arr1, arr2, n, k);
    }
    else {
      break;
    }
  }
  return 0;
} 