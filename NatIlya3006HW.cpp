// Задание 1
// К уже существующему проекту класса Student добавьте механизмы сохранения / загрузки данных класса.Используйте механизм потоков для файловых операций.

#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

// Класс "Студент".
class Student
{
private:
    string name; // Имя или ФИО студента.
    int* marks; // Массив оценок.
    int amountOfMarks; // Количество оценок.
public: 
    // Конструктор класса "Студент".
    Student(string settingName, int* arrayWithMarks, int settingAmountOfMarks) : name{ settingName }, marks{ arrayWithMarks }, amountOfMarks{ settingAmountOfMarks } {};

    // Печать инфорамции о студенте.
    void printInformation()
    {
        cout << "Информация о студенте: \n";
        cout << "Имя: " << name << "\n";
        cout << "Количество оценок: " << amountOfMarks << "\n";
        cout << "Оценки: " ;
        for (int i = 0; i < amountOfMarks; i++)
            cout << marks[i] << ' ';
        cout << '\n';
        cout << "Средний балл: " << getAverageMark();
        cout << '\n';
    }

    // Вывод в файл информации о студенте.
    void outputInformation()
    {
        ofstream outputFile;

        outputFile.open("output.txt", ios::out);

        outputFile << "Информация о студенте: \n";
        outputFile << "Имя: " << name << "\n";
        outputFile << "Количество оценок: " << amountOfMarks << "\n";
        outputFile << "Оценки: ";
        for (int i = 0; i < amountOfMarks; i++)
            outputFile << marks[i] << ' ';
        outputFile << '\n';
        outputFile << "Средний балл: " << getAverageMark();
        outputFile << '\n';

        outputFile.close();
    }

    // Вычисление среднего балла.
    double getAverageMark()
    {
        double sum = 0;
        for (int i = 0; i < amountOfMarks; i++)
        {
            sum += marks[i];
        }
        return sum / amountOfMarks;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string name; 
    int size;
    int choice;
    int* arrayWithMarks;
    cout << "Добро пожаловать в систему учёта студентов.\n";
    do {
        cout << "Ввести вручную или импортировать данные студента из файла \"input.txt\"(1 - ввести вручную, 2 - импортировать): ";
        cin >> choice;
        if (choice != 1 && choice != 2)
            cout << "Неправильно введённая команда. Повторите ввод\n";
    } while (choice != 1 && choice != 2);
    if (choice == 1)
    {        
        cout << "Введите ФИО студента: ";
        cin >> name;

        cout << "Введите количество оценок: ";
        cin >> size;

        int* array = new int[size];

        for (int i = 0; i < size; i++)
        {
            cout << "Введите " << i + 1 << "-ую оценку студента: ";
            cin >> array[i];
        }
        arrayWithMarks = array;
    }
    else
    {
        cout << "Внимание! Файл должен быть заполнен по образцу:\nПупкин Владислав Егорович\n5\n1 2 3 4 5\n";

        ifstream inputFile;
        char buffer[100];

        inputFile.open("input.txt", ios::in);
                
        inputFile.getline(buffer, 100);
        name = buffer;
        
        inputFile >> size;
        int* array = new int[size];

        for (int i = 0; i < size; i++)
            inputFile >> array[i];

        cout << "Полученные данные:\n";
        cout << "ФИО: " << name << '\n';
        cout << "Количество оценок: " << size << '\n';
        cout << "Оценки: ";
        for (int i = 0; i < size; i++)
            cout << array[i] << ' ';
        cout << '\n';
        cout << '\n';

        arrayWithMarks = array;
        inputFile.close();
    }
    Student student(name, arrayWithMarks, size);

    student.printInformation();
    student.outputInformation();
    cout << "\nВся информация о студенте была выведена в файл \"output.txt\".";
}
