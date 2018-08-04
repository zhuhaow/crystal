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

#include <type_traits>

#include "blob.h"

namespace crystal {
namespace tensor {

class CpuTag {};

template <typename T> using CpuBlob = Blob<T, std::allocator<T>, CpuTag>;

using CpuInt8 = CpuBlob<int8_t>;
using CpuInt16 = CpuBlob<int16_t>;
using CpuInt32 = CpuBlob<int32_t>;
using CpuInt64 = CpuBlob<int64_t>;

using CpuFloat = CpuBlob<float>;
using CpuDouble = CpuBlob<double>;

template <typename B>
struct is_cpu_blob : public std::is_same<typename B::TagType, CpuTag> {};

} // namespace tensor
} // namespace crystal
