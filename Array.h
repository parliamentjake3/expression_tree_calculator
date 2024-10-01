#ifndef _ARRAY_H_
#define _ARRAY_H_

#include "Base_Array.h"
#include <cstring> // for size_t definition
#include <stdexcept> // for std::out_of_bounds exception

template <typename T>
class Array : public Base_Array<T> {
public:
    /// Type definition of the element type.
    typedef T type;

    /// Default constructor.
    Array(void) : Base_Array<T>() {}

    /**
     * Initializing constructor.
     *
     * @param[in]      length        Initial size
     */
    Array(size_t length) : Base_Array<T>(length) {}

    /**
     * Initializing constructor.
     *
     * @param[in]      length        Initial size
     * @param[in]      fill          Initial value for each element
     */
    Array(size_t length, T fill) : Base_Array<T>(length, fill) {}

    /**
     * Copy constructor
     *
     * @param[in]     arr         The source array.
     */
    Array(const Array& array) : Base_Array<T>(array) {}

    /// Destructor.
    ~Array(void) {}

    /**
     * Assignment operation
     *
     * @param[in]       rhs      Right-hand side of equal sign
     * @return          Reference to self
     */
    const Array& operator=(const Array& rhs) {
        Base_Array<T>::operator=(rhs);
        return *this;
    }

    /**
     * Set a new size for the array. If \a new_size is less than the current
     * size, then the array is truncated. If \a new_size if greater then the
     * current size, then the array is made larger and the new elements are
     * not initialized to anything. If \a new_size is the same as the current
     * size, then nothing happens.
     *
     * The array's original contents are preserved regardless of whether the
     * array's size is either increased or decreased.
     *
     * @param[in]       new_size              New size of the array
     */
    void resize(size_t new_size)
    {
        if (new_size > this->max_size_) {
            T* newData = new T[new_size];
            for (size_t i = 0; i < this->cur_size_; ++i) {
                newData[i] = this->data_[i];
            }
            delete[] this->data_;
            this->data_ = newData;
            this->max_size_ = new_size;
        }
        this->cur_size_ = new_size;
    }

    void shrink() {
        if (this->cur_size() < this->max_size()) {
            // Allocate new array of the current size
            T* shrink_data = new T[this->cur_size()];

            // Copy the current elements to the new array
            for (size_t i = 0; i < this->cur_size(); i++) {
                shrink_data[i] = this->data_[i];  // Assuming direct access or getter for data_
            }

            // Delete the old array and assign the new one
            delete[] this->data_;
            this->data_ = shrink_data;

            // Update max size to match the current size
            this->set_max_size(this->cur_size());  // Using the setter method
        }
    }

    Array slice(size_t begin) const {
        return this->slice(begin, this->size());
    }

    Array slice(size_t begin, size_t end) const {
        if (begin >= this->size() || end > this->size()) throw std::out_of_range("Index is out of range.");
        if (begin >= end) throw std::invalid_argument("Begin index must be less than end index.");

        size_t newSize = end - begin;
        Array slicedArray(newSize);
        for (size_t i = 0; i < newSize; i++) {
            slicedArray[i] = (*this)[begin + i];
        }
        return slicedArray;
    }
};

#endif // _ARRAY_H_

