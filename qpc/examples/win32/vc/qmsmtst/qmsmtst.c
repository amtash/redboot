/*****************************************************************************
* Model: qmsmtst.qm
* File:  ./qmsmtst.c
*
* This code has been generated by QM tool (see state-machine.com/qm).
* DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
*
* This program is open source software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
*****************************************************************************/
/* @(/2/1) .................................................................*/
#include "qep_port.h"
#include "qmsmtst.h"

/* @(/1/0) .................................................................*/
typedef struct QMsmTstTag {
/* protected: */
    QMsm super;

/* private: */
    uint8_t foo;
} QMsmTst;

/* protected: */
static QState QMsmTst_initial(QMsmTst * const me, QEvt const * const e);
static QState QMsmTst_s  (QMsmTst * const me, QEvt const * const e);
static QState QMsmTst_s_e(QMsmTst * const me);
static QState QMsmTst_s_x(QMsmTst * const me);
static QState QMsmTst_s_i(QMsmTst * const me);
static QMState const QMsmTst_s_s = {
    (QMState const *)0,
    Q_STATE_CAST(&QMsmTst_s),
    Q_ACTION_CAST(&QMsmTst_s_x)
};
static QState QMsmTst_s1  (QMsmTst * const me, QEvt const * const e);
static QState QMsmTst_s1_e(QMsmTst * const me);
static QState QMsmTst_s1_x(QMsmTst * const me);
static QState QMsmTst_s1_i(QMsmTst * const me);
static QMState const QMsmTst_s1_s = {
    &QMsmTst_s_s,
    Q_STATE_CAST(&QMsmTst_s1),
    Q_ACTION_CAST(&QMsmTst_s1_x)
};
static QState QMsmTst_s11  (QMsmTst * const me, QEvt const * const e);
static QState QMsmTst_s11_e(QMsmTst * const me);
static QState QMsmTst_s11_x(QMsmTst * const me);
static QMState const QMsmTst_s11_s = {
    &QMsmTst_s1_s,
    Q_STATE_CAST(&QMsmTst_s11),
    Q_ACTION_CAST(&QMsmTst_s11_x)
};
static QState QMsmTst_s2  (QMsmTst * const me, QEvt const * const e);
static QState QMsmTst_s2_e(QMsmTst * const me);
static QState QMsmTst_s2_x(QMsmTst * const me);
static QState QMsmTst_s2_i(QMsmTst * const me);
static QMState const QMsmTst_s2_s = {
    &QMsmTst_s_s,
    Q_STATE_CAST(&QMsmTst_s2),
    Q_ACTION_CAST(&QMsmTst_s2_x)
};
static QState QMsmTst_s21  (QMsmTst * const me, QEvt const * const e);
static QState QMsmTst_s21_e(QMsmTst * const me);
static QState QMsmTst_s21_x(QMsmTst * const me);
static QState QMsmTst_s21_i(QMsmTst * const me);
static QMState const QMsmTst_s21_s = {
    &QMsmTst_s2_s,
    Q_STATE_CAST(&QMsmTst_s21),
    Q_ACTION_CAST(&QMsmTst_s21_x)
};
static QState QMsmTst_s211  (QMsmTst * const me, QEvt const * const e);
static QState QMsmTst_s211_e(QMsmTst * const me);
static QState QMsmTst_s211_x(QMsmTst * const me);
static QMState const QMsmTst_s211_s = {
    &QMsmTst_s21_s,
    Q_STATE_CAST(&QMsmTst_s211),
    Q_ACTION_CAST(&QMsmTst_s211_x)
};


static QMsmTst l_msmtst; /* the only instance of the QMsmTst class */

/* global-scope definitions ---------------------------------------*/
QMsm * const the_msm = (QMsm *)&l_msmtst;    /* the opaque pointer */

