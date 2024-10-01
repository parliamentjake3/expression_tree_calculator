#ifndef _BASE_ARRAY_H_
#define _BASE_ARRAY_H_

#include <cstring> // for size_t definition
#include <stdexcept> // for std::out_of_range exception

template <typename T>
class Base_Array {
public:
    // Type definition of the element type.
    typedef T type;

    // Default constructor.
    Base_Array(void) : data_(nullptr), cur_size_(0), max_size_(0) {}

    // Initializing constructor.
    Base_Array(size_t length) : data_(new T[length]), cur_size_(length), max_size_(length) {}

    // Initializing constructor.
    Base_Array(size_t length, T fill) : data_(new T[length]), cur_size_(length), max_size_(length) {
        std::fill_n(data_, length, fill);
    }

    // Copy constructor
    Base_Array(const Base_Array& arr) : data_(new T[arr.max_size_]), cur_size_(arr.cur_size_), max_size_(arr.max_size_) {
        std::copy(arr.data_, arr.data_ + arr.cur_size_, data_);
    }

    // Destructor.
    ~Base_Array(void) {
        delete[] data_;
    }

    // Assignment operation
    const Base_Array& operator=(const Base_Array& rhs) {
        if (this != &rhs) {
            T* newData = new T[rhs.max_size_];
            std::copy(rhs.data_, rhs.data_ + rhs.cur_size_, newData);
            delete[] data_;
            this->data_ = newData;
            this->cur_size_ = rhs.cur_size_;
            this->max_size_ = rhs.max_size_;
        }
        return *this;
    }

    // Retrieve the current size of the array.
    size_t size(void) const {
        return this->cur_size_;
    }

    // Retrieve the maximum size of the array.
    size_t max_size(void) const {
        return this->max_size_;
    }

    void setSize(size_t newSize) {
        this->cur_size_ = newSize;
    }

    void setMaxSize(size_t newSize) {
        this->max_size_ = newSize;
    }

    // Access operators
    T& operator[](size_t index) {
        if (index >= this->cur_size_) throw std::out_of_range("Index out of range");
        return this->data_[index];
    }

    const T& operator[](size_t index) const {
        if (index >= this->cur_size_) throw std::out_of_range("Index out of range");
        return this->data_[index];
    }

    T get(size_t index) const {
        if (index >= this->cur_size_) throw std::out_of_range("Index out of range");
        return this->data_[index];
    }

    void set(size_t index, T value) {
        if (index >= this->cur_size_) throw std::out_of_range("Index out of range");
        this->data_[index] = value;
    }

    int find(T element) const {
        for (size_t i = 0; i < this->cur_size_; i++) {
            if (this->data_[i] == element) return static_cast<int>(i);
        }
        return -1;
    }

    int find(T element, size_t start) const {
        if (start >= this->cur_size_) throw std::out_of_range("Start index out of range");
        for (size_t i = start; i < this->cur_size_; i++) {
            if (this->data_[i] == element) return static_cast<int>(i);
        }
        return -1;
    }

    bool operator==(const Base_Array& rhs) const {
        if (this == &rhs) return true;
        if (this->cur_size_ != rhs.cur_size_) return false;
        for (size_t i = 0; i < this->cur_size_; i++) {
            if (this->data_[i] != rhs.data_[i]) return false;
        }
        return true;
    }

    bool operator!=(const Base_Array& rhs) const {
        return !(*this == rhs);
    }

    void fill(T element) {
        std::fill_n(this->data_, this->cur_size_, element);
    }

protected:
    T* data_; // Pointer to the actual data.
    size_t cur_size_; // Current size of the array.
    size_t max_size_; // Maximum size of the array.
};

#endif // _BASE_ARRAY_H_

