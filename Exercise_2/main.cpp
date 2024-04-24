#include "Utils.hpp"
#include<iostream>
using namespace std;
int main()
{
    string InputFileName="data.csv";
    size_t n=0;
    double S=0;
    double* w=nullptr;
    double* r=nullptr;
    char delimiter=';';
    if(!ImportData(InputFileName,n,S,w,r,delimiter)){
        cerr<<"file non aperto correttamente"<<endl;
        return -1;
    }
    double rateOfReturn=RateOfReturn(w,r,n);
    double portfolio=Portfolio(rateOfReturn,S);
    string OutputFileName="result.txt";
    if(!ExportResult(OutputFileName,w,r,S,n,rateOfReturn,portfolio)){
        cerr<<"errore"<<endl;
        return -1;
    }
    delete[] w;
    delete[] r;


    return 0;
}

