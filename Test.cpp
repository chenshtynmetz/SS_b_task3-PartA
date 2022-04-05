/*
 *
 * AUTHORS: chen
 * 
 * Date: 2022-04
 */

#include "doctest.h"
#include "Matrix.hpp"
#include <vector>
using namespace zich;

#include <string>
#include <algorithm>
using namespace std;



TEST_CASE("matrix*scalar") {
	vector <double> vec= {2,4,5,3,7,12,7.2,8,13};
	Matrix a = Matrix{vec, 3, 3};
	a*3;
    vector <double> ans_vec = {6, 12, 15, 9, 21, 36, 21.6, 24, 39};
	CHECK(a == Matrix{ans_vec, 3, 3});
	a*(-1);
    vector <double> ans_vec2 = {-6, -12, -15, -9, -21, -36, -21.6, -24, -39};
	CHECK(a == Matrix{ans_vec2, 3, 3});
}

TEST_CASE("scalar*matrix") {
	vector<double> vec= {4, -7, -2, 8, 12, 25, 4,-1.2, 17, 23};
	Matrix a = Matrix{vec, 5, 2};
	4*a;
    vector<double> ans_vec = {16, -28, -8, 32, 48, 100, 16, -4.8, 68, 92};
	CHECK(a == Matrix{ans_vec, 5, 2});
	0.5*a;
    vector<double> ans_vec2 = {8, -14, -4, 16, 24, 50, 8, -2.4};
	CHECK(a ==  Matrix{ans_vec2, 5, 2});
}

TEST_CASE("matrix*matrix"){
	vector<double> vec1= {4, -7, -2, 8, 12, 25, 4,-1.2, 17, 23};
	vector<double> vec2 = {2,4,5,3,7,12,7.2,8,13};
	vector<double> vec3 = {1,1,1,1,1,1};
	Matrix a = Matrix{vec2, 3, 3};
	Matrix b = Matrix{vec1, 5, 2};
	Matrix c = Matrix{vec3, 2, 3};
	CHECK_THROWS(a*b);
	CHECK_THROWS(a*c);
	CHECK_THROWS(c*b);
	CHECK_THROWS(b*a);
	Matrix ca = c*a;
	Matrix bc = b*c;
    vector<double> ans_vec = {12.2, 19, 30, 12.2, 19, 30}; 
	CHECK(ca == Matrix{ans_vec, 2, 3});
    vector<double> ans_vec2 = {-3, -3, -3, 6, 6, 6, 37, 37, 37, 2.8, 2.8, 2.8, 40, 40, 40};
    CHECK(bc == Matrix{ans_vec2, 5, 3});
}


TEST_CASE("matrix*=matrix"){
    vector<double> vec1= {4, -7, -2, 8, 12, 25, 4,-1.2, 17, 23};
	vector<double> vec2 = {2,4,5,3,7,12,7.2,8,13};
	vector<double> vec3 = {1,1,1,1,1,1};
	Matrix a = Matrix{vec2, 3, 3};
	Matrix b = Matrix{vec1, 5, 2};
	Matrix c = Matrix{vec3, 2, 3};
	CHECK_THROWS(a*=b);
	CHECK_THROWS(a*=c);
	CHECK_THROWS(c*=b);
	CHECK_THROWS(b*=a);
    c*=a;
    b*=c;
    vector<double> ans_vec = {12.2, 19, 30, 12.2, 19, 30}; 
	CHECK(c == Matrix{ans_vec, 2, 3});
    vector<double> ans_vec2 = {-36.6, -57, -90, 73.2, 114, 180, 451.4, 703, 1110, 34.16, 53.2, 84, 488, 760, 1200};
    CHECK(b == Matrix{ans_vec2, 5, 3});
}

TEST_CASE("matrix*=scalar"){
    vector<double> vec1 = {2,4,5,3,7,12,7.2,8,13};
    vector<double> vec2 = {4, -7, -2, 8, 12, 25, 4,-1.2, 17, 23};
    Matrix a = Matrix{vec1, 3, 3};
	Matrix b = Matrix{vec2, 5, 2};
    a*=5;
    b*=(-2);
    vector<double> ans_vec = {10, 20, 25, 15, 35, 60, 36, 40, 65};
    vector<double> ans_vec2 = {-8, 14, 4, -16, -24, -50, -8, 2.4, -34, 46};
    CHECK(a == Matrix{ans_vec, 3, 3});
    CHECK(b == Matrix(ans_vec2, 5, 2));
}

