#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <vector>
#include "Functions.h"
using namespace std;

void remove_account(string& name_user, string& pass_user) {



}

void Edit_personal_data(string& name_user,string& pass_user) {
	system("cls");
	bool choise = false;
	cout << "You really want to overwrite the user's data. All previous data will be deleted!\n\t[0]Do not delete\n\t[1]Delete\nChoise:";
	cin >> choise;
	if (choise == false){}
	else {
		string pass="None";
		bool again = false;
		while (pass != pass_user) {
			system("cls");
			if (again != false)
				cout << "Incorrect password! Try again" << endl;
			cout << "Enter the password:";
			cin >> pass;
			again = true;
		}
		cout << "password correct!" << endl;
		remove_account(name_user,pass_user);
		cout << "Profile deleted" << endl;
		system("pause");
		add_user();
		system("cls");
	}
	//TODO удалить текущий аккаунт. ЗАПРОСТИТЬ ПАРОЛЬ!
	//TODO создать новый аккаунт

}//TODO сделать редактирование данных пользователя

void settings_account(string& name_user,string& pass_user) {
	int choise;
	cout << "Choose what you need to do:\n\t[1]Edit user data\n\t[2]Create a new account\n\t[3]Log out of your account(does not work)\nChoice:";
	cin >> choise;
	if (choise == 1) {
		Edit_personal_data(name_user,pass_user);
	} 
	else if (choise == 2)
		add_user();
	else if (choise == 3)
		cout << "The function is not working at this stage" << endl;
	else {
		system("cls");
		cout << "Incorrect input. Try again" << endl;
		system("pause");
		settings_account(name_user, pass_user);
	}
}//TODO сделать выход из аккаунта

void registration(string& name, string& pass, bool& autoris) {
	ifstream file("users_reg.txt");
	if (!file.is_open()) {
		cout << "Error in working with the file system!";
		return;
	}
	string name_file, pass_file, name_user, pass_user;
	system("cls");
	cout << "Введите ник:";
	cin >> name_user;
	system("cls");
	cout << "Введите пароль:";
	cin >> pass_user;
	system("cls");

	for (int i = 1; !file.eof(); i++){
		file >> name_file >> pass_file;
		if ((name_user == name_file) and (pass_user == pass_file)) {
			break;
		}
		
	}
	file.close();
	name = name_user;
	pass = pass_user;
	autoris = true;
}//вход пользователей

void add_user() {
	system("cls");
	ofstream file1("users_reg.txt");
	if (!file1.is_open()) {
		cout << "Error in working with the file system!";
		return;
	}
	string name, pass;
	cout << "Enter the user name:";
	cin >> name;
	system("cls");
	cout << "Come up with a password for this user:";
	cin >> pass;
	system("cls");
	file1 <<endl<< name<<endl << pass;
	file1.close();



	ofstream file2("users.txt");
	if (!file2.is_open()) {
		cout << "Error in working with the file system!";
		return;
	}
	int sex;
	float height, weight;
	{
		cout << "Enter your height (cm):";
		cin >> height;
		system("cls");
		cout << "Enter your weight (kg):";
		cin >> weight;
		system("cls");
		cout << "Choose your gender:\n\t[1]male\n\t[2]female\n\t[other]I'm an idiot\n\nInput:";
		cin >> sex; 
	}//запись данных о пользователе в файл
	if(sex==1)
		file2 <<endl<< name <<endl<< height<<endl << weight<<endl << "male";
	else if(sex==2)
		file2 << endl << name << endl << height << endl << weight << endl << "female";
	else
		file2 <<endl<< name <<endl<< height<<endl << weight<<endl << "You're an idiot";
	file2.close();

}

void add_product(string name_user) {

	system("cls");
	cout << "Продолжить отсчёт каллорий со старого дня или делать запись о новом дне?\n\t[0]Старый день\n\t[1]Новый день(Не работает!)\nChoise:";
	bool old_or_new = false;
	cin >> old_or_new;
	if (old_or_new == false) {//Продолжаем записывать в старый день
		float calories_day;

		ifstream calories_old("calories.txt");
		if (!calories_old.is_open()) {
			cout << "Error in working with the file system!";
			return;
		}

		int par;
		while (!calories_old.eof()) {
			calories_old >> par;
			if (par-1 == name_user) {
				calories_old >> calories_day;
			}
		}

		calories_old.close();
		ofstream calories("calories.txt");
		if (!calories.is_open()) {
			cout << "Error in working with the file system!";
			return;
		}
		cout << "Введите калорийность продукта:";
		float calories_product_new;
		cin >> calories_product_new;
		system("cls");
		calories.close();
	}
	else {//Создаём запись о калориях как на новый день(С этого момента калории равны 0)

	}
}

