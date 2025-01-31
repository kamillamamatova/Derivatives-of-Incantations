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

int main(){
  char incantations[MAX_INCANTATIONS][MAX_LENGTH];
  int isNonDerivative[MAX_INCANTATIONS] = {0}; // 0 means non-derivative
  int incantationCount = 0;

  // Read incantations until "END" is encountered
  while(1){
    char buffer[MAX_LENGTH];
    if(!fgets(buffer, MAX_LENGTH, stdin)) break;

    // Remove newline character if present
    buffer[strcspn(buffer, "\n")] = '\0';

    // Stop reading if we encounter "END"
    if(strcmp(buffer, "END")] == 0) break;

    // Copy the incantations to the array
    strcpy(incantations[incantationCount++], buffer);
  }

  // Mark derivatives by looping through all pairs
  for(int i = 0; i < incantationCount; i++){
    for(int j = 0; j < incantationCount; j++){
      if(i == j) continue;

      // Check if incantation[j] is a derivative of incantation[i]
      if(isDerivative(incantations[i], incantations[j])){
        // Mark incantation[j] as derivative
        isNonDerivative[j] = 1; 
      }
    }
  }
  
  // Count non-derivative incantations
  int nonDerivativeCount = 0;
  for (int i = 0; i < incantationCount; i++) {
    if(!isNonDerivative[i]){
      nonDerivativeCount++;
    }
  }
