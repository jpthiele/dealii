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


// test ConsecutiveControl


#include <deal.II/base/utilities.h>

#include <deal.II/lac/solver_control.h>

#include <iostream>

#include "../tests.h"


int
main(int argc, char **argv)
{
  initlog();
  deallog << std::setprecision(4);

  {
    ConsecutiveControl solver_control(12345, 1.e-3, 3, false, false);
    //                                                     //
    //                                                     n_converged_iterations:
    deallog << solver_control.check(0, 1.e-1) << std::endl; // 0
    deallog << solver_control.check(1, 1.e-4) << std::endl; // 1
    deallog << solver_control.check(2, 1.e-5) << std::endl; // 2
    deallog << solver_control.check(3, 2.e-3) << std::endl; // 0
    deallog << solver_control.check(4, 5.e-4) << std::endl; // 1
    deallog << solver_control.check(5, 4.e-4) << std::endl; // 2
    deallog << solver_control.check(6, 3.e-4) << std::endl; // 3 ==> success

    // reuse
    deallog << solver_control.check(0, 3.e-4) << std::endl; // 1
    deallog << solver_control.check(1, 2.e-4) << std::endl; // 2
    deallog << solver_control.check(2, 1.e-4) << std::endl; // 3 ==> success
  }
}