void show_menu() {
	ifstream file("users.txt");
	if (!file.is_open()) {
		cout << "Error in working with the file system!";
		return;
	}
	string name, sex;
	float height, weight;
	cout << "\t\tMain menu:" << endl;
	height = 0;
	for (int i = 1; !file.eof(); i++)
	{
		file >> name >> height >> weight >> sex;		
		if (name.empty())
			continue;
		cout<< "\tName: " << name << endl << "\tHeight: " << height << endl << "\tWeight: " << weight << endl << "\tSex: " << sex << endl << "\tBMI: " << weight/(pow((height/100),2)) << endl;
	}

	
	cout << endl << endl;
	
	
	cout << "[1] account settings" << endl;
	cout << "[2] add products" << endl;
	cout << "[3] summary for the day" << endl;
	cout << "[4] Exit" << endl;
	file.close();
}//вывод меню

void see_do() {
	ifstream file_date("date.txt");
	cout << "How to display cases?:\n\n\t1.By Time[No Work!!]\n\t2.By priority \n\t3.All cases\input:" << endl;
	int choice1 = 0;
	cin >> choice1;
	if (choice1 == 3)
	{
		system("cls");
		see_all_notes();
	}

	else if (choice1 == 2) {
		see_priority_notes();
	}
	
	else if (choice1 == 1) {
		system("cls");
		int now_day, now_mounth, now_year;
		cout << "Enter the date now (Format \"dd mm yyyy\"):";
		cin >> now_day >> now_mounth >> now_year;
		system("cls");
		cout << "How to make a conclusion in time?:\n\n\t1.For the day[unstable work]\n\t2.For a week[unstable work]\n\t3.For a month[unstable work]\n\t4.By time the closer[does not work]." << endl;
		int choice2;
		cin >> choice2;
		if (choice2 == 1) {
			int day_to_see = now_day + 1;
			see_to_day(day_to_see, now_mounth, now_year);
		}
		else if (choice2 == 2) {
			int day_to_see = now_day + 7;
			see_to_day(day_to_see, now_mounth, now_year);
		}
		else if (choice2 == 3) {
			int mounth_to_see = now_mounth + 1;
			see_to_day(now_day, mounth_to_see, now_year);
		}
	}
}

void see_priority_notes() {
	system("cls");
	cout << "\t\tAll matters of importance:" << endl;
	really_important();
	important();
	the_usual();
}

void really_important() {
	ifstream file("calories.txt");
	if (!file.is_open()) {
		cout << "Error in working with the file system!";
		return;
	}
	string note_name, date, opisaniye, priority;
	for (int i = 1; !file.eof(); i++)
	{
		getline(file, note_name);
		getline(file, priority);
		getline(file, opisaniye);
		getline(file, date);
		if (note_name.empty())
			continue;
		if (priority == "Очень важно")
			cout << '[' << i << ']' << endl << "\work team: " << note_name << endl << "\t Priority of work: " << priority << endl << "\job description: " << opisaniye << endl << "\t date of work: " << date << endl;
	}
	file.close();
}

void important() {
	ifstream file("calories.txt");
	if (!file.is_open()) {
		cout << "Error in working with the file system!";
		return;
	}
	string note_name, date, opisaniye, priority;
	for (int i = 1; !file.eof(); i++)
	{
		getline(file, note_name);
		getline(file, priority);
		getline(file, opisaniye);
		getline(file, date);
		if (note_name.empty())
			continue;
		if (priority == "Важно")
			cout << '[' << i << ']' << endl << "\work team: " << note_name << endl << "\t Priority of work: " << priority << endl << "\job description: " << opisaniye << endl << "\t date of work: " << date << endl;
	}
	file.close();
}

void the_usual() {
	ifstream file("calories.txt");
	if (!file.is_open()) {
		cout << "Error in working with the file system!";
		return;
	}
	string note_name, date, opisaniye, priority;
	for (int i = 1; !file.eof(); i++)
	{
		getline(file, note_name);
		getline(file, priority);
		getline(file, opisaniye);
		getline(file, date);
		if (note_name.empty())
			continue;
		if (priority == "Обычно")
			cout << '[' << i << ']' << endl << "\work team: " << note_name << endl << "\t Priority of work: " << priority << endl << "\job description: " << opisaniye << endl << "\t date of work: " << date << endl;
	}
	file.close();
}

