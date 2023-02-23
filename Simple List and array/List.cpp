#include "List.h"

void list();
void arr(); 
void ListPrint(List &);
void MyFunc(List &);

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	cout << "Оберiть способ збереження тексту: " << endl;
	int msg;
	do {
		cout << "Оберiть способ збереження тексту:\n1.Масив \n2.Cписок\n0.Вихiд\n>>> ";
		cin.clear();
		cin >> msg;
		switch (msg)
		{
		case 1:
		{
			arr();
		}break;
		case 2:
		{
			list();
		}break;
		}
		system("pause");
		system("CLS");
	} while (msg != 0);
	
	return 0;
}

void arr()
{
	clock_t start = clock();
	system("CLS");
	cout << "Введiть розмiр тексту: ";
	long int size;
	cin >> size;
	char *text = new char[size];
	cout << "Введiть текст. Завершiть його знаком \";\"" << endl;
	cin.getline(text, sizeof(text), ';');
	cout << text << endl;
	if (text[0] == '\0')
	{
		cout << "Field is empty";
	}
	int len = strlen(text);
	for (int i = 0; i < len; i++) // Шукаємо першу лiтеру
	{
		if (text[i] != ' ')
		{
			for (int j = i + 1; j <= len; j++) //визначаємо кiнець слова
			{
				if (text[j] == ' ' || (j == len)) //
				{
					//cout << "\nword count: " << j - i << " % 2 = " << (j - i) % 2 << endl;
					if ((j - i) % 2)
					{
						for (int k = i + 1; k <= j - 1; k++) // друкуємо слово та видаляємо першу i останню лiтери кожного слова
						{
							cout << text[k];
						}
					}
					cout << " "; // Додаємо пробiл мiж словами
					i = j; // Починаємо пошук пiсля надрукованого слова
					break; // Досрочно вихоимо з циклу пошуку кiнця слова
				}
			}
		}
	}
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "\nWork time array: \t" << seconds << endl;
}

void list()
{
	clock_t start = clock();
	system("CLS");
	List lst;
	int msg;
	do {
		cout << "Оберiть дiю:\n";
		cout << "1.Вставка в початок\n2.Вставка в середину\n3.Вставка в кiнець\n";
		cout << "4.Видалення першого елементу\n5.Видалення останнього елементу\n6.Видалення вiльного елементу\n";
		cout << "7.Очистити список\n8.Вивiд на екран\n9.Моя функцiя\n0.Вихiд\n>>> ";
		cin >> msg;
		switch (msg)
		{
		case 1:
		{
			lst.push_front("front");
		}break;
		case 2:
		{
			lst.push_middle("middle");
		}break;
		case 3:
		{
			lst.push_back("back");
		}break;
		case 4:
		{
			lst.pop_front();
		}break;
		case 5:
		{
			lst.pop_back();
		}break;
		case 6:
		{
			lst.pop_middle();
		}break;
		case 7:
		{
			lst.clear();
		}
		case 8:
		{
			ListPrint(lst);
		}break;
		case 9:
		{
			MyFunc(lst);
		}break;
		}
		system("pause");
		system("CLS");
	} while (msg != 0);
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "\nWork time list: \t" << seconds << endl;
}

void ListPrint(List &lst)
{
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << " ";
	}

	cout << endl;
}

void MyFunc(List &lst) 
{
	if (lst.GetSize() == 0)
	{
		cout << "List is empty" << endl;
	}
	for (int i = 0; i < lst.GetSize(); i++)
	{
		if (lst[i].size() % 2)
		{
			lst[i].erase(lst[i].begin());
			lst[i].erase(lst[i].end() - 1);
			cout << lst[i] << " ";
		}
	}
}
