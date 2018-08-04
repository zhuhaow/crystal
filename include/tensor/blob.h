// MIT License

// Copyright (c) 2018 Zhuhao Wang

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <memory>

namespace crystal {
namespace tensor {
template <typename T, typename Allocator, typename Tag> class Blob {
public:
  using ValueType = T;
  using AllocatorType = Allocator;
  using TagType = Tag;

  Blob(size_t size)
      : allocator_{}, data_{allocator_.allocate(size)}, size_{size} {};

  Blob(Allocator allocator, T *data, size_t size)
      : allocator_{allocator}, data_{data}, size_{size} {}

  Blob(const Blob &) = delete;
  Blob &operator=(const Blob &) = delete;

  Blob(Blob &&) = delete;
  Blob &operator=(Blob &&) = delete;

  ~Blob() {
    if (data_)
      allocator_.deallocate(data_, size_);
  }

  T *Data() { return data_; }

  size_t Size() { return size_; }

  void Free() {
    allocator_.deallocate(data_, size_);
    data_ = nullptr;
    size_ = 0;
  }

private:
  Allocator allocator_;
  T *data_;
  size_t size_;
};

} // namespace tensor
} // namespace crystal