TEST_CASE("++matrix"){
    vector<double> vec1 = {2,4,5,3,7,12,7.2,8,13};
    vector<double> vec2 = {4, -7, -2, 8, 12, 25, 4,-1.2, 17, 23};
    Matrix a = Matrix{vec1, 3, 3};
	Matrix b = Matrix{vec2, 5, 2};
    vector<double> ans_vec = {3,5,6,4,8,13,8.2,9,14};
    vector<double> ans_vec2 = {5, -6, -1, 9, 13, 26, 5, -0.2, 18, 24};
    CHECK((++a == Matrix(ans_vec, 3, 3)));
    CHECK((++b == Matrix(ans_vec2, 5, 2)));
}

TEST_CASE("--matrix"){
    vector<double> vec1 = {2,4,5,3,7,12,7.2,8,13};
    vector<double> vec2 = {4, -7, -2, 8, 12, 25, 4,-1.2, 17, 23};
    Matrix a = Matrix{vec1, 3, 3};
	Matrix b = Matrix{vec2, 5, 2};
    vector<double> ans_vec = {1,3,4,2,6,11,6.2,7,12};
    vector<double> ans_vec2 = {3, -8, -3, 7, 11, 24, 3, -2.2, 16, 22};
    CHECK((--a == Matrix{ans_vec, 3, 3}));
    CHECK((--b == Matrix{ans_vec2, 5, 2}));
}

TEST_CASE("matrix++"){
    vector<double> vec1 = {2,4,5,3,7,12,7.2,8,13};
    vector<double> vec2 = {4, -7, -2, 8, 12, 25, 4,-1.2, 17, 23};
    Matrix a = Matrix{vec1, 3, 3};
	Matrix b = Matrix{vec2, 5, 2};
    vector<double> ans_vec = {3,5,6,4,8,13,8.2,9,14};
    vector<double> ans_vec2 = {5, -6, -1, 9, 13, 26, 5, -0.2, 18, 24};
    CHECK(a++ != Matrix{ans_vec, 3, 3});
    CHECK(a == Matrix{ans_vec, 3, 3});
    CHECK(b++ != Matrix{ans_vec2, 5, 2});
    CHECK(b == Matrix{ans_vec2, 5, 2});
}

TEST_CASE("matrix--"){
    vector<double> vec1 = {2,4,5,3,7,12,7.2,8,13};
    vector<double> vec2 = {4, -7, -2, 8, 12, 25, 4,-1.2, 17, 23};
    Matrix a = Matrix{vec1, 3, 3};
	Matrix b = Matrix{vec2, 5, 2};
    vector<double> ans_vec = {1,3,4,2,6,11,6.2,7,12};
    vector<double> ans_vec2 = {3, -8, -3, 7, 11, 24, 3, -2.2, 16, 22};
    CHECK((a-- != Matrix{ans_vec, 3, 3}));
    CHECK(a == Matrix{ans_vec, 3, 3});
    CHECK(b-- != Matrix{ans_vec2, 5, 2});
    CHECK(b == Matrix{ans_vec2, 5, 2});
}

TEST_CASE("matrix+matrix"){
    vector<double> vec1 = {2, 4, 5, 3, 7, 12, 7.2, 8, 13};
    vector<double> vec2 = {4, -7, -2, 8, 12, 25, 4,-1.2, 17, 23};
    vector<double> vec3 = {5, 2, 3, 12, -9, 10, 5.6, 4, 23};
    vector<double> vec4 = {6, 87, 12, 32.2, -9, -17, 5, 4.5, 8, 1};
    Matrix a = Matrix{vec1, 3, 3};
	Matrix b = Matrix{vec2, 5, 2};
    Matrix c = Matrix{vec3, 3, 3};
    Matrix d = Matrix{vec4, 5, 2};
    CHECK_THROWS(a+b);
    CHECK_THROWS(a+d);
    CHECK_THROWS(b+c);
    CHECK_THROWS(b+a);
    CHECK_THROWS(c+b);
    CHECK_THROWS(c+d);
    CHECK_THROWS(d+a);
    CHECK_THROWS(d+c);
    vector<double> ans_vec1= {7,6,8,15,-2,22,12.8,12,36};
    vector<double> ans_vec2= {10, 80, 10, 40.2, 3, 8, 9, 3.3, 25, 24};
    Matrix ac = a+c;
    Matrix ca = c+a;
    Matrix bd = b+d; 
    Matrix db = d+b;
    CHECK(ac == Matrix(ans_vec1, 3, 3));
    CHECK(ca == Matrix(ans_vec1, 3, 3));
    CHECK(bd == Matrix(ans_vec2, 5, 2));
    CHECK(db == Matrix(ans_vec2, 5, 2));
}

