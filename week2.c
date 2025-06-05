#include <stdio.h>
#include <string.h>

int main() {
    char input[100], key[30], temp[30], quot[100], rem[30];
    int i, j, msglen, keylen;

    printf("Enter Data: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    printf("Enter Key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0;

    msglen = strlen(input);
    keylen = strlen(key);

    for (i = 0; i < keylen - 1; i++)
        input[msglen + i] = '0';
    input[msglen + keylen - 1] = '\0';

    strncpy(temp, input, keylen);

    for (i = 0; i < msglen; i++) {
        if (temp[0] == '1') {
            for (j = 0; j < keylen; j++)
                rem[j] = (temp[j] == key[j]) ? '0' : '1';
        } else {
            for (j = 0; j < keylen; j++)
                rem[j] = temp[j];
        }

        for (j = 0; j < keylen - 1; j++)
            temp[j] = rem[j + 1];
        temp[keylen - 1] = input[i + keylen];

        quot[i] = temp[0];
    }

    strncpy(rem, temp, keylen - 1);

    printf("\nQuotient is: ");
    for (i = 0; i < msglen; i++) printf("%c", quot[i]);

    printf("\nRemainder is: ");
    for (i = 0; i < keylen - 1; i++) printf("%c", rem[i]);

    printf("\nFinal data is: ");
    for (i = 0; i < msglen; i++) printf("%c", input[i]);
    for (i = 0; i < keylen - 1; i++) printf("%c", rem[i]);

    printf("\n");
    return 0;
}
