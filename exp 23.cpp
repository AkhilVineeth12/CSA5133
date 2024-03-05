#include <stdio.h>
unsigned short key = 0b0111111101;
unsigned short counter = 0b00000000;
unsigned short sdes_encrypt(unsigned short plaintext, unsigned short key);
void ctr_encrypt(unsigned short *plaintext, int length);
void ctr_decrypt(unsigned short *ciphertext, int length);

int main() {
    unsigned short plaintext[] = {0b0000, 0b0001, 0b0000, 0b0010, 0b0000, 0b0100};
    int length = sizeof(plaintext) / sizeof(plaintext[0]);
    ctr_encrypt(plaintext, length);

    printf("Encrypted ciphertext:\n");
    for (int i = 0; i < length; i++) {
        printf("%04x ", plaintext[i]);
    }
    printf("\n");
    ctr_decrypt(plaintext, length);
    printf("Decrypted plaintext:\n");
    for (int i = 0; i < length; i++) {
        printf("%04x ", plaintext[i]);
    }
    printf("\n");
    return 0;
}
unsigned short sdes_encrypt(unsigned short plaintext, unsigned short key) {
    
}
void ctr_encrypt(unsigned short *plaintext, int length) {
    for (int i = 0; i < length; i++) {
        plaintext[i] ^= sdes_encrypt(counter, key);
        counter++;
    }
}
void ctr_decrypt(unsigned short *ciphertext, int length) {
    ctr_encrypt(ciphertext, length);
}

