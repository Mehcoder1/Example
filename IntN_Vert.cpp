#include "Factory_Vert.h"
int IntN_Vert::output() {
	Get_file_Vert();
	std::ofstream file;
	file.open(filename0, std::ios_base::app);
	file << "{";
	for (int i = 0; i < sz; i++) {
		if (i + 1 != sz) {
			file << x[i] << std::endl;
		}
		else {
			file << x[i];
		}
	}
	file << "}\n";
	return 0;
}
IntN_Vert::IntN_Vert(int sz, int* x) : IntN(sz, x) {

}
IntN_Vert::IntN_Vert(const IntN& b) {
	for (int i = 0; i < 20; i++)
		filename0[i] = 0;
	sz = b.Size();
	x = new int[sz];
	if (x == NULL) {
		std::cout << "Can not allocate memory";
		exit(1);
	}
	for (int i = 0; i < sz; i++) {
		x[i] = b.X()[i];
	}
}
void IntN_Vert:: Get_file_Vert() {
	memset(filename0, 0, 20);
	std::ifstream f;
	f.open("Data.txt");
	std::string line;

	if (f.is_open()) {
		while (getline(f, line)) {
			if (line[0] == '1') {
				for (int i = 0; i < 8; i++) {
					filename0[i] = line[i + 2];
				}
			}
		}
	}
	else std::cout << "File was not opened!";
	f.close();
}
//using IntN::operator=;
IntN& IntN_Vert::operator=(const IntN& b) {
	if (sz != b.Size() && x != NULL) {
		throw std::runtime_error("Error! Opeartor= Sizes of classes are not equal!\n");
		exit(1);
	}
	delete[] x;
	sz = b.Size();
	x = new int[sz];
	if (x == NULL) {
		std::cout << "Can not allocate memory";
		exit(1);
	}
	for (int i = 0; i < sz; i++) {
		x[i] = b.X()[i];
	}
	//	std::copy(b.x,b.x+sz,x);
	return *this;
}

//IntN_Vert:: ~IntN_Vert() {
        //delete[] x;
        //x = NULL;
//}
