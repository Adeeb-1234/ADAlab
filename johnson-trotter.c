#include <stdio.h>

// Function to print the current permutation
void printPermutation(int perm[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", perm[i]);
    printf("\n");
}

// Function to find the largest mobile element index
int getMobile(int perm[], int dir[], int n) {
    int mobile = 0;
    int mobile_index = -1;

    for (int i = 0; i < n; i++) {
        // LEFT direction
        if (dir[perm[i] - 1] == -1 && i > 0) {
            if (perm[i] > perm[i - 1] && perm[i] > mobile) {
                mobile = perm[i];
                mobile_index = i;
            }
        }
        // RIGHT direction
        if (dir[perm[i] - 1] == 1 && i < n - 1) {
            if (perm[i] > perm[i + 1] && perm[i] > mobile) {
                mobile = perm[i];
                mobile_index = i;
            }
        }
    }

    return mobile_index;
}

// Johnson-Trotter algorithm
void johnsonTrotter(int n) {
    int perm[n];
    int dir[n]; // -1 = LEFT, 1 = RIGHT

    // Initialize permutation and directions
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = -1; // all pointing LEFT initially
    }

    printPermutation(perm, n);

    while (1) {
        int mobile_index = getMobile(perm, dir, n);

        if (mobile_index == -1)
            break;

        int mobile = perm[mobile_index];

        // Swap based on direction
        if (dir[mobile - 1] == -1) {
            int temp = perm[mobile_index];
            perm[mobile_index] = perm[mobile_index - 1];
            perm[mobile_index - 1] = temp;
            mobile_index--;
        } else {
            int temp = perm[mobile_index];
            perm[mobile_index] = perm[mobile_index + 1];
            perm[mobile_index + 1] = temp;
            mobile_index++;
        }

        // Reverse direction of elements greater than mobile
        for (int i = 0; i < n; i++) {
            if (perm[i] > mobile)
                dir[perm[i] - 1] *= -1;
        }

        printPermutation(perm, n);
    }
}

// Driver code
int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
