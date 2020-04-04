/*****************************************************************************
 * Id: oste1799
 * Purpose:
 *   This is an algorithm that determines the shortest distance between values entered from the command line
 * Input:
 *  ./assignment1 # # # # # ... n     where # are numbers
 * Output:
 *  The only output is the shortest distance between values
 *
 * Compile:
 *  gcc -Wall -o assignment1 assignment1.c
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>
int minDistance(int *, int); // This is a prototype
int main(int argc, char *argv[]){
   int numOfArrayVals = argc - 1; // keeps track of number of values to be tested against each other
   int arr[numOfArrayVals]; // array to hold number of command line arguments
   int i;
   for(i = 1; i < argc; i++)
   {
      arr[i] = atoi(argv[i]); // converts all array chars to ints
   }
   printf("%d\n",minDistance(arr, numOfArrayVals));
   return 0;
}
// This function calculates the smallest distance between any two points in an array
// It accepts an array of integers and an integer
int minDistance(int *arr, int numOfArrayVals){
   int j;
   int k;
   int tempDis;
   int finalMinDis = 2147483647; // finalMinDis initialized to max regular integer size
   for(j = 1; j < numOfArrayVals + 1; j++)
   {
      for(k = 1; k < numOfArrayVals + 1; k++)
      {
         if(arr[j] != arr[k])
         {
            tempDis = abs(arr[j]-arr[k]); // current distance between array positions
            if(tempDis < finalMinDis)
            {
               finalMinDis = tempDis; // finalMinDis is set to temp distance if smaller than finalMinDis
            }
         }
         else
         {
            finalMinDis = 0;
         }
      }
   }
   return finalMinDis;
}
