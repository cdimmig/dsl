#ifndef DSL_LIB_UTILS_H_
#define DSL_LIB_UTILS_H_

#include <sys/time.h>
#include <Eigen/Dense>
#include <vector>
#include "utilsimg.h"
#include <cmath>

namespace dsl {

void save_map(const char* map, int width, int height, const char* filename);

char* load_map(int &width, int &height, const char* filename);

void timer_start(struct timeval* time);

long timer_us(struct timeval* time);

double fangle(double a);

/**
 * Convert SE2 Matrix to its coordinate representation
 * @param m
 * @param q
 */
void se2_q2g(Eigen::Matrix3d& m, const Eigen::Vector3d& q);

/**
 * Obtain SE2 Matrix from its coordinate representation
 * @param q
 * @param m
 */
void se2_g2q(Eigen::Vector3d& q, const Eigen::Matrix3d& m);

/**
 * Invert a SE2 Matrix. Not same as matrix inverse.
 * @param mi
 * @param m
 */
void se2_inv(Eigen::Matrix3d& mi, const Eigen::Matrix3d& m);

/**
 * Exponentiate the se2 element(twist) to obtain SE2 Matrix
 * @param m
 * @param v
 * @param tol
 */
void se2_exp(Eigen::Matrix3d& m, const Eigen::Vector3d& v, double tol = 1e-16);

/**
 * Take the log of the SE2 Matrix to obtain se2 element(twist)
 * @param v
 * @param m
 * @param tol
 */
void se2_log(Eigen::Vector3d& v, const Eigen::Matrix3d& m, double tol = 1e-16);

/**
 * se2 twist(only w and vx) that takes you exactly only to (xf,yf) and not angle
 * @param xf
 * @param yf
 * @return twist(only w and vx). vy=0
 */
Eigen::Vector2d se2_get_wvx( double xf,double yf);

/**
 * Removes the specified dimension. [10,56,75] = removedDim( [10,14,56,75], 1 );
 * @param in input std::vector
 * @param dim dimension to remove
 * @return output std::vector
 */
template<typename T,int n>
Eigen::Matrix<T,n-1,1> RemoveDimension(const Eigen::Matrix<T,n,1>& in, int dim){
  assert(dim>=0 && dim <n);
  dim = dim<0 ? 0 : dim;
  dim = dim>=n ? n-1 : dim;

  Eigen::Matrix<T,n-1,1> out;
  out = in.template head<n-1>();
  out.tail(n-1-dim) = in.tail(n-1-dim);
  return out;
}

/**
 *Inserts an extra dim and sets the value at that dim.
 *e.g. [100, 10, 14, 56, 75] = InsertDimension( [10,14,56,75], 100, 0);
 *e.g. [ 10,100, 14, 56, 75] = InsertDimension( [10,14,56,75], 100, 1);
 *e.g. [ 10, 14, 56,100, 75] = InsertDimension( [10,14,56,75], 100, 3);
 *e.g. [ 10, 14, 56, 75,100] = InsertDimension( [10,14,56,75], 100, 4);
 * @param in input std::vector
 * @param dim dimension where to insert
 * @param val value to insert
 * @return output std::vector
 */
template<typename T,int n>
Eigen::Matrix<T,n+1,1> InsertDimension(const Eigen::Matrix<T,n,1>& in, int dim, T val){
  assert(dim>=0 && dim <=n);
  dim = dim<0 ? 0 : dim;
  dim = dim>n ? n : dim;

  Eigen::Matrix<T,n+1,1> out;
  out.template head<n>() = in;
  out(dim) = val;
  out.tail(n-dim) = in.tail(n-dim);
  return out;
}

/**
 * Function that returns a sign for object of any class as long as the operator
 * - and operator < are defined
 * for that class
 * @param val the object whose sign we need to check
 * @return sign of the object
 */
template < typename T >
int sgn(T val) {
  return (T(0) < val) - (val < T(0));
}

/**
 * Change the extension of a std::string.
 * @param s
 * @param newExt
 */
void ReplaceExtension(std::string& s, const std::string& new_extension);

}

#endif
