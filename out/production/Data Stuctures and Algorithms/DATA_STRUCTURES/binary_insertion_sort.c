//binary insertion sort
#include <stdio.h>
 int binarySearch(int a[], int item,  int low, int high)
{
    if (high <= low)
        return (item > a[low]) ?  (low + 1) : low;
     int mid = (low + high) / 2;
     if (item == a[mid])
           return mid + 1;
     if (item > a[mid])
        return binarySearch(a, item, mid + 1, high);
      return binarySearch(a, item, low,  mid - 1);
}
 void insertionSort(int a[], int n)
{    int i, loc, j, k, selected;
     for (i = 1; i < n; ++i)      {
        j = i - 1;
        selected = a[i];
        loc = binarySearch(a, selected, 0, j);
         while (j >= loc) 
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
}
 int main ()
{
   int i, n, a[10];
   printf ("Enter the number of items to be sorted: ");
   scanf ("%d", &n);
   printf ("Enter items: ");
   for (i = 0; i < n; i++){
      scanf ("%d", &a[i]);
   }
   insertionSort (a, n);
   printf ("Sorted items : ");
   for (i = 0; i < n; i++)
      printf ("%d ", a[i]);
   printf ("\n");
   return 0;
}


