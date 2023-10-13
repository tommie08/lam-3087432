#include <stdio.h>

int main()
{

    char sale[12];
    int i = 0;
    int tot = 0;
    FILE* file = fopen("sale.txt", "r");
    while(fgets(line[i], LSIZ, file)); {
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
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
