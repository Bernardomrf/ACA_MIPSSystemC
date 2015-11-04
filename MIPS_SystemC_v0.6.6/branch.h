#ifndef BRANCH_H
#define BRANCH_H

/**
 *
 * Branch module interface.
 */

 #include <systemc.h>

 SC_MODULE(branch) {

   sc_in< sc_uint<32> >  imm_ext;
   sc_in< sc_uint<26> >  jtarget;

   sc_in< sc_uint<32> >  rs;
   sc_in< sc_uint<32> >  rt;

   sc_in< sc_uint<6> >  opcode;
   sc_in< sc_uint<3> >  branch_in;

   sc_in< sc_uint<32> >  PC4;



   sc_out< bool >  BranchTaken;
   sc_out< sc_uint<32> >  BranchTarget;


   SC_CTOR(branch)
      {
       SC_METHOD(branch_detect);
       sensitive << imm_ext << jtarget << rs
                << rt << opcode << branch_in << PC4;
     }

   void branch_detect();
 };

 #endif
