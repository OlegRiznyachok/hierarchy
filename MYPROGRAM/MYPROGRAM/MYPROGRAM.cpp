#include <iostream>
#include<string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	bool sign;
	string number;


	do                                 
	{
		sign = true;
		cout << "Введите количество критериев: ";
		cin >> number;
		for (int i = 0; i < number.length(); i++)
		{
			if ((!isdigit(number[i])) and (number[i] != '-'))
			{
				sign = false;
				cout << "Вы ввели не число! Попробуйте ввести еще раз!" << endl;
			}
		}
	} while (!sign);
	float rows = std::stof(number);

	float** array = new float* [rows];  
	float* sumOfRow = new float[rows];   

	for (int i = 0; i < rows; i++)
	{
		array[i] = new float[rows];
	}

	cout << "\nВведите данные попарного сравнения критериев! Ввод десятичных чисел осуществляется через точку!\n";
	for (int i = 0; i < rows; i++)    
	{
		for (int j = i; j < rows; j++)
		{
			if (i == j)
			{
				array[i][j] = 1;
			}
			else
			{
				cout << i + 1 << "-й критерий по отношению к  ";
				cout << j + 1 << "-ому критерию: ";
				cin >> array[i][j];
			}
		}
	}

	for (int i = rows - 1; i >= 1; --i)    
	{
		for (int j = i - 1; j >= 0; --j)
		{
			array[i][j] = (1 / array[j][i]);
		}
	}

	cout << "\nТаблица данных попарного сравнения критериев: \n";
	for (int i = 0; i < rows; i++)    
	{
		sumOfRow[i] = 0;
		for (int j = 0; j < rows; j++)
		{
			cout << array[i][j] << "\t";
			sumOfRow[i] += array[i][j];
		}
		cout << endl;
	}

	cout << "\nСумма по строкам!\n";  
	float sum=0;
	for (int i = 0; i < rows; i++)
	{
		cout << i + 1 << "-й критерий: " << sumOfRow[i] << endl;
		sum+= sumOfRow[i];
	}
	cout << "\nОбщая сумма строк!\n"; 
	cout << sum << endl;

	cout << "\nСумма всех весовых коэффициентов равна 1\n";
	
	cout << endl;

	cout << "\nВесовые коэффициенты каждого критерия!\n";
	for (int i = 0; i < rows; i++)   
	{
		cout << i + 1 << "-й критерий: " << round(sumOfRow[i] / sum * 100) / 100 << endl;
	}

	for (int i = 0; i < rows; i++)   
	{
		delete[] array[i];
	}

	delete[] array;
	delete[] sumOfRow;
}