#ifndef REG_ID1_ID2_H
#define REG_ID1_ID2_H

/**
 *
 * reg_id2_exe_t module interface.
 */

#include <systemc.h>

#include "regT.h"

/**
 * reg_id2_exe_t module.
 * reg_id2_exe_t module is the ID/EXE pipeline register.
 */

SC_MODULE(reg_id1_id2_t) {

	// Ports

	sc_in  < bool > clk;
	sc_in  < bool > reset;
	sc_in  < bool > enable;

	sc_in  < sc_uint<16> > imm_id1;
	sc_out < sc_uint<16> > imm_id2;

	sc_in  < sc_uint<32> > PC4_id1;
	sc_out < sc_uint<32> > PC4_id2;

	sc_in  < sc_uint<5> > rt_id1, rd_id1;
	sc_out < sc_uint<5> > rt_id2, rd_id2;

	sc_in  < sc_uint<6> > opcode_id1, funct_id1;
	sc_out  < sc_uint<6> > opcode_id2, funct_id2;

	regT < sc_uint<32> > *PC4;
	regT < sc_uint<16> > *imm;
	regT < sc_uint<5> > *rt,*rd;
	regT < sc_uint<6> > *opcode,*funct;

	SC_CTOR(reg_id1_id2_t) {

		rt = new regT < sc_uint<5> > ("rt");;
		rt->din(rt_id1);
		rt->dout(rt_id2);
		rt->clk(clk);
		rt->enable(enable);
		rt->reset(reset);

		rd = new regT < sc_uint<5> >("rd");
		rd->din(rd_id1);
		rd->dout(rd_id2);
		rd->clk(clk);
		rd->enable(enable);
		rd->reset(reset);

		PC4 = new regT < sc_uint<32> >("PC4");
		PC4->din(PC4_id1);
		PC4->dout(PC4_id2);
		PC4->clk(clk);
		PC4->enable(enable);
		PC4->reset(reset);

		imm = new regT < sc_uint<16> >("imm");
		imm->din(imm_id1);
		imm->dout(imm_id2);
		imm->clk(clk);
		imm->enable(enable);
		imm->reset(reset);

		opcode = new regT < sc_uint<6> >("opcode");
		opcode->din(opcode_id1);
		opcode->dout(opcode_id2);
		opcode->clk(clk);
		opcode->enable(enable);
		opcode->reset(reset);

		funct = new regT < sc_uint<6> >("funct");
		funct->din(funct_id1);
		funct->dout(funct_id2);
		funct->clk(clk);
		funct->enable(enable);
		funct->reset(reset);

	}
};

#endif
