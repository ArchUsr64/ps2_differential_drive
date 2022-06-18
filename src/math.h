#ifndef MATH_H_
#define MATH_H_

typedef float Scalar;

typedef struct _Vector {
  union {
    Scalar x;
    Scalar left;
  };
  union {
    Scalar y;
    Scalar right;
  };
} Vector;

#endif
