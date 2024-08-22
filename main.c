#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

#define N 5

void print_array(int *arr, int size) {
  printf("Printing array:\n");
  for (int i = 0; i < size; i++) {
    printf("%d - ", arr[i]);
  }
  printf("\n");
}

int *create_new_smaller_arr(int *arr, int size) {
  int *new_smaller_arr = (int *)malloc((size - 1) * sizeof(int));
  // printf("Arr argument in create_new_smaller_arr function\n");
  // print_array(arr, size);
  for (int i = 0; i < size - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      // printf("assigning left value of: %d\n", arr[i]);
      new_smaller_arr[i] = arr[i];
    } else {
      // printf("assigning left value of: %d\n", arr[i + 1]);
      new_smaller_arr[i] = arr[i + 1];
    }
  }
  //  4 6 6 2
  // 4 3 6 2 1
  // printf("new_smaller_arr before returning: \n");
  print_array(new_smaller_arr, size - 1);
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

  // int base[N] = {1, 2, 3, 4, 5};
  // int base[N] = {1, 10, 1, 10, 1, 10};
  int base[N] = {4,3,6,2,1};

  int output_sum = 0;

  // for (int i = 0; i < N; i++){
  //   output_sum += base[i];
  // }

  // dla kazdego poziomu
  // stworz mniejsza arrajke
  // znajdz mniejsza arrajke
  // przypisz mniejsza arrajke
  int *current_base_arr = base;
  int current_size = N;

  output_sum += get_sum_of_arr(current_base_arr, N);
  for (int i = 0; i < N - 1; i++) { // For every level
    int *new_arr = create_new_smaller_arr(current_base_arr, current_size);
    int arr_value = get_sum_of_arr(new_arr, current_size - 1);
    output_sum += arr_value;
    printf("Adding %d to output sum\n", arr_value);

    if (i>0){
      free(current_base_arr);
    }
    current_base_arr = new_arr;
    current_size--;

  }
  free(current_base_arr);
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
