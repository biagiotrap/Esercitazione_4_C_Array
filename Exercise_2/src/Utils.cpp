#include "Utils.hpp"
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;
bool ImportData(const string& InputFileName,size_t& n, double& S, double*& w,
                double*& r, const char& delimiter)
{
    ifstream file;
    file.open(InputFileName);
    if (file.fail()){
        cerr<<"file non aperto correttamente"<<endl;
        return false;
    }
    string line;
    while(!file.eof()){
        getline(file,line,delimiter);
        if(line[0]!='S')
            break;
    }
    istringstream convertS;
    convertS.str(line);
    convertS>>S;
    while(!file.eof()){
        getline(file,line,delimiter);
        if(line[0]!='n')
            break;
    }
    istringstream convertN;
    convertN.str(line);
    convertN>>n;
    getline(file,line);
    istringstream convertW;
    istringstream convertR;
    w=new  double[n];
    r=new double[n];
    for(unsigned int i=0;i<n;i++){
        getline(file,line,delimiter);
        convertW.clear();
        convertW.str(line);
        convertW>>w[i];
        getline(file,line);
        convertR.clear();
        convertR.str(line);
        convertR>>r[i];
    }
    file.close();
    return true;
 }

double RateOfReturn(const  double* const& w,
                    const double* const& r, const size_t& n)
{
    double rateOfReturn=0;
    for (unsigned int i=0;i<n;i++){
        rateOfReturn+=w[i]*r[i];
    }
    return rateOfReturn;
}

double Portfolio(const double& rateOfReturn,  const double& S){
    double portfolio=0;
    portfolio=(1+rateOfReturn)*S;
    return portfolio;
}
bool ExportResult(const string& OutputFileName,const double* const& w,
                  const double* const& r, const double& S, size_t& n,
                  const double& rateOfReturn, const double& portfolio ){
    ofstream file;
    file.open(OutputFileName);
    if(file.fail()){
        cerr<<"file non aperto correttamente"<<endl;
        return false;
    }
    file<<"S = "<<S<<", n = "<<n<<endl;
    file<<"w = [";
    file.precision(3);
    for(unsigned int i=0; i<n;i++){
        file<<w[i]<<" ";
    }
    file<<"]"<<endl;
    file<<"r= [";
    for(unsigned int i=0; i<n;i++){
        file<<r[i]<<" ";
    }
    file<<"]"<<endl;
    file<<"Rate of retutn of the portfolio: "<<rateOfReturn<<endl;
    file<<"V: "<<portfolio<<endl;
    file.close();
    stringstream ss;
    ss<<"S = "<<S<<", n= "<<n<<endl<<"w= [";
    for(unsigned int i=0; i<n;i++){
        ss<<w[i]<<" ";
    }
    ss<<"]"<<endl;
    ss<<"r= [";
    for(unsigned int i=0; i<n;i++){
        ss<<r[i]<<" ";
    }
    ss<<"]"<<endl;
    ss<<"Rate of return of the portfolio: "<<rateOfReturn<<endl<<"V: "<<portfolio;
    string fullstr=ss.str();
    cout.precision(2);
    cout<<fullstr<<endl;
    return true;
}
