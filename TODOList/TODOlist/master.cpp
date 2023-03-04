#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Functions.h"
using namespace std;


enum CHOICE {
    Settings_account =1,
    add_products,
    summary_for_the_day,
   EXIT
};

int main()
{
    string name,pass;//в переменную помещаем имя и пароль зарегестрированного ныне пользователя
    setlocale(LC_ALL, ""); 
    SetConsoleCP(1251);
    HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
    int choice = 0;
    cout << "Attention! the program uses memory. Be careful\a";
    Sleep(3000);
    bool x = 1;
    int z=1;
    system("cls");
    while (x != 0) {
        system("cls");
        bool autorisation = false;
        while (autorisation==false)
        {
            {
                cout << "Do you have a profile?\n\t[0]No\n\t[1]Yes\nInput:";
                bool f1 = 0;
                cin >> f1;
                if (f1 == false) {
                    add_user();
                }
                else {
                    registration(name, pass,autorisation);
                }
                system("cls"); }
        }//регистрация пользователя в системе
        show_menu();// функция выводит на экран меню пользователя
        cout << endl << "Make a choice:";
        cin >> choice;
        if (choice == Settings_account) {
            system("cls");
            settings_account(name,pass);
            cout << endl << endl;
            system("pause");
            system("cls");
        }
        else if (choice == add_products) {
            system("cls");
            see_do();
            cout << endl << endl;
            system("pause");
            system("cls");
        }
        else if (choice == summary_for_the_day) {
            system("cls");
            string note_to_find;
            cout << "Внимание! Введите только одно слово для поиска!"<<endl;
            getline(cin, note_to_find);
            cout << "Поисковое слово:";
            getline(cin, note_to_find);
            int n_found = 0;
            string* found_notes = find_one_note(note_to_find, n_found);
            if (found_notes)
            {
                cout << "Найденные заметки:"<<endl;
                for (int i = 0; i < n_found; i++) 
                    cout << found_notes[i] << endl;   
                delete[] found_notes;
                cout << endl;
            }
            else
                cout << "Извините, я не нашел необходимых заметок." << endl;

            system("pause");
        }
       
        else if (choice == EXIT) {
            cout << "Are you shure? All affairs SAVE!\nif you are sure, then enter 1. Or enter 0\n\nInput:";
            bool f = 0;
            cin >> f;
            if (f == 0) {
                continue;
            }
            else {
                x = 0;
            }
        }

        else {
            cout << "ERROR!";
            cout << endl;
            system("pause");
        }
        
        }
        {
            SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "Good buy\n";
            SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            Sleep(2000);
        }
        //good buy to red color
        
        return 0;
    }