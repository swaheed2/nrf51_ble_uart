/*
 * stress_algo.h
 *
 *  Created on: Apr 24, 2016
 *      Author: ubuntu
 */

#ifndef __STRESS_ALGO_H
#define __STRESS_ALGO_H

#define REAL double
#define TOTAL_VALUES 1001




//extern double rrReadings[TOTAL_VALUES];
extern double SD2;


inline static REAL sqr(REAL x);

double getHighestValue(int startIndex, int endIndex);
void fillAverageArray();

void peakDetect(int count);
double * getRRValuesArr();

double getRMSSD(double rrReadings[]);
double getSD1(double rrReadingsp[]);
double getSD2(double rrReadingsp[]);
double getPNN50(double rrReadings[]);


double getStressScale(double reading,double x,double y);


void printArray(double array[], int size);

#endif
