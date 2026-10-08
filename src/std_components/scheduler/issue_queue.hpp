#ifndef SINUCA3_ISSUE_QUEUE_HPP_
#define SINUCA3_ISSUE_QUEUE_HPP_

//
// Copyright (C) 2024  HiPES - Universidade Federal do Paraná
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

#include <cstring>

#include "engine/default_packets.hpp"

//Inprove this, find a better way to the lower bound 
const int defaultQueueSize = MAX_REGISTERS;

class IssueQueue {
  private:
    typedef struct {
        InstrucionPacket instruction;
        unsigned int destReg;
        unsigned int sourceReg1;
        unsigned int sourceReg2;
        bool isFloat;
    } IqEntry;

    unsigned int iqSize;
    unsigned int head, tail;
    unsigned int occupation;
    unsigned int iqEntrySize;
    IssueEntry* iq;

    int Enqueue(IqEntry input);

    int Dequeue(IqEntry *output);
    int GetFirstElement(IqEntry *output);
    int GetNextElement(IqEntry *output);
    void Pop();

  public:
    IssueQueue() 
        : iqSize(0), iqEntrySize(0), head(0), tail(0), occupation(0) {}

    inline bool IsFull() { return this->occupation == this->iqSize}
    inline bool IsEmpty() { return this->occupation == 0}

    int Allocate(int sizeOfIq);
    int GetPriorityInstruction(/*implement*/);

    ~IssueQueue() {
        this->iqSize = 0;
        if (iq) delete[] iq;
        iq = NULL;
    };
};

#endif
