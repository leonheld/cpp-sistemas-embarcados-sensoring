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
#include <iostream>

int err_arr[1]{-1};

namespace Utils {
template <typename T>
class Vector {
 public:
  explicit Vector(unsigned int size) {
    size_ = size;
    elements_ = new T[size_];
  }

  ~Vector() { delete[] elements_; }

  T& operator[](unsigned int index) {
    if (index < occupied_until) {
      return elements_[index];
    } else {
      // FIXME(ljh): the most stupid error handling in the entire existence.
      return err_arr[0];
    }
  }

  auto remove_at(unsigned int pos) -> void {
    auto tmp = new T[size_ - 1];
    // std::move would be better.
    for (int i = 0; i < pos; ++i) {
      tmp[i] = elements_[i];
    }

    for (int i = pos + 1; i < size_; ++i) {
      tmp[i - 1] = elements_[i];
    }

    occupied_until--;
    delete[] elements_;
    elements_ = tmp;
  }

  auto push_back(const T& element) -> void {
    // FIXME(ljh): should ideally resize if and only if it's near capacity
    resize();
    elements_[occupied_until] = element;
    occupied_until++;
  }

 private:
  unsigned int size_;
  unsigned int occupied_until = 0;
  T* elements_;

  auto resize() -> void {
    // doubling the underlying array is an easy way of doing as few of new
    // allocations as possible because you'll probably end up inserting
    // more elements in the future. I think the STL does something like
    // this but not sure.
    uint64_t resize_factor = 2;
    auto tmp = new T[resize_factor * size_];
    for (int i = 0; i < size_; ++i) {
      tmp[i] = elements_[i];
    }
    delete[] elements_;
    elements_ = tmp;
  }
};

}  // namespace Utils