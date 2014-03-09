//****************************************************************************
// Product: Simple Blinky example
// Last Updated for Version: 5.1.0
// Date of the Last Update:  Oct 01, 2013
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
#include "qp_port.h"
#include "bsp.h"

#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;
using namespace QP;

Q_DEFINE_THIS_FILE

//............................................................................
void BSP_init(void) {
    cout << "Simple Blinky example" << endl
         << "QP version: " << QP_VERSION_STR << endl
         << "Press ESC to quit..." << endl;
}
//............................................................................
void BSP_ledOff(void) {
    cout << "OFF" << endl;
}
//............................................................................
void BSP_ledOn(void) {
    cout << "ON" << endl;
}

//............................................................................
void QF::onStartup(void) {
    QF_setTickRate(BSP_TICKS_PER_SEC);            // set the desired tick rate
}
//............................................................................
void QF::onCleanup(void) {
}
//............................................................................
void QP::QF_onClockTick(void) {
    QF::TICK_X(0U, (void *)0);  // perform QF clock tick processing for rate 0
    if (_kbhit()) {                                        // any key pressed?
        int ch = _getch();
        if (ch == '\33') {                       // see if the ESC key pressed
            cout << endl << "Bye Bye!!!" << endl;
            QF::stop();
        }
    }
}
//............................................................................
extern "C" void Q_onAssert(char const Q_ROM * const file, int line) {
    cout << "Assertion failed in " << file
              << "line " << line << endl;
    exit(-1);
}
