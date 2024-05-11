#pragma once

#include <vector>
#include <cmath>
#include <GL/freeglut.h>

#include "easy_plot.hpp"

#define v_double std::vector<double>


class GraphPloter
{
public:

	GraphPloter(const double* frequencyArray, const double* amplitudeRealArray,
		const double* amplitudeImagArray, const int arraysSize);

	void ShowAmplitudeFrequencyRealGraf();
	void ShowAmplitudeFrequencyImagGraf();

	~GraphPloter();

private:

	int m_arraysSize;

	v_double m_frequency;
	v_double m_amplitudeReal;
	v_double m_amplitudeImag;

	void FillTheArray(const double* dataArray, v_double& fillingArray, const int arraysSize);

};

