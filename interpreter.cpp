#include <iostream>
#include <fstream>
#include <string>
using namespace std;



class variable{
public:

	char *name;
	char *value;
	void setvalue(char* x, char* y){
		name = x;
		value = y;
	}
	
	template <typename T>
	T add(T &a, T &b) {
	return a + b;
	}


	template <typename T>
	T sub(T &a, T &b) {
		return a - b;
	}
	
	template <typename T>
	T div(T &a, T &b) {
		return a / b;
	}
	
	template <typename T>
	T mul(T &a, T &b) {
		return a * b;
	}

};

int main(){

	string line;
	string indx;
	variable first[10] = {};
	//variable second;
	char str[100];
	int j = 0;
	ifstream file("iqra_file.txt");
	if (file.is_open())
	{		
		
		if (line.find("Let") != NULL) {
			
			int a = 0;
			int b = 3;

			while (1) {

				if (line.compare(a, b, "Let") == 0) {

					a += b;
					b = 1;

					if (line.compare(a, b, " ") == 0) {

						a++;

						while (line.compare(a, b, " ") == 0)
						{
							a++;
						}

						int i = a;

						while (line.compare(i, b, " ") != 0)
						{
							i++;
						}


						line.copy(first[j].name, (i - a), a);
						a = i;
						while (line.compare(a, b, "=") != 0)
						{
							a++;
						}
						while (line.compare(a, b, " ") != 0)
						{
							a++;
						}

						char value[5];

						while (line.compare(i, b, "\n") != 0)
						{
							i++;
						}

						line.copy(first[j].value, i - a, a);
						j++;
					}
					else
					{
						cout << "Syntax Error in Declaration part!!!" << endl;
						exit(1);
					}
				}
				else
				{
					a++;
				}


				if ((line.find("+") != NULL) || (line.find("-") != NULL) || (line.find("/") != NULL) || (line.find("*") != NULL)) {
					a = 0;
					b = 1;
					int i = 0;
					while (1) {
						while (line.compare(a, b, " ") == 0) {
							a++;
						}
						i = a;			
						while ( line.compare(a, b, " ") != 0) {		
							a++;
						}

						char name[100];

						line.copy(name, (i - a), a);

					}

				}
				else
				{
					cout << "Syntax Error";
				}
			}
			cout << line << '\n';
		}
		else
		{
			cout << "Syntax Error";
		}
		file.close();
	}

	else 
		cout << "Unable to open file";

	getchar();
	return 0;
	}




	


