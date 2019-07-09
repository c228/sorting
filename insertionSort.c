#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void insertionSort(int arr[], int arrLen) {
  int i,j;
  int key;
  for(j=1; j<arrLen; j++){
    key=arr[j];
    i=j-1;
    while(i>=0 && arr[i]>key){
      arr[i+1]=arr[i];
      i=i-1;
    }
    arr[i+1]=key;
  }
}

int main() {
  int array[6] = {5, 2, 7, 3, 9, 0};
  int arrLen = 6;

  int i;
  printf("Original Array\n");
  for(i=0; i<arrLen; i++){
    printf("%d, ", array[i]);
  }
  printf("\n");

  insertionSort(array, arrLen);
  
  printf("Sorted Array\n");
  int j;
  for(j=0; j<arrLen; j++){
    printf("%d, ", array[j]);
  }
  printf("\n");
}

