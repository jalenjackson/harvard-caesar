#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int main(int argc , char *argv[]) {

    // ci = (pi + k) % 26

    string cypher;
    string backToPlain;
    string message;
    int key;
    bool decypherIt = false;
    bool cypherIt = false;

    if (argc > 3) {

        if (strcmp(argv[1], "cypher") == 0)
            cypherIt = true;

        if (strcmp(argv[1], "decypher") == 0)
            decypherIt = true;

        key = atoi(argv[2]);

        if(!isdigit(atoi(argv[2])))
            printf("please enter a key to cypher. ex: ./main cypher 2 hello world\n");

    } else {
        printf("Please enter either cypher or decypher and a key");
    }

    if (cypherIt) {
        for (int i = 3; i < argc; i++) {
            for (int j = 0, n=strlen(argv[i]); j < n; j++) {

                if (argv[i][j] != '\0') {

                    if (!isalpha(argv[i][j])) {
                        cypher += argv[i][j];
                    } else if (isupper(argv[i][j])) {
                        cypher += (((argv[i][j] - 65) + key) % 26) + 65;
                    } else if (islower(argv[i][j])) {
                        cypher += (((argv[i][j] - 97) + key) % 26) + 97;
                    }
                }
            }
            cypher += " ";
        }
    }

    if(decypherIt) {
        for (int i = 3; i < argc; i++) {
            for(int j=0, n=strlen(argv[i]); j<n ;j++) {

                if (!isalpha(argv[i][j])) {
                    backToPlain += argv[i][j];
                } else if (isupper(argv[i][j])) {
                    backToPlain += (((argv[i][j] - 90) - key) % 26) + 90;
                } else if (islower(argv[i][j])) {
                    backToPlain += (((argv[i][j] - 122) - key) % 26) + 122;
                }
            }

            backToPlain += " ";
        }
    }

    for (int i = 3; i < argc; i++) {
        message += argv[i];
        message += " ";
    }

    if(cypherIt) {
        printf("Your message: %s\n", message.c_str());
        printf("Your cypher: %s\n", cypher.c_str());
    }
    else if(decypherIt) {
        printf("The cyphered message is: %s\n ", backToPlain.c_str());
    } else {
        printf("Please enter either cypher or decypher in the command line");
    }
}

