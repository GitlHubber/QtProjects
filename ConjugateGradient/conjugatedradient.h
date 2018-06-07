#ifndef CONJUGATEDRADIENT_H
#define CONJUGATEDRADIENT_H

#include <QObject>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const double NEARZERO = 1.0e-10;

using vec    = vector<double>;
using matrix = vector<vec>;

// Prototypes
void print( string title, const vec &V );
void print( string title, const matrix &A );
vec matrixTimesVector( const matrix &A, const vec &V );
vec vectorCombination( double a, const vec &U, double b, const vec &V );
double innerProduct( const vec &U, const vec &V );
double vectorNorm( const vec &V );
vec conjugateGradientSolver( const matrix &A, const vec &B );

class ConjugateDradient : public QObject
{
    Q_OBJECT
public:
    explicit ConjugateDradient(QObject *parent = nullptr);
    matrix A;
    vec B;
    vec res;
    void calc();

signals:

public slots:
};

#endif
