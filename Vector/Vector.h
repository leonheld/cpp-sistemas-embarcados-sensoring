#pragma once
// Simple std::vector like implementation, because I really enjoy the STL.
// Requisites:
/*
 * 1. Templated to accept any type
 * 2. One single simple constructor
 *
 * Must have:
 * 1. A remove_at() member function
 * 2. The [] operator to access members
 * 3. A push_back() member function
 * */
#include <algorithm>
#include <cstring>
#include <iostream>

const int err_arr[1]{-1};

namespace utils {
template <typename T>
class Vector {
 public:
  // rationale: we start with a decent size array and resize dinamically. For
  // more information, see utils::Vector::resize().
  explicit Vector() : size_(20) { elements_ = new T[size_]; }

  ~Vector() { delete[] elements_; }

  T& operator[](unsigned int index) {
    return elements_[index];
    /*if (index < number_of_elements_) {
      return elements_[index];
    } else {
      // FIXME(ljh): the most stupid error handling in the entire existence.
      return err_arr[0];
    }
     */
  }

  auto remove_at(unsigned int pos) -> void {
    auto tmp = new T[size_ - 1];

    for (int i = 0; i < pos; ++i) {
      tmp[i] = elements_[i];
    }

    for (int i = pos + 1; i < number_of_elements_; ++i) {
      tmp[i - 1] = elements_[i];
    }

    number_of_elements_--;
    size_--;
    delete[] elements_;
    elements_ = tmp;
  }

  auto number_of_elements() -> int { return number_of_elements_; }
  auto push_back(const T& element) -> void {
    if (number_of_elements_ == size_ - 1) {
      resize();
    }
    if (number_of_elements_ < size_) {
      elements_[number_of_elements_] = element;
      number_of_elements_++;
    } else {
      std::cout << "Oopses." << std::endl;
    }
  }

 private:
  unsigned int size_;
  unsigned int number_of_elements_ = 0;
  T* elements_;

  auto resize() -> void {
    // doubling the underlying array is an easy way of doing as few of new
    // allocations as possible because you'll probably end up inserting
    // more elements in the future. I think the STL does something like
    // this but not sure.
    uint64_t resize_factor = 2;
    auto tmp = new T[resize_factor * size_];
    std::memset(tmp, 0, sizeof tmp);

    for (int i = 0; i < size_; ++i) {
      tmp[i] = elements_[i];
    }

    delete[] elements_;
    elements_ = tmp;
    size_ = size_ * 2;
  }
};

}  // namespace utils