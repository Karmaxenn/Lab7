#include <stdio.h>

void swap(int *a, int *b)
{
  int temp=*a;
  *a=*b;
  *b=temp;
}
void printSwaps(int arr[], int n, int swaps[])
{
    int i;
    for(i=0;i<n;i++)
    {
      printf("%d is swapped %d times\n", arr[i], swaps[arr[i]]);
    }
}

void bubbleSort(int arr[], int n, int swaps[])
{
    int i, j, temp, totalSwaps=0;
    for(i=0;i<n-1;i++)
    {
      for(j=0;j<n-i-1;j++)
      {
        if(arr[j]>arr[j+1])
        {
          swap(&arr[j], &arr[j+1]);
          swaps[arr[j]]++;
          swaps[arr[j+1]]++;
          totalSwaps++;
        }
      }
    }
    printSwaps(arr, n, swaps);
    printf("Total swaps: %d\n", totalSwaps);
}

void selectionSort(int arr[], int n, int swaps[])
{
    int i, j, min_index, temp, totalSwaps=0;
    for(i=0;i<n-1;i++)
    {
      min_index=i;
      for(j=i+1;j<n;j++)
      {
        if(arr[j]<arr[min_index])
        {
          min_index=j;
          totalSwaps++;
        }
      }
      swap(&arr[min_index], &arr[i]);
      swaps[arr[i]]++;
      swaps[arr[min_index]]++;
    }
    printSwaps(arr, n, swaps);
    printf("Total swaps: %d\n", totalSwaps);
}

int main()
  {
  int array1[]={97, 16, 45, 63, 13, 22, 7, 58, 72};
  int array2[]={90, 80, 70, 60, 50, 40, 30, 20, 10};
  int size=sizeof(array1)/sizeof(array1[0]);

  int swaps1[100]={0};
  int swaps2[100]={0};
  int temp[size];

  for(int i=0;i<size;i++)
  {
    temp[i]=array1[i];
  }
  printf("Bubble Sort Array 1:\n");
  bubbleSort(array1, size, swaps1);

  for(int i=0;i<100;i++)
    swaps1[i]=0;
    
  printf("\nSelection Sort Array 1:\n");
  selectionSort(temp, size, swaps1);

  for(int i=0;i<size;i++)
  {
    temp[i]=array2[i];
  }

  printf("\nBubble Sort Array 2:\n");
  bubbleSort(array2, size, swaps2);

  for(int i=0;i<100;i++)
    swaps2[i]=0;
    
  printf("\nSelection Sort Array 2:\n");
  selectionSort(temp, size, swaps2);
  
  return 0;
}