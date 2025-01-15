// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VUART_rx.h for the primary calling header

#include "VUART_rx.h"
#include "VUART_rx__Syms.h"

//==========

void VUART_rx::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VUART_rx::eval\n"); );
    VUART_rx__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VUART_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("UART_rx.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VUART_rx::_eval_initial_loop(VUART_rx__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("UART_rx.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VUART_rx::_sequent__TOP__2(VUART_rx__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_rx::_sequent__TOP__2\n"); );
    VUART_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->rst) {
        vlTOPp->UART_rx__DOT__dataReg = 0U;
        vlTOPp->UART_rx__DOT__dataRegSize = 0U;
        vlTOPp->UART_rx__DOT__countingReg = 0U;
        vlTOPp->UART_rx__DOT__stateReg = 0U;
    } else {
        vlTOPp->UART_rx__DOT__dataReg = vlTOPp->UART_rx__DOT__nextDataReg;
        vlTOPp->UART_rx__DOT__dataRegSize = vlTOPp->UART_rx__DOT__nextDataRegSize;
        vlTOPp->UART_rx__DOT__countingReg = vlTOPp->UART_rx__DOT__nextCountingReg;
        vlTOPp->UART_rx__DOT__stateReg = vlTOPp->UART_rx__DOT__nextStateReg;
    }
    vlTOPp->UART_rx__DOT__clkWire = (1U & ((~ (IData)(vlTOPp->rst)) 
                                           & ((0xa2ULL 
                                               == vlTOPp->UART_rx__DOT__counter)
                                               ? 1U
                                               : 0U)));
    vlTOPp->readval = vlTOPp->UART_rx__DOT__dataReg;
    vlTOPp->UART_rx__DOT__counter = ((IData)(vlTOPp->rst)
                                      ? 0ULL : vlTOPp->UART_rx__DOT__counter_next);
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
    vlTOPp->UART_rx__DOT__counter_next = ((0xa3ULL 
                                           == vlTOPp->UART_rx__DOT__counter)
                                           ? 0ULL : 
                                          (0x1ffffffffULL 
                                           & (1ULL 
                                              + vlTOPp->UART_rx__DOT__counter)));
}

VL_INLINE_OPT void VUART_rx::_combo__TOP__4(VUART_rx__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_rx::_combo__TOP__4\n"); );
    VUART_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
}

void VUART_rx::_eval(VUART_rx__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_rx::_eval\n"); );
    VUART_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->rst) & (~ (IData)(vlTOPp->__Vclklast__TOP__rst))))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst = vlTOPp->rst;
}

VL_INLINE_OPT QData VUART_rx::_change_request(VUART_rx__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_rx::_change_request\n"); );
    VUART_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VUART_rx::_change_request_1(VUART_rx__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_rx::_change_request_1\n"); );
    VUART_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VUART_rx::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_rx::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((rx & 0xfeU))) {
        Verilated::overWidthError("rx");}
}
#endif  // VL_DEBUG
