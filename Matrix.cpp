#include "Matrix.hpp"
#include <iostream>

namespace zich{
        Matrix::Matrix(std::vector<double> vec, int row, int col){

        }
        Matrix Matrix :: operator+(Matrix& other){
            return other;
        }
        Matrix Matrix :: operator-(Matrix& other){
            return other;
        }
        Matrix& Matrix :: operator+=(Matrix& other){
            return other;
            
        }
        Matrix& Matrix :: operator-=(Matrix& other){
            return other;
        }
        bool Matrix :: operator<(const Matrix& other)const{
            return false;
        }
        bool Matrix :: operator>(const Matrix& other)const{
            return false;
        }
        bool Matrix :: operator<=(const Matrix& other)const{
            return false;
        }
        bool Matrix :: operator>=(const Matrix& other)const{
            return false;
        }
        bool Matrix :: operator==(const Matrix& other)const{
            return false;
        }
        bool Matrix :: operator!=(const Matrix& other)const{
            return false;
        }
        Matrix& Matrix :: operator++(){
            std::vector<double> vec = {1,1,1};
            static Matrix a= Matrix{vec, 1, 3};
            return a;
        }
        Matrix& Matrix :: operator++(int num){
            std::vector<double> vec = {1,1,1};
            static Matrix a= Matrix{vec, 1, 3};
            return a;
        }
        Matrix& Matrix :: operator--(){
            std::vector<double> vec = {1,1,1};
            static Matrix a= Matrix{vec, 1, 3};
            return a;
        }
        Matrix& Matrix :: operator--(int num){
            std::vector<double> vec = {1,1,1};
            static Matrix a= Matrix{vec, 1, 3};
            return a;
        }
        Matrix Matrix :: operator*(double num){
            std::vector<double> vec = {1,1,1};
            static Matrix a= Matrix{vec, 1, 3};
            return a;
        }
        Matrix& Matrix :: operator*=(double num){
            std::vector<double> vec = {1,1,1};
            static Matrix a= Matrix{vec, 1, 3};
            return a;
        }
        Matrix Matrix :: operator*(Matrix& other){
            return other;
        }
        Matrix& Matrix :: operator*=(Matrix& other){
            return other;
        }
        Matrix :: ~Matrix(){

        }
        // + - onari
        Matrix operator+(Matrix& a){
            return a;
        }
        Matrix operator-(Matrix& a){
            return a;
        }
        //
        Matrix operator*(double num, Matrix& other){
            return other;
        }
        std::ostream& operator<<(std::ostream& os, const Matrix& a){
            return std :: cout << "hi";
        }
        std::istream& operator>>(std::istream& os, const Matrix& a){
            return std :: cin >> a;
        }
}