///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Math Non Scalars Library
// Copyright (c) 2019 Michael Heilmann
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

#include "primordialmachine/math/non_scalars/element_type.hpp"
#include "primordialmachine/math/non_scalars/is_degenerate.hpp"
#include "primordialmachine/math/non_scalars/is_non_degenerate.hpp"
#include "primordialmachine/math/non_scalars/is_non_scalar.hpp"
#include "primordialmachine/math/non_scalars/make_element_indices.hpp"
#include "primordialmachine/math/scalars/include.hpp"

namespace primordialmachine {

template<typename A, typename B, typename E = void>
struct default_elementwise_binary_plus_functor;

template<typename A, typename B, typename E = void>
struct default_elementwise_binary_minus_functor;

template<typename A, typename E = void>
struct default_elementwise_unary_plus_functor;

template<typename A, typename E = void>
struct default_elementwise_unary_minus_functor;

template<typename A, typename B, typename E = void>
struct default_elementwise_binary_star_functor;

template<typename A, typename B, typename E = void>
struct default_elementwise_binary_slash_functor;

template<typename A, typename B, typename E = void>
struct default_elementwise_plus_assignment_functor;

template<typename A, typename B, typename E = void>
struct default_elementwise_minus_assignment_functor;

template<typename A, typename B, typename E = void>
struct default_elementwise_star_assignment_functor;

template<typename A, typename B, typename E = void>
struct default_elementwise_slash_assignment_functor;

} // namespace primordialmachine
