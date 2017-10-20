#ifndef INCLUDEME_H
#   define INCLUDEME_H

    typedef enum {INT, DOUBLE, CHAR} _datatype;

    typedef union{
        int ival;
        double dval;
        char *cval;
    } _val;

    typedef struct{
        _datatype datatype;
        _val val;
    } _gentype;

#endif