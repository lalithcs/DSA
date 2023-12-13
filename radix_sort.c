//radix Sort
#include<stdio.h>
int getMax(int array[], int n) 
{
int max = array[0];
int i;
for (i = 1; i < n; i++) 
if (array[i] > max)
max = array[i];
return max;
} 
void countSort(int array[], int n, int dig)
 {
int output[n]; 
int i, count[10] = { 0 };
for (i = 0; i < n; i++)
count[(array[i] / dig) % 10]++; 
for (i = 1; i < 10; i++)
 count[i] += count[i - 1]; 
for (i = n - 1; i >= 0; i--) {
output[count[(array[i] / dig) % 10] - 1] = array[i];
count[(array[i] / dig) % 10]--;
} 
for (i = 0; i < n; i++)
 array[i] = output[i]; 
} 
void radixsort(int array[], int n)
 { 
int max = getMax(array, n);
 int dig; 
for (dig = 1; max / dig > 0; dig *= 10)
countSort(array, n, dig);
}
void print(int arr[], int n) {
int i;
for (i = 0; i < n; i++)
printf("%d ", arr[i]);
} 
int main (){
   int i, n, a[10];
   printf ("Enter the number of items to be sorted: ");
   scanf ("%d", &n);
   printf ("Enter items: ");
   for (i = 0; i < n; i++){
      scanf ("%d", &a[i]);
   }
   radixsort (a, n);
   printf ("Sorted items : ");
   for (i = 0; i < n; i++)
      printf ("%d ", a[i]);
   printf ("\n");
   return 0;
}

