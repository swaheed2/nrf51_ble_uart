#ifndef __STRESS_ALGO_H
#define __STRESS_ALGO_H
 
#define REAL double 
#define TOTAL_VALUES 89	
extern double rrReadings[TOTAL_VALUES];
extern double STD2;

inline static REAL sqr(REAL x);


 

double getRMSSD(double rrReadings[]);
double getSTD1(double rrReadingsp[]);
double getSTD2(double rrReadingsp[]);
double getPNN50(double rrReadings[]);


double getStresScale(double reading,double x,double y);


int linreg(int n, const REAL x[], const REAL y[], REAL* m, REAL* b, REAL* r);
void printArray(double array[], int size);
double getBestFitLine(double rrReadings[]); 
 
#endif