#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>

// all of your function definitions should be in this file now

template <typename T>
class Matrix {
private:
    int _size; //size
    std::vector<std::vector<T>> _matrix;

public:
    Matrix(std::size_t N);
    Matrix(std::vector<std::vector<T>> nums);

    static file_read(const std::string &myfile);
    Matrix operator+(const Matrix &rhs) const;
    Matrix operator*(const Matrix &rhs) const;
    void set_value(std::size_t i, std::size_t j, int n);
    T get_value(std::size_t i, std::size_t j) const;
    int get_size() const;
    T sum_diagonal_major() const;
    T sum_diagonal_minor() const;
    void swap_rows(std::size_t r1, std::size_t r2);
    void swap_cols(std::size_t c1, std::size_t c2);
    void print_matrix() const;
};

template <typename T>
static std::vector<Matrix<T>> file_read(const std::string &myfile) {
    std::ifstream file(myfile):

    std::size_t size;
    file >> size;

    std::vector<std::vector<T>> matrix_1(size, std::vector<T>(size));
    std::vector<std::vector<T>> matrix_2(size, std::vector<T>(size));

    for (std::size_t i=0; i < size; ++i) {
        for (std::size_t j = 0; j<size; ++j) {
            file >> matrix_1[i][j];
        }
    }

    for (std::size_t i=0; i < size; ++i) {
        for (std::size_t j = 0; j<size; ++j) {
            file >> matrix_2[i][j];
        }
    }

    return (Matrix(matrix_1), Matrix(matrix_2));

}

// colon after parameter list of a constructor is a list of member
// variables and what to initialize them to
template <typename T>
Matrix<T>::Matrix(std::size_t size) : _size(size) {
    for (int i = 0; i < _size; i++) {
        _matrix.push_back(std::vector<int> ());
        for (int j = 0; j < _size; j++) {
            _matrix.at(i).push_back(0);
        }
    }
}

template <typename T> 
Matrix<T>::Matrix(std::vector<std::vector<T>> matrix) : _matrix(matrix), _size(matrix.size()) {

}

template <typename T> 
Matrix<T> Matrix<T>::operator+(const Matrix &rhs) const {
    Matrix result(_size);
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            result.set_value(i, j, (rhs.get_value(i, j) + this->get_value(i, j)));
        }
    }
    return result;
}

template <typename T> 
Matrix<T> Matrix<T>::operator*(const Matrix &rhs) const {
    Matrix<T> result(_size);
    int product; 
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            for (int k = 0; k <_size; k++) {
                product += rhs.get_value(i, k) * this->get_value(i, k); 
            }
            result.set_value(i, j, product);
            product = 0;
        }
    }
    return result;
}

template <typename T> 
T Matrix<T>::get_value(std::size_t i, std::size_t j) const{
    return _matrix.at(i).at(j);
}

template <typename T> 
int Matrix<T>::get_size() const {
    return _size;
}

template <typename T> 
void Matrix<T>::set_value(std::size_t i, std::size_t j, int k) {
    _matrix.at(i).at(j) = k;
}

template <typename T> 
T Matrix<T>::sum_diagonal_major() const {
    int sum = 0;
    for (int i = 0; i < _size; i++) {
        sum += this->get_value(i, i);
    }
    return sum;
}

template <typename T> 
T Matrix<T>::sum_diagonal_minor() const {
    int sum = 0;
    for (int i = 0; i < _size; i++) {
        sum += this->get_value(i, _size - i);
    }
    return sum;
};

template <typename T> 
void Matrix<T>::swap_rows(std::size_t r1, std::size_t r2) {
    int value1; 
    int value2;
    for (int i = 0; i < _size; i++) {
        value1 = this->get_value(r1, i);
        value2 = this->get_value(r2, i);
        this->set_value(r1, i, value2);
        this->set_value(r2, i, value1);
    }
};

template <typename T> 
void Matrix<T>::swap_cols(std::size_t c1, std::size_t c2) {
    int value1; 
    int value2;
    for (int i = 0; i < _size; i++) {
        value1 = this->get_value(i, c1);
        value2 = this->get_value(i, c2);
        this->set_value(i, c1, value2);
        this->set_value(i, c2, value1);
    }
}

template <typename T> 
void Matrix<T>::print_matrix() const {
    for (int i = 0; i <= _size; i++) {
        for (int j = 0; j <= _size; i++) {
            std::cout <<get_value(i, j) << "\n";
        }
    } 
}

#endif // __MATRIX_HPP__