TEST_CASE("matrix += matrix"){
    vector<double> vec1 = {2, 4, 5, 3, 7, 12, 7.2, 8, 13};
    vector<double> vec2 = {4, -7, -2, 8, 12, 25, 4,-1.2, 17, 23};
    vector<double> vec3 = {5, 2, 3, 12, -9, 10, 5.6, 4, 23};
    vector<double> vec4 = {6, 87, 12, 32.2, -9, -17, 5, 4.5, 8, 1};
    Matrix a = Matrix{vec1, 3, 3};
	Matrix b = Matrix{vec2, 5, 2};
    Matrix c = Matrix{vec3, 3, 3};
    Matrix d = Matrix{vec4, 5, 2};
    CHECK_THROWS(a+=b);
    CHECK_THROWS(a+=d);
    CHECK_THROWS(b+=c);
    CHECK_THROWS(b+=a);
    CHECK_THROWS(c+=b);
    CHECK_THROWS(c+=d);
    CHECK_THROWS(d+=a);
    CHECK_THROWS(d+=c);
    vector<double> ans_vec1= {7,6,8,15,-2,22,12.8,12,36};
    vector<double> ans_vec2= {10, 80, 10, 40.2, 3, 8, 9, 3.3, 25, 24};
    vector<double> ans_vec3= {12,8,11,27,-11,32,18.4,16,59};
    vector<double> ans_vec4= {16, 167, 32, 72.4, -6, -9, 14, 7.8, 33, 25};
    a+=c;
    c+=a;
    b+=d;
    d+=b;
    CHECK(a == Matrix(ans_vec1, 3, 3));
    CHECK(c == Matrix(ans_vec3, 3, 3));
    CHECK(b == Matrix(ans_vec2, 5, 2));
    CHECK(d == Matrix(ans_vec4, 5, 2));
}

TEST_CASE("matrix-matrix"){
    vector<double> vec1 = {2, 4, 5, 3, 7, 12, 7.2, 8, 13};
    vector<double> vec2 = {4, -7, -2, 8, 12, 25, 4,-1.2, 17, 23};
    vector<double> vec3 = {5, 2, 3, 12, -9, 10, 5.6, 4, 23};
    vector<double> vec4 = {6, 87, 12, 32.2, -9, -17, 5, 4.5, 8, 1};
    Matrix a = Matrix{vec1, 3, 3};
	Matrix b = Matrix{vec2, 5, 2};
    Matrix c = Matrix{vec3, 3, 3};
    Matrix d = Matrix{vec4, 5, 2};
    CHECK_THROWS(a-b);
    CHECK_THROWS(a-d);
    CHECK_THROWS(b-c);
    CHECK_THROWS(b-a);
    CHECK_THROWS(c-b);
    CHECK_THROWS(c-d);
    CHECK_THROWS(d-a);
    CHECK_THROWS(d-c);
    vector<double> ans_vec1 = {-3, 2, 2, -9, 16, 2, 1.6, 4, -10};
    vector<double> ans_vec2 = {3, -2, -2, 9, -16, -2, -1.6, -4, 10};
    vector<double> ans_vec3 = {-2, -94, -14, -14.6, 21, 42, -1, -5.7, 9, 22};
    vector<double> ans_vec4 = {2, 94, 14, 14.6, -21, -42, 1, 5.7, -9, -22};
    Matrix ac = a-c;
    Matrix ca = c-a;
    Matrix bd = b-d; 
    Matrix db = d-b;
    CHECK(ac == Matrix(ans_vec1, 3, 3));
    CHECK(ca == Matrix(ans_vec2, 3, 3));
    CHECK(bd == Matrix(ans_vec3, 5, 2));
    CHECK(db == Matrix(ans_vec4, 5, 2));
}

