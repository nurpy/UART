// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VUART_rx.h for the primary calling header

#include "VUART_rx.h"
#include "VUART_rx__Syms.h"

//==========

VL_CTOR_IMP(VUART_rx) {
    VUART_rx__Syms* __restrict vlSymsp = __VlSymsp = new VUART_rx__Syms(this, name());
    VUART_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VUART_rx::__Vconfigure(VUART_rx__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VUART_rx::~VUART_rx() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VUART_rx::_initial__TOP__1(VUART_rx__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_rx::_initial__TOP__1\n"); );
    VUART_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->rx_done = 0U;
    vlTOPp->UART_rx__DOT__dataReg = 0U;
}

void VUART_rx::_settle__TOP__3(VUART_rx__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_rx::_settle__TOP__3\n"); );
    VUART_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->UART_rx__DOT__nextDataRegSize = vlTOPp->UART_rx__DOT__dataRegSize;
    if ((2U & (IData)(vlTOPp->UART_rx__DOT__stateReg))) {
        if ((1U & (IData)(vlTOPp->UART_rx__DOT__stateReg))) {
            if (vlTOPp->UART_rx__DOT__clkWire) {
                if ((0xfU == (IData)(vlTOPp->UART_rx__DOT__countingReg))) {
                    if ((7U != (IData)(vlTOPp->UART_rx__DOT__dataRegSize))) {
                        vlTOPp->UART_rx__DOT__nextDataRegSize 
                            = (0xfU & ((IData)(1U) 
                                       + (IData)(vlTOPp->UART_rx__DOT__dataRegSize)));
                    }
                }
            }
        }
    } else {
        if ((1U & (IData)(vlTOPp->UART_rx__DOT__stateReg))) {
            if (vlTOPp->UART_rx__DOT__clkWire) {
                if ((7U == (IData)(vlTOPp->UART_rx__DOT__countingReg))) {
                    vlTOPp->UART_rx__DOT__nextDataRegSize = 0U;
                }
            }
        }
    }
    vlTOPp->UART_rx__DOT__nextCountingReg = vlTOPp->UART_rx__DOT__countingReg;
    if ((2U & (IData)(vlTOPp->UART_rx__DOT__stateReg))) {
        if ((1U & (IData)(vlTOPp->UART_rx__DOT__stateReg))) {
            if (vlTOPp->UART_rx__DOT__clkWire) {
                vlTOPp->UART_rx__DOT__nextCountingReg 
                    = ((0xfU == (IData)(vlTOPp->UART_rx__DOT__countingReg))
                        ? 0U : (0xfU & ((IData)(1U) 
                                        + (IData)(vlTOPp->UART_rx__DOT__countingReg))));
            }
        } else {
            if (vlTOPp->UART_rx__DOT__clkWire) {
                if ((0xfU != (IData)(vlTOPp->UART_rx__DOT__countingReg))) {
                    vlTOPp->UART_rx__DOT__nextCountingReg 
                        = (0xfU & ((IData)(1U) + (IData)(vlTOPp->UART_rx__DOT__countingReg)));
                }
            }
        }
    } else {
        if ((1U & (IData)(vlTOPp->UART_rx__DOT__stateReg))) {
            if (vlTOPp->UART_rx__DOT__clkWire) {
                vlTOPp->UART_rx__DOT__nextCountingReg 
                    = ((7U == (IData)(vlTOPp->UART_rx__DOT__countingReg))
                        ? 0U : (0xfU & ((IData)(1U) 
                                        + (IData)(vlTOPp->UART_rx__DOT__countingReg))));
            }
        } else {
            if ((1U & (~ (IData)(vlTOPp->rx)))) {
                vlTOPp->UART_rx__DOT__nextCountingReg = 0U;
            }
        }
    }
    vlTOPp->rx_done = 0U;
    if ((2U & (IData)(vlTOPp->UART_rx__DOT__stateReg))) {
        if ((1U & (~ (IData)(vlTOPp->UART_rx__DOT__stateReg)))) {
            if (vlTOPp->UART_rx__DOT__clkWire) {
                if ((0xfU == (IData)(vlTOPp->UART_rx__DOT__countingReg))) {
                    vlTOPp->rx_done = 1U;
                }
            }
        }
    }
    vlTOPp->UART_rx__DOT__nextStateReg = vlTOPp->UART_rx__DOT__stateReg;
    if ((2U & (IData)(vlTOPp->UART_rx__DOT__stateReg))) {
        if ((1U & (IData)(vlTOPp->UART_rx__DOT__stateReg))) {
            if (vlTOPp->UART_rx__DOT__clkWire) {
                if ((0xfU == (IData)(vlTOPp->UART_rx__DOT__countingReg))) {
                    if ((7U == (IData)(vlTOPp->UART_rx__DOT__dataRegSize))) {
                        vlTOPp->UART_rx__DOT__nextStateReg = 2U;
                    }
                }
            }
        } else {
            if (vlTOPp->UART_rx__DOT__clkWire) {
                if ((0xfU == (IData)(vlTOPp->UART_rx__DOT__countingReg))) {
                    vlTOPp->UART_rx__DOT__nextStateReg = 0U;
                }
            }
        }
    } else {
        if ((1U & (IData)(vlTOPp->UART_rx__DOT__stateReg))) {
            if (vlTOPp->UART_rx__DOT__clkWire) {
                if ((7U == (IData)(vlTOPp->UART_rx__DOT__countingReg))) {
                    vlTOPp->UART_rx__DOT__nextStateReg = 3U;
                }
            }
        } else {
            if ((1U & (~ (IData)(vlTOPp->rx)))) {
                vlTOPp->UART_rx__DOT__nextStateReg = 1U;
            }
        }
    }
    vlTOPp->UART_rx__DOT__counter_next = ((0xa3ULL 
                                           == vlTOPp->UART_rx__DOT__counter)
                                           ? 0ULL : 
                                          (0x1ffffffffULL 
                                           & (1ULL 
                                              + vlTOPp->UART_rx__DOT__counter)));
    vlTOPp->readval = vlTOPp->UART_rx__DOT__dataReg;
    vlTOPp->UART_rx__DOT__nextDataReg = vlTOPp->UART_rx__DOT__dataReg;
    if ((2U & (IData)(vlTOPp->UART_rx__DOT__stateReg))) {
        if ((1U & (IData)(vlTOPp->UART_rx__DOT__stateReg))) {
            if (vlTOPp->UART_rx__DOT__clkWire) {
                if ((0xfU == (IData)(vlTOPp->UART_rx__DOT__countingReg))) {
                    vlTOPp->UART_rx__DOT__nextDataReg 
                        = (((IData)(vlTOPp->rx) << 7U) 
                           | (0x7fU & ((IData)(vlTOPp->UART_rx__DOT__dataReg) 
                                       >> 1U)));
                }
            }
        }
    }
}

void VUART_rx::_eval_initial(VUART_rx__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_rx::_eval_initial\n"); );
    VUART_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst = vlTOPp->rst;
}

void VUART_rx::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_rx::final\n"); );
    // Variables
    VUART_rx__Syms* __restrict vlSymsp = this->__VlSymsp;
    VUART_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VUART_rx::_eval_settle(VUART_rx__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_rx::_eval_settle\n"); );
    VUART_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

void VUART_rx::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_rx::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    rx = VL_RAND_RESET_I(1);
    rx_done = VL_RAND_RESET_I(1);
    readval = VL_RAND_RESET_I(8);
    UART_rx__DOT__clkWire = VL_RAND_RESET_I(1);
    UART_rx__DOT__counter = VL_RAND_RESET_Q(33);
    UART_rx__DOT__counter_next = VL_RAND_RESET_Q(33);
    UART_rx__DOT__stateReg = VL_RAND_RESET_I(2);
    UART_rx__DOT__nextStateReg = VL_RAND_RESET_I(2);
    UART_rx__DOT__dataReg = VL_RAND_RESET_I(8);
    UART_rx__DOT__nextDataReg = VL_RAND_RESET_I(8);
    UART_rx__DOT__dataRegSize = VL_RAND_RESET_I(4);
    UART_rx__DOT__nextDataRegSize = VL_RAND_RESET_I(4);
    UART_rx__DOT__countingReg = VL_RAND_RESET_I(4);
    UART_rx__DOT__nextCountingReg = VL_RAND_RESET_I(4);
}
