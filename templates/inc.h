template<typename T, int n>
class data {
    T var[n];
};

template<int n>
class data<int, n> {
    int var[n];
};

template<>
class data<double, 4> {
    double var[4];
};

void fun();