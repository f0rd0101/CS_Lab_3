#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10  


int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[MAX_SIZE];
    int n;

   
    printf("Введіть кількість елементів вектора (не більше %d): ", MAX_SIZE);
    scanf("%d", &n);

 
    if (n < 3) {
        printf("Вектор повинен містити хоча б 3 елементи.\n");
        return 1;
    }

   
    printf("Введіть елементи вектора, елементи потрібно вводити в порядку a b c d : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    qsort(arr, n, sizeof(int), compare);

  
    int temp[3];
    for (int i = 0; i < 3; i++) {
        temp[i] = arr[i];  
    }

    
    for (int i = 3; i < n; i++) {
        arr[i - 3] = arr[i];
    }

   
    for (int i = 0; i < 3; i++) {
        arr[n - 3 + i] = temp[i];
    }

    
    printf("Результат:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
