#include <iostream>
#include <dlfcn.h>
#include "library.h"

int main() {
    void* handle = dlopen("/Users/darynaburdak/CLionProjects/assigment3_library_sh/libassigment3.dylib", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    char* (*encrypt)(char* raw_text, int key);
    encrypt = (char* (*)(char*, int))dlsym(handle, "encrypt");
    if (!encrypt) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    char* (*decrypt)(char* encrypted_text, int key);
    decrypt = (char* (*)(char*, int))dlsym(handle, "decrypt");
    if (!decrypt) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    char exit_s[50];
    int key;
    char key_text[20];
    char * encrypted_text_p;
    char * decrypted_text_p;
    char text[300];
    while (exit_s!="yes") {
        printf("Enter the shift key for encrypting: ");
        fgets(key_text, 20, stdin);
        key = atoi(key_text);
        printf("Enter the text for encrypting: ");
        fgets(text, 300, stdin);
        encrypted_text_p=encrypt(text, key);
        printf("Encrypted text is: %s", encrypted_text_p);
        decrypted_text_p=decrypt(encrypted_text_p,key);
        printf("Decrypted text is: %s", decrypted_text_p);
        printf("Do you want to encrypt and decrypt another text?(enter - yes) ");
        fgets(exit_s, 50, stdin);


    }


    dlclose(handle);


}