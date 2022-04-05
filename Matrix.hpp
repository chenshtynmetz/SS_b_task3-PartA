#include <vector>
#include <iostream>
// לטפל ברפרנסים
namespace zich{
    class Matrix{
    private:
        int col;
        int row;
        std :: vector<double> mat;
    public:
        Matrix(std::vector<double> vec, int row, int col); // constructor
        // getters
        int get_col(){
            return this->col;
        }
        int get_row(){
            return this->row;
        }
        Matrix operator+(Matrix& other); // matrix + matrix
        Matrix operator-(Matrix& other); // matrix  -matrix
        Matrix& operator+=(Matrix& other); // matrix += matrix
        Matrix& operator-=(Matrix& other); // matrix -= matrix
        // + - onari
        friend Matrix operator+(Matrix& a); // +matrix
        friend Matrix operator-(Matrix& a);  // -matrix
        //
        bool operator<(const Matrix& other)const; // matrix < matrix
        bool operator>(const Matrix& other)const; // matrix > matrix
        bool operator<=(const Matrix& other)const; // matrix <= matrix
        bool operator>=(const Matrix& other)const; // matrix >= matrix
        bool operator==(const Matrix& other)const; // matrix == matrix
        bool operator!=(const Matrix& other)const; // matrix != matrix
        Matrix& operator++(); // ++matrix
        Matrix& operator++(int num); // matrix++
        Matrix& operator--(); // --matrix
        Matrix& operator--(int num); // matrix--
        Matrix operator*(double num); // matrix*scalar
        Matrix& operator*=(double num); // matrix*=scalar
        Matrix operator*(Matrix& other); // matrix*matrix 
        Matrix& operator*=(Matrix& other); // matrix *= matrix
        friend Matrix operator*(double num, Matrix& other); // scalar * matrix
        friend std::ostream& operator<<(std::ostream& os, const Matrix& a); // <<
        friend std::istream& operator>>(std::istream& os, const Matrix& a); // >>
        ~Matrix(); // destructor
    };
}