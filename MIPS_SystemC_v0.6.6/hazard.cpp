
#include "hazard.h"

/**
 * Callback for the hazrd detection of \c hazard module.
 */
void hazard::detect_hazard()
{
	if (BranchTaken.read()==true){
	    enable_pc.write(true);
		enable_ifid.write(true);
		reset_ifid.write(true);

		enable_regs.write(true);
		enable_id1id2.write(true);
		enable_id2exe.write(true);

		reset_id1id2.write(false);
		reset_id2exe.write(false);
		reset_exemem.write(false);
		reset_regs.write(false);
	}
	else {
	    enable_pc.write(true);
		enable_ifid.write(true);
		enable_regs.write(true);
		enable_id1id2.write(true);
		enable_id2exe.write(true);

		reset_id1id2.write(false);
		reset_id2exe.write(false);
		reset_ifid.write(false);
		reset_exemem.write(false);
		reset_regs.write(false);

	}
}
