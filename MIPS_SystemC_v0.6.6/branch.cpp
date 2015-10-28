
#include "branch.h"

/**
 * \c Branch module callback function.
 */
void branch::branch_detect()
{
    sc_uint<32> target32 = jtarget.read();

    switch(opcode.read())
    {
        case 2:
            perror("J");
            fprintf(stderr, "jtarget: %#08x\n", (int)(jtarget.read()));
            fprintf(stderr, "pc4 %#08x\n", (int)(PC4.read()));
            fprintf(stderr, "target32 %#08x\n", (int)(target32));
            BranchTaken.write(true);
            BranchTarget.write(target32 | (PC4.read() & 0xFC000000));

            break;

        case 4:
            if (rs.read() == rt.read() && branch_in.read() == true){
                BranchTaken.write(true);
                BranchTarget.write(PC4.read() + (imm_ext.read() << 2));
            }
            break;

        case 5:
            if (rs.read() != rt.read() && branch_in.read() == true){
                BranchTaken.write(true);
                BranchTarget.write(PC4.read() + (imm_ext.read() << 2));
            }
            break;

        case 6:
            if (rs.read() <= 0 && branch_in.read() == true){
                BranchTaken.write(true);
                BranchTarget.write(PC4.read() + (imm_ext.read() << 2));
            }
            break;

        case 7:
            if (rs.read() > 0 && branch_in.read() == true){
                BranchTaken.write(true);
                BranchTarget.write(PC4.read() + (imm_ext.read() << 2));
            }
            break;

        case 8:
            BranchTaken.write(true);
            BranchTarget.write(rs.read());
            break;

        default:
            BranchTaken.write(false);
            break;

    }
}
