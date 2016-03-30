#include "stress_algo.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <string.h>  



double sizeOfRR = TOTAL_VALUES;
double rrReadings[TOTAL_VALUES] = {
709.4,
710,
645,
774,
452,
839,
451,
710,
645,
581,
709,
646,
709,
516,
711,
710,
710,
640,
650,
710,
640,
580,
780,
710,
710,
710,
710,
640,
580,
650,
710,
710,
710,
640,
710,
650,
640,
710,
650,
510,
710,
650,
710,
640,
580,
650,
710,
640,
710,
650,
640,
460,
700,
650,
710,
640,
590,
640,
450,
780,
580,
510,
580,
580,
710,
710,
650,
770,
710,
650,
510,
650,
640,
710,
780,
710,
640,
710,
710,
580,
710,
710,
710,
650,
640,
650,
710,
580,
580,
640
};

 


inline static REAL sqr(REAL x) {
	return x * x;
}


void printArray(double array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%lf,", array[i]);
	}
	printf("\n\n");
}
 

double getRMSSD(double rrReadings[]) {
	//printf("Entered funcion RMSSD");
	double sum = 0;
	for (int i = 0; i < sizeOfRR-1; i++) {
		//printf("(%lf - %lf)", rrReadings[i + 1], rrReadings[i]);
		sum += pow((rrReadings[i + 1] - rrReadings[i]), 2);
		//printf(", sum is: %lf\n", sum);
	}

	sum *= 1 / (sizeOfRR - 1);
	//printf("Sum is: %lf", sum);

	//printf("Exiting funcion RMSSD");
	return sqrt(sum);

} // RMSSD function ends 


double getPNN50(double rrReadings[]) {

	double pnnValues[TOTAL_VALUES];
	int counter = 0;
	for (int i = 0; i < sizeOfRR; i++) {
		//printf("%lf - %lf = %lf\n", rrReadings[i], rrReadings[i+1], rrReadings[i] - rrReadings[i+1]);
		if (abs(rrReadings[i] - rrReadings[i + 1]) > 50) {
			pnnValues[counter] = rrReadings[i] - rrReadings[i + 1];
			counter++;
		}
	}
	double pnnPercentage = (counter / sizeOfRR * 100);
	return pnnPercentage;
}

double getSTD1(double rrReadings[]) { 
    float mean=0.0, sum_deviation=0.0;
    int i;
    for(i=0; i<sizeOfRR;++i)
    {
        mean+=rrReadings[i];
    }
    mean=mean/sizeOfRR;
    for(i=0; i<sizeOfRR;++i)
    sum_deviation+=(rrReadings[i]-mean)*(rrReadings[i]-mean);
    return sqrt(sum_deviation/sizeOfRR);  
}

double getSTD2(double rrReadings[]) { 
    float mean=0.0, sum_deviation=0.0;
    int i;
	  // ----------------------------------------
		double sdt2Array[TOTAL_VALUES]; 
		for(i=0; i<sizeOfRR;++i)
    {
        sdt2Array[i] = abs(rrReadings[i+1]-rrReadings[i]);
    }  
		//printArray(sdt2Array,TOTAL_VALUES);
	  // ----------------------------------------
    for(i=0; i<sizeOfRR;++i)
    {
        mean+=sdt2Array[i];
    }
    mean=mean/sizeOfRR; 
    for(i=0; i<sizeOfRR;++i){
			sum_deviation+=pow((sdt2Array[i]-mean),2);
		} 
    return sum_deviation/sizeOfRR;  
}

double getStressScale(double a,double x,double y){ 
	if(x > y){
		double com = ( (x-y)/4.0);
		printf("%lf is greater than %lf\n",x,y);
		if(a <= y + com){
			printf("1a. Should return 0\n"); 
			return 0.0;
		}
		else if(((y + com) < a) && (a <= (y + (com*2)) ) ){ 
			  printf("2a. Should return 5\n");
			printf("2a. y + com: %lf , a: %lf,  (y + (com*2)): %lf",(y + com),a,(y + (com*2)));
				return 5.0;
		} 
		else if((y + (com*2)) && (a <= (y + (com*3)) ) ){
			  printf("3a. Should return 12\n");
				return 25.0;
		}
		else if(a > y + (com*3)){
			  printf("4a. Should return 12\n");
				return 25.0;
		}
		else {
			printf("error\n");
			return 0.0;
		}  
	}
	else if(y > x) {
		double com = ( (y-x)/4.0);
		printf("%lf is greater than %lf\n",y,x);
		if(a <= x + com){
			printf("1b. Should return 0\n"); 
			return 25.0;
		}
		else if( (x + com < a) && (a <= (x + (com*2))) ){ 
			  printf("2b. Should return 5\n");
				return 12.0;
		} 
		else if( ((x + (com*2)) < a) && (a <= (x + (com*3))) ){ 
			  printf("3b. Should return 12\n");
				return 5.0;
		}
		else if(a > x + (com*3)){
			  printf("4b. Should return 12\n");
				return 0.0;
		}
		else {
			printf("error\n");
			return 0.0;
		} 
	}
	else{
		return 12.0;
	}
}

int linreg(int n, const REAL x[], const REAL y[], REAL* m, REAL* b, REAL* r) {
	REAL sumx = 0.0; /* sum of x                      */
	REAL sumx2 = 0.0; /* sum of x**2                   */
	REAL sumxy = 0.0; /* sum of x * y                  */
	REAL sumy = 0.0; /* sum of y                      */
	REAL sumy2 = 0.0; /* sum of y**2                   */

	for (int i = 0; i < n; i++) {
		sumx += x[i];
		sumx2 += sqr(x[i]);
		sumxy += x[i] * y[i];
		sumy += y[i];
		sumy2 += sqr(y[i]);
	}

	REAL denom = (n * sumx2 - sqr(sumx));
	if (denom == 0) {
		// singular matrix. can't solve the problem.
		*m = 0;
		*b = 0;
		if (r)
			*r = 0;
		return 1;
	}

	*m = (n * sumxy - sumx * sumy) / denom;
	*b = (sumy * sumx2 - sumx * sumxy) / denom;
	if (r != NULL) {
		*r = (sumxy - sumx * sumy / n) / /* compute correlation coeff     */
		sqrt((sumx2 - sqr(sumx) / n) * (sumy2 - sqr(sumy) / n));
	}

	return 0;
}

double getBestFitLine(double rrReadings[]) {
	int sizeOfxy = sizeOfRR / 2;
	double x[sizeOfxy];
	double y[sizeOfxy];

	int counter = 0;
	for (int i = 0; i < sizeOfRR-1; i += 2) {
		x[counter] = rrReadings[i];
		y[counter] = rrReadings[i + 1]; 

		counter++;
		//printf(", sum is: %lf\n", sum);
	}
	printf("\n\n");
	//printf("XY SIZE %d  ,", sizeOfxy );
	//printf("%lf\n", x[0]);
	printArray(x, sizeOfxy);

	printf("\n\n");
	printArray(y, sizeOfxy);
	printf("\n\n");

	REAL m, b, r;
	linreg(sizeOfxy, x, y, &m, &b, &r);
	printf("m=%g b=%g r=%g\n", m, b, r);

	return 0;
}