/* @(/1/1) .................................................................*/
void QMsmTst_ctor(void) {
    QMsmTst *me = &l_msmtst;
    QMsm_ctor(&me->super, Q_STATE_CAST(&QMsmTst_initial));
}
/* @(/1/0) .................................................................*/
/* @(/1/0/1) ...............................................................*/
/* @(/1/0/1/0) */
static QState QMsmTst_initial(QMsmTst * const me, QEvt const * const e) {
    static QActionHandler const act_[] = {
        Q_ACTION_CAST(&QMsmTst_s_e),
        Q_ACTION_CAST(&QMsmTst_s2_e),
        Q_ACTION_CAST(&QMsmTst_s2_i),
        Q_ACTION_CAST(0)
    };
    (void)e; /* avoid compiler warning */
    me->foo = 0U;
    BSP_display("top-INIT;");
    return QM_INITIAL(&QMsmTst_s2_s, &act_[0]);
}
/* @(/1/0/1/1) .............................................................*/
static QState QMsmTst_s_e(QMsmTst * const me) {
    BSP_display("s-ENTRY;");
    return QM_ENTRY(&QMsmTst_s_s);
}
static QState QMsmTst_s_x(QMsmTst * const me) {
    BSP_display("s-EXIT;");
    return QM_EXIT(&QMsmTst_s_s);
}
static QState QMsmTst_s_i(QMsmTst * const me) {
    static QActionHandler const act_[] = {
        Q_ACTION_CAST(&QMsmTst_s1_e),
        Q_ACTION_CAST(&QMsmTst_s11_e),
        Q_ACTION_CAST(0)
    };
    BSP_display("s-INIT;");
    return QM_INITIAL(&QMsmTst_s11_s, &act_[0]);
}
static QState QMsmTst_s(QMsmTst * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* @(/1/0/1/1/1) */
        case I_SIG: {
            /* @(/1/0/1/1/1/0) */
            if (me->foo) {
                me->foo = 0U;
                BSP_display("s-I;");
                status_ = QM_HANDLED();
            }
            else {
                status_ = QM_UNHANDLED();
            }
            break;
        }
        /* @(/1/0/1/1/2) */
        case E_SIG: {
            static QActionHandler const act_[] = {
                Q_ACTION_CAST(&QMsmTst_s1_e),
                Q_ACTION_CAST(&QMsmTst_s11_e),
                Q_ACTION_CAST(0)
            };
            BSP_display("s-E;");
            status_ = QM_TRAN(&QMsmTst_s11_s, &act_[0]);
            break;
        }
        /* @(/1/0/1/1/3) */
        case TERMINATE_SIG: {
            BSP_exit();
            status_ = QM_HANDLED();
            break;
        }
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    return status_;
}
/* @(/1/0/1/1/4) ...........................................................*/
static QState QMsmTst_s1_e(QMsmTst * const me) {
    BSP_display("s1-ENTRY;");
    return QM_ENTRY(&QMsmTst_s1_s);
}
static QState QMsmTst_s1_x(QMsmTst * const me) {
    BSP_display("s1-EXIT;");
    return QM_EXIT(&QMsmTst_s1_s);
}
static QState QMsmTst_s1_i(QMsmTst * const me) {
    static QActionHandler const act_[] = {
        Q_ACTION_CAST(&QMsmTst_s11_e),
        Q_ACTION_CAST(0)
    };
    BSP_display("s1-INIT;");
    return QM_INITIAL(&QMsmTst_s11_s, &act_[0]);
}
static QState QMsmTst_s1(QMsmTst * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* @(/1/0/1/1/4/1) */
        case I_SIG: {
            BSP_display("s1-I;");
            status_ = QM_HANDLED();
            break;
        }
        /* @(/1/0/1/1/4/2) */
        case D_SIG: {
            /* @(/1/0/1/1/4/2/0) */
            if (!me->foo) {
                static QActionHandler const act_[] = {
                    Q_ACTION_CAST(&QMsmTst_s1_x),
                    Q_ACTION_CAST(&QMsmTst_s_i),
                    Q_ACTION_CAST(0)
                };
                me->foo = 1U;
                BSP_display("s1-D;");
                status_ = QM_TRAN(&QMsmTst_s_s, &act_[0]);
            }
            else {
                status_ = QM_UNHANDLED();
            }
            break;
        }
        /* @(/1/0/1/1/4/3) */
        case A_SIG: {
            static QActionHandler const act_[] = {
                Q_ACTION_CAST(&QMsmTst_s1_x),
                Q_ACTION_CAST(&QMsmTst_s1_e),
                Q_ACTION_CAST(&QMsmTst_s1_i),
                Q_ACTION_CAST(0)
            };
            BSP_display("s1-A;");
            status_ = QM_TRAN(&QMsmTst_s1_s, &act_[0]);
            break;
        }
        /* @(/1/0/1/1/4/4) */
        case B_SIG: {
            static QActionHandler const act_[] = {
                Q_ACTION_CAST(&QMsmTst_s11_e),
                Q_ACTION_CAST(0)
            };
            BSP_display("s1-B;");
            status_ = QM_TRAN(&QMsmTst_s11_s, &act_[0]);
            break;
        }
        /* @(/1/0/1/1/4/5) */
        case F_SIG: {
            static QActionHandler const act_[] = {
                Q_ACTION_CAST(&QMsmTst_s1_x),
                Q_ACTION_CAST(&QMsmTst_s2_e),
                Q_ACTION_CAST(&QMsmTst_s21_e),
                Q_ACTION_CAST(&QMsmTst_s211_e),
                Q_ACTION_CAST(0)
            };
            BSP_display("s1-F;");
            status_ = QM_TRAN(&QMsmTst_s211_s, &act_[0]);
            break;
        }
        /* @(/1/0/1/1/4/6) */
        case C_SIG: {
            static QActionHandler const act_[] = {
                Q_ACTION_CAST(&QMsmTst_s1_x),
                Q_ACTION_CAST(&QMsmTst_s2_e),
                Q_ACTION_CAST(&QMsmTst_s2_i),
                Q_ACTION_CAST(0)
            };
            BSP_display("s1-C;");
            status_ = QM_TRAN(&QMsmTst_s2_s, &act_[0]);
            break;
        }
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    return status_;
}
/* @(/1/0/1/1/4/7) .........................................................*/
static QState QMsmTst_s11_e(QMsmTst * const me) {
    BSP_display("s11-ENTRY;");
    return QM_ENTRY(&QMsmTst_s11_s);
}
static QState QMsmTst_s11_x(QMsmTst * const me) {
    BSP_display("s11-EXIT;");
    return QM_EXIT(&QMsmTst_s11_s);
}
static QState QMsmTst_s11(QMsmTst * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* @(/1/0/1/1/4/7/0) */
        case H_SIG: {
            static QActionHandler const act_[] = {
                Q_ACTION_CAST(&QMsmTst_s11_x),
                Q_ACTION_CAST(&QMsmTst_s1_x),
                Q_ACTION_CAST(&QMsmTst_s_i),
                Q_ACTION_CAST(0)
            };
            BSP_display("s11-H;");
            status_ = QM_TRAN(&QMsmTst_s_s, &act_[0]);
            break;
        }
        /* @(/1/0/1/1/4/7/1) */
        case D_SIG: {
            /* @(/1/0/1/1/4/7/1/0) */
            if (me->foo) {
                static QActionHandler const act_[] = {
                    Q_ACTION_CAST(&QMsmTst_s11_x),
                    Q_ACTION_CAST(&QMsmTst_s1_i),
                    Q_ACTION_CAST(0)
                };
                me->foo = 0U;
                BSP_display("s11-D;");
                status_ = QM_TRAN(&QMsmTst_s1_s, &act_[0]);
            }
            else {
                status_ = QM_UNHANDLED();
            }
            break;
        }
        /* @(/1/0/1/1/4/7/2) */
        case G_SIG: {
            static QActionHandler const act_[] = {
                Q_ACTION_CAST(&QMsmTst_s11_x),
                Q_ACTION_CAST(&QMsmTst_s1_x),
                Q_ACTION_CAST(&QMsmTst_s2_e),
                Q_ACTION_CAST(&QMsmTst_s21_e),
                Q_ACTION_CAST(&QMsmTst_s211_e),
                Q_ACTION_CAST(0)
            };
            BSP_display("s11-G;");
            status_ = QM_TRAN(&QMsmTst_s211_s, &act_[0]);
            break;
        }
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    return status_;
}
/* @(/1/0/1/1/5) ...........................................................*/
static QState QMsmTst_s2_e(QMsmTst * const me) {
    BSP_display("s2-ENTRY;");
    return QM_ENTRY(&QMsmTst_s2_s);
}
static QState QMsmTst_s2_x(QMsmTst * const me) {
    BSP_display("s2-EXIT;");
    return QM_EXIT(&QMsmTst_s2_s);
}
static QState QMsmTst_s2_i(QMsmTst * const me) {
    static QActionHandler const act_[] = {
        Q_ACTION_CAST(&QMsmTst_s21_e),
        Q_ACTION_CAST(&QMsmTst_s211_e),
        Q_ACTION_CAST(0)
    };
    BSP_display("s2-INIT;");
    return QM_INITIAL(&QMsmTst_s211_s, &act_[0]);
}
static QState QMsmTst_s2(QMsmTst * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* @(/1/0/1/1/5/1) */
        case I_SIG: {
            /* @(/1/0/1/1/5/1/0) */
            if (!me->foo) {
                me->foo = 1U;
                BSP_display("s2-I;");
                status_ = QM_HANDLED();
            }
            else {
                status_ = QM_UNHANDLED();
            }
            break;
        }
        /* @(/1/0/1/1/5/2) */
        case F_SIG: {
            static QActionHandler const act_[] = {
                Q_ACTION_CAST(&QMsmTst_s2_x),
                Q_ACTION_CAST(&QMsmTst_s1_e),
                Q_ACTION_CAST(&QMsmTst_s11_e),
                Q_ACTION_CAST(0)
            };
            BSP_display("s2-F;");
            status_ = QM_TRAN(&QMsmTst_s11_s, &act_[0]);
            break;
        }
        /* @(/1/0/1/1/5/3) */
        case C_SIG: {
            static QActionHandler const act_[] = {
                Q_ACTION_CAST(&QMsmTst_s2_x),
                Q_ACTION_CAST(&QMsmTst_s1_e),
                Q_ACTION_CAST(&QMsmTst_s1_i),
                Q_ACTION_CAST(0)
            };
            BSP_display("s2-C;");
            status_ = QM_TRAN(&QMsmTst_s1_s, &act_[0]);
            break;
        }
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    return status_;
}
/* @(/1/0/1/1/5/4) .........................................................*/
static QState QMsmTst_s21_e(QMsmTst * const me) {
    BSP_display("s21-ENTRY;");
    return QM_ENTRY(&QMsmTst_s21_s);
}
static QState QMsmTst_s21_x(QMsmTst * const me) {
    BSP_display("s21-EXIT;");
    return QM_EXIT(&QMsmTst_s21_s);
}
static QState QMsmTst_s21_i(QMsmTst * const me) {
    static QActionHandler const act_[] = {
        Q_ACTION_CAST(&QMsmTst_s211_e),
        Q_ACTION_CAST(0)
    };
    BSP_display("s21-INIT;");
    return QM_INITIAL(&QMsmTst_s211_s, &act_[0]);
}
static QState QMsmTst_s21(QMsmTst * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* @(/1/0/1/1/5/4/1) */
        case G_SIG: {
            static QActionHandler const act_[] = {
                Q_ACTION_CAST(&QMsmTst_s21_x),
                Q_ACTION_CAST(&QMsmTst_s2_x),
                Q_ACTION_CAST(&QMsmTst_s1_e),
                Q_ACTION_CAST(&QMsmTst_s1_i),
                Q_ACTION_CAST(0)
            };
            BSP_display("s21-G;");
            status_ = QM_TRAN(&QMsmTst_s1_s, &act_[0]);
            break;
        }
        /* @(/1/0/1/1/5/4/2) */
        case A_SIG: {
            static QActionHandler const act_[] = {
                Q_ACTION_CAST(&QMsmTst_s21_x),
                Q_ACTION_CAST(&QMsmTst_s21_e),
                Q_ACTION_CAST(&QMsmTst_s21_i),
                Q_ACTION_CAST(0)
            };
            BSP_display("s21-A;");
            status_ = QM_TRAN(&QMsmTst_s21_s, &act_[0]);
            break;
        }
        /* @(/1/0/1/1/5/4/3) */
        case B_SIG: {
            static QActionHandler const act_[] = {
                Q_ACTION_CAST(&QMsmTst_s211_e),
                Q_ACTION_CAST(0)
            };
            BSP_display("s21-B;");
            status_ = QM_TRAN(&QMsmTst_s211_s, &act_[0]);
            break;
        }
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    return status_;
}
/* @(/1/0/1/1/5/4/4) .......................................................*/
static QState QMsmTst_s211_e(QMsmTst * const me) {
    BSP_display("s211-ENTRY;");
    return QM_ENTRY(&QMsmTst_s211_s);
}
static QState QMsmTst_s211_x(QMsmTst * const me) {
    BSP_display("s211-EXIT;");
    return QM_EXIT(&QMsmTst_s211_s);
}
static QState QMsmTst_s211(QMsmTst * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* @(/1/0/1/1/5/4/4/0) */
        case H_SIG: {
            static QActionHandler const act_[] = {
                Q_ACTION_CAST(&QMsmTst_s211_x),
                Q_ACTION_CAST(&QMsmTst_s21_x),
                Q_ACTION_CAST(&QMsmTst_s2_x),
                Q_ACTION_CAST(&QMsmTst_s_i),
                Q_ACTION_CAST(0)
            };
            BSP_display("s211-H;");
            status_ = QM_TRAN(&QMsmTst_s_s, &act_[0]);
            break;
        }
        /* @(/1/0/1/1/5/4/4/1) */
        case D_SIG: {
            static QActionHandler const act_[] = {
                Q_ACTION_CAST(&QMsmTst_s211_x),
                Q_ACTION_CAST(&QMsmTst_s21_i),
                Q_ACTION_CAST(0)
            };
            BSP_display("s211-D;");
            status_ = QM_TRAN(&QMsmTst_s21_s, &act_[0]);
            break;
        }
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    return status_;
}

