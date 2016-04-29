#include "stress_algo.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double values[TOTAL_VALUES] = { 83553, 83545, 83540, 83534, 83553, 83542, 83530,
		83527, 83529, 83547, 83527, 83530, 83539, 83530, 83542, 83533, 83532,
		83536, 83524, 83530, 83530, 83538, 83537, 83536, 83536, 83543, 83540,
		83526, 83546, 83542, 83534, 83539, 83545, 83549, 83547, 83548, 83551,
		83554, 83549, 83554, 83549, 83554, 83564, 83569, 83551, 83559, 83553,
		83548, 83558, 83562, 83556, 83562, 83562, 83553, 83568, 83574, 83567,
		83568, 83567, 83578, 83582, 83587, 83579, 83576, 83586, 83585, 83585,
		83587, 83589, 83591, 83591, 83587, 83595, 83609, 83596, 83598, 83601,
		83592, 83592, 83593, 83596, 83592, 83599, 83599, 83610, 83604, 83587,
		83605, 83597, 83611, 83605, 83599, 83603, 83595, 83594, 83600, 83598,
		83579, 83595, 83588, 83579, 83572, 83572, 83565, 83573, 83577, 83564,
		83565, 83557, 83571, 83564, 83558, 83567, 83560, 83563, 83561, 83573,
		83556, 83559, 83542, 83553, 83555, 83551, 83557, 83566, 83553, 83566,
		83555, 83544, 83543, 83560, 83550, 83554, 83556, 83558, 83562, 83552,
		83552, 83554, 83559, 83558, 83556, 83555, 83557, 83564, 83556, 83560,
		83558, 83558, 83547, 83561, 83563, 83548, 83557, 83548, 83553, 83567,
		83553, 83546, 83560, 83567, 83552, 83565, 83551, 83556, 83556, 83557,
		83565, 83563, 83554, 83565, 83558, 83566, 83565, 83548, 83551, 83561,
		83558, 83570, 83560, 83557, 83560, 83564, 83566, 83559, 83561, 83574,
		83567, 83570, 83566, 83569, 83570, 83569, 83565, 83556, 83556, 83567,
		83565, 83564, 83563, 83570, 83577, 83563, 83565, 83559, 83570, 83565,
		83578, 83568, 83576, 83570, 83567, 83571, 83583, 83586, 83568, 83573,
		83573, 83576, 83588, 83580, 83575, 83579, 83582, 83585, 83580, 83583,
		83579, 83580, 83585, 83588, 83591, 83595, 83590, 83589, 83597, 83581,
		83595, 83594, 83599, 83588, 83586, 83600, 83590, 83601, 83596, 83592,
		83592, 83596, 83597, 83598, 83593, 83593, 83593, 83593, 83593, 83596,
		83600, 83582, 83585, 83578, 83585, 83586, 83569, 83569, 83575, 83561,
		83565, 83562, 83540, 83562, 83547, 83546, 83544, 83550, 83555, 83551,
		83544, 83548, 83549, 83545, 83543, 83551, 83538, 83549, 83538, 83540,
		83529, 83541, 83543, 83535, 83535, 83540, 83539, 83540, 83536, 83530,
		83542, 83540, 83534, 83536, 83537, 83527, 83534, 83541, 83539, 83530,
		83545, 83539, 83535, 83545, 83544, 83544, 83542, 83542, 83543, 83532,
		83534, 83540, 83553, 83544, 83541, 83540, 83549, 83537, 83539, 83547,
		83542, 83545, 83528, 83540, 83549, 83537, 83550, 83550, 83544, 83550,
		83546, 83538, 83545, 83550, 83547, 83540, 83531, 83552, 83542, 83552,
		83559, 83543, 83557, 83556, 83560, 83559, 83550, 83565, 83552, 83563,
		83565, 83568, 83554, 83563, 83558, 83561, 83565, 83571, 83566, 83564,
		83566, 83565, 83567, 83564, 83574, 83577, 83573, 83579, 83578, 83564,
		83579, 83576, 83578, 83583, 83588, 83577, 83578, 83590, 83577, 83582,
		83591, 83595, 83595, 83581, 83579, 83589, 83588, 83597, 83586, 83594,
		83603, 83603, 83596, 83603, 83593, 83601, 83602, 83595, 83606, 83586,
		83605, 83606, 83604, 83609, 83611, 83602, 83611, 83615, 83612, 83604,
		83611, 83620, 83606, 83610, 83616, 83609, 83603, 83603, 83599, 83608,
		83598, 83601, 83597, 83587, 83585, 83590, 83578, 83578, 83572, 83578,
		83573, 83572, 83570, 83565, 83573, 83568, 83560, 83550, 83548, 83564,
		83560, 83563, 83551, 83558, 83553, 83538, 83545, 83553, 83538, 83549,
		83552, 83548, 83533, 83546, 83539, 83548, 83540, 83541, 83534, 83541,
		83536, 83544, 83538, 83539, 83540, 83537, 83533, 83542, 83536, 83534,
		83538, 83534, 83537, 83528, 83542, 83539, 83543, 83542, 83542, 83545,
		83539, 83544, 83543, 83536, 83531, 83526, 83534, 83539, 83542, 83535,
		83532, 83543, 83542, 83535, 83532, 83534, 83534, 83542, 83535, 83537,
		83533, 83532, 83539, 83535, 83532, 83542, 83534, 83535, 83545, 83539,
		83535, 83533, 83545, 83541, 83553, 83537, 83541, 83547, 83555, 83546,
		83549, 83540, 83539, 83546, 83534, 83544, 83545, 83551, 83543, 83555,
		83552, 83552, 83553, 83556, 83547, 83543, 83545, 83555, 83563, 83551,
		83545, 83559, 83554, 83561, 83566, 83557, 83564, 83566, 83562, 83574,
		83571, 83569, 83572, 83579, 83565, 83570, 83578, 83574, 83571, 83581,
		83574, 83571, 83588, 83573, 83592, 83579, 83579, 83586, 83580, 83581,
		83577, 83584, 83585, 83595, 83587, 83587, 83589, 83600, 83590, 83597,
		83598, 83594, 83593, 83600, 83599, 83597, 83601, 83600, 83595, 83597,
		83598, 83588, 83591, 83586, 83581, 83585, 83569, 83578, 83575, 83562,
		83564, 83561, 83558, 83566, 83563, 83553, 83553, 83552, 83556, 83541,
		83546, 83549, 83532, 83540, 83531, 83528, 83542, 83534, 83533, 83522,
		83525, 83523, 83539, 83538, 83527, 83530, 83518, 83532, 83523, 83521,
		83522, 83517, 83518, 83519, 83513, 83525, 83525, 83515, 83517, 83507,
		83515, 83504, 83511, 83516, 83511, 83504, 83520, 83512, 83503, 83504,
		83506, 83502, 83499, 83507, 83505, 83502, 83490, 83495, 83494, 83499,
		83498, 83505, 83503, 83496, 83499, 83499, 83491, 83500, 83496, 83499,
		83495, 83497, 83488, 83498, 83494, 83493, 83503, 83505, 83497, 83512,
		83498, 83501, 83509, 83508, 83507, 83517, 83511, 83510, 83502, 83521,
		83515, 83517, 83511, 83521, 83514, 83528, 83532, 83529, 83522, 83539,
		83533, 83527, 83537, 83542, 83546, 83544, 83544, 83542, 83551, 83548,
		83557, 83561, 83561, 83556, 83564, 83559, 83556, 83561, 83559, 83563,
		83566, 83571, 83562, 83574, 83568, 83566, 83564, 83564, 83584, 83566,
		83566, 83578, 83576, 83571, 83580, 83593, 83585, 83577, 83583, 83576,
		83576, 83590, 83587, 83585, 83589, 83594, 83587, 83586, 83588, 83587,
		83598, 83582, 83601, 83592, 83604, 83598, 83597, 83597, 83601, 83596,
		83588, 83590, 83589, 83590, 83593, 83581, 83585, 83579, 83585, 83580,
		83587, 83567, 83571, 83565, 83566, 83563, 83559, 83564, 83561, 83549,
		83566, 83555, 83557, 83553, 83551, 83556, 83554, 83554, 83543, 83554,
		83546, 83541, 83560, 83545, 83548, 83552, 83544, 83541, 83544, 83542,
		83548, 83556, 83547, 83552, 83555, 83560, 83553, 83541, 83549, 83564,
		83552, 83548, 83557, 83554, 83551, 83561, 83556, 83556, 83553, 83555,
		83560, 83553, 83559, 83552, 83556, 83555, 83556, 83572, 83550, 83557,
		83569, 83565, 83555, 83558, 83570, 83551, 83557, 83566, 83560, 83561,
		83561, 83562, 83569, 83577, 83580, 83574, 83572, 83581, 83566, 83561,
		83562, 83569, 83564, 83569, 83563, 83573, 83569, 83579, 83568, 83581,
		83571, 83575, 83590, 83580, 83581, 83578, 83574, 83578, 83574, 83575,
		83574, 83577, 83579, 83576, 83583, 83582, 83578, 83578, 83592, 83596,
		83581, 83595, 83586, 83590, 83589, 83596, 83597, 83585, 83588, 83587,
		83587, 83591, 83592, 83601, 83602, 83602, 83591, 83598, 83608, 83599,
		83597, 83609, 83595, 83604, 83604, 83593, 83596, 83598, 83607, 83603,
		83609, 83604, 83608, 83609, 83607, 83610, 83603, 83607, 83603, 83605,
		83602, 83602, 83600, 83593, 83595, 83588, 83593, 83589, 83588, 83586,
		83576, 83580, 83578, 83581, 83576, 83578, 83575, 83563, 83572, 83577,
		83565, 83566, 83570, 83565, 83560, 83570, 83568, 83567, 83565, 83567,
		83563, 83569, 83561, 83568, 83562, 83558, 83564, 83562, 83563, 83562,
		83565, 83561, 83559, 83561, 83562, 83566, 83559, 83569, 83564, 83563,
		83575, 83573, 83557, 83565, 83572, 83565, 83574, 83567, 83561, 83576,
		83568, 83572, 83574, 83577, 83575, 83566, 83573, 83574, 83574, 83583,
		83574, 83570, 83574 };

