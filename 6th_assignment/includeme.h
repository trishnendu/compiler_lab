#ifndef INCLUDEME_H
#   define INCLUDEME_H

    typedef enum {NONE, CHAR, INT, DOUBLE } _datatype;

    typedef union{
        int ival;
        double dval;
        char chval;
    } _val;

    typedef struct{
        _datatype datatype;
        _val val;
    } _gentype;

    
#endif