TEST_CASE("matrix-=matrix"){
    vector<double> vec1 = {2, 4, 5, 3, 7, 12, 7.2, 8, 13};
    vector<double> vec2 = {4, -7, -2, 8, 12, 25, 4,-1.2, 17, 23};
    vector<double> vec3 = {5, 2, 3, 12, -9, 10, 5.6, 4, 23};
    vector<double> vec4 = {6, 87, 12, 32.2, -9, -17, 5, 4.5, 8, 1};
    Matrix a = Matrix{vec1, 3, 3};
	Matrix b = Matrix{vec2, 5, 2};
    Matrix c = Matrix{vec3, 3, 3};
    Matrix d = Matrix{vec4, 5, 2};
    CHECK_THROWS(a-=b);
    CHECK_THROWS(a-=d);
    CHECK_THROWS(b-=c);
    CHECK_THROWS(b-=a);
    CHECK_THROWS(c-=b);
    CHECK_THROWS(c-=d);
    CHECK_THROWS(d-=a);
    CHECK_THROWS(d-=c);
    vector<double> ans_vec1 = {-3, 2, 2, -9, 16, 2, 1.6, 4, -10};
    vector<double> ans_vec2 = {8, 0, 1, 21, -25, 8, 4, 0, 33};
    vector<double> ans_vec3 = {-2, -94, -14, -14.6, 21, 42, -1, -5.7, 9, 22};
    vector<double> ans_vec4 = {8, 181, 26, 46.8, -30, -59, 6, 10.2, -1, -21};
    a-=c;
    c-=a;
    b-=d; 
    d-=b;
    CHECK(a == Matrix(ans_vec1, 3, 3));
    CHECK(c == Matrix(ans_vec2, 3, 3));
    CHECK(b == Matrix(ans_vec3, 5, 2));
    CHECK(d == Matrix(ans_vec4, 5, 2));
}

TEST_CASE("+matrix"){
    vector<double> vec1 = {2, 4, 5, 3, 7, 12, 7.2, 8, 13};
    vector<double> vec2 = {4, -7, -2, 8, 12, 25, 4,-1.2, 17, 23};
    Matrix a = Matrix{vec1, 3, 3};
	Matrix b = Matrix{vec2, 5, 2};
    Matrix c = +a;
    Matrix d = +b;
    CHECK(c == a);
    CHECK(d == c);
}

TEST_CASE("-matrix"){
    vector<double> vec1 = {2, 4, 5, 3, 7, 12, 7.2, 8, 13};
    vector<double> vec2 = {4, -7, -2, 8, 12, 25, 4,-1.2, 17, 23};
    Matrix a = Matrix{vec1, 3, 3};
	Matrix b = Matrix{vec2, 5, 2};
    Matrix c = -a;
    Matrix d = -b;
    vector<double> ans_vec1 = {-2, -4, -5, -3, -7, -12, -7.2, -8, -13};
    vector<double> ans_vec2 = {-4, 7, 2, -8, -12, -25, -4, 1.2, -17, -23};
    CHECK(c == Matrix{ans_vec1, 3, 3});
    CHECK(d == Matrix{ans_vec2, 5, 2});
}

TEST_CASE("matrix == matrix"){
    vector<double> vec1 = {2, 4, 5, 3, 7, 12, 7.2, 8, 13};
    vector<double> vec2 = {4, -7, -2, 8, 12, 25, 4,-1.2, 17, 23};
    Matrix a = Matrix{vec1, 3, 3};
	Matrix b = Matrix{vec2, 5, 2};
    Matrix c = Matrix{vec1, 3, 3};
    CHECK_THROWS(bool ans2 = (a == b)); //change to error
    CHECK_THROWS(bool ans2 = (b == a));
    CHECK_THROWS(bool ans2 = (c == b));
    CHECK_THROWS(bool ans2 = (b == c));
    bool ans = (a == c);
    CHECK_EQ(ans, true);
    vector<double> vec3 = {4, 5, 1, 3, 3.2, 7, 12, 4, 2};
    Matrix d = Matrix{vec3, 3, 3};
    CHECK_FALSE(d == a);
    CHECK_FALSE(a == d);
}


TEST_CASE("matrix != matrix"){
    vector<double> vec1 = {2, 4, 5, 3, 7, 12, 7.2, 8, 13};
    vector<double> vec2 = {4, -7, -2, 8, 12, 25, 4,-1.2, 17, 23};
    Matrix a = Matrix{vec1, 3, 3};
	Matrix b = Matrix{vec2, 5, 2};
    Matrix c = Matrix{vec1, 3, 3};
    CHECK_FALSE(a != c);
    CHECK_FALSE(c != a);
    CHECK_THROWS(bool ans2 = (a != b));
    CHECK_THROWS(bool ans2 = (c != b));
    CHECK_THROWS(bool ans2 = (b != a));
    CHECK_THROWS(bool ans2 = (b != c));
    vector<double> vec3 = {4, 5, 1, 3, 3.2, 7, 12, 4, 2};
    Matrix d = Matrix{vec3, 3, 3};
    bool ans = (a != d);
    CHECK_EQ(ans, true);
    ans = (d != a);
    CHECK_EQ(ans, true);
}

