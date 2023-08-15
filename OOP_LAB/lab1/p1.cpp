/*Write a program to find the average expenditure of a company for each month of each year, each year and average over the range of years specified. 
Use arrays to construct a table, display the table of expenditure and find the sum and average.*/

#include <stdio.h>

int main()
{
    int start,end,n,start1,total_sum=0;
    int years[100][12],sum[100],sum_per_month[12];
    printf("Enter starting years: ");
    scanf("%d",&start);
    printf("Enter ending year: ");
    scanf("%d",&end);
    start1 = start;
    n = end-start+1;
    int i=0,j=0;
    for(i=1;i<=n;i++)
    {
        int sum_per_year =0;
        for(j=1;j<=12;j++)
        {
            printf("Enter expenses for year %d and month %d: ",start,j);
            scanf("%d",years[i][j]);
            sum_per_year = years[i][j];
        }
        sum[i] = sum_per_year;
        total_sum += sum_per_year;
        start++;
    }
    start = start1;
    printf("year | jan| feb| mar| apr| may| jun| jul | sep| oct| nov | dec |\n");
    for(j=1;j<=n;j++){
        printf("%d |",start1);
    
    for(int i=1;i<=12;i++)
    {
        printf("%d |", years[j][i]);
    }
    start1++;
    printf("\n");
    }
    printf("avg |");
    int sum_1=0;
    for(i=1;i<=12;i++)
    {
        int sum_1=0;
        for(int j=1;j<n;j++){
            sum_1 += years[j][i];
        }
        printf("%.2f |", float(sum_1)/n);
    }
    printf("\n");

    for(i=0;i<n;i++)
    {
        printf("Average in year %d: %.2f\n",start,float(sum_1)/12);
    }
    printf("Average in given number of years: %.2f\n",float(total_sum)/n);
    return 0;
}
