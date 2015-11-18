
#include "forward.h"

/**
 * \c Branch module callback function.
 */
void forward::forward_detect()
{
    // Default State
    rs_mux_id2.write(0);
    rt_mux_id2.write(0);
    rs_mux_exe.write(0);
    rt_mux_exe.write(0);


    // EXE/MEM --> EXE (rs)
    if ( rs_id2.read() != 0 && rs_id2.read() == WriteReg_exe.read() && RegWrite_exe.read() == true ){
        rs_mux_exe.write(1);
    }
    // EXE/MEM --> EXE (rt)
    if ( rt_id2.read() != 0 && rt_id2.read() == WriteReg_exe.read() && RegWrite_exe.read() == true && MemRead.read() == false ){
        rt_mux_exe.write(1);
    }
    // EXE/MEM --> ID2 (rs - saltos)
    if ( rs_id2.read() != 0 && rs_id2.read() == WriteReg_exe.read() && RegWrite_exe.read() == true && Branch.read() != 0 ){
        rs_mux_id2.write(1);
    }
    // EXE/MEM --> ID2 (rt - saltos)
    if ( rt_id2.read() != 0 && rt_id2.read() == WriteReg_exe.read() && RegWrite_exe.read() == true && Branch.read() != 0  && MemRead.read() == false ){
        rt_mux_id2.write(1);
    }
    //--------------------------------------------
    // MEM/WB --> EXE (rs)
    if ( rs_id2.read() != 0 && rs_id2.read() == WriteReg_mem.read() && RegWrite_mem.read() == true ){
        rs_mux_exe.write(2);
    }
    // MEM/WB --> EXE (rt)
    if ( rt_id2.read() != 0 && rt_id2.read() == WriteReg_mem.read() && RegWrite_mem.read() == true && MemRead.read() == false ){
        rt_mux_exe.write(2);
    }
    // MEM/WB --> ID2 (rs - saltos)
    if ( rs_id2.read() != 0 && rs_id2.read() == WriteReg_mem.read() && RegWrite_mem.read() == true && Branch.read() != 0 ){
        rs_mux_id2.write(2);
    }
    // MEM/WB --> ID2 (rt - saltos)
    if ( rt_id2.read() != 0 && rt_id2.read() == WriteReg_mem.read() && RegWrite_mem.read() == true && Branch.read() != 0  && MemRead.read() == false ){
        rt_mux_id2.write(2);
    }
}
