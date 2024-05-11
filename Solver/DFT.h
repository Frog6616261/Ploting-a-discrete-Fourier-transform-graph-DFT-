#pragma once
#include <complex>
#include <math.h>
#include <iostream>
#define c_double std::complex <double>
#define PI 3.141592

//Discrete Fourier Transfom
class DFT
{
public:

	DFT();
	DFT(const double* valueArray, const double* timeArray, const int sizeOfArrays);

	void DoDiscreteFourierTransfom(const double* valueArray,
		const double* timeArray, const int sizeOfArrays);

	int GetsizeOfTheArrays();
	double* GetArrayOfFrequencies();
	double* GetArrayOfRealAmplitudes();
	double* GetArrayOfImaginaryAmplitudes();

	void PrintTheResultData();

	~DFT(); // delete arrays: value, time, frequency, amplitude

private:

	int m_sizeOfArrays = 10;
    double m_sizeOfTheInterval;
	double m_deltaTime;
	double m_deltaFrequency;

	double* m_frequency;
	c_double* m_amplitude;
	double* m_amplitudeReal;
	double* m_amplitudeImag;

	void AllocateMemoryForArrays();

	c_double GetTheComplexExp(const int numberOfTheFrequency,
		const int countOfTheValues, const int numberOftheValue);

	c_double GetTheAmplitude(const int numberOfTheFrequency, const double* valueArray);

	void SetConstValues(const double* valueArray,
		const double* timeArray, const int sizeOfArrays);

	double GetTheFrequency(const int numberOfTheFrequency);

};

