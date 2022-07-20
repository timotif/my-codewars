#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void print_array(int *arr, int size)
{
    for (int x = 0; x < size; x++)
        printf("%d ", arr[x]);
    printf("\n");
}
void swap(int *a, int *b)
{
        int tmp = *a;
        *a = *b;
        *b = tmp;
}


bool comp(const int *a, const int *b, size_t n)
{
  int sort_a[n];
  int sort_b[n];
  
  for (size_t i = 0; i < n; i++)
    {
    sort_a[i] = a[i];
    sort_b[i] = b[i];
  }
  // Sort
  int sorted = 0;
  for (size_t i = 0; i < n - 1; i++)
    {
    sorted = 1;
    for (size_t j = 0; j < n - i - 1; j++)
      {
      if (sort_a[j] > sort_a[j + 1])
        {
        sorted = 0;
        swap(&sort_a[j], &sort_a[j + 1]);
      }
       if (sort_b[j] > sort_b[j + 1])
        {
        sorted = 0;
        swap(&sort_b[j], &sort_b[j + 1]);
      }
    }
    if (sorted)
      break;
  }
  for (size_t i = 0; i < n; i++)
    {
        if (sort_a[i]*sort_a[i] != sort_b[i])
            return false;
  }
  return true;
}

int main(void)
{
    int a[] = {121, 144, 19, 161, 19, 144, 19, 11};
    int b[] = {121, 14641, 20736, 361, 25921, 361, 20736, 361};
    printf("%s\n", comp(a, b, 8) ? "Same" : "Not same");
}