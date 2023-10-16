#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12


void printMonthlyReport(double sales[]);
void printSalesSummary(double sales[]);
void printMovingAverages(double sales[]);
void printSalesHighToLow(double sales[]);

const char *months[MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

const char* getMonthName(int index) {
    return months[index];
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    double sales[MONTHS];
    for (int i = 0; i < MONTHS; i++) {
        fscanf(file, "%lf", &sales[i]);
    }
    fclose(file);

    printMonthlyReport(sales);
    printSalesSummary(sales);
    printMovingAverages(sales);
    printSalesHighToLow(sales);
    return 0;
}

void printMonthlyReport(double sales[]) {
    printf("Monthly sales report for 2022:\n");
    printf("Month Sales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s $%.2lf\n", months[i], sales[i]);
    }
    printf("\n");
}

void printSalesSummary(double sales[]) {
    double min = sales[0], max = sales[0], total = 0.0;
    int minMonth = 0, maxMonth = 0;
    for (int i = 0; i < MONTHS; i++) {
        if (sales[i] < min) {
            min = sales[i];
            minMonth = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            maxMonth = i;
        }
        total += sales[i];
    }
    printf("Sales summary:\n");
    printf("Minimum sales: $%.2lf (%s)\n", min, getMonthName(minMonth));
    printf("Maximum sales: $%.2lf (%s)\n", max, getMonthName(maxMonth));
    printf("Average sales: $%.2lf\n\n", total / MONTHS);
}

void printMovingAverages(double sales[]) {
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i < MONTHS - 5; i++) {
        double sum = 0.0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("%s - %s $%.2lf\n", getMonthName(i), getMonthName(i+5), sum / 6.0);
    }
    printf("\n");
}

void printSalesHighToLow(double sales[]) {
    typedef struct {
        double value;
        int index;
    } SaleData;

    SaleData sortedSales[MONTHS];
    for (int i = 0; i < MONTHS; i++) {
        sortedSales[i].value = sales[i];
        sortedSales[i].index = i;
    }

    for (int i = 0; i < MONTHS - 1; i++) {
        for (int j = 0; j < MONTHS - i - 1; j++) {
            if (sortedSales[j].value < sortedSales[j + 1].value) {
                SaleData temp = sortedSales[j];
                sortedSales[j] = sortedSales[j + 1];
                sortedSales[j + 1] = temp;
            }
        }
    }

    printf("Sales Report (Highest to Lowest):\n");
    printf("Month Sales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s $%.2lf\n", getMonthName(sortedSales[i].index), sortedSales[i].value);
    }
    printf("\n");
}
