#ifndef INLINE_VARIABLE_H
#define INLINE_VARIABLE_H

// with inline, we can have single globally available object by defining it only in header file,
// which might be included by multiple CPP files. --> It will be refereing to same global variable
class demo {
    public:
        static int var;
        static constexpr int name = 515; // constexpr iplies inline since C++17
};

inline int demo::var = 10;
struct myType {
    int value;
    myType(int i) : value(i) {}

    static myType max;
};

inline myType myType::max{0};

#endif //INLINE_VARIABLE_H