// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VUART_RX_H_
#define _VUART_RX_H_  // guard

#include "verilated.h"

//==========

class VUART_rx__Syms;

//----------

VL_MODULE(VUART_rx) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(rx,0,0);
    VL_OUT8(rx_done,0,0);
    VL_OUT8(readval,7,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ UART_rx__DOT__clkWire;
    CData/*1:0*/ UART_rx__DOT__stateReg;
    CData/*1:0*/ UART_rx__DOT__nextStateReg;
    CData/*7:0*/ UART_rx__DOT__dataReg;
    CData/*7:0*/ UART_rx__DOT__nextDataReg;
    CData/*3:0*/ UART_rx__DOT__dataRegSize;
    CData/*3:0*/ UART_rx__DOT__nextDataRegSize;
    CData/*3:0*/ UART_rx__DOT__countingReg;
    CData/*3:0*/ UART_rx__DOT__nextCountingReg;
    QData/*32:0*/ UART_rx__DOT__counter;
    QData/*32:0*/ UART_rx__DOT__counter_next;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__rst;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VUART_rx__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VUART_rx);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VUART_rx(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VUART_rx();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VUART_rx__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VUART_rx__Syms* symsp, bool first);
  private:
    static QData _change_request(VUART_rx__Syms* __restrict vlSymsp);
    static QData _change_request_1(VUART_rx__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__4(VUART_rx__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VUART_rx__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VUART_rx__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VUART_rx__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(VUART_rx__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(VUART_rx__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(VUART_rx__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
