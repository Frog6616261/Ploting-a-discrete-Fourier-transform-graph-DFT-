#pragma once
#include <string>
#include <iostream>

class FileParser
{
public:

	FileParser(const char* oldDataArray, const int oldDataSizeOFArray);

	double* GetTimeArray();
	double* GetValueArray();
	int GetSizeOfTheArrrays();
	void MakeCopyDataArray(const char* oldData, int oldDataSize);// don't delete oldData array, only copy

	void ParseTheData();

	void PrintData();
	void PrintTime();
	void PrintValue();

	~FileParser();// delete data, timeArray, valueArray

private:
	double* m_TimeArray;
	int m_TimeArraySize;
	int m_FirstNotNullTimeIndex = 0;

	double* m_ValueArray;
	int m_ValueArraySize;
	int m_FirstNotNullValueIndex = 0;

	char* m_data;
	int m_dataSize;


	void AllocateMemoryForArrays();

	void AddTimeOrValueToArray(std::string& word, bool& isTimeWord);

	void SetTheSizeForArrays();
	
};

