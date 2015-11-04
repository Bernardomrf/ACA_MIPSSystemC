
#include "branch.h"

/**
 * \c Branch module callback function.
 */
void branch::branch_detect()
{
    sc_uint<32> target32 = jtarget.read();


    switch(branch_in.read())
    {
        case 1:
            if (rs.read() == rt.read()){
                BranchTaken.write(true);
                BranchTarget.write(PC4.read() + (imm_ext.read() << 2));
            }else{
                BranchTaken.write(false);
            }
            break;

        case 2:
            if (rs.read() != rt.read()){
                BranchTaken.write(true);
                BranchTarget.write(PC4.read() + (imm_ext.read() << 2));
            }else{
                BranchTaken.write(false);
            }
            break;


        case 3:
            if ((int)rs.read() > 0){
                BranchTaken.write(true);
                BranchTarget.write(PC4.read() + (imm_ext.read() << 2));
            }else{
                BranchTaken.write(false);
            }
            break;

        case 4:
            if ((int)rs.read() <= 0){
                BranchTaken.write(true);
                BranchTarget.write(PC4.read() + (imm_ext.read() << 2));
            }else{
                BranchTaken.write(false);
            }
            break;

        case 5:
            BranchTaken.write(true);
            BranchTarget.write(target32 | (PC4.read() & 0xFC000000));

            break;

        case 6:
            BranchTaken.write(true);
            BranchTarget.write(rs.read());
            break;

        default:
            BranchTaken.write(false);
            break;

    }
}
