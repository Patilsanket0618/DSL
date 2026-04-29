#include <stdio.h>

#define MAX 100

int main() {
    int arr[MAX], n, i, choice, pos, value;

    // Input array size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input elements
    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Traverse\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Sort\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1: // Traverse
                printf("Array elements are:\n");
                for(i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                break;

            case 2: // Insert
                printf("Enter position and value: ");
                scanf("%d %d", &pos, &value);

                if(pos < 0 || pos > n) {
                    printf("Invalid position!\n");
                } else {
                    for(i = n; i > pos; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[pos] = value;
                    n++;
                }
                break;

            case 3: // Delete
                printf("Enter position to delete: ");
                scanf("%d", &pos);

                if(pos < 0 || pos >= n) {
                    printf("Invalid position!\n");
                } else {
                    for(i = pos; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                }
                break;

            case 4: // Search
                printf("Enter value to search: ");
                scanf("%d", &value);
                int found = 0;

                for(i = 0; i < n; i++) {
                    if(arr[i] == value) {
                        printf("Element found at position %d\n", i);
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    printf("Element not found!\n");
                }
                break;

            case 5: // Sort (Bubble Sort)
                for(i = 0; i < n - 1; i++) {
                    for(int j = 0; j < n - i - 1; j++) {
                        if(arr[j] > arr[j + 1]) {
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                printf("Array sorted successfully!\n");
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 6);

    return 0;
}