void see_to_day(int day, int mounth, int year) {
	ifstream file("calories.txt");
	if (!file.is_open()) {
		cout << "Error in working with the file system!";
		return;
	}
	string note_name, date, opisaniye, priority;
	int note_day, note_mounth, note_year;
	cout << "     day: " << day << "     \tmounth: " << mounth << "    \t year: " << year << endl;
	cout << "\t\tAll cases:" << endl;
	for (int i = 0; !file.eof(); i++){
		getline(file, note_name);
		getline(file, priority);
		getline(file, opisaniye);
		getline(file, date);
		note_day = date[0, 1];
		note_mounth = date[3, 4];
		note_year = date[6,7,8,9];
		if (note_name.empty())
			continue;
		cout << date;
		cout << endl;
		cout << "note_day: " << note_day << "\tnote_mounth: " << note_mounth << "\tnote_year: " << note_year << endl;
		
		if (note_day <= day and note_mounth <= mounth and note_year <= year)
			cout << '[' << i << ']' << endl << "\tИмя дела: " << note_name << endl << "\tПриоритет дела: " << priority << endl << "\tОписание дела: " << opisaniye << endl << "\tДата дела: " << date << endl << endl;//TODO сделать вывод номера дела
	}
	cout << endl << endl << "This is what the error looks like in reading the date from the file";
	file.close();
}

void see_all_notes() {
	ifstream file("calories.txt");
	if (!file.is_open()) {
		cout << "Error in working with the file system!";
		return;
	}
	string note_name,date,opisaniye,priority;
	cout << "\t\tAll cases:" << endl;
	for (int i = 1;!file.eof(); i++)
	{
		getline(file, note_name);
		getline(file, priority);
		getline(file, opisaniye);
		getline(file, date);
		if (note_name.empty())
			continue;
		cout << '[' << i << ']' << endl << "\tИмя дела: " << note_name << endl << "\tПриоритет дела: " << priority << endl << "\tОписание дела: " << opisaniye << endl << "\tДата дела: " << date << endl;//TODO сделать вывод номера дела
	}

	file.close();
}//просмотр всех заметок в файле

void importance() {
	cout << "Choose how important this case is:\n\t1.Очень важно(Very important)\n\t2.Важно(important)\n\t3.Usually\n\nA choice is expected:";
}

void add_note() {
	ofstream file("calories.txt", ios::app);
	if (!file.is_open()) {
		cout << "Error in working with the file system!";
		exit(EXIT_FAILURE);
	}
	{
		
		string note_name;
		getline(cin, note_name);
		cout << "Enter the name of the case:";
		getline(cin, note_name);
		file << note_name << endl;
	}//name note
	{
		cout << endl;
		importance();
		int x = 0;
		cin >> x;
		string priority;
		
		if (x == 1) {
			priority = "Очень важно";
		}
		else if (x == 2) {
			priority = "Важно";
		}
		else if (x == 3) {
			priority = "Обычно";
		}
		
		file << priority << endl;
	}//note priority
	{
		string description;
		
		getline(cin, description);
		cout << "Enter a description of the case:";
		getline(cin, description);
		file << description << endl;
	}//note description
	{
		int day=-5;
		int mounth=-5;
		int year=0;
		cout << "Enter the date(format:\"dd mm yyyy\"):";
		cin >> day >> mounth >> year;
		if (day < 10 or mounth<10) {
			string redact_day,redact_mounth;
			if (day == 1)
				redact_day = "01";
			else if (day == 2)
				redact_day = "02";
			else if (day == 3)
				redact_day = "03";
			else if (day == 4)
				redact_day = "04";
			else if (day == 5)
				redact_day = "05";
			else if (day == 6)
				redact_day = "06";
			else if (day == 7)
				redact_day = "07";
			else if (day == 8)
				redact_day = "08";
			else if (day == 9)
				redact_day = "09";
			else if (day == 10)
				redact_day = "10";
			else
				redact_day = day;

			if (mounth == 1)
				redact_mounth = "01";
			else if (mounth == 2)
				redact_mounth = "02";
			else if (mounth == 3)
				redact_mounth = "03";
			else if (mounth == 4)
				redact_mounth = "04";
			else if (mounth == 5)
				redact_mounth = "05";
			else if (mounth == 6)
				redact_mounth = "06";
			else if (mounth == 7)
				redact_mounth = "07";
			else if (mounth == 8)
				redact_mounth = "08";
			else if (mounth == 9)
				redact_mounth = "09";
			else if (mounth == 10)
				redact_mounth = "10";
			else
				redact_mounth = mounth;

			file << redact_day << "." << redact_mounth << "." << year << endl;
		}
		else
			file<<day<< "."<<mounth<<"." << year << endl;
		}//date
		file.close();
	cout << endl << "Ваше дело добавлена успешно!" << endl;
	//добавление заметок
}

