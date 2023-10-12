#include <stdio.h>


float CalculateIncomeTax(int income)
{
    float incomeTax = 0;
    float incomeTaxTable[7][2] = {
            {11000, 0},
            {18000-11000,0.2f},
            {31000-18000,0.35f},
            {60000-31001,0.42f},
            {90000-60001,0.48f},
            {100000-90001,0.25f},
            {0,0.55f},
    };

    for (int i = 0; i < sizeof(incomeTaxTable) / sizeof(incomeTaxTable[0]); ++i) {
        if(income > 0)
        {
            float taxCap = incomeTaxTable[i][0];
            float percent = incomeTaxTable[i][1];
            float incomeToTax = 0;

            incomeToTax = income > taxCap  ? taxCap : income;
            income = income - incomeToTax;
            incomeTax = incomeTax + (incomeToTax *percent);
        }

    }
    return incomeTax;
}

float CalculateDistanceMoney(int distance)
{
    float distanceMoney = distance * 2;

    float distanceMoneyTable[4][2] =            {
                    {20, 0},
                    {40, 696},
                    {60, 1356},
                    {-1, 2016},
            };

    for (int i = 1; i < sizeof(distanceMoneyTable) / sizeof(distanceMoneyTable[0]); ++i)
    {

        if((distance <= distanceMoneyTable[i][0] && distance > distanceMoneyTable[i -1][0]) ||
           (distance > distanceMoneyTable[i -1][0] &&  distanceMoneyTable[i][0] == -1))
        {
            distanceMoney += distanceMoneyTable[i][1];
        }
    }
    return distanceMoney;
}

int main() {
    int income, distance, adCosts;
    printf("Please enter you income: ");
    scanf("%i", &income);


    printf("Please enter you distance: ");
    scanf("%i", &distance);


    printf("Please enter you advertisment costs: ");
    scanf("%i", &adCosts);

    income = income - adCosts;
    float incomeTax = CalculateIncomeTax(income);
    float distanceMoney = CalculateDistanceMoney(distance);
    float tax = incomeTax - distanceMoney;
    float net = income - tax + adCosts;

    printf("\nYour taxes are %.2f € and you net income is %.2f €", tax, net);
    return 0;
}