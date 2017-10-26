#include <stdio.h>
#include <stdlib.h>

int n;
int findSubSet(int array[], int subset[], int sum, int index, int subSetIndex) {
        if (index == n) {
            return 0;
        }

        if (array[index] == sum) {
            subset[subSetIndex] = array[index];
            return 1;
        }

        for (int i = index; i < n; i++) {
            if (array[i] > sum) {
                continue;
            }

            if (array[i] == sum) {
                subset[subSetIndex] = array[i];
                return 1;
            }

            subset[subSetIndex] = array[i];
            if (findSubSet(array, subset, sum - array[i], i + 1, subSetIndex + 1)) {
                return 1;
            }

        }
        return 0;
    }
void findSumSubSet(int array[], int sum) {

        int subset[100] ;

        int isSubSetFound = findSubSet(array, subset, sum, 0, 0);
        if (isSubSetFound) { 
            printf("\nSum subset for :%d\n",sum);

            for (int temp = 0, i = 0; temp != sum; temp += subset[i], i++) {
                printf("%d ->",subset[i]);
            }
            printf("\n");
        } else {
            printf("\nSubset not found for sum : %d\n",sum);
        }
    }


int main() {
        int array[] = {1 ,2 ,5 ,6 ,8};
         n=5;
        findSumSubSet(array, 9);
    }


//Contributed by Ajay Hegde