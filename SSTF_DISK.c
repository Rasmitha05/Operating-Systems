#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

void array_sort(int arr[], int index[], int size)
{
  int i, j, temp;
  int tempIndex;

  for (i = 0; i < size - 1; i++)
  {
    for (j = 0; j < size - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {

        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;

        tempIndex = index[j];
        index[j] = index[j + 1];
        index[j + 1] = tempIndex;
      }
    }
  }
}

int main()
{
  int head = 53;
  int loc[] = {98, 183, 37, 122, 14, 124, 65, 67};
  int sam[8];
  int index[8];

  for (int i = 0; i < 8; i++)
  {
    sam[i] = abs(loc[i] - head);
    index[i] = i;
  }

  array_sort(sam, index, 8);

  printf("The order of sequence is %d ", head);
  for (int i = 0; i < 8; i++)
  {
    printf("-> %d ", loc[index[i]]);
  }

  printf("\n");
  return 0;
}
