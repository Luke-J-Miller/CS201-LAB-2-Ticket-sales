#include <iostream>
//#include <cmath> //http://www.cplusplus.com/reference/clibrary/cmath/
#include <cstdlib> //https://cplusplus.com/reference/cstdlib/
//#include <ciso646> //allows python words //https://cplusplus.com/reference/ciso646/
//#include <cstring>  // allows tools such as string concatenation and comparison //https://cplusplus.com/reference/cstring/
#include <iomanip> //include setprecision, fixed and get_time //https://cplusplus.com/reference/iomanip/?kw=iomanip
//#include <cctype> 
#include <limits>
using namespace std;

char printMenu() {
	char ticketChoice = 'X';
	while (ticketChoice == 'X') {
		cout << "\nEnter (C)hild, (A)dult, (S)enior or (V)IP or (Q)uit >> ";
		cin >> ticketChoice;
		ticketChoice = toupper(ticketChoice);
		switch (ticketChoice) {
		case 'C':
			ticketChoice == 'C';
			break;
		case 'A':
			ticketChoice == 'A';
			break;
		case 'S':
			ticketChoice == 'S';
			break;
		case 'V':
			ticketChoice == 'V';
			break;
		case 'Q':
			ticketChoice == 'Q';
			break;
		default:
			ticketChoice = 'X';
			break;

		}

	}
	return ticketChoice;
}
double printDayReturnTotal(int numChild, int numAdult, int numSenior, int numVIP, int dayCount) {
	const double childPrice = 10.95, adultPrice = 19.99, seniorPrice = 18.99, VIPPrice = 7.99;
	double dayTotal = numChild * childPrice + numAdult * adultPrice + numSenior * seniorPrice + numVIP * VIPPrice;

	cout << "Day " << dayCount << endl;
	cout << "     " << "Child " << numChild << " @ " << childPrice << " = " << fixed << setprecision(2) << numChild * childPrice << endl;
	cout << "     " << "Adult " << numAdult << " @ " << adultPrice << " = " << numAdult * adultPrice << endl;
	cout << "     " << "Senior " << numSenior << " @ " << seniorPrice << " = " << numSenior * seniorPrice << endl;
	cout << "     " << "VIP " << numVIP << " @ " << VIPPrice << " = " << numVIP * VIPPrice << endl;
	cout << endl;
	cout << "     " << "Total " << dayTotal << endl;
	return dayTotal;
}

int validateInteger() {
	int x;
	cin >> x;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Bad entry.  Enter a NUMBER: ";
		cin >> x;
	}
	return x;
}


int main() {
	int dayCount = 1;
	char userChoice;
	int numChild = 0, numAdult = 0, numSenior = 0, numVIP = 0, userNum;
	double threeDayTotal = 0;
	cout << "Welcome to Fun Park Menu System !!" << endl;
	cout << "Starting day " << dayCount << endl;
	while (dayCount <= 3) {
		int i = 0;
		userChoice = printMenu();
		cout << endl;
		if (userChoice == 'Q') {
			threeDayTotal += printDayReturnTotal(numChild, numAdult, numSenior, numVIP, dayCount);
			numChild = 0; numAdult = 0; numSenior = 0; numVIP = 0;
			dayCount += 1;
			cout << endl;
			if (dayCount < 4) {
				cout << "Starting day " << dayCount << endl;
			}
			continue;
		}
		else if (userChoice == 'C') {
			cout << "How many children? ";
			userNum = validateInteger();
			numChild += userNum;
		}
		else if (userChoice == 'A') {
			cout << "How many adults? ";
			userNum = validateInteger();
			numAdult += userNum;
		}
		else if (userChoice == 'S') {
			cout << "How many seniors? ";
			userNum = validateInteger();
			numSenior += userNum;
		}
		else if (userChoice == 'V') {
			cout << "How many VIPs? ";
			userNum = validateInteger();
			numVIP += userNum;
			cout << endl;
		}

	}
	cout << "The total for all days is " << threeDayTotal;
	//start coding here


	return 0;
}
