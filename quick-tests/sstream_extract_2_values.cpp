#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

void OpenFile(ifstream& f) {
	string fileName;
	while (true) {
		cout << "Please input file name: ";
		if (!getline(cin, fileName)) {
			continue;
		}

		f.open(fileName);
		if (f.is_open()) {
			break;
		}
	}
}

int main() {
	ifstream f;
	OpenFile(f);

	string oneLine;
	stringstream converter;
	int x, y;
	while (getline(f, oneLine)) {
		converter.str("");
		converter.clear();
		converter << oneLine;
		converter >> x >> y;
		cout << "x: " << x << ", y: " << y << endl;
	}

	return 0;
}