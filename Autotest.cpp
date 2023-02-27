#include "Autotest.h"
int Autotest1() {
        int arr_1[3] = { 5,7,9 };
        int arr_2[4] = {1,3,7,8};
        IntN* a = new IntN_Hori(3,arr_1);
        IntN* b = new IntN_Hori(4,arr_2);
        IntN_Hori c;
        c = *a + *b;
        if (((c).X()[3] == 7) && ((c).X()[2] == 5) && ((c).X()[1] == 9) && ((c).X()[0] == 1)) {
                std::cout << "Autotest1 is passed\n";
                delete a;
                delete b;
                return 0;
        }
        else {
            delete a;
            delete b;
            std::cout << "Autotest1 is failed\n";
            return 1;
        }


}
int Autotest2() {
        int arr_1[5] = { 2,2,3,4,5 };
        int arr_2[4] = { 6,7,8,9 };
        IntN* a = new IntN_Hori(5, arr_1);
        IntN* b = new IntN_Hori(4, arr_2);
       // std::cout<<"222";
        IntN_Hori c;
        c = *a - *b;
        if (((c).X()[0]==1) &&((c).X()[1] == 5) && ((c).X()[2] == 5) && ((c).X()[3] == 5) && ((c).X()[4] == 6)) {
                std::cout << "Autotest2 is passed\n";
                delete a;
                delete b;
                return 0;
        }
       else { std::cout << "Autotest2 is failed\n";
            delete a;
            delete b;
        return 1;
        }
}
int Autotest3() {
        int arr_1[3] = { 6,2,3 };
        int arr_2[3] = { -1,2,3 };
        IntN* a = new IntN_Vert(3, arr_1);
        IntN* b = new IntN_Vert(3, arr_2);
        IntN_Vert c;
        c = *a + *b;
        if (((c).X()[2] ==0) && ((c).X()[1] == 0) && ((c).X()[0] == 5)) {
                std::cout << "Autotest3 is passed\n";
                delete a;
                delete b;
                return 0;
        }
        else {std::cout << "Autotest3 is failed\n";
            delete a;
            delete b;
           return 1;
}

}
int Autotest4() {
        int arr_1[4] = { 1,6,2,3 };
        int arr_2[3] = { -1,2,3 };
        IntN* a = new IntN_Vert(4, arr_1);
        IntN* b = new IntN_Vert(3, arr_2);
        IntN_Vert c;
        c = *a - *b;
        if (((c).X()[3] == 6) && ((c).X()[2] == 4) && ((c).X()[1] == 7) && ((c).X()[0])==1) {
                std::cout << "Autotest4 is passed\n";
                delete a;
                delete b;
                return 0;
        }
else{        std::cout << "Autotest4 is failed\n";
            delete a;
            delete b;
             return 1;
        }

}
int Autotest() {
        if (!Autotest1() && !Autotest2() && !Autotest3() && !Autotest4()) {
                return 0;
        }
        return 1;
}
