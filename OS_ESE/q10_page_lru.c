#include <stdio.h>

int findLRU(int time[], int n) {
    int min = time[0], pos = 0;
    for (int i = 1; i < n; i++) {
        if (time[i] < min) { min = time[i]; pos = i; }
    }
    return pos;
}

int main() {
    int n, f, i, j, pf = 0, counter = 0;
    printf("Enter no. of pages and frames: ");
    scanf("%d %d", &n, &f);
    int pg[n], fr[f], time[f];
    for (i = 0; i < f; i++) fr[i] = -1;

    printf("Enter page string: ");
    for (i = 0; i < n; i++) scanf("%d", &pg[i]);

    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < f; j++) {
            if (fr[j] == pg[i]) {
                found = 1;
                time[j] = ++counter; // Update access time
                break;
            }
        }
        if (!found) { // Page Fault
            int pos;
            if (i < f) pos = i; // Frames not full yet
            else pos = findLRU(time, f); // Kick out the oldest access
            
            fr[pos] = pg[i];
            time[pos] = ++counter;
            pf++;
        }
    }
    printf("Total Page Faults: %d\n", pf);
    return 0;
}