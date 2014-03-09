//****************************************************************************
// Product: QS/C++
// Last Updated for Version: 5.2.0
// Date of the Last Update:  Nov 12, 2013
//
//                    Q u a n t u m     L e a P s
//                    ---------------------------
//                    innovating embedded systems
//
// Copyright (C) 2002-2013 Quantum Leaps, LLC. All rights reserved.
//
// This program is open source software: you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published
// by the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Alternatively, this program may be distributed and modified under the
// terms of Quantum Leaps commercial licenses, which expressly supersede
// the GNU General Public License and are specifically designed for
// licensees interested in retaining the proprietary status of their code.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.
//
// Contact information:
// Quantum Leaps Web sites: http://www.quantum-leaps.com
//                          http://www.state-machine.com
// e-mail:                  info@quantum-leaps.com
//****************************************************************************
#include "qs_pkg.h"

/// \file
/// \ingroup qs
/// \brief QS_u64_() and QS_u64() implementation

namespace QP {

#if (QS_OBJ_PTR_SIZE == 8) || (QS_FUN_PTR_SIZE == 8)

//............................................................................
void QS::u64_(uint64_t d) {
    uint8_t chksum_ = priv_.chksum;
    uint8_t *buf_   = priv_.buf;
    QSCtr   head_   = priv_.head;
    QSCtr   end_    = priv_.end;

    priv_.used += static_cast<QSCtr>(8);      // 8 bytes are about to be added
    for (int_t i = static_cast<int_t>(8); i != static_cast<int_t>(0); --i) {
        uint8_t b = static_cast<uint8_t>(d);
        QS_INSERT_ESC_BYTE(b)
        d >>= 8;
    }

    priv_.head   = head_;                                     // save the head
    priv_.chksum = chksum_;                               // save the checksum
}
//............................................................................
void QS::u64(uint8_t format, uint64_t d) {
    uint8_t chksum_ = priv_.chksum;
    uint8_t *buf_   = priv_.buf;
    QSCtr   head_   = priv_.head;
    QSCtr   end_    = priv_.end;

    priv_.used += static_cast<QSCtr>(9);      // 9 bytes are about to be added
    QS_INSERT_ESC_BYTE(format)                       // insert the format byte

    for (int_t i = static_cast<int_t>(8); i != static_cast<int_t>(0); --i) {
        format = static_cast<uint8_t>(d);
        QS_INSERT_ESC_BYTE(format)
        d >>= 8;
    }

    priv_.head   = head_;                                     // save the head
    priv_.chksum = chksum_;                               // save the checksum
}

#endif

}                                                              // namespace QP

