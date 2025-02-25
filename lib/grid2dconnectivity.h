// This file is part of libdsl, a library for heuristic graph search
//
// Copyright (C) 2004 Marin Kobilarov <marin@jhu.edu>
//
// This Source Code Form is subject to the terms of the Mozilla
// Public License v. 2.0. If a copy of the MPL was not distributed
// with this file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef DSL_GRID2DCONNECTIVITY_H
#define DSL_GRID2DCONNECTIVITY_H

#include "lineconnectivity.h"

namespace dsl {

/**
 * Defines a simple connectivity between cells in a 2d grid.
 * The default implementation is the 8-cell Moore neighborhood connectivity.
 * The costs are the Euclidean distances b/n the cell centers.
 */
  class Grid2dConnectivity : public LineConnectivity< Eigen::Vector2d, double> {
 public:
    Grid2dConnectivity(const Grid< Eigen::Vector2d, double >& grid);
  };
}

#endif
