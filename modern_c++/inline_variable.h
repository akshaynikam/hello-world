#ifndef INLINE_VARIABLE_H
#define INLINE_VARIABLE_H

// with inline, we can have single globally available object by defining it only in header file,
// which might be included by multiple CPP files. --> It will be refereing to same global variable
class demo {
    public:
        static inline int var = 10;
};

#endif //INLINE_VARIABLE_H