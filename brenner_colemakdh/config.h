/* 
prevents layout mirroring on flash, use dfu-split-left and dfu-split-right as bootloader targets
ex: qmk compile -kb ferris/sweep -km brenner-colemakdh:dfu-split-left
*/

#define EE_HANDS
// Pick good defaults for enabling homerow modifiers
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
