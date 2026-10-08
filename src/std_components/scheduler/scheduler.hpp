//
// Copyright (C) 2026  HiPES - Universidade Federal do Paraná
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

/**
 * @file scheduler.hpp
 * @brief Basic scheduler interface for renamed instructions.
 */

#ifndef SINUCA3_STD_COMPONENTS_SCHEDULER_SCHEDULER_HPP_
#define SINUCA3_STD_COMPONENTS_SCHEDULER_SCHEDULER_HPP_

#include "std_components/renaming/renaming.hpp"
#include "utils/circular_buffer.hpp"

/** @brief Buffers renamed instructions for future selection and issue. */
class Scheduler : public Component<SchedulerPacket> {
  private:
    CircularBuffer issueQueue;
    unsigned long numberOfInstructions;

    /** @brief Receives instructions and stores them in the issue queue. */
    void ReceiveInstructions();

  public:
    inline Scheduler() : numberOfInstructions(0) {}

    /** @brief Initializes the issue queue. */
    virtual int Configure(Config config);
    /** @brief Receives instructions each cycle; issue is not implemented yet. */
    virtual void Clock();
    /** @brief Prints the number of instructions received. */
    virtual void PrintStatistics();

    virtual ~Scheduler() {}
};

#endif _
