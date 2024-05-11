#include "GraphPloter.h"

GraphPloter::GraphPloter(const double* frequencyArray, const double* amplitudeRealArray, const double* amplitudeImagArray, const int arraysSize)
{
	m_arraysSize = arraysSize;

	FillTheArray(frequencyArray, m_frequency, arraysSize);
	FillTheArray(amplitudeRealArray, m_amplitudeReal, arraysSize);
	FillTheArray(amplitudeImagArray, m_amplitudeImag, arraysSize);
	
	ShowAmplitudeFrequencyRealGraf();
	ShowAmplitudeFrequencyImagGraf();  
}

void GraphPloter::ShowAmplitudeFrequencyRealGraf()
{

	ep::plot("Amplitude-Frequency (Real Component) Graph", m_frequency, m_amplitudeReal, ep::LineSpec(1,0,0));


}

void GraphPloter::ShowAmplitudeFrequencyImagGraf()
{
	ep::plot("Amplitude-Frequency (Imag Component) Graph", m_frequency, m_amplitudeImag, ep::LineSpec(0, 0, 1));
}

GraphPloter::~GraphPloter()
{

}

void GraphPloter::FillTheArray(const double* dataArray, v_double& fillingArray, const int arraysSize)
{
	fillingArray.resize(arraysSize, 0);
	v_double::iterator iter = fillingArray.begin();

	for (int i = 0; i < arraysSize; i++)
	{
		double a = dataArray[i];
		fillingArray[i] = dataArray[i];
		double b = fillingArray[i];
	}

}


