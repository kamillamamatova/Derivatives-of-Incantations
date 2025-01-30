#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for input
#define MAX_INCANTATIONS 1000
#define MAX_LENGTH 1001

// Helper function to check if one string is a substring of another
int isDerivative(char * a, char * b){
  return strstr(b, a) != NULL;
}

