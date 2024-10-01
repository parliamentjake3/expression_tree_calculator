#ifndef _CS507_STACK_H_
#define _CS507_STACK_H_

#include <exception>
#include "Array.h"
#include <cstring> 
#include <new> 

template <typename T>
class Stack {
public:
    typedef T type;
    Stack(void) : data_(), top_index_(-1) {}
    Stack(const Stack& s) : data_(s.data_), top_index_(s.top_index_) {}
    ~Stack(void) {}

    const Stack& operator=(const Stack& rhs) {
        if (this != &rhs) {
            this->data_ = rhs.data_;
            this->top_index_ = rhs.top_index_;
        }
        return *this;
    }

    void push(T element) {
        if (top_index_ + 1 == data_.size()) {
            size_t newSize = data_.size() == 0 ? 1 : data_.size() * 2;
            data_.resize(newSize);
        }
        data_[++top_index_] = element;
    }

    T pop(void) {
        if (is_empty()) {
            throw empty_exception("The stack is empty.");
        }
        return this->data_[top_index_--];
    }

    T peek(void) {
        if (is_empty()) {
            throw empty_exception("The stack is empty.");
        }
        return this->data_[top_index_];
    }

    T top(void) const {
        if (is_empty()) {
            throw empty_exception("The stack is empty.");
        }
        return this->data_[top_index_];
    }

    bool is_empty(void) const {
        return this->top_index_ == -1;
    }

    size_t size(void) const {
        return this->top_index_ + 1;
    }

    void clear(void) {
        this->top_index_ = -1;
        this->data_.resize(1);
    }

private:
    Array<T> data_;
    size_t top_index_;

    class empty_exception : public std::exception {
    private:
        char* msg_;
    public:
        empty_exception(const char* msg) {
            try {
                msg_ = new char[std::strlen(msg) + 1];
                std::strcpy(msg_, msg);
            } catch (const std::bad_alloc&) {
                msg_ = nullptr;
            }
        }

        virtual const char* what() const noexcept override {
            return msg_ ? msg_ : "Stack is empty";
        }

        empty_exception(const empty_exception& other) {
            msg_ = new char[std::strlen(other.msg_) + 1];
            std::strcpy(msg_, other.msg_);
        }

        virtual ~empty_exception() noexcept {
            delete[] msg_;
        }

        empty_exception& operator=(const empty_exception& other) {
            if (this != &other) {
                delete[] msg_;
                msg_ = new char[std::strlen(other.msg_) + 1];
                std::strcpy(msg_, other.msg_);
            }
            return *this;
        }
    };
};

#endif  // !defined _CS507_STACK_H_
