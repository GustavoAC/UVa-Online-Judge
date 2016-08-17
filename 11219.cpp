#include <cstdio>

struct Date {
	int day;
	int month;
	int year;
};

int main(int argc, char const *argv[]) {

	char tempStr[11];
	int numDates, age;
	Date currentDate, birthDate;

	scanf("%i", &numDates);

	for (int i = 0; i < numDates; ++i) {
		scanf("%s", tempStr);
		currentDate.day = (tempStr[1] - '0') + (tempStr[0] - '0') * 10;
		currentDate.month = (tempStr[4] - '0') + (tempStr[3] - '0') * 10;
		currentDate.year = (tempStr[9] - '0') + (tempStr[8] - '0') * 10 + (tempStr[7] - '0') * 100 + (tempStr[6] - '0') * 1000;

		scanf("%s", tempStr);
		birthDate.day = (tempStr[1] - '0') + (tempStr[0] - '0') * 10;
		birthDate.month = (tempStr[4] - '0') + (tempStr[3] - '0') * 10;
		birthDate.year = (tempStr[9] - '0') + (tempStr[8] - '0') * 10 + (tempStr[7] - '0') * 100 + (tempStr[6] - '0') * 1000;

		printf("Case #%i: ", i+1);

		if (currentDate.year < birthDate.year or
		    (currentDate.year == birthDate.year and currentDate.month < birthDate.month) or
		    (currentDate.year == birthDate.year and currentDate.month == birthDate.month) and currentDate.day < birthDate.day) {
		    	printf("Invalid birth date\n");
		    	continue;
		}

		age = currentDate.year - birthDate.year;
		if (currentDate.month < birthDate.month or (currentDate.month <= birthDate.month and currentDate.day < birthDate.day)) {
			age--;
		}

		if (age > 130)
			printf("Check birth date\n");
		else
			printf("%i\n", age);
	}

	return 0;
}