string* find_one_note(string& note_to_find, int& n_count) {
	ifstream file("calories.txt");
	if (!file.is_open())
	{
		cout << "Ошибка в работе с файловой системой!";
		return nullptr;
	}
	string one_note;
	string* found_notes=nullptr;
	string* found_notes_tmp = nullptr;
	int count = 0;//кол-во найденых заметок
	while (!file.eof())
	{
		getline(file, one_note);
		if (one_note.find(note_to_find)!=-1)
		{
			count++;
			found_notes_tmp = new string[count];
			for (int i = 0; i < count-1; i++)
				found_notes_tmp[i] = found_notes[i];
			found_notes_tmp[count - 1] = one_note;
			delete[] found_notes;
			found_notes = found_notes_tmp;
			found_notes_tmp = nullptr;
		}
	}


	file.close();
	n_count = count;
	return found_notes;
}//поиск одной заметки среди всех

string* all_notes(int &n_count) {
	string* all_notes = nullptr;
	string* all_notes_ptr = nullptr;
	ifstream file("calories.txt");
	if (!file.is_open()) {
		cout << "Ошибка в работе с файловой системой!";
		exit(EXIT_FAILURE);
	}
	string note_name;
	int count = 0;
	while (!file.eof()) {
		getline(file, note_name);
		if (note_name.empty())
			continue;
		count++;
		all_notes_ptr = new string[count];
		for (int i = 0; i < count-1; i++)
			all_notes_ptr[i] = all_notes[i];
		all_notes_ptr[count - 1] = note_name;
		delete[] all_notes;
		all_notes = all_notes_ptr;
		all_notes_ptr = nullptr;
	}

	file.close();
	n_count = count;
	return all_notes;
}//доп функция вывода заметок для удаления одной из них

void remove_one_note(string* all_notes_arr,int &count, int& choice) {
	ofstream file("calories.txt");
	if (!file.is_open())
	{
		cout << "Ошибка в работе с файловой системой!";
		exit(EXIT_FAILURE);
	}
	
	for (int i = 0; i < count; i++){
		if (i == choice)
			continue;
		if (i == choice + 1)
			continue;
		if (i == choice + 2)
			continue;
		if (i == choice + 3)
			continue;
		file << all_notes_arr[i] << endl;
	}
	
	file.close();
}//удаление одной заметки

void remove_all_notes() {
	fstream file("calories.txt", ios::out, ios::trunc);
	if (!file.is_open()) {
		cout << "Ошибка в работе с файловой системой!"; 
		exit(EXIT_FAILURE);
	}
		
	file.close();
	system("cls");
	cout << "Дела удалены!" << endl;
	Sleep(2000);
}//удаление всех заметок

void add_note_for_redact() {
	system("cls");
	ofstream file("calories.txt", ios::app);
	if (!file.is_open()) {
		cout << "Ошибка в работе с файловой системой!";
		exit(EXIT_FAILURE);
	}
	{

		string note_name;
		getline(cin, note_name);
		cout << "Введите новое название дела:";
		getline(cin, note_name);
		file << note_name << endl;
	}//name note
	{
		cout << endl;
		importance();
		int x = 0;
		cin >> x;
		string priority;

		if (x == 1) {
			priority = "Очень важно";
		}
		else if (x == 2) {
			priority = "Важно";
		}
		else if (x == 3) {
			priority = "Обычно";
		}

		file << priority << endl;
	}//note priority
	{
		string description;

		getline(cin, description);
		cout << "Введите описание дела:";
		getline(cin, description);
		file << description << endl;
	}//note description
	{
		int day = -5;
		int mounth = -5;
		int year = 0;

		cout << "Введите дату(формат:\"dd mm yyyy\"):";
		cin >> day >> mounth >> year;

		file << day << "." << mounth << "." << year << endl;
	}//date
	file.close();
	cout << endl << "Ваше дело успешно отредактированно!" << endl;
	//добавление заметок
}
