#ifndef __STRESS_ALGO_H
#define __STRESS_ALGO_H
 
#define REAL double 
#define TOTAL_VALUES 1001




//extern double rrReadings[TOTAL_VALUES];
extern double STD2;


inline static REAL sqr(REAL x);

double getHighestValue(int startIndex, int endIndex);
void fillAverageArray();
 
void peakDetect(int count);
double * getRRValuesArr();

double getRMSSD(double rrReadings[]);
double getSTD1(double rrReadingsp[]);
double getSTD2(double rrReadingsp[]);
double getPNN50(double rrReadings[]);


double getStressScale(double reading,double x,double y);


int linreg(int n, const REAL x[], const REAL y[], REAL* m, REAL* b, REAL* r);
void printArray(double array[], int size);
double getBestFitLine(double rrReadings[]); 
 
#endif
