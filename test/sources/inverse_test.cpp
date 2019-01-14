///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Math Matrices Library
// Copyright (C) 2017-2019 Michael Heilmann
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the
// use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "primordialmachine/math/matrices/include.hpp"
#include "gtest/gtest.h"

using namespace primordialmachine;

static_assert(is_matrix<matrix<matrix_traits<float, 3, 3>>>::value,
              "not a matrix type");

using matrix_traits_type = matrix_traits<float, 3, 3>;
using matrix_type = matrix<matrix_traits_type>;

#define STATIC_ASSERT(expr)                                                    \
  static_assert(expr, "static assertion `" #expr " failed")

TEST(matrices_tests, inverse_test)
{
  matrix_type a, i, b;
  //
  a = identity<matrix_type>();
  i = inverse(a);
  b = a * i;
  ASSERT_TRUE(a == b);
}
