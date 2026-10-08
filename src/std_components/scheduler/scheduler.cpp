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
 * @file scheduler.cpp
 * @brief Basic scheduler implementation.
 */

#include "scheduler.hpp"

#include "utils/logger.hpp"

int Scheduler::Configure(Config config) {
    (void)config;
    this->issueQueue.Allocate(0, sizeof(SchedulerPacket));
    return 0;
}

void Scheduler::ReceiveInstructions() {
    long numberOfConnections = this->GetNumberOfConnections();

    for (long i = 0; i < numberOfConnections; ++i) {

        SchedulerPacket packet;

        while (this->ReceiveRequestFromConnection(i, &packet) == 0) {
            this->issueQueue.Enqueue(&packet);
            ++this->numberOfInstructions;
        }
    }
}

void Scheduler::Clock() {
    this->ReceiveInstructions();
    // Wake up dependent instructions when execution completes.
    // Select ready instructions and send them to execution units.
}

void Scheduler::PrintStatistics() {
    SINUCA3_LOG_PRINTF("Scheduler instructions received: %lu\n",
                      this->numberOfInstructions);
}