int threshold = 20; // Peak detection threshold
int key_divider = 10;
double averageValues[TOTAL_VALUES];
double *peaksArr;
int numOfPeaks = 0;
double *rrReadings;
int sizeOfRR;


double getHighestValue(int startIndex, int endIndex) {
	double heighest = values[startIndex];
	for (int i = startIndex; i <= endIndex; i++) {
		if (values[i] > heighest) {
			heighest = values[i];
		}
	}

	return heighest;
}

void fillAverageArray() {

	int numOfDivisions = TOTAL_VALUES / key_divider;
	int partial_average_begin = 1;
	int q = 0;
	for (int i = numOfDivisions; i < TOTAL_VALUES; i += numOfDivisions) {
		double sum = 0;
		for (int j = partial_average_begin; j <= i; j++) {
			sum += values[j];

		}
		double average_val = sum / numOfDivisions;
		for (int j = partial_average_begin; j < i; j++) {
			averageValues[j] = average_val;
		}
		q++;
		partial_average_begin += numOfDivisions;
	}
}

void printArray(double array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%lf ", array[i]);
	}
	printf("\n\n");
}

double * getRRValuesArr() {
	sizeOfRR = (numOfPeaks - 1);
	if (sizeOfRR < 0) {
		sizeOfRR = 0;
	}
	//printf("Number of peaks: %d \n\n", numOfPeaks);
	printf("\nsizeOfRR: %d \n", sizeOfRR);
	rrReadings = malloc(sizeof(*rrReadings) * sizeOfRR);
	int q = 0;
	for (int i = 0; i < (numOfPeaks - 1); i++) {

		double x = peaksArr[i + 1];
		double y = peaksArr[i];
		double r = abs(x - y);

		//printf("peaksArr[i+1] %lf - peaksArr[i] %lf : r= %lf \n", x,  y, r);

		rrReadings[q] = r;
		q++;
		r = 0;
	}
	return rrReadings;
}

