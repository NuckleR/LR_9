#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <io.h>
#include <sys/types.h>
#include <deque>
#include "Exception.h"

namespace Lab_9 {

	using namespace std;

	class Casino {
	public:
		string name;
		int money;
		int profit;
		int players;
	public:
		Casino() {
			this->name = " ";
			this->money = 10000;
			this->profit = 1000;
			this->players = 10;
		}
		Casino(string name, int amount, int price, int rest) {
			this->name = name;
			this->money = amount;
			this->profit = price;
			this->players = rest;
		}
		friend ostream& operator<<(ostream& out, const Casino& art);
		friend istream& operator>>(istream& in, Casino& art);
		friend bool operator==(const Casino num1, const Casino num2);

		string get_name();
		int get_money();
		int get_profit();
		int get_players();

		void set_name(string);
		void set_money(int);
		void set_profit(int);
		void set_players(int);
	};


	class Algorithms {
	public:
		void first_Alg();
		void second_Alg(deque<Casino>);
		void third_Alg(deque<Casino>, deque<Casino>);
	};



	class Exception
	{
	protected:
		int error;
	public:
		Exception() :error(0) {}
		Exception(int error) {
			this->error = error;
		}
		~Exception() { };

		void Print() {
			switch (error) {
			case 1: cout << "File isn't open!" << endl;
				break;
			case 2: cout << "The class is empty!" << endl;
				break;
			case 3: cout << "Input error! Enter int!" << endl;
				break;
			case 4: cout << "Input error! Enter double!" << endl;
				break;
			case 5: cout << "The deque is empty!" << std::endl;
			}
		}
	};







	void Algorithms::first_Alg() {

		cout << "Первый алгоритм ищет слова в которых есть определенные символы.\n\n";
		ofstream fout1, fout2;
		ifstream fin1, fin2;
		int n;
		try {
			fout1.open("file1.txt");
			if (!fout1.is_open()) {
				throw 1;
			}
		}
		catch (int g) {
			Exception ex(g);
			ex.Print();
			return;
		}

		cout << "Введите кол-во строк: ";
		try {
			cin >> n;
			if (cin.fail()) {
				throw 3;
			}
		}
		catch(int g){
			Exception ex(g);
			ex.Print();
			return;
		}


		string temp;
		deque<string> ins;
		rewind(stdin);
		cout << "Введите строки: \n";
		for (int i = 0; i < n; i++) {
			getline(cin, temp);
			ins.push_back(temp);
		}


		deque<string>::iterator it = ins.begin();
		try {
			if (ins.size() == 0) {
				throw 5;
			}
			while (it != ins.end()) {
				fout1 << *it << "\n";
				++it;
			}
			fout1.close();
		}
		catch (int g) {
			Exception ex(g);
			ex.Print();
			return;
		}

		string symb;
		rewind(stdin);
		cout << "Введите символы: \n";
		getline(cin, symb);

		for (int i = 0; i < symb.size(); i++) {
			for (int j = i; j < symb.size(); j++) {
				if (symb[i] < symb[j]) {
					swap(symb[i], symb[j]);
				}
			}
		}

		deque<char> symb_temp;
		int counter = 0;
		for (int i = 0; i < symb.size();i = counter) {
			for (int j = i; j < symb.size(); j++) {
				if (symb[i] == symb[j]) {
					counter++;
				}
				else {
					symb_temp.push_back(symb[j - 1]);
					break;
				}
			}
		}
		symb_temp.push_back(symb[counter-1]);

		cout << "\nНабор символов: \n";
		deque<char>::iterator its = symb_temp.begin();
		try {
			if (symb_temp.size() == 0) {
				throw 5;
			}
			while (its != symb_temp.end()) {
				cout << *its;
				its++;
			}
		}
		catch (int g) {
			Exception ex(g);
			ex.Print();
			return;
		}
		cout << "\n\n";

		try{
		fout2.open("file2.txt");
		if (!fout2.is_open()) {
			throw 1;
		}
		}
		catch (int g) {
			Exception ex(g);
			ex.Print();
			return;
		}

		int inside = false;
		int beg_pos;
		its = symb_temp.begin();
		try {
			if (symb_temp.empty()|| ins.empty()) {
				throw 5;
			}
			while (its != symb_temp.end()) {
				it = ins.begin();
				cout << "Для символа ";
				cout << *its << ":\n";
				fout2 << "\nДля символа ";
				fout2 << *its << ":\n";
				while (it != ins.end()) {
					temp = *it;
					beg_pos = 0;
					inside = false;
					for (int i = 0; i < temp.size(); i++) {
						if (*its == ' ') break;
						if (temp[i] == *its) {
							while (temp[i] != ' ' && temp[i] != '\0') {
								i++;
							}
							for (int j = beg_pos; j < i; j++) {
								cout << temp[j];
								fout2 << temp[j];
							}
							cout << ' ';
							fout2 << ' ';
							while (temp[i] == ' ') {
								i++;
							}
							inside = true;
						}
						if (inside == true || temp[i] == ' ') {
							beg_pos = i;
							inside = false;
							if (temp[i] != ' ')i--;
						}
					}
					cout << "\n";
					it++;
				}
				cout << "\n\n";
				its++;
			}
		}
		catch (int g) {
			Exception ex(g);
			ex.Print();
			return;
		}
		fout2.close();
	}

