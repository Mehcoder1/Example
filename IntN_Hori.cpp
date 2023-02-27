#include "IntN_Hori.h"
int IntN_Hori:: output() {
                Get_file_Hori();
                std::ofstream file;
                file.open(filename0,std::ios_base::app);
                if (!file.is_open()) {
                        std::cout << "\nCan not open file!";
                        exit(0);
                }
                file << "{";
                for (int i = 0; i < sz; ++i) {
                        file <<  x[i] << " ";
                }
                file << "}\n";

                return 0;
        }
IntN_Hori::IntN_Hori(int sz, int* x) : IntN(sz, x) {}
IntN_Hori::IntN_Hori(const IntN& b) {
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
IntN& IntN_Hori::operator=(const IntN& b)  {
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
  void IntN_Hori::  Get_file_Hori() {
                        memset(filename0, 0, 20);
                        std::ifstream f;
                        f.open("Data.txt");
                        std::string line;

                        if (f.is_open()) {
                                while (getline(f, line)) {
                                        if (line[0] == '0') {
                                                for (int i = 0; i < 8; i++) {
                                                        filename0[i] = line[i + 2];
                                                }
                                        }
                                }
                        }
                        else std::cout << "File was not opened!";
                        f.close();
                }
 IntN_Hori operator+(IntN& b, IntN& f) {
    int* array = f.X();
    int size_1 = f.Size();
    int k = 0;
    int max, min;
    int* x = b.X();
    int sz = b.Size();
    if (sz > size_1) {
        max = sz;
        min = size_1;
    }
    else if (sz < size_1) {
        max = size_1;
        min = sz;
    }
    else {
        max = sz;
        min = sz;
    }

    int flag = 0;
    if (array[0] < 0 && x[0] < 0) {
        array[0] = abs(array[0]);
        x[0] = abs(x[0]);
        flag = 1;
    }
    else if (array[0] < 0 && x[0]>0) {
        f.X()[0] = abs(f.X()[0]);
        IntN_Hori c;
        IntN_Hori last(sz, x);
        c = last - f;
        return c;
    }
    else if (array[0] > 0 && x[0] < 0) {


        x[0] = abs(x[0]);
        IntN_Hori c;
        IntN_Hori last(sz, x);

        c = f - last;
        return c;
    }int* arr = new int[max];
    if (sz <= size_1) {
        for (int i = max - 1; i >= 0; --i) {
            if (min <= 0) {
                arr[i] = array[i] + k;
            }
            else
            {
                arr[i] = (x[min - 1] + array[i]) + k;
            }
            k = 0;
            if (arr[i] >= 10 && i != 0) {
                ++k;
                arr[i] = arr[i] - 10;
            }
            else if (i == 0 && arr[i] >= 10) {
                k = 0;
                std::cout << "Error(3), the number is out of decimal system";
                exit(3);
            }
            --min;
        }
        if (flag == 1) {
            arr[0] = -arr[0];
        }
    }
    else if (sz > size_1) {
        for (int i = max - 1; i >= 0; --i) {
            if (min <= 0) {
                arr[i] = x[i] + k;
            }
            else
            {
                arr[i] = (x[i] + array[min - 1]) + k;
            }
            k = 0;
            if (arr[i] >= 10 && i != 0) {
                ++k;
                arr[i] = arr[i] - 10;
            }
            else if (i == 0 && arr[i] >= 10) {
                k = 0;

                std::cout << "Error(3), the number is out of decimal system";
                exit(3);
            }
            --min;
        }
        if (flag == 1) {
            arr[0] = -arr[0];
        }
    }
    IntN_Hori sum(max, arr);
    //std::cout << sum.X()[0];
    delete[] arr;
    //	std::cout << "  end of +   ";
    return sum;
}
IntN_Hori operator-(IntN& b, IntN& f) {
    int* array = f.X();
    int size_1 = f.Size();
    int k = 0;
    int s = 0;
    int max, min;
    int* x = b.X();
    int sz = b.Size();
    int flag_minus_numbers = 0;
    if (sz > size_1) {
        max = sz;
        min = size_1;
    }
    else if (sz < size_1) {
        max = size_1;
        min = sz;
    }
    else {
        max = sz;
        min = sz;
    }
    if (array[0] < 0 && x[0]>0) {
        IntN_Hori sum1;
        IntN_Hori last(sz, x);
        f.X()[0] = abs(f.X()[0]);
        sum1 = last + f;
        return sum1;
    }
    else if (array[0] > 0 && x[0] < 0) {
        IntN_Hori sum1;
        IntN_Hori last(sz, x);
        f.X()[0] = -f.X()[0];
        sum1 = last + f;
        return sum1;
    }
    else if (array[0] < 0 && x[0] < 0) {
        array[0] = abs(array[0]);
        x[0] = abs(x[0]);
        flag_minus_numbers = 1;
    }
    int flag = 0;
    int* arr = new int[max];
    if (k == 0) {
        for (int i = max - 1; i >= 0; --i) {
            if (sz > size_1) {

                if (min <= 0) {
                    arr[i] = x[i] - s;
                    s = 0;
                }
                else {
                    arr[i] = x[i] - array[min - 1] - s;
                    s = 0;
                }

                if (arr[i] < 0 && i != 0) {
                    s = 1;
                    arr[i] = 10 + arr[i];
                }

            }
            else if (sz < size_1) {
                flag = 1;
                if (min <= 0) {
                    arr[i] = array[i] - s;
                    s = 0;
                }
                else {
                    arr[i] = array[i] - x[min - 1] - s;
                    s = 0;
                }
                if (arr[i] < 0 && i != 0) {
                    s = 1;
                    arr[i] = 10 + arr[i];
                }

            }
            else if (sz == size_1) {
                arr[i] = x[i] - array[i] - s;
                s = 0;
            }
            if (arr[i] < 0 && i != 0) {
                s = 1;
                arr[i] = 10 + arr[i];
            }
            else
                if (arr[i] < 0 && i == 0) {
                    k++;

                }
            --min;
        }
        if (flag == 1 && flag_minus_numbers == 0) {
            if (arr[0] == 0) {
                int i = 0;
                while (arr[i] == 0) {
                    i++;
                }
                arr[i] = -arr[i];
            }
            else {
                arr[0] = -arr[0];
                flag_minus_numbers = 0;
            }
        }
        else
            if (flag == 0 && flag_minus_numbers != 0) {
                if (arr[0] == 0) {
                    int i = 0;
                    while (arr[i] == 0) {
                        i++;
                    }
                    arr[i] = -arr[i];
                }
                else
                    arr[0] = -arr[0];
            }
    }
    if (k == 1) {
        for (int i = max - 1; i >= 0; --i) {

            arr[i] = array[i] - x[i] - s;
            s = 0;

            if (arr[i] < 0 && i != 0) {
                s = 1;
                arr[i] = 10 + arr[i];
            }


            --min;
        }
        if (arr[0] == 0) {
            int i = 0;
            while (arr[i] == 0) {
                i++;
            }
            arr[i] = -arr[i];
        }
        else
            arr[0] = -arr[0];
    }
    IntN_Hori difference(max, arr);
    delete[] arr;
    return difference;
}








