#ifndef FORWARD_H
#define FORWARD_H

/**
 *
 * Forward module interface.
 */

 #include <systemc.h>

 SC_MODULE(forward) {

    sc_in< sc_uint<3> >  Branch;

    sc_in< sc_uint<5> >  rs_id2;
    sc_in< sc_uint<5> >  rt_id2;

    sc_in< sc_uint<5> >  WriteReg_exe;
    sc_in< sc_uint<5> >  WriteReg_mem;

    sc_in< bool >  RegWrite_exe;
    sc_in< bool >  RegWrite_mem;
    sc_in< bool >  MemRead;

    sc_out< sc_uint<2> > rs_mux_exe ;
    sc_out< sc_uint<2> > rt_mux_exe ;
    sc_out< sc_uint<2> > rs_mux_id2 ;
    sc_out< sc_uint<2> > rt_mux_id2 ;


    SC_CTOR(forward)
      {
       SC_METHOD(forward_detect);
       sensitive << rs_id2 << rt_id2 << WriteReg_exe
                << WriteReg_mem << RegWrite_exe << RegWrite_mem << MemRead;
     }

    void forward_detect();
 };

 #endif
