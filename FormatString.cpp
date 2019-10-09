Problem: 
Given a string to reformat. The string consists of N characters of letters, digits, spaces, and/or dashes. 
The string always contains at least 2 alphanumeric characters. Spaces and dashes in the string should be ignored. 
We want to reformat the string so that the characters 
are grouped in blocks of three, separated by single spaces. 
If necessary, the final block or the last 2 blocks can be of length 2.

My Solution: 

#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<unordered_map>

using namespace std;

/*
3 cases : 
Final 2 pairs. 
Case 1 : 3 3 
Case 2 : 3 2 
Case 3 : 2 2

Count number of alphanumeric characters. 

4 characters : 2, 2 { Final 2 pairs }
5 characters : 3, 2 
6 characters : 3, 3 

For each 
Length divisible by 3x, 3x+1 and 3x+2 

Check whether remainder is 0 in case1,
remainder is 2 in case 2 
remainder is 1 in case 3. 
*/


int main() {

	string S = "ABCDEFG";

	string S2;
	int size = S.size();

	int length = 0;

	// Find length of alphanumeric characters. 

	for (int i = 0; i < size; i++) {
		if ((int)S.at(i) > 45) {
			length++;
		}
	}

	//cout << "Number of alphanumeric characters are: " << length << endl ; 


	int count = 0; vector<char> v;

	//cout << " S is : " << S << endl; 
//cout << " S2 is : " << S2; 

		// Case 1 : 

	if (length % 3 == 0) {

		for (int i = 0; i < size; i++) {

			int size = v.size(); // be careful while naming same name variables. 

			if (S.at(i) != '-' && S.at(i) != ' ') {

				v.push_back(S.at(i)); count++;

				if (count == 3) {

					for (int j = 0; j < 3; j++) {
						S2 = S2 + v[j];
					}

					//cout << "S2 is" << S2 << endl;

					S2 = S2 + ' ';  // append a space after 3 characters. 
					count = 0;
					v.clear();

					continue;

				}


			}
		}

	}

	// Case2 : Final 2 pairs are of 3 2  // assuming atleast 3 are there. 
	else if (length % 3 == 2) {

		for (int i = 0; i < size; i++) {

			int size = v.size();

			if (S.at(i) != '-' && S.at(i) != ' ') {

				v.push_back(S.at(i)); count++;

				if (count == 3) {

					for (int j = 0; j < 3; j++) {
						S2 = S2 + v[j];
					}

					S2 = S2 + ' ';  // append a space after 3 characters. 
					count = 0;
					v.clear();

					// cout << "S2 is : " << S2 << endl; 

				}

			}

			
			cout << "Vector elements are : " << endl;

			for (char& p : v) {
				cout << p << "   ";
			}

			cout << endl;
			

			int length2 = 0;
			// Find length of S2 here. 

			for (int k = 0; k < S2.size(); k++) {
				if ((int)S2.at(k) > 45) {
					length2++;
				}
			}

			//cout << "length - length2 is : " << length - length2 << endl ; 

			if (length - length2 == 2) // 2 alphanumeric characters are left. 
			{
				v.clear();

				int z = i + 1;


				for (int a1 = z; a1 < S.size(); a1++) {

					if (S.at(a1) != '-' && S.at(a1) != ' ') {

						//	cout << "a1 is " << a1 << endl; 
						v.push_back(S.at(a1));

					}

				}


				S2 = S2 + v[0] + v[1];

				break;

			}

		}


	}
	
	// Can Handle lengths 2, 4, 5 as base case if required. 
	// Case 3 : Final pairs are of 2 2 ; minimum length of 7. 

	else if (length % 3 == 1) {


		for (int i = 0; i < size; i++) {

			int size = v.size();

			if (S.at(i) != '-' && S.at(i) != ' ') {

				v.push_back(S.at(i)); count++;


				if (count == 3) { // this will run atleast once as the minimum length is 7. 

					for (int j = 0; j < 3; j++) {
						S2 = S2 + v[j];
					}

					S2 = S2 + ' ';  // append a space after 3 characters. 
					count = 0;
					v.clear();

				}

			}

			int length2 = 0;
			// Find length of S2 here. 
			for (int k = 0; k < S2.size(); k++) {
				if ((int)S2.at(k) > 45) {
					length2++;
				}
			}


			if (length - length2 == 4) // 2 alphanumeric characters are left. 
			{
				v.clear(); int z = i + 1;

				for (int a1 = z; a1 < S.size(); a1++) {

					if (S.at(a1) != '-' && S.at(a1) != ' ') {
						v.push_back(S.at(a1));
					}

				}

				//S2 = S2 + ' ';
				S2 = S2 + v[0] + v[1] + ' ' + v[2] + v[3];

				break;

			}



		}

	}

	cout << "Final string is : " << S2;

	return 0;

}

