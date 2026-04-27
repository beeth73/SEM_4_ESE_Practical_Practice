#include <stdio.h>

// Structure to represent an item
struct Item {
    int id;
    double profit;
    double weight;
    double ratio;
};

// Function to perform Selection Sort on items based on Ratio (Descending)
// We use Selection Sort here to keep the code simple and readable
void sortItems(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (items[j].ratio > items[max_idx].ratio) {
                max_idx = j;
            }
        }
        // Swap items
        struct Item temp = items[i];
        items[i] = items[max_idx];
        items[max_idx] = temp;
    }
}

void fractionalKnapsack(struct Item items[], int n, double capacity) {
    double totalProfit = 0.0;
    double currentWeight = 0.0;

    printf("\n--- Processing Knapsack ---\n");
    printf("Capacity: %.2f\n\n", capacity);

    for (int i = 0; i < n; i++) {
        // If adding the whole item won't exceed capacity
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalProfit += items[i].profit;
            printf("Added Item %d (Full): Profit %.2f, Weight %.2f\n", 
                    items[i].id, items[i].profit, items[i].weight);
        } 
        // If we can only take a fraction
        else {
            double remaining = capacity - currentWeight;
            double fractionProfit = items[i].profit * (remaining / items[i].weight);
            
            totalProfit += fractionProfit;
            printf("Added Item %d (Fraction): Added %.2f weight, Profit %.2f\n", 
                    items[i].id, remaining, fractionProfit);
            
            currentWeight += remaining;
            break; // Knapsack is now full
        }
    }

    printf("\nFinal Result:\n");
    printf("Total Weight in Knapsack: %.2f\n", currentWeight);
    printf("Maximum Profit: %.2f\n", totalProfit);
}

int main() {
    int n;
    double capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
        printf("Enter Profit and Weight for Item %d: ", i + 1);
        scanf("%lf %lf", &items[i].profit, &items[i].weight);
        // Pre-calculate the ratio for sorting
        items[i].ratio = items[i].profit / items[i].weight;
    }

    printf("Enter maximum capacity of knapsack: ");
    scanf("%lf", &capacity);

    // Step 1: Sort items by ratio descending
    sortItems(items, n);

    printf("\nSorted items (by Profit/Weight ratio):\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: Ratio %.2f (P:%.1f, W:%.1f)\n", 
                items[i].id, items[i].ratio, items[i].profit, items[i].weight);
    }

    // Step 2: Greedy selection
    fractionalKnapsack(items, n, capacity);

    return 0;
}