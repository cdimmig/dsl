// This file is part of libdsl, a library for heuristic graph search
//
// Copyright (C) 2004 Marin Kobilarov <marin@jhu.edu>
//
// This Source Code Form is subject to the terms of the Mozilla
// Public License v. 2.0. If a copy of the MPL was not distributed
// with this file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef DSL_TRAVEDGECOST_H
#define DSL_TRAVEDGECOST_H

#include "edgecost.h"

/**
 *  Calculates the edge cost as the height gradient between two vertices 
 *
 *  Author: Matt Sheckells (c) 2015 msheckells(at)jhu.edu
 */


namespace dsl {

  class TravEdgeCost : public EdgeCost
  {
  public:
    
    
    /**
     * Calculates the cost (usually a height) gradient between two vertices.
     * param v1cost cost of "from" vertex  
     * param v2cost cost of "to" vertex  
     * param ecost cost of edge
     */
    virtual double CalcEdgeCost(double v1cost, double v2cost, double elength);
  };
}


#endif
