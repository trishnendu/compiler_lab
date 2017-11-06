#ifndef INCLUDEME_H
#   define INCLUDEME_H

    #define GLOBAL 0

    typedef enum {NONE, CHAR, INT, DOUBLE } _datatype;
    typedef enum {VAR, FUNC } _vartype;
    
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