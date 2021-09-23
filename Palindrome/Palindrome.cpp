#include <iostream>
#include <cstring>

using namespace std;

/* Jack Porter 9/23/2021
 * 'Palindrome'
 * This program checks to see if a string is a palindrome (ignoring punctuation and capitalization)!
 */
int main() {

	char str[80];
	char str2[80];
	
	cout << "Test if a word/phrase/sentence	is a palindrome:" << endl;

	cin.get(str, 80);
	cin.get();
	
	cout << "\"" << str << "\"";
	// remove all non-alphanumeric characters and capitalize all letters
	char c;
	int j = 0;
	for (int i = 0; i < 80; i++) {
		
		if (str[i] == '\0') {str[j] = '\0'; break;}
		c = toupper(str[i]);
		if ((c < 58 && c >= 47)||(c < 91 && c >= 65)) {
			str[j] = c;
			j++;
		}

	}
	
	// store string into string 2 in a reverse order, then add the null character back at the end
	j = 0;
	for (int i = strlen(str)-1; i >= 0; i--) {
		str2[j] = str[i];
		j++;
	}
	str2[j] = '\0';

	if (strcmp(str, str2) == 0) {cout << " is a palindrome" << endl;} 
	else cout << " is not a palindrome" << endl;

	return 0;
}
