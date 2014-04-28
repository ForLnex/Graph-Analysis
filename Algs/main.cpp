#include "CityInfo.h"
#include "BSTNode.h"

int main () {
	double latitude, longitude;
	int population, nodeCount = 0;
	string cityname;
	CityInfo test1("New York", 40.7141667, -74.0063889, 8107916),
		test2, test3("Uh Oh", 200.0, -200.0, -10), test4("Toledo", 41.6638889, -83.5552778, 306974),  *test5=NULL;
	cout << test1 << endl;
	cout << test2 << endl;
	cout << test3 << endl;
	cout << test4 << endl;
	BSTNode *root = NULL;

	cout << test4.calculateDistance(test1) << endl;

	ifstream infile ("sorted2.txt");
	if (infile.good()) {
		while (infile.good() ) {
			infile >> latitude >> longitude >> population;
			while(infile.peek() == '\t' || infile.peek() == ' ') {
				infile.get();
			}
			getline(infile, cityname);
			if (infile.good()) {
				test5 = new CityInfo(cityname, latitude, longitude, population);
				if (root != NULL) {
					root->add(test5);
				} else {
					root = new BSTNode(test5);
				}
				nodeCount++;
				test5 = NULL;
			}
		}
		infile.close();
	} else {
		cerr << "Failed to open input file." << endl;
	}

	ofstream outfile;
	outfile.open("preorder.txt");
	if (outfile.good()) {
		root->preOrder(outfile);
	}
	outfile.close();

	return EXIT_SUCCESS;
	}