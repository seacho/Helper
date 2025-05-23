/* Capstone Disassembly Engine, https://www.capstone-engine.org */
/* By Nguyen Anh Quynh <aquynh@gmail.com>, 2013-2022, */
/*    Rot127 <unisono@quyllur.org> 2022-2024 */
/* Automatically generated file by Capstone's LLVM TableGen Disassembler Backend. */

/* LLVM-commit: <commit> */
/* LLVM-tag: <tag> */

/* Do not edit. */

/* Capstone's LLVM TableGen Backends: */
/* https://github.com/capstone-engine/llvm-capstone */

	{ MIPS_INS_ALIAS_ADDIU_B32, "addiu_b32" },
	{ MIPS_INS_ALIAS_BITREVB, "bitrevb" },
	{ MIPS_INS_ALIAS_BITREVH, "bitrevh" },
	{ MIPS_INS_ALIAS_BYTEREVH, "byterevh" },
	{ MIPS_INS_ALIAS_NOT, "not" },
	{ MIPS_INS_ALIAS_RESTORE_JRC, "restore_jrc" },
	{ MIPS_INS_ALIAS_RESTORE, "restore" },
	{ MIPS_INS_ALIAS_SAVE, "save" },
	{ MIPS_INS_ALIAS_MOVE, "move" },
	{ MIPS_INS_ALIAS_BAL, "bal" },
	{ MIPS_INS_ALIAS_JALR_HB, "jalr_hb" },
	{ MIPS_INS_ALIAS_NEG, "neg" },
	{ MIPS_INS_ALIAS_NEGU, "negu" },
	{ MIPS_INS_ALIAS_NOP, "nop" },
	{ MIPS_INS_ALIAS_BNEZL, "bnezl" },
	{ MIPS_INS_ALIAS_BEQZL, "beqzl" },
	{ MIPS_INS_ALIAS_SYSCALL, "syscall" },
	{ MIPS_INS_ALIAS_BREAK, "break" },
	{ MIPS_INS_ALIAS_EI, "ei" },
	{ MIPS_INS_ALIAS_DI, "di" },
	{ MIPS_INS_ALIAS_TEQ, "teq" },
	{ MIPS_INS_ALIAS_TGE, "tge" },
	{ MIPS_INS_ALIAS_TGEU, "tgeu" },
	{ MIPS_INS_ALIAS_TLT, "tlt" },
	{ MIPS_INS_ALIAS_TLTU, "tltu" },
	{ MIPS_INS_ALIAS_TNE, "tne" },
	{ MIPS_INS_ALIAS_RDHWR, "rdhwr" },
	{ MIPS_INS_ALIAS_SDBBP, "sdbbp" },
	{ MIPS_INS_ALIAS_SYNC, "sync" },
	{ MIPS_INS_ALIAS_HYPCALL, "hypcall" },
	{ MIPS_INS_ALIAS_NOR, "nor" },
	{ MIPS_INS_ALIAS_C_F_S, "c_f_s" },
	{ MIPS_INS_ALIAS_C_UN_S, "c_un_s" },
	{ MIPS_INS_ALIAS_C_EQ_S, "c_eq_s" },
	{ MIPS_INS_ALIAS_C_UEQ_S, "c_ueq_s" },
	{ MIPS_INS_ALIAS_C_OLT_S, "c_olt_s" },
	{ MIPS_INS_ALIAS_C_ULT_S, "c_ult_s" },
	{ MIPS_INS_ALIAS_C_OLE_S, "c_ole_s" },
	{ MIPS_INS_ALIAS_C_ULE_S, "c_ule_s" },
	{ MIPS_INS_ALIAS_C_SF_S, "c_sf_s" },
	{ MIPS_INS_ALIAS_C_NGLE_S, "c_ngle_s" },
	{ MIPS_INS_ALIAS_C_SEQ_S, "c_seq_s" },
	{ MIPS_INS_ALIAS_C_NGL_S, "c_ngl_s" },
	{ MIPS_INS_ALIAS_C_LT_S, "c_lt_s" },
	{ MIPS_INS_ALIAS_C_NGE_S, "c_nge_s" },
	{ MIPS_INS_ALIAS_C_LE_S, "c_le_s" },
	{ MIPS_INS_ALIAS_C_NGT_S, "c_ngt_s" },
	{ MIPS_INS_ALIAS_BC1T, "bc1t" },
	{ MIPS_INS_ALIAS_BC1F, "bc1f" },
	{ MIPS_INS_ALIAS_C_F_D, "c_f_d" },
	{ MIPS_INS_ALIAS_C_UN_D, "c_un_d" },
	{ MIPS_INS_ALIAS_C_EQ_D, "c_eq_d" },
	{ MIPS_INS_ALIAS_C_UEQ_D, "c_ueq_d" },
	{ MIPS_INS_ALIAS_C_OLT_D, "c_olt_d" },
	{ MIPS_INS_ALIAS_C_ULT_D, "c_ult_d" },
	{ MIPS_INS_ALIAS_C_OLE_D, "c_ole_d" },
	{ MIPS_INS_ALIAS_C_ULE_D, "c_ule_d" },
	{ MIPS_INS_ALIAS_C_SF_D, "c_sf_d" },
	{ MIPS_INS_ALIAS_C_NGLE_D, "c_ngle_d" },
	{ MIPS_INS_ALIAS_C_SEQ_D, "c_seq_d" },
	{ MIPS_INS_ALIAS_C_NGL_D, "c_ngl_d" },
	{ MIPS_INS_ALIAS_C_LT_D, "c_lt_d" },
	{ MIPS_INS_ALIAS_C_NGE_D, "c_nge_d" },
	{ MIPS_INS_ALIAS_C_LE_D, "c_le_d" },
	{ MIPS_INS_ALIAS_C_NGT_D, "c_ngt_d" },
	{ MIPS_INS_ALIAS_BC1TL, "bc1tl" },
	{ MIPS_INS_ALIAS_BC1FL, "bc1fl" },
	{ MIPS_INS_ALIAS_DNEG, "dneg" },
	{ MIPS_INS_ALIAS_DNEGU, "dnegu" },
	{ MIPS_INS_ALIAS_SLT, "slt" },
	{ MIPS_INS_ALIAS_SLTU, "sltu" },
	{ MIPS_INS_ALIAS_SIGRIE, "sigrie" },
	{ MIPS_INS_ALIAS_JR, "jr" },
	{ MIPS_INS_ALIAS_JRC, "jrc" },
	{ MIPS_INS_ALIAS_JALRC, "jalrc" },
	{ MIPS_INS_ALIAS_DIV, "div" },
	{ MIPS_INS_ALIAS_DIVU, "divu" },
	{ MIPS_INS_ALIAS_LAPC, "lapc" },
	{ MIPS_INS_ALIAS_WRDSP, "wrdsp" },
	{ MIPS_INS_ALIAS_WAIT, "wait" },
	{ MIPS_INS_ALIAS_SW, "sw" },
	{ MIPS_INS_ALIAS_JALRC_HB, "jalrc_hb" },
	{ MIPS_INS_ALIAS_ADDIU_B, "addiu_b" },
	{ MIPS_INS_ALIAS_ADDIU_W, "addiu_w" },
	{ MIPS_INS_ALIAS_JRC_HB, "jrc_hb" },
	{ MIPS_INS_ALIAS_BEQC, "beqc" },
	{ MIPS_INS_ALIAS_BNEC, "bnec" },
	{ MIPS_INS_ALIAS_BEQZC, "beqzc" },
	{ MIPS_INS_ALIAS_BNEZC, "bnezc" },
	{ MIPS_INS_ALIAS_MFC0, "mfc0" },
	{ MIPS_INS_ALIAS_MFHC0, "mfhc0" },
	{ MIPS_INS_ALIAS_MTC0, "mtc0" },
	{ MIPS_INS_ALIAS_MTHC0, "mthc0" },
	{ MIPS_INS_ALIAS_DMT, "dmt" },
	{ MIPS_INS_ALIAS_EMT, "emt" },
	{ MIPS_INS_ALIAS_DVPE, "dvpe" },
	{ MIPS_INS_ALIAS_EVPE, "evpe" },
	{ MIPS_INS_ALIAS_YIELD, "yield" },
	{ MIPS_INS_ALIAS_MFTC0, "mftc0" },
	{ MIPS_INS_ALIAS_MFTLO, "mftlo" },
	{ MIPS_INS_ALIAS_MFTHI, "mfthi" },
	{ MIPS_INS_ALIAS_MFTACX, "mftacx" },
	{ MIPS_INS_ALIAS_MTTC0, "mttc0" },
	{ MIPS_INS_ALIAS_MTTLO, "mttlo" },
	{ MIPS_INS_ALIAS_MTTHI, "mtthi" },
	{ MIPS_INS_ALIAS_MTTACX, "mttacx" },
