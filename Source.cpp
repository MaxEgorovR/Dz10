#include "Queue.h"
#include "Stack.h"
#include "LinkedList.h"
using namespace std;

int main() {

	int choise,counterS = 0, counterLL = 0,counterQ = 0,length;
	shared_ptr<Stack<int>> st;
	shared_ptr<Queue<int>> que;
	shared_ptr<LinkedList<int>> ll;
	

	while (true) {
		cout << "1 - Stack\n2 - Queue\n3 - LinkedList\nElse - Exit\n";
		cin >> choise;
		if (choise == 1) {
			if (counterS == 0) {
				cout << "Enter the length: ";
				cin >> length;
				st = make_shared<Stack<int>>(length);
			}
			cout << "1 - Add elem\n2 - Delete elem\n3 - Info\nElse - Exit\n";
			cin >> choise;
			if (choise == 1) {
				cout << "Enter the value: ";
				cin >> length;
				st->push_back(length);
			}
			else if (choise == 2) {
				st->pop();
			}
			else if (choise == 3) {
				st->info();
			}
			else {
				break;
			}
			counterS++;
		}
		else if (choise == 2) {
			if (counterQ == 0) {
				cout << "Enter the length: ";
				cin >> length;
				que = make_shared<Queue<int>>(length);
			}
			cout << "1 - Add elem\n2 - Delete elem\n3 - Info\nElse - Exit\n";
			cin >> choise;
			if (choise == 1) {
				cout << "Enter the value: ";
				cin >> length;
				que->push_back(length);
			}
			else if (choise == 2) {
				que->pop();
			}
			else if (choise == 3) {
				que->info();
			}
			else {
				break;
			}
			counterQ++;
		}
		else if (choise == 3) {
			if (counterLL == 0) {
				cout << "Enter the value: ";
				cin >> length;
				ll = make_shared<LinkedList<int>>(length);
			}
			cout << "1 - Add elem\n2 - Delete elem\n3 - Info\nElse - Exit\n";
			cin >> choise;
			if (choise == 1) {
				cout << "Enter the value: ";
				cin >> length;
				ll->push_back(length);
			}
			else if (choise == 2) {
				cout << "Enter the value: ";
				cin >> length;
				ll->pop(length);
			}
			else if (choise == 3) {
					ll->info();
			}
			else {
				break;
			}
			counterLL++;
		}
		else {
			break;
		}
	}
}