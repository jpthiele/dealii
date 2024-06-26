// ------------------------------------------------------------------------
//
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright (C) 2017 - 2020 by the deal.II authors
//
// This file is part of the deal.II library.
//
// Part of the source code is dual licensed under Apache-2.0 WITH
// LLVM-exception OR LGPL-2.1-or-later. Detailed license information
// governing the source code and code contributions can be found in
// LICENSE.md and CONTRIBUTING.md at the top level directory of deal.II.
//
// ------------------------------------------------------------------------


// Test that all of the Sacado number traits return the correct information
// Sacado::Fad::DFad

#include <deal.II/differentiation/ad/ad_number_types.h>
#include <deal.II/differentiation/ad/sacado_number_types.h>

#include <complex>
#include <fstream>
#include <iomanip>
#include <type_traits>

#include "../tests.h"

namespace AD = Differentiation::AD;

template <typename NumberTraitsType>
void
print_info()
{
  deallog << "type_code: "
          << static_cast<std::underlying_type<AD::NumberTypes>::type>(
               NumberTraitsType::type_code)
          << std::endl;
  deallog << "is_taped: " << NumberTraitsType::is_taped << std::endl;
  deallog << "is_tapeless: " << NumberTraitsType::is_tapeless << std::endl;
  deallog << "is_real_valued: " << NumberTraitsType::is_real_valued
          << std::endl;
  deallog << "is_complex_valued: " << NumberTraitsType::is_complex_valued
          << std::endl;
  deallog << "n_supported_derivative_levels: "
          << NumberTraitsType::n_supported_derivative_levels << std::endl;

  deallog << "is_ad_number: "
          << AD::is_ad_number<typename NumberTraitsType::ad_type>::value
          << std::endl;
  deallog << "is_sacado_number: "
          << AD::is_sacado_number<typename NumberTraitsType::ad_type>::value
          << std::endl;
  deallog << "is_taped_ad_number: "
          << AD::is_taped_ad_number<typename NumberTraitsType::ad_type>::value
          << std::endl;
  deallog
    << "is_tapeless_ad_number: "
    << AD::is_tapeless_ad_number<typename NumberTraitsType::ad_type>::value
    << std::endl;
}

int
main()
{
  initlog();

  deallog.push("NumberTraits");

  deallog.push("float");
  print_info<AD::NumberTraits<float, AD::NumberTypes::sacado_dfad>>();
  deallog.pop();

  deallog.push("std::complex<float>");
  print_info<
    AD::NumberTraits<std::complex<float>, AD::NumberTypes::sacado_dfad>>();
  deallog.pop();

  deallog.push("double");
  print_info<AD::NumberTraits<double, AD::NumberTypes::sacado_dfad>>();
  deallog.pop();

  deallog.push("std::complex<double>");
  print_info<
    AD::NumberTraits<std::complex<double>, AD::NumberTypes::sacado_dfad>>();
  deallog.pop();

  deallog.push("Sacado::Fad::DFad<float>");
  print_info<
    AD::NumberTraits<Sacado::Fad::DFad<float>, AD::NumberTypes::sacado_dfad>>();
  deallog.pop();

  deallog.push("std::complex< Sacado::Fad::DFad<float> >");
  print_info<AD::NumberTraits<std::complex<Sacado::Fad::DFad<float>>,
                              AD::NumberTypes::sacado_dfad>>();
  deallog.pop();

  deallog.push("Sacado::Fad::DFad<double>");
  print_info<AD::NumberTraits<Sacado::Fad::DFad<double>,
                              AD::NumberTypes::sacado_dfad>>();
  deallog.pop();

  deallog.push("std::complex< Sacado::Fad::DFad<double> >");
  print_info<AD::NumberTraits<std::complex<Sacado::Fad::DFad<double>>,
                              AD::NumberTypes::sacado_dfad>>();
  deallog.pop();

  deallog.pop(); // NumberTraits

  deallog << std::endl;

  deallog.push("ADNumberTraits");

  deallog.push("Sacado::Fad::DFad<float>");
  print_info<AD::ADNumberTraits<Sacado::Fad::DFad<float>>>();
  deallog.pop();

  deallog.push("std::complex< Sacado::Fad::DFad<float> >");
  print_info<AD::ADNumberTraits<std::complex<Sacado::Fad::DFad<float>>>>();
  deallog.pop();

  deallog.push("Sacado::Fad::DFad<double>");
  print_info<AD::ADNumberTraits<Sacado::Fad::DFad<double>>>();
  deallog.pop();

  deallog.push("std::complex< Sacado::Fad::DFad<double> >");
  print_info<AD::ADNumberTraits<std::complex<Sacado::Fad::DFad<double>>>>();
  deallog.pop();

  deallog.pop(); // ADNumberTraits

  deallog << "OK" << std::endl;
}
