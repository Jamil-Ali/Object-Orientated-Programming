#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
#include <vector>
using namespace std; // So "std::cout" may be abbreviated to "cout"


void insertionSort(vector <double> &list, int listLength) 
{

	int firstOutOfOrder;
	int temp;
	int index;

	for (firstOutOfOrder = 1; firstOutOfOrder < listLength; firstOutOfOrder++) {

		if (list[firstOutOfOrder] < list[firstOutOfOrder - 1]) 
		{

			temp = list[firstOutOfOrder];
			index = firstOutOfOrder;

			do 
			{

				list[index] = list[index - 1];
				index--;
			} while (index > 0 && list[index - 1] > temp);
			
			list[index] = temp;
		}
	}
}


double binarySearch(vector <double> &list, int listLength, double searchItem) {

	int first = 0;
	int last = listLength - 1;
	int mid;

	bool found = false;

	while (first <= last && found == false) 
	{

		mid = (first + last) / 2;

		if (list[mid] == searchItem) {
			found = true;
		}
		else if (list[mid] > searchItem)
		{

			last = mid - 1;

		}
		else {
			first = mid + 1;
		}
		
	}

	if (found)
	{
		return mid;
	}
	else {
		return -1;
	}
}


int main() {

	vector <double> list;
	int size = 0;
	double  searchItem;
	double values;



	cout << "How many numbers do you want the list to contain initially? ";
	cin >> size;

	

	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ") " << "Enter values you want in list: ";
		cin >> values;
		if (values < 0) {
			break;
		}

		list.push_back(values);


	}

	/*cout << "List of values are: ";
		for (int i = 0; i < list.size(); i++)
			{

				cout << list.at(i) << " ";
			}


			cout << endl;
			*/

	insertionSort(list, list.size());

	cout << "The sorted list is: " << endl;

	for (int i = 0; i < list.size(); i++) 
	{
		cout << list[i] << " ";
	}
	cout << endl;

	cout << "Enter an item in the list to search for: ";
	cin >> searchItem;

	cout << binarySearch(list, list.size(), searchItem);


}





	
