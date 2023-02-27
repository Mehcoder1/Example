#include "IntN.h"
#include <sstream>
#include "IntN_Hori.h"
#include "IntN_Vert.h"
#include "Factory.h"
#include "Factory_Hori.h"
#include "Factory_Vert.h"
#include <map>
#include "Autotest.h"
int main() {

       if (Autotest()) {
                std::cout << "\nSome tests are failed";
                return 0;
        }
        else  std::cout << "\nAll tests are passed\n";
        std::map<int, Factory*> Our_map;
        Our_map[0] = new Factory_Hori;
        Our_map[1] = new Factory_Vert;
        std::vector<IntN*> Vect;
        const std::string FileName = "Data.txt";
        std::ifstream inputFile(FileName.c_str(), std::ios_base::in);
        if (!inputFile.is_open()) {
                throw std::invalid_argument("Error! Cannot open file " + FileName + "!\n");
        }
        std::string line;
        while (std::getline(inputFile, line)) {
                std::stringstream strStream(std::ios_base::in| std::ios_base::out);
                int n; int I;
                strStream << line;
                std::string s;
                strStream >> I>>s>>n;
                int* array = new int[n];
                std::stringstream strStream_2(std::ios_base::in | std::ios_base::out);
                for (int i = 0; i < n; ++i) {
                        strStream >> array[i];
                }
                auto curFactory = Our_map.find(I);
                if (curFactory == Our_map.end()) {
                        throw std::invalid_argument("Error! Wrong type of vector in file input.txt!\n");
                }
                IntN* Cur_IntN= curFactory->second->Create(n,array);
                delete[] array;
                Vect.push_back(Cur_IntN);
        }
        inputFile.close();
        for (size_t i = 0; i < Vect.size(); ++i)
                Vect[i]->output();

        for (auto it: Vect)
            delete it;
        delete Our_map[0];
        delete Our_map[1];
        return 0;
}
