#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

#define N 5

void print_array(int *arr, int size){
  printf("Printing array:\n");
  for (int i = 0; i < size; i++){
    printf("%d - ", arr[i]);
  }
  printf("\n");
}

int *create_new_smaller_arr(int *arr, int size) {
  int *new_smaller_arr = (int *)malloc((size - 1) * sizeof(int));
  printf("Arr argument in create_new_smaller_arr function\n");
  print_array(arr, size);
  for (int i = 0; i < size - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      printf("assigning left value of: %d\n", arr[i]);
      new_smaller_arr[i] = arr[i];
    } else {
      printf("assigning left value of: %d\n", arr[i+1]);
      new_smaller_arr[i] = arr[i + 1];
    }
  }
  //  4 6 6 2
  // 4 3 6 2 1
  printf("new_smaller_arr before returning: \n");
  print_array(new_smaller_arr, size-1);
  return new_smaller_arr;
}

int get_sum_of_arr(int *arr, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    int value = arr[i];
    sum += value;
  }
  return sum;
}

int main() {

  printf("Starting...\n");

  int base[N];
  base[0] = 1;
  base[1] = 2;
  base[2] = 3;
  base[3] = 4;
  base[4] = 5;

  int output_sum = 0;

  // for (int i = 0; i < N; i++){
  //   output_sum += base[i];
  // }

  // dla kazdego poziomu
  // stworz mniejsza arrajke
  // znajdz mniejsza arrajke
  // przypisz mniejsza arrajke
  for (int i = 0; i < N; i++) { // For every level
    int *new_base_arr = (int *)malloc((N - i) * sizeof(int));
    int *new_arr = (int *)malloc((N - i - 1) * sizeof(int));
    if (i == 0) {
      printf("\ncheck - 1\n");
      new_base_arr = base;
    }
    new_arr = create_new_smaller_arr(new_base_arr, N - i);
    // print_array(new_arr, N - i - 1);
    int arr_value = get_sum_of_arr(new_arr, N - 1);
    output_sum += arr_value;
    new_base_arr = new_arr;

    // free(new_base_arr);
    // free(new_arr);
  }
  printf("output sum: %d\n", output_sum);

}
/*

    6
   6 6
  6 6 6
 4 6 6 2
4 3 6 2 1


    5
   4 5
  3 4 5
 2 3 4 5
1 2 3 4 5
*/
