// See LICENSE for license details.

#ifndef _RISCV_EVENT_TRACER_H
#define _RISCV_EVENT_TRACER_H

#include <cstdint>

enum trace_event_ty {
    TE_READ = 0,
    TE_WRITE = 1,
    TE_BRANCH = 2,
    TE_JUMP = 3,
};

struct trace_event_t {
    uint32_t pc;
    uint32_t addr = 0;
    uint8_t size = 0;
    trace_event_ty ty;
    trace_event_t(uint32_t pc, trace_event_ty ty): pc(pc), ty(ty) {}
    trace_event_t(uint32_t pc, trace_event_ty ty, uint32_t addr, uint8_t size): pc(pc), addr(addr), size(size), ty(ty) {}
};

#endif