void thresholdCalc() {

	int sampleCount = 300;
	double max[3];
	double highest = 0;
	int j = 0;
	int i = 0;
	int tIndex = 0;

	for (i = 150; i < 600; i += 150) {
		for (j = i; j < sampleCount; j++) {
			double temp = values[j];
			if (highest < temp) {
				highest = values[j];
				max[tIndex] = temp;
			}
		}
		highest = 0;
		sampleCount += 150;
		tIndex++;
	}

	sampleCount = 300;
	double min[3];
	double lowest = values[150];
	int r = 0;
	int t = 0;
	int minIndex = 0;

	for (r = 150; r < 600; r += 150) {
		for (t = r; t < sampleCount; t++) {
			double tempo = values[t];
			if (lowest > tempo) {
				lowest = values[t];
				min[minIndex] = tempo;
			}
		}
		sampleCount += 150;
		lowest = values[r];
		minIndex++;
	}

	double sumOfMax = 0;
	double sumOfMin = 0;
	for (int q = 0; q < 3; q++) {
		sumOfMax += max[q];
		sumOfMin += min[q];
	}
	int sumOfMax_INTEGER;
	sumOfMax_INTEGER = sumOfMax;
	int sumOfMin_INTEGER;
	sumOfMin_INTEGER = sumOfMin;
	threshold = ((sumOfMax_INTEGER - sumOfMin_INTEGER) / 4);
	printf("\nthreshold: %d\n", threshold);

}

