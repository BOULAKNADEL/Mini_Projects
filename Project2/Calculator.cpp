#include <iostream>
#include <limits>
using namespace std;

enum enOperationType {Add = 1, Mult = 2, Sub = 3, Div = 4};

int ReadNumber(string message)
{
	int Number;

	do
	{
		cout << message << endl;
		cin >> Number;

	}while (Number < 0);

	return (Number);
}

enOperationType ReadOperationType()
{
	char OpType;

	do
	{
		cout << "Enter The operation type (+, -, /, *)\n";
		cin >> OpType;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

	}while (OpType != '+' && OpType != '-' && OpType != '/' && OpType != '*');

	switch (OpType) 
	{
		case '+':
			return enOperationType::Add;
			break;
			
		case '-':
			return enOperationType::Sub;
			break;

		case '*':
				return enOperationType::Mult;
				break;

		case '/':
				return enOperationType::Div;
				break;

		default :
				return Add;
				break;
	}

}

float Calculator(float &Number1, float Number2, enOperationType &OpType)
{
	switch (OpType) 
	{
		case enOperationType::Add:
			cout << Number1 << " + " << Number2 << " = ";
			return (Number1 + Number2);
			break;

		case enOperationType::Sub:
			cout << Number1 << " - " << Number2 << " = ";
			return (Number1 - Number2);
			break;

		case enOperationType::Mult:
			cout << Number1 << " * " << Number2 << " = ";
			return (Number1 * Number2);
			break;

		case enOperationType::Div:
			if (Number2 == 0)
			{
				cout << "Division by 0 is not possible \n";
				return (0);
			}
			else
			{
				cout << Number1 << " / " << Number2 << " = ";
				return Number1 / Number2;
				break;
			}

		default:
			cout << "The Operation Invalid";
			return (0);

	}
}

int main(void)
{
	float Number1 = ReadNumber("Enter The first Number Please !");
	float Number2 = ReadNumber("Enter The second number please !");
	enOperationType OpType = ReadOperationType();
	float Result = Calculator(Number1, Number2, OpType);

	cout << Result << endl;

	return (0);
}