TEST_CASE("matrix < matrix"){
    vector<double> vec1 = {2, 4, 5, 3, 7, 12, 7.2, 8, 13};
    vector<double> vec2 = {4, -7, -2, 8, 12, 25, 4,-1.2, 17, 23};
    Matrix a = Matrix{vec1, 3, 3};
	Matrix b = Matrix{vec2, 5, 2};
    Matrix c = Matrix{vec1, 3, 3};
    CHECK_THROWS(bool ans2 = (a < b));
    CHECK_THROWS(bool ans2 = (c < b));
    CHECK_THROWS(bool ans2 = (b < a));
    CHECK_THROWS(bool ans2 = (b < c));
    CHECK_FALSE(a < c);
    CHECK_FALSE(c < a);
    vector<double> vec3 = {4, 5, 1, 3, 3.2, 7, 12, 4, 2};
    Matrix d = Matrix{vec3, 3, 3};
    CHECK_FALSE(a < d);
    bool ans = (d < a);
    CHECK_EQ(ans, true);
}

TEST_CASE("matrix > matrix"){
    vector<double> vec1 = {2, 4, 5, 3, 7, 12, 7.2, 8, 13};
    vector<double> vec2 = {4, -7, -2, 8, 12, 25, 4,-1.2, 17, 23};
    Matrix a = Matrix{vec1, 3, 3};
	Matrix b = Matrix{vec2, 5, 2};
    Matrix c = Matrix{vec1, 3, 3};
    CHECK_THROWS(bool ans2 = (a > b));
    CHECK_THROWS(bool ans2 = (c > b));
    CHECK_THROWS(bool ans2 = (b > a));
    CHECK_THROWS(bool ans2 = (b > c));
    CHECK_FALSE(a > c);
    CHECK_FALSE(c > a);
    vector<double> vec3 = {4, 5, 1, 3, 3.2, 7, 12, 4, 2};
    Matrix d = Matrix{vec3, 3, 3};
    CHECK_FALSE(d > a);
    bool ans = (a > d);
    CHECK_EQ(ans, true);
}

TEST_CASE("matrix <= matrix"){
    vector<double> vec1 = {2, 4, 5, 3, 7, 12, 7.2, 8, 13};
    vector<double> vec2 = {4, -7, -2, 8, 12, 25, 4,-1.2, 17, 23};
    Matrix a = Matrix{vec1, 3, 3};
	Matrix b = Matrix{vec2, 5, 2};
    Matrix c = Matrix{vec1, 3, 3};
    CHECK_THROWS(bool ans2 = (a <= b));
    CHECK_THROWS(bool ans2 = (c <= b));
    CHECK_THROWS(bool ans2 = (b <= a));
    CHECK_THROWS(bool ans2 = (b <= c));
    bool ans = (a <= c);
    CHECK_EQ(ans, true);
    ans = (c <= a);
    CHECK_EQ(ans, true);
    vector<double> vec3 = {4, 5, 1, 3, 3.2, 7, 12, 4, 2};
    Matrix d = Matrix{vec3, 3, 3};
    CHECK_FALSE(a <= d);
    ans = (d < a);
    CHECK_EQ(ans, true);
}

TEST_CASE("matrix >= matrix"){
    vector<double> vec1 = {2, 4, 5, 3, 7, 12, 7.2, 8, 13};
    vector<double> vec2 = {4, -7, -2, 8, 12, 25, 4,-1.2, 17, 23};
    Matrix a = Matrix{vec1, 3, 3};
	Matrix b = Matrix{vec2, 5, 2};
    Matrix c = Matrix{vec1, 3, 3};
    CHECK_THROWS(bool ans2 = (a >= b));
    CHECK_THROWS(bool ans2 = (c >= b));
    CHECK_THROWS(bool ans2 = (b >= a));
    CHECK_THROWS(bool ans2 = (b >= c));
    bool ans = (a >= c);
    CHECK_EQ(ans, true);
    ans = (c >= a);
    CHECK_EQ(ans, true);
    vector<double> vec3 = {4, 5, 1, 3, 3.2, 7, 12, 4, 2};
    Matrix d = Matrix{vec3, 3, 3};
    CHECK_FALSE(d >= a);
    ans = (a >= d);
    CHECK_EQ(ans, true);
}

