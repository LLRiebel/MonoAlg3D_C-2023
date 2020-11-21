############## TEN TUSCHER 2006 ##############################
MODEL_FILE_CPU="ten_tusscher_2006_RS_CPU.c"
MODEL_FILE_GPU="ten_tusscher_2006_RS_GPU.cu"
COMMON_HEADERS="ten_tusscher_2006.h"

COMPILE_MODEL_LIB "ten_tusscher_2006" "$MODEL_FILE_CPU" "$MODEL_FILE_GPU" "$COMMON_HEADERS"

##########################################################

############## TEN TUSCHER 2004 ##############################
MODEL_FILE_CPU="ten_tusscher_2004_RS_CPU.c"
MODEL_FILE_GPU="ten_tusscher_2004_RS_GPU.cu"
COMMON_HEADERS="ten_tusscher_2004.h"

COMPILE_MODEL_LIB "ten_tusscher_2004_endo" "$MODEL_FILE_CPU" "$MODEL_FILE_GPU" "$COMMON_HEADERS"
##########################################################

############## TEN TUSCHER 3 ENDO ##############################
MODEL_FILE_CPU="ten_tusscher_3_RS_CPU.c"
MODEL_FILE_GPU="ten_tusscher_3_RS_GPU.cu"
COMMON_HEADERS="ten_tusscher_3_RS.h"
COMPILE_MODEL_LIB "ten_tusscher_3_endo" "$MODEL_FILE_CPU" "$MODEL_FILE_GPU" "$COMMON_HEADERS" "-DENDO"
##########################################################

############## TEN TUSCHER 3 EPI ##############################
MODEL_FILE_CPU="ten_tusscher_3_RS_CPU.c"
MODEL_FILE_GPU="ten_tusscher_3_RS_GPU.cu"
COMMON_HEADERS="ten_tusscher_3_RS.h"
COMPILE_MODEL_LIB "ten_tusscher_3_epi" "$MODEL_FILE_CPU" "$MODEL_FILE_GPU" "$COMMON_HEADERS" "-DEPI"
##########################################################

############## ELNAZ TENTUSSCHER ORIGINAL 2004 ##############################
MODEL_FILE_CPU="ten_tusscher_2004_RS_CPU_epi.c"
MODEL_FILE_GPU="ten_tusscher_2004_RS_GPU_epi.cu"
COMMON_HEADERS="ten_tusscher_2004_epi.h"

COMPILE_MODEL_LIB "ten_tusscher_2004_epi" "$MODEL_FILE_CPU" "$MODEL_FILE_GPU" "$COMMON_HEADERS"
############################################################################################