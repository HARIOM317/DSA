# include <stdio.h>

int main(){
    int n;
    printf("Array size : ");
    scanf("%d", &n);
    int arr[n], i, sum = 0;
    printf("Enter array elements : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (i%2 == 0)
        {
            sum += arr[i];
        }
    }
    printf("Sum of even position elements : %d", sum);

    return 0;
}