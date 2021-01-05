#include "Header.h"
#include "Windows.h"

using namespace Lab_9;

int main() {
	system("chcp 1251");
	system("CLS");

	Algorithms alg;
	Casino u1("777", 11111, 2000, 40), u2("MaxBet", 30000, 3000, 200),
		u3("1TBit", 22222, 1000, 150), u4("WelBik", 12000, 450, 20), u5("DoretyCas", 20000, 300, 100);
	Casino f1("Casino888", 50000, 2000, 300), f2("Birec", 30000, 3000, 200),
		f3("Folks", 12000, 450, 200), f4("Zelen", 40000, 400, 40), f5("Dobrov", 10000, 200, 20);
	deque<Casino> flg, ulg;
	ulg.push_back(u1); ulg.push_back(u2); ulg.push_back(u3); ulg.push_back(u4); ulg.push_back(u5);
	flg.push_back(f1); flg.push_back(f2); flg.push_back(f3); flg.push_back(f4); flg.push_back(f5);

	alg.first_Alg();
	alg.second_Alg(ulg);
	alg.third_Alg(ulg, flg);

	getchar(); getchar();
}
