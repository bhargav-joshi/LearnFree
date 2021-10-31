#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void insertionSortAsc(int arr[], int n)
{ int key, j; for(int i=1;i<n;i++)
{
    key = arr[i]; 
    j = i - 1; 
    while (j >= 0 && arr[j] > key) 
    {
        arr[j + 1] = arr[j];
        j = j - 1; 
        
    } 
    arr[j + 1] = key;
    }
} 
void insertionSortDesc(int arr[], int n)
{ 
    int key, j; 
    for(int i=1;i<n;i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] < key){
            arr[j + 1] = arr[j];
            j = j - 1;
            }
            arr[j + 1] = key;
        }
} void printArray(int arr[], int n)
{ 
    int i;
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]); 
        
    } 
    printf("\n");
} 
int main()
{
    time_t start, end; 
    double t;
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n); int arr[n];
    printf("\n 0:Quit \n 1:Create the array \n 2:Display the array \n 3:Sort in Asc Order \n 4:Sort in Dsc Order \n 5:Time Complexity for random\n 6:Time taken asc \n 7:Time taken desc \n 8:Time taken \n");
    insertionSortAsc(arr, n); 
    int ch = 1;
    while (ch) 
    { 
        scanf("%d",&ch);
        switch (ch) { 
            case 0:
            break; 
            case 1:
            for(int i=0;i<n;i++){
                arr[i] = 1 + rand() % 100;
                }
                printf("Vals Inserted\n");
                break;
            case 2:
            printArray(arr, n);
             break;
            case 3:
            insertionSortAsc(arr, n);
            printf("Sorted in asc\n");
            break;
            case 4:
            insertionSortDesc(arr, n);
            printf("Sorted in desc\n");
            break; 
            case 5: 
            for(int i=0;i<n;i++){
                arr[i] = 1 + rand() % 100;
                }
            start = clock();
            insertionSortAsc(arr, n);
            end = clock();
            t = end - start;
            printf("Time taken rand: %f\n", (t / CLOCKS_PER_SEC));
            break;
            case 6:
            for(int i=0;i<n;i++){
                arr[i] = 1 + rand() % 100;
                }
            insertionSortAsc(arr, n);
            start = clock();
            insertionSortAsc(arr, n);
            end = clock();
            t = end - start;
            printf("Time taken asc: %f\n", (t / CLOCKS_PER_SEC));
            break; case 7:
            for(int i=0;i<n;i++){
                arr[i] = 1 + rand() % 100;
                }
            insertionSortDesc(arr, n);
            start = clock();
            insertionSortAsc(arr, n);
            end = clock();
            t = end - start;
            printf("Time taken desc: %f\n", (t / CLOCKS_PER_SEC));
            break;
            case 8:
            for(int i=0;i<n;i++){
                arr[i] = 1 + rand() % 100;
                }
            insertionSortAsc(arr, n);
            start = clock();
            insertionSortAsc(arr, n);
            end = clock();
            t = end - start;
            printf("Time taken asc: %f\n", (t / CLOCKS_PER_SEC));
            for(int i=0;i<n;i++){ 
                arr[i] = 1 + rand() % 100;
            }
            insertionSortDesc(arr, n);
            start = clock();
            insertionSortAsc(arr, n);
            end = clock();
            t = end - start;
            printf("Time taken desc: %f\n", (t / CLOCKS_PER_SEC));
            for(int i=0;i<n;i++){
                arr[i] = 1 + rand() % 100;
                }
                start = clock();
            insertionSortAsc(arr, n);
            end = clock();
            t = end - start;
            printf("Time taken random: %f\n", (t / CLOCKS_PER_SEC));
            break;
            default:
            printf("Wrong choice try again\n");
            }
        }
        return 0;
}
