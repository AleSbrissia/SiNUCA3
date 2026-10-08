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
#include "issue_queue.hpp"

#include <cstring>

#include "engine/default_packets.hpp"


int IssueQueue::Enqueue(IqEntry input) {
    if(this->isFull()) return -1;

    int idx = this->tail;
    this->iq[idx] = input;
    ++this->occupation;
    ++this->tail;

    if (this->tail == this->iqSize) {
        this->tail = 0 ;
    }

    return idx;
}

int IssueQueue::Dequeue(IqEntry *output) {
    if(!(this->IsEmpty())) {
        memcpy



int GetFirstElement(IqEntry *output);
int GetNextElement(IqEntry *output);
void Pop();

int IssueQueue::Allocate(int sizeOfIq) {
    if (sizeOfIq <= 0) {
        this->IqSize = defaultIqSize;
    } else {
        this->IqSize = sizeOfIq;
    };

    this->iq = new IqEntry[this->iqSize]();
    this->iqEntrySize = sizeof(IqEntry);
    if (!(this->iq)) return 1;

    return 0;
}

int GetPriorityInstruction(/*implement*/);

