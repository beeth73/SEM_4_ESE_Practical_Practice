#include <stdio.h>

int main() {
    int n, f, i, j, pf_fifo=0, pf_lru=0;
    printf("Enter no. of pages and frames: ");
    scanf("%d %d", &n, &f);
    int pg[n], fr[f], time[f], counter=0;

    printf("Enter page string: ");
    for(i=0; i<n; i++) scanf("%d", &pg[i]);

    // FIFO Logic (Simplified)
    int next = 0;
    for(i=0; i<f; i++) fr[i] = -1;
    for(i=0; i<n; i++) {
        int found = 0;
        for(j=0; j<f; j++) if(fr[j] == pg[i]) found = 1;
        if(!found) { fr[next] = pg[i]; next = (next+1)%f; pf_fifo++; }
    }

    // LRU Logic (Simplified)
    for(i=0; i<f; i++) { fr[i] = -1; time[i] = 0; }
    for(i=0; i<n; i++) {
        int found = 0;
        for(j=0; j<f; j++) if(fr[j] == pg[i]) { found = 1; time[j] = ++counter; }
        if(!found) {
            int min = time[0], pos = 0;
            for(j=1; j<f; j++) if(time[j] < min) { min = time[j]; pos = j; }
            fr[pos] = pg[i]; time[pos] = ++counter; pf_lru++;
        }
    }

    printf("\nFIFO Page Faults: %d", pf_fifo);
    printf("\nLRU Page Faults: %d\n", pf_lru);
    return 0;
}