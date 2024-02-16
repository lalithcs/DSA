#include <stdio.h>
#include <string.h>

void computeLPS(char *pattern, int M, int *lps) {
    int len = 0, i = 1;
    lps[0] = 0;

    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(char *text, char *pattern) {
    int N = strlen(text);
    int M = strlen(pattern);

    int lps[M];
    computeLPS(pattern, M, lps);

    int i = 0, j = 0;
    while (i < N) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }
        if (j == M) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    char text[100], pattern[100];

    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter pattern: ");
    scanf("%s", pattern);

    KMP(text, pattern);
    return 0;
}
