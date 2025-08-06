#include <stdio.h>
#include <stdlib.h>

void abso(int *n)
{
    if (*n < 0) {
        *n = -(*n); // Make the number positive
    }
    return;
}
void main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num); // Read the number
    printf("Original number: %d\n", num);
    abso(&num);
    printf("Absolute value: %d\n", num);
}