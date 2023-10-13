#include <stdio.h>

int main()
{
    int num[12];
    File* stats = fopen("input.txt", "r");

    if (!stats){
        printf("Error opening the file...\n");
        return -1;
    }

    for (int i = 0; i < 12; ++i) {
        if (fscanf(stats, "d", &num[i]) != 1) {
            printf("File contains invalid line\n");
            return -1;
        }
        num[i] = 
    }

    fclose(stats);
    return 0

    printf("Monthly sales report for 2022:\n");
    printf("\n Month        Sales\n");
    printf("\nJanuary    $");
    printf("\nFebruary   $");
    printf("\nMarch      $");
    printf("\nApril      $");
    printf("\nMay        $");
    printf("\nJune       $");
    printf("\nJuly       $");
    printf("\nAugust     $");
    printf("\nSeptember  $");
    printf("\nOctober    $");
    printf("\nNovember   $");
    printf("\nDecember   $\n");
    
    printf("\nSales summary:\n");
    printf("\nMinimun sales:   $");
    printf("\nMaximun sales:   $");
    printf("\nAverage sales:   $\n");
    
    printf("\nSix-Month Moving Average Report:\n");
    printf("\nJanuary    -  June       $");
    printf("\nFebruary   -  July       $");
    printf("\nMarch      -  August     $");
    printf("\nApril      -  September  $");
    printf("\nMay        -  October    $");
    printf("\nJune       -  November   $");
    printf("\nJuly       -  December   $\n");
    
    printf("\nSales Report (Highest to Lowest:\n");
    printf("\n Month        Sales\n");
    printf("\nJanuary    $");
    printf("\nFebruary   $");
    printf("\nMarch      $");
    printf("\nApril      $");
    printf("\nMay        $");
    printf("\nJune       $");
    printf("\nJuly       $");
    printf("\nAugust     $");
    printf("\nSeptember  $");
    printf("\nOctober    $");
    printf("\nNovember   $");
    printf("\nDecember   $\n");
    return 0;
}
