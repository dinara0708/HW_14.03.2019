﻿#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>
#include<cstring>
#include<fstream>

using namespace std;

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn; cin.get();

		switch (tn)
		{
		case 1:
			//Дан текстовый файл.Необходимо создать новый файл и записать в него следующую статистику по исходному файлу :
			// 1 количество символов
			// 2 количество строк
			// 3 количество гласных букв
			// 4 количество согласных букв
			// 5 количество цифр.
		{
			ifstream i1_file("1.txt");
			ofstream i2_file("2.txt");

			char buf[50];
			char sym;
			char vowels[13] = "AEIOUYaeiouy";
			int k1 = 0, k2 = 0, k3 = 0, k4 = 0, k5 = 0;
			int check = 0;

			while (i1_file.get(sym))
			{
				k1++;
				if (sym >= 48 && sym <= 57) k5++;
				else
				{
					check = 0;
					for (int i = 0; i < 13; i++)
					{
						if (sym == vowels[i])
						{
							k3++;
							check++;
							break;
						}
					}
					if (check == 0 && sym >= 65 && sym <= 122)
						k4++;
				}
			}
			i1_file.close();
			i1_file.open("1.txt");

			while (i1_file.getline(buf, 50))
				k2++;

			i2_file << "количество символов: " << k1 << endl;
			i2_file << "количество строк: " << k2 << endl;
			i2_file << "количество гласных букв: " << k3 << endl;
			i2_file << "количество согласных букв: " << k4 << endl;
			i2_file << "количество цифр: " << k5 << endl;
		}
		break;
		case 2:
			//Шифр Цезаря — один из древнейших шифров. При шифровании каждый символ заменяется другим, отстоящим от него в алфавите на фиксированное число позиций.
			//Пример:
			//Шифрование с использованием ключа : 3
			//Оригинальный текст : Съешь же ещё этих мягких французских булок, да выпей чаю.
			//Шифрованный текст : Фэзыя йз зьи ахлш пвёнлш чугрщцкфнлш дцосн, жг еютзм ъгб.
			//Дан текстовый файл.Зашифровать его, используя шифр Цезаря.Результат записать в другой файл.
		{
			ifstream i3_file("3.txt");
			ofstream i4_file("4.txt");
			char sym;
			int key;
			cout << "Enter the key" << endl;
			cin >> key;
			int period;
			char start;

			while (i3_file.get(sym))
			{
				if (sym >= 'А' && sym <= 'Я')
				{
					period = 'Я' - 'А';
					start = 'А';
				}
				else if (sym >= 'а' && sym <= 'я')
				{
					period = 'я' - 'а';
					start = 'а';
				}
				else if (sym >= 'A' && sym <= 'Z')
				{
					period = 'Z' - 'A';
					start = 'A';
				}
				else if (sym >= 'a' && sym <= 'z')
				{
					period = 'z' - 'a';
					start = 'a';
				}
				else
				{
					i4_file << sym;
					continue;
				}

				if (sym + key - start <= period)
					sym = sym + key;
				else
					sym = sym + key - period - 1;

				i4_file << sym;
			}
		}
		break;
		case 3: // можно через свой алфавитный чар-массив, т.к. в ASCII таблице нет Ё, поэтому вывод не совсем как в задании
		{
			fstream i5_file("5.txt");
			ofstream i6_file("6.txt");
			//чтобы зациклить алфавит придется не через таблицу ASCII кодов, а через свой массив символов
			char alphabet[34] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
			char sym;
			int key;
			cout << "Enter the key" << endl;
			cin >> key;
			//cin.ignore();

			while (i5_file.get(sym))
			{
				for (int i = 0; i <= 33; i++)
				{
					if (sym == alphabet[i])
					{
						if (i + key <= 32)
						{
							sym = alphabet[i + key];
							i6_file << sym;
							break;
						}
						else
						{
							sym = alphabet[i + key - 33];
							i6_file << sym;
							break;
						}
					}
					else if (i == 33)
					{
						i6_file << sym;
						break;
					}
				}
			}

			// почему-то на github в файлах не видно русского текста, только через visual studio
		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}