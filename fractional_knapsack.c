#include <stdio.h>

struct Item {
    int id;
    int profit;
    int weight;
    float ratio;
};

// Function to sort items based on ratio
void sortItems(struct Item items[], int n) {
    int i, j;
    struct Item temp;

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

// Fractional Knapsack Function
float fractionalKnapsack(struct Item items[], int n, int capacity) {

    int i;
    float totalProfit = 0.0;

    // Sort items by ratio
    sortItems(items, n);

    printf("\nSelected Items:\n");
    printf("Item\tProfit\tWeight\tFraction Taken\n");

    for(i = 0; i < n; i++) {

        // Take complete item
        if(items[i].weight <= capacity) {

            capacity -= items[i].weight;
            totalProfit += items[i].profit;

            printf("%d\t%d\t%d\t1.00\n",
                   items[i].id,
                   items[i].profit,
                   items[i].weight);
        }

        // Take fractional item
        else {

            float fraction = (float)capacity / items[i].weight;

            totalProfit += items[i].profit * fraction;

            printf("%d\t%d\t%d\t%.2f\n",
                   items[i].id,
                   items[i].profit,
                   items[i].weight,
                   fraction);

            break;
        }
    }

    return totalProfit;
}

int main() {

    int n, capacity, i;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    // Input profits and weights
    for(i = 0; i < n; i++) {

        items[i].id = i + 1;

        printf("\nEnter profit for item %d: ", i + 1);
        scanf("%d", &items[i].profit);

        printf("Enter weight for item %d: ", i + 1);
        scanf("%d", &items[i].weight);

        items[i].ratio =
            (float)items[i].profit / items[i].weight;
    }

    printf("\nEnter knapsack capacity: ");
    scanf("%d", &capacity);

    float maxProfit =
        fractionalKnapsack(items, n, capacity);

    printf("\nMaximum Profit = %.2f\n", maxProfit);

    return 0;
}
