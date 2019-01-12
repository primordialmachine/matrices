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

#pragma once

#include "primordialmachine/math/matrices/determinant_functor.hpp"
#include "primordialmachine/math/matrices/matrix_default_implementation_0.hpp"
#include "primordialmachine/math/matrices/matrix_default_implementation_n.hpp"

namespace primordialmachine {

// Specialization for 0 x 0 matrices.
template<typename M>
struct determinant_functor<
  M,
  std::enable_if_t<is_matrix<M>::value && M::traits_type::is_square &&
                   M::traits_type::number_of_rows == 0 &&
                   M::traits_type::number_of_columns == 0>>
{
  using result_type = typename M::traits_type::element_type;
  using operand_type = M;
  auto operator()(const operand_type& a) const { return one<result_type>(); }
}; // struct determinant_functor

// Specialization for 1 x 1 matrices.
template<typename M>
struct determinant_functor<
  M,
  std::enable_if_t<is_matrix<M>::value && M::traits_type::is_square &&
                   M::traits_type::number_of_rows == 1 &&
                   M::traits_type::number_of_columns == 1>>
{
  using result_type = typename M::traits_type::element_type;
  using operand_type = M;
  auto operator()(const operand_type& a) const { return a(0, 0); }
}; // struct determinant_functor

// Specialization for 2 x 2 matrices.
template<typename M>
struct determinant_functor<
  M,
  std::enable_if_t<is_matrix<M>::value && M::traits_type::is_square &&
                   M::traits_type::number_of_rows == 2 &&
                   M::traits_type::number_of_columns == 2>>
{
  using result_type = typename M::traits_type::element_type;
  using operand_type = M;
  auto operator()(const operand_type& a) const
  {
    return a(0, 0) * a(1, 1) - a(0, 1) * a(1, 0);
  }
}; // struct determinant_functor

// Specialization for n x m, n, m> 2 matrices.
template<typename M>
struct determinant_functor<
  M,
  std::enable_if_t<is_matrix<M>::value && M::traits_type::is_square &&
                   (M::traits_type::number_of_rows > 2) &&
                   (M::traits_type::number_of_columns > 2)>>
{
  using result_type = typename M::traits_type::element_type;
  using operand_type = M;
  auto operator()(const operand_type& a) const
  {
    // For each element of the rop row.
    return impl0(a, std::make_index_sequence<M::traits_type::number_of_columns>{});
  }

  template<size_t... COLUMNS>
  static auto impl0(const operand_type& a,
                    std::index_sequence<COLUMNS...> columns)
  {
    return (... + (impl1<COLUMNS>(a)));
  }

  template<size_t COLUMN>
  static auto impl1(const operand_type& a)
  {
    using S = typename M::traits_type::element_type;
    auto sgn = (COLUMN % 2 != 0) ? -one<S>() : +one<S>();
    using R = const_delete_row_view<M, 0>;
    using C = const_delete_column_view<R, COLUMN>;
    return sgn * a(0,COLUMN) * determinant(C(R(a)));
  }

}; // struct determinant_functor

} // namespace primordialmachine
