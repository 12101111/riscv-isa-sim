// See LICENSE for license details.

#ifndef _RISCV_TRACER_H
#define _RISCV_TRACER_H

#include "processor.h"

static inline void trace_opcode(processor_t UNUSED *p, insn_bits_t UNUSED opc,
                                insn_t UNUSED insn, reg_t UNUSED pc) {
  if (p->is_hooked(pc)) {
    switch (opc) {
    case MATCH_C_J:
    case MATCH_C_JR:
#if xlen == 32
    case MATCH_C_JAL:
#endif
    case MATCH_C_JALR:
    case MATCH_JAL:
    case MATCH_JALR:
      p->branch_count++;
      break;
    case MATCH_C_BEQZ:
    case MATCH_C_BNEZ:
    case MATCH_BEQ:
    case MATCH_BNE:
    case MATCH_BLT:
    case MATCH_BGE:
    case MATCH_BLTU:
    case MATCH_BGEU:
      p->condition_count++;
      break;
    case MATCH_C_LW:
    case MATCH_C_LWSP:
#if xlen == 32
    case MATCH_C_FLW:
    case MATCH_C_FLWSP:
#elif xlen == 64
    case MATCH_C_LD:
    case MATCH_C_LDSP:
#endif
    case MATCH_C_FLD:
    case MATCH_C_FLDSP:
    case MATCH_LB:
    case MATCH_LH:
    case MATCH_LBU:
    case MATCH_LHU:
    case MATCH_LW:
    case MATCH_LWU:
    case MATCH_LD:
    case MATCH_FLH:
    case MATCH_FLW:
    case MATCH_FLD:
      p->load_count++;
      break;
    case MATCH_C_SW:
    case MATCH_C_SWSP:
#if xlen == 32
    case MATCH_C_FSW:
    case MATCH_C_FSWSP:
#elif xlen == 64
    case MATCH_C_SD:
    case MATCH_C_SDSP:
#endif
    case MATCH_C_FSD:
    case MATCH_C_FSDSP:
    case MATCH_SB:
    case MATCH_SH:
    case MATCH_SW:
    case MATCH_SD:
    case MATCH_FSH:
    case MATCH_FSW:
    case MATCH_FSD:
      p->store_count++;
      break;
    default:
      p->other_count++;
      break;
    }
  }
}

#endif
