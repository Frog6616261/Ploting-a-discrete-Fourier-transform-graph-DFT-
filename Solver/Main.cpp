#include <iostream>
#include <string>
#include "FileReader.h"
#include "FileParser.h"
#include "DFT.h"
#include "GraphPloter.h"

#define PRINT_ALL_OBJECT_DATA false


void SetFileNamePath(std::string& line, std::string readersFileName);


int main(int argc, char* argv[])
{
    ep::init(&argc, argv);

    
    setlocale(LC_ALL, "ru");
    setlocale(LC_NUMERIC, "eng");

    std::string line = argv[0];
    if (argc < 2)
    {
        std::cout << "Для работы кода, требуется указать файл с данными"<< std::endl;

        return -1;
    }
    
    SetFileNamePath(line, argv[1]);

    std::cout << line << std::endl;

    FileReader Reader;
    Reader.ReadFile(line);

#ifdef PRINT_ALL_OBJECT_DATA
    Reader.PrintData();
#endif    


    FileParser Parser{ Reader.GetDataArray(), Reader.GetSizeOfArray() };
#ifdef PRINT_ALL_OBJECT_DATA
    Parser.PrintTime();
    Parser.PrintValue();
#endif     
    
    DFT Solver{ Parser.GetValueArray(), Parser.GetTimeArray(),
        Parser.GetSizeOfTheArrrays() };
#ifdef PRINT_ALL_OBJECT_DATA
    Solver.PrintTheResultData();
#endif 


    GraphPloter Ploter{ Solver.GetArrayOfFrequencies(), Solver.GetArrayOfRealAmplitudes(),
    Solver.GetArrayOfImaginaryAmplitudes(), Solver.GetsizeOfTheArrays() };


    while (!exit) {
        std::this_thread::yield();
    }

    return 0;
}


void SetFileNamePath(std::string& line, std::string readersFileName)
{
    int sizeLine = line.size();
    int sizeName = readersFileName.size();
    int lastPosition = 0;
    
    for (int i = 0; i < sizeLine; i++) 
    {
        if (line[i] == '\\')
            lastPosition = i;
    }

    line.erase(lastPosition, sizeLine - lastPosition);
    line = line + "\\" + readersFileName;
}



