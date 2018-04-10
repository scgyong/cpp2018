#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
	int b = 10;
	int a = 3 + (b = 30);
	int c = b = a;

	if (argc < 2) {
		cout << "Enter number" << endl;
		return 0;
	}

	int number = atoi(argv[1]);
	//if (number < 2) {
	//	cout << "Number should be >= 2" << endl;
	//	return 0;
	//}
	long long int fact = 1;
	for (int n = 2; n <= number; n++) {
		fact *= n;
	}

	cout << number << "! = " << fact << endl;
	return 0;
}