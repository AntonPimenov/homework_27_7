#include "Logger.h"
#include <iostream>
#include <string>
#include <fstream>
#include <mutex>
#include <thread>
#include <memory>

using namespace std;

Logger::Logger(const string& filename)
{
    logFile.open(filename, ios::app); //открываем файл для добавления логов
    readFile.open(filename); //открытие файла для чтения
    if(!logFile.is_open() || !readFile.is_open())
    {
        throw runtime_error("Не удалось открыть файл логов!");

    }
}
Logger::~Logger()
{
    if(logFile.is_open())
    {
        logFile.close();
    }
    if(readFile.is_open())
    {
        readFile.close();
    }
}
void Logger::log(const string& message)
{
    lock_guard<mutex> lock(mtx); //блокировка мьютекса
    logFile << message << endl; //запись сообщения в лог
}
string Logger::readline()
{
    lock_guard<mutex> lock(mtx);
    string line;
    if(getline(readFile, line))
    {
        return "";
    }
}
