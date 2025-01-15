// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VUART_RX__SYMS_H_
#define _VUART_RX__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "VUART_rx.h"

// SYMS CLASS
class VUART_rx__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    VUART_rx*                      TOPp;
    
    // CREATORS
    VUART_rx__Syms(VUART_rx* topp, const char* namep);
    ~VUART_rx__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
