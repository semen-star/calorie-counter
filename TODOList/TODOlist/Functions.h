#pragma once
#include <string>
#include <iostream>
using namespace std;


void settings_account(string& name_user, string& pass_user);

void Edit_personal_data(string& name_user, string& pass_user);//No use in master

void registration(string& name, string& pass, bool& autoris);//�������� ������������ � ��� ���� � �������

void add_user();//���������� ������ ������������

void add_product(string name_user);

void show_menu();//����� ����

void add_note();//���������� ����

void see_to_day(int day_to_see, int mounth, int year);

void see_to_mounth(int day, int mounth_to_see, int year);

void see_all_notes();

void see_priority_notes();

void really_important();

void important();

void the_usual();

void see_do();//�������� ��� ����

string* find_one_note(string&note_to_find, int &n_count);//����� ����

string* all_notes(int &count);//���������� ��� �������� ������ ����

void remove_one_note(string* all_notes_arr, int &count,int& choice);//�������� ������ ����

void remove_all_notes();//�������� ���� ���
