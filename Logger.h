#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <mutex>
#include <thread>
#include <memory>

using namespace std;

class Logger
{
    private:
        ofstream logFile; //файл для записи
        ifstream readFile; //файл для чтения
        mutex mtx; //мьютекс для синхронизации доступа к файлу

    public:
        Logger(const string& filename);
        ~Logger();
        void log(const string& message); //запись строки в лог
        string readline(); //чтение одной строки из лога
};