void peakDetect(int count) {
	if (count == 0) {
		peaksArr = malloc(sizeof(*peaksArr) * numOfPeaks);
	}
	int q = 0;
	int start = 0;

	for (int i = 0; i < TOTAL_VALUES; i++) {
		if (values[i] >= averageValues[q]) {
			// ignore
		} else {
			start = i;
			break;
		}
	}

//	if (start == 0) {
//		start++;
//	}

	// start peak detection now
	int up = 0; // boolean
	int down = 0; // boolean
	int peakStart = 0;
	int peakEnd = 0;

	//printf("Starting from: %d\n", start);
	int peakCounter = 0;
	for (int i = start; i < TOTAL_VALUES; i++) {
		if (up == 0) {
			if (values[i] <= averageValues[i]) {
				// ignore
			} else {
				//printf("crossed avg line from bottom %d\n", i);
				up = 1;
				peakStart = i;
			}
		} else {
			if (values[i] >= averageValues[i]) {
				//ignore

			} else {
				//printf("crossed avg line from top %d\n", i);
				down = 1;
				peakEnd = i;
				//printf("averageValues[%d] = %lf \n", i, averageValues[i]);
				if (getHighestValue(peakStart, peakEnd) - averageValues[i]
						> threshold) {
					// valid peak
					//getHighestValue(peakStart, peakEnd);
					if (count == 1) {
						numOfPeaks++;
						//printf("Number of peaks: %d \n\n" , numOfPeaks);
					} else {
						peaksArr[peakCounter] = i * 5.0; // getHighestValue(peakStart, peakEnd);
						peakCounter++;
						printf("Peak: %d: \n", i * 5);
					}

					//printf("\n\n");
				} else {
					// its just noise
					//printf("\n\n");
				}
				// At this postion we have crossed a peak

				//reset
				up = 0;
				down = 0;

			}
		}

	}
	if(count == 1){
		printf("Number of peaks: %d \n\n" , numOfPeaks);
	}
}

