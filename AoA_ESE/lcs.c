#include <stdio.h>
#include <string.h>

/*
How it works (The DP Logic):
We create a 2D table L[m+1][n+1] where m and n are lengths of the strings.
Base Case: If either string is empty, the LCS length is 0. So, the first row and first column of our table are filled with 0.
Match Found: If characters S1[i-1] == S2[j-1], we look at the diagonal result and add 1:
L[i][j] = 1 + L[i-1][j-1]
No Match: If characters don't match, we take the maximum value from either the cell above or the cell to the left:
L[i][j] = max(L[i-1][j], L[i][j-1])
Reconstruction: After filling the table, we start from the bottom-right corner and "backtrack" to find the actual characters.
*/

// Helper function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

void findLCS(char* S1, char* S2) {
    int m = strlen(S1);
    int n = strlen(S2);
    int L[m + 1][n + 1]; // DP Table

    // --- STEP 1: Fill the DP Table ---
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // If any string is empty, LCS length is 0
            if (i == 0 || j == 0)
                L[i][j] = 0;
            
            // If characters match, add 1 to the diagonal result
            else if (S1[i - 1] == S2[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            
            // If characters don't match, take max of Top or Left
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    // The value at L[m][n] is the length of the LCS
    int index = L[m][n];
    printf("\nLength of LCS: %d\n", index);

    // --- STEP 2: Reconstruct the LCS String (Backtracking) ---
    char lcsString[index + 1];
    lcsString[index] = '\0'; // Null terminator

    int i = m, j = n;
    while (i > 0 && j > 0) {
        // If current characters in S1 and S2 match, it's part of LCS
        if (S1[i - 1] == S2[j - 1]) {
            lcsString[index - 1] = S1[i - 1]; // Put character in result
            i--; j--; index--; // Move diagonally up
        }
        // If not matching, move in direction of larger value
        else if (L[i - 1][j] > L[i][j - 1])
            i--; // Move Up
        else
            j--; // Move Left
    }

    printf("LCS String: %s\n", lcsString);
}

int main() {
    char S1[100], S2[100];

    printf("Enter First String: ");
    scanf("%s", S1);
    printf("Enter Second String: ");
    scanf("%s", S2);

    findLCS(S1, S2);

    return 0;
}