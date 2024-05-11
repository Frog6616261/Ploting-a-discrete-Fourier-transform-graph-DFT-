#include "FileParser.h"


FileParser::FileParser(const char* oldDataArray, const int oldDataSizeOFArray)
{
	MakeCopyDataArray(oldDataArray, oldDataSizeOFArray);
	ParseTheData();
}

double* FileParser::GetTimeArray()
{
	return m_TimeArray;
}

double* FileParser::GetValueArray()
{
	return m_ValueArray;
}

int FileParser::GetSizeOfTheArrrays()
{
	return m_ValueArraySize;
}

void FileParser::MakeCopyDataArray(const char* oldData, int oldDataSize)
{
	m_data = new char[oldDataSize] {};
	m_dataSize = oldDataSize;

	for (int i = 0; i < oldDataSize; i++)
		*(m_data + i) = *(oldData + i);
}

void FileParser::ParseTheData()
{
	SetTheSizeForArrays();
	AllocateMemoryForArrays();

	std::string word = "";
	bool isTimeWord = true;
	
	for (int i = 0; i < m_dataSize; i++)
	{
		if (((int)m_data[i] <= 57 && (int)m_data[i] >= 45)
			&& (int)m_data[i] != 47)
		{
			word += m_data[i];
		}
		else if (word != "")
		{			
			AddTimeOrValueToArray(word, isTimeWord);			
		}
	}
	
}

void FileParser::PrintData()
{
	std::cout << "===============data===============\n";
	for (int i = 0; i < m_dataSize; i++)
		std::cout << *(m_data + i);
	std::cout << "\n===============data===============\n";
}

void FileParser::PrintTime()
{
	std::cout << "===============time===============\n";
	for (int i = 0; i < m_TimeArraySize; i++)
		std::cout << *(m_TimeArray + i)<<std::endl;
	std::cout << "===============time===============\n";
}

void FileParser::PrintValue()
{
	std::cout << "===============value===============\n";
	for (int i = 0; i < m_ValueArraySize; i++)
		std::cout << *(m_ValueArray + i)<< std::endl;
	std::cout << "===============value===============\n";
}

FileParser::~FileParser()
{
	delete[] m_TimeArray;
	delete[] m_ValueArray;
	delete[] m_data;
}


void FileParser::AllocateMemoryForArrays()
{
	m_TimeArray = new double[m_TimeArraySize] {};
	m_ValueArray = new double[m_ValueArraySize] {};
}

void FileParser::AddTimeOrValueToArray(std::string& word, bool& isTimeWord)
{
	if (isTimeWord)
	{
		*(m_TimeArray + m_FirstNotNullTimeIndex) = std::stod(word);
		m_FirstNotNullTimeIndex++;
	}
	else
	{
		*(m_ValueArray + m_FirstNotNullValueIndex) = std::stod(word);
		m_FirstNotNullValueIndex++;
	}

	isTimeWord = !isTimeWord;
	word = "";
}

void FileParser::SetTheSizeForArrays()
{
	std::string word = "";
	int countOfWords = 0;

	for (int i = 0; i < m_dataSize; i++)
	{
		if (((int)m_data[i] <= 57 && (int)m_data[i] >= 45)
			&& (int)m_data[i] != 47)
		{
			word += m_data[i];
		}
		else if (word != "")
		{
			countOfWords++;
			word = "";			
		}
	}

	m_TimeArraySize = countOfWords / 2;
	m_ValueArraySize = countOfWords / 2;
}


