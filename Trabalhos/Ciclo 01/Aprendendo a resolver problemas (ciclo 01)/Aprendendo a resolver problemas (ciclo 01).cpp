#include <stdio.h>

int BuscaBinaria(int arr[], int l, int r, int x)
{
if (r >= l)
{
int mid = l + (r - l)/2;
if (arr[mid] == x) return mid;
if (arr[mid] > x) return BuscaBinaria(arr, l, mid-1, x);
return BuscaBinaria(arr, mid+1, r, x);
}
return -1;
}
int main(void)
{
int arr[] = {2, 3, 4, 10, 40};
int n = sizeof(arr)/ sizeof(arr[0]);
int x = 10;
int result = BuscaBinaria(arr, 0, n-1, x);
(result == -1)? printf("Elemento não está presente na matriz")
: printf("Elemento está presente no índice %d", result);
return 0;
}