double getRMSSD(double rrReadings[]) {
	//printf("Entered funcion RMSSD");
	double sum = 0;
	for (int i = 0; i < sizeOfRR - 1; i++) {
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

	//double pnnValues[TOTAL_VALUES];
	int counter = 0;
	for (int i = 0; i < sizeOfRR; i++) {
		//printf("%lf - %lf = %lf\n", rrReadings[i], rrReadings[i+1], rrReadings[i] - rrReadings[i+1]);
		if (abs(rrReadings[i] - rrReadings[i + 1]) > 50) {
			//pnnValues[counter] = rrReadings[i] - rrReadings[i + 1];
			counter++;
		}
	}
	printf("pnn50 counter: %d\n", counter);
	double pnnPercentage = counter / (double) sizeOfRR;
	pnnPercentage = pnnPercentage * 100;
	return pnnPercentage;
}

double getSD1(double rrReadings[]) {
	float mean = 0.0, sum_deviation = 0.0;
	int i;
	int sizeOfSd1 = sizeOfRR - 1;
	double sdt1Array[sizeOfSd1]; // differences of RR intervals
	for (i = 0; i < sizeOfSd1; ++i) {
		sdt1Array[i] = abs(rrReadings[i + 1] - rrReadings[i]);
		//printf("sdt1Array: %lf \n", sdt1Array[i]);
	}
	// now do everything to sdt1Array
	for (i = 0; i < sizeOfSd1; ++i) {
		mean += sdt1Array[i];
	}
	//printf("sum of sdt1Array: %lf \n", mean);
	mean = mean / sizeOfSd1;
	//printf("mean of sdt1Array: %lf \n", mean);
	for (i = 0; i < sizeOfSd1; ++i) {
		sum_deviation += pow((sdt1Array[i] - mean), 2);
	}

	return sqrt(sum_deviation / sizeOfSd1);
}

double getSD2(double rrReadings[]) {
	float mean = 0.0, sum_deviation = 0.0;
	int i;
	for (i = 0; i < sizeOfRR; ++i) {
		mean += rrReadings[i];
	}
	mean = mean / sizeOfRR;
	for (i = 0; i < sizeOfRR; ++i) {
		sum_deviation += pow(rrReadings[i] - mean, 2);
	}
	double sd2StandarDeviation = sqrt(sum_deviation / sizeOfRR);
	//square it
	double sd2 = pow(sd2StandarDeviation, 2);
	// multiple by 2
	sd2 = sd2 * 2;
	// subtract the square of sd1 from it
	sd2 = sd2 - pow(getSD1(rrReadings), 2);
	// then take the squareroot of everything
	return sqrt(sd2);
}

double getStressScale(double a, double x, double y) {
	if (x > y) {
		double com = ((x - y) / 4.0);
		//printf("%lf is greater than %lf\n",x,y);
		if (a <= y + com) {
			//printf("1a. Should return 0\n");
			return 0.0;
		} else if (((y + com) < a) && (a <= (y + (com * 2)))) {
			//printf("2a. Should return 5\n");
			return 5.0;
		} else if ((y + (com * 2)) && (a <= (y + (com * 3)))) {
			//printf("3a. Should return 12\n");
			return 12.0;
		} else if (a > y + (com * 3)) {
			//printf("4a. Should return 25\n");
			return 24.0;
		} else {
			//printf("error\n");
			return 0.0;
		}
	} else if (y > x) {
		double com = ((y - x) / 4.0);
		//printf("%lf is greater than %lf\n",y,x);
		if (a <= x + com) {
			//printf("1b. Should return 25\n");
			return 24.0;
		} else if ((x + com < a) && (a <= (x + (com * 2)))) {
			//printf("2b. Should return 12\n");
			return 12.0;
		} else if (((x + (com * 2)) < a) && (a <= (x + (com * 3)))) {
			//printf("3b. Should return 5\n");
			return 5.0;
		} else if (a > x + (com * 3)) {
			//printf("4b. Should return 0\n");
			return 0.0;
		} else {
			//printf("error\n");
			return 0.0;
		}
	} else {
		return 12.0;
	}

}

