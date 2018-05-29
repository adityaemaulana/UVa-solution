#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    int mLoan, nRec; //months of loan, month of depreciation, number of records
    double mDepr, dp, amnLoan, amnItem, pDepr,pDeprTemp,ind, res, i, b; //Down Payment, Amount of Loan, Percentage of Depreciation
    mLoan = 1;
    while(mLoan > 0){
        scanf("%d %lf %lf %d", &mLoan, &dp, &amnLoan, &nRec);
        if(mLoan <= 0) break;
        i = 0;b = 0;

        while(i < nRec){
            pDeprTemp = pDepr;
            scanf("%lf %lf", &mDepr, &pDepr);

            if(i == 0) amnItem = amnLoan+dp - (amnLoan+dp)*pDepr;
            else{
                b = mDepr - b;

                if(b == 1){
                    amnItem -= amnItem*pDepr;
                }else{
                    amnItem = (amnItem*(1-pDeprTemp*(b-1)))-(amnItem*(1-pDeprTemp*(b-1)))*pDepr;
                }

                amnLoan -= dp*b;
            }

            ind = (amnLoan-amnItem)/(dp-amnLoan*pDepr);
            cout<<ind<<endl;
            if(amnLoan < amnItem) res = ind+mDepr;
            cout<<amnLoan<<" "<<amnItem<<endl;

            i++;
        }
        if(amnLoan > amnItem) res = ind+mDepr;

        if(res > 1) printf("%lf months \n", ceil(res));
        else printf("%lf month \n", ceil(res));
    }

    return 0;

}
