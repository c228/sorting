/*
  DESCRIPTION
  divide & sort algorithm
  divides input array into two halves,
  calls itself for the two halves,
  then merges the two sorted halves 
  merge() function used for merging two halves
  merge(arr, l, m, r) is a key process that assumes that
  arr[l,m] & arr[m+1, r] are sorted 
 */

/*
  PSEUDOCODE
  If r>1
  1. Find the middle point to divide the array into two halves
  middle m = (l+r)/2
  2. Call mergesort for first half
  mergeSort(arr, l, m)
  3. Call mergesort for second half
  mergeSort(arr, m+1, r)
  4. Merge the two halves sorted in step 2 and 3:
  merge(arr, l, m, r)

 */

void merge(int arr[], int l, int m, int r){
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  //temp arrays
  int L[n1];
  int R[n2];

  //copy data to temp arrays L[] and R[]
  for(i=0; i<n1; i++)
    L[i] = arr[l+i];
  for(j=0; j<n2; j++)
    R[j] = arr[m+1+j];

  // merge the temp arrays back into arr[l...r] 
  i = 0;
  j = 0;
  k = l; // initial index of merged subarray

  while(i<n1 && j<n2){
    if(L[i] <= R[j]){
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // copy the remaining elements of L[], if any
  while(i<n1){
    arr[k] = L[i];
    i++;
    k++;
  }

  // copy the remaining elements of R[], if any
  while(j<n2){
    arr[k] = R[j];
    j++;
    k++;
  }

}

void mergeSort(int arr[], int l, int r){
  if(l<r){
    // for avoiding overflow
    int m = l+(r-l)/2;
    
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);

    merge(arr, l, m, r);
  }
}

void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
}

int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
} 