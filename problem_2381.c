#include <stdio.h>
#include <string.h>

void sortNames(char names[][21], int n) {
    char temp[21];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    char names[n][21];

    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    sortNames(names, n);

    printf("%s\n", names[k - 1]);

    return 0;
}