	void Algorithms::second_Alg(deque<Casino> flg) {

		ofstream fout;
		ifstream fin;
		string temp;

		try{
			fout.open("file3.txt");
			if (!fout.is_open()) {
				throw 1;
			}
		}
		catch (int g) {
			Exception ex(g);
			ex.Print();
			return;
		}

		cout << "\n\n\n\n\n\n\n\nВторой Алгоритм выводит все объекты класса казино в которых денег больше, чем введено.\n";
		deque<Casino>::iterator it = flg.begin();

		int i = 0;

		try {
			if (flg.empty()) {
				throw 5;
			}
			while (it != flg.end()) {
				i++;
				cout << "      ";
				cout << *it;
				++it;
			}
		}
		catch (int g) {
			Exception ex(g);
			ex.Print();
			return;
		}

		int k;
		cout << "\nВведите кол-во денег: ";
		try{
		cin >> k;
		if (cin.fail()) {
			throw 3;
		}
	}
	catch (int g) {
		Exception ex(g);
		ex.Print();
		return;
	}

		try {
			if (flg.empty()) {
				throw 5;
			}
			it = flg.begin();
			while (it != flg.end()) {
				if (it->get_money() > k) {
					fout << *it;
				}
				++it;
			}fout.close();
		}
		catch (int g) {
			Exception ex(g);
			ex.Print();
			return;
		}


		cout << "\nВывод элементов:\n";

	try{
		fin.open("file3.txt");
		if (!fin.is_open()) {
			throw 1;
		}
		while (!fin.eof()) {
			i++;
			cout << "      ";
			getline(fin, temp, '\n'); 
			cout << temp << "\n";
		}
	}
	catch (int g) {
		Exception ex(g);
		ex.Print();
		return;
	}

	}

	void Algorithms::third_Alg(deque<Casino> ulg, deque<Casino> flg) {
		ofstream fout; 
		ifstream fin;
		string temp;

		try {
			fout.open("file4.txt");
			if (!fout.is_open()) {
				throw 1;
			}
		}
		catch (int g) {
			Exception ex(g);
			ex.Print();
			return;
		}

		deque<Casino> temp_Cas, temp_Cas_2;

		cout << "\n\n\n\n\n\n\n\nТретий алгоритм добавляет в двусвязный список множество элементов, удовлетворяющих условию.\n ";
		deque<Casino>::iterator it = flg.begin();

		int k;
		try{
		cout << "\nВведите кол-во денег: ";
		cin >> k;
		if (cin.fail()) {
			throw 3;
		}
	}
	catch (int g) {
		Exception ex(g);
		ex.Print();
		return;
	}

	try {
		if (flg.empty()) {
			throw 5;
		}
		while (it != flg.end()) {
			if (it->get_money() < k) {
				fout << *it;
				temp_Cas.push_back(*it);
			}
			++it;
		}fout << "\n\n";
	}
		catch (int g) {
			Exception ex(g);
			ex.Print();
			return;
		}


		int i = 0;
		deque<Casino>::iterator its = ulg.begin();
		try {
			if (ulg.empty()) {
				throw 5;
			}
			while (its != ulg.end()) {
				i++;
				cout << i << ".|    ";
				cout << *its;
				++its;
			}
		}
		catch (int g) {
			Exception ex(g);
			ex.Print();
			return;
		}


		cout << "\nВведите номер, после которого стоит вставить множество элементов: ";
		cin >> k;
		cout << "\n\n";

		i = 0;
		it = temp_Cas.begin();
		its = ulg.begin();
		try {
			if (ulg.empty()) {
				throw 5;
			}
			while (its != ulg.end()) {
				i++;
				if (i > k) {
					while (it != temp_Cas.end()) {
						temp_Cas_2.push_back(*it);
						++it;
					}
				}
				temp_Cas_2.push_back(*its);
				++its;
			}
		}
		catch (int g) {
			Exception ex(g);
			ex.Print();
			return;
		}

		ulg.clear();
		
		its = temp_Cas_2.begin();
		try {
			if (temp_Cas_2.empty()) {
				throw 5;
			}
			while (its != temp_Cas_2.end()) {
				ulg.push_back(*its);
				++its;
			}
		}
		catch (int g) {
			Exception ex(g);
			ex.Print();
			return;
		}

		i = 0;
		cout << "\n\nВывод списка с скопированным множеством\n\n";
		fout << "\n\nВывод списка с скопированным множеством\n\n";
		it = ulg.begin();
		try {
			if (ulg.empty()) {
				throw 5;
			}
			while (it != ulg.end()) {
				i++;
				cout << i << ".|    ";
				cout << *it;
				fout << i << ".|    ";
				fout << *it;
				++it;
			} fout.close();
		}
		catch (int g) {
			Exception ex(g);
			ex.Print();
			return;
		}
	}





	ostream& operator<<(ostream& out, const Casino& Cas)
	{
		try {
			if (Cas.name == " ") {
				throw 2;
			}
		}
		catch (int i)
		{
			Exception ex(i);
			ex.Print();
		}
		out << Cas.name << " " << Cas.money << " " << Cas.profit << " " << Cas.players << endl;
		return out;
	}

	istream& operator>>(istream& in, Casino& Cas)
	{
		in >> Cas.name;
		in >> Cas.money;
		in >> Cas.profit;
		in >> Cas.players;
		return in;
	}

	bool operator==(Casino num1, Casino num2) {
		if (num1.get_name() == num2.get_name() && num1.get_money() == num2.get_money() && num1.get_profit() == num2.get_profit() &&
			num1.get_players() == num2.get_players()) {
			return true;
		}
		else {
			return false;
		}
	}


	string Casino::get_name() {
		return this->name;
	}
	int Casino::get_money() {
		return this->money;
	}
	int Casino::get_profit() {
		return this->profit;
	}
	int Casino::get_players() {
		return this->players;
	}

	void Casino::set_name(string temp) {
		this->name = temp;
	}
	void Casino::set_money(int temp) {
		this->money = temp;
	}
	void Casino::set_profit(int temp) {
		this->profit = temp;
	}
	void Casino::set_players(int temp) {
		this->players = temp;
	}
}