#include "conjugatedradient.h"

ConjugateDradient::ConjugateDradient(QObject *parent) : QObject(parent)
{

}

void ConjugateDradient::calc()
{
    res = conjugateGradientSolver(this->A, this->B);
}

vec conjugateGradientSolver( const matrix &A, const vec &B )
{
   double TOLERANCE = 1.0e-10;

   int n = A.size();
   vec X( n, 0.0 );

   vec R = B;
   vec P = R;
   int k = 0;

   while ( k < n )
   {
      vec Rold = R;
      vec AP = matrixTimesVector( A, P );

      double alpha = innerProduct( R, R ) / max( innerProduct( P, AP ), NEARZERO );
      X = vectorCombination( 1.0, X, alpha, P );
      R = vectorCombination( 1.0, R, -alpha, AP );

      if ( vectorNorm( R ) < TOLERANCE ) break;

      double beta = innerProduct( R, R ) / max( innerProduct( Rold, Rold ), NEARZERO );
      P = vectorCombination( 1.0, R, beta, P );
      k++;
   }

   return X;
}

vec matrixTimesVector( const matrix &A, const vec &V )
{
   int n = A.size();
   vec C( n );
   for ( int i = 0; i < n; i++ ) C[i] = innerProduct( A[i], V );
   return C;
}

vec vectorCombination( double a, const vec &U, double b, const vec &V )
{
   int n = U.size();
   vec W( n );
   for ( int j = 0; j < n; j++ ) W[j] = a * U[j] + b * V[j];
   return W;
}

double innerProduct( const vec &U, const vec &V )
{
   return inner_product( U.begin(), U.end(), V.begin(), 0.0 );
}

double vectorNorm( const vec &V )
{
   return sqrt( innerProduct( V, V ) );
}
