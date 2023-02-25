#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Functions.h"
using namespace std;


enum CHOICE {
    edit_personal_data =1,
    add_products,
    summary_for_the_day,
   EXIT
};

int main()
{
    setlocale(LC_ALL, ""); 
    SetConsoleCP(1251);
    HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
    int choice = 0;
    cout << "Attention! the program uses memory. Be careful";
    Sleep(3000);
    bool x = 1;
    int z=1;
    system("cls");
    while (x != 0) {
        system("cls");
        cout << "Do you have a profile?" << endl;
        bool f1 = 0;
        cin >> f1;
        if (f1==false){
            add_user();
        }
        else{
            registration();
        }
        system("cls");
        show_menu();// функция выводит на экран меню пользователя
        cout << endl << "Make a choice:";
        cin >> choice;
        if (choice == edit_personal_data) {
            system("cls");
            add_note();
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
            cout << "Attention! Enter only one word to search for!"<<endl;
            getline(cin, note_to_find);
            cout << "Search word:";
            getline(cin, note_to_find);
            int n_found = 0;
            string* found_notes = find_one_note(note_to_find, n_found);
            if (found_notes)
            {
                cout << "Found notes:"<<endl;
                for (int i = 0; i < n_found; i++) 
                    cout << found_notes[i] << endl;   
                delete[] found_notes;
                cout << endl;
            }
            else
                cout << "Sorry, I didn't find the necessary notes." << endl;

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