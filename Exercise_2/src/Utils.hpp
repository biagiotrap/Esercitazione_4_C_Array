#pragma once
#include<iostream>

using namespace std;

bool ImportData(const string& InputFileName,size_t& n, double& S, double*& w,
                 double*& r, const char& delimiter);

double RateOfReturn(const  double* const& w,
                          const double* const& r, const size_t& n);

double Portfolio(const double& rateOfReturn, const double& S);

bool ExportResult(const string& OutputFileName,const double* const& w,
                  const double* const& r, const double& S, size_t& n,
                  const double& rateOfReturn, const double& portfolio );

