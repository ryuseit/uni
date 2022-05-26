INSTALL_DIR		= ./
CC			= gcc
CFLAGS			= -O1
CLIBS			= -lm

HEADERS			= common.h

DCUT			= dcut
IRCAT			= ircat
SNR				= snr
DIV				= div

PROGRAMS		=\
			$(DCUT)\
			$(IRCAT)\
			$(SNR)\
			$(DIV)

C_COMMON_FOPEN		= common_fopen.o
C_COMMON_MEMORY		= common_memory.o

C_MAIN_DCUT		= main_dcut.o
C_MAIN_IRCAT	= main_ircat.o
C_MAIN_SNR		= main_snr.o
C_MAIN_DIV		= main_div.o

C_DCUT		=\
			$(C_MAIN_DCUT)\
			$(C_COMMON_FOPEN)\
			$(C_COMMON_MEMORY)

C_IRCAT		=\
			$(C_MAIN_IRCAT)\
			$(C_COMMON_FOPEN)\
			$(C_COMMON_MEMORY)

C_SNR		=\
			$(C_MAIN_SNR)\
			$(C_COMMON_FOPEN)\
			$(C_COMMON_MEMORY)

C_DIV		=\
			$(C_MAIN_DIV)\
			$(C_COMMON_FOPEN)\
			$(C_COMMON_MEMORY)

all: $(PROGRAMS)

$(DCUT): $(C_DCUT) $(HEADERS) Makefile
		$(CC) $(CFLAGS) -o $(DCUT) $(C_DCUT) $(CLIBS)

$(IRCAT): $(C_IRCAT) $(HEADERS) Makefile
		$(CC) $(CFLAGS) -o $(IRCAT) $(C_IRCAT) $(CLIBS)

$(SNR): $(C_SNR) $(HEADERS) Makefile
		$(CC) $(CFLAGS) -o $(SNR) $(C_SNR) $(CLIBS)

$(DIV): $(C_DIV) $(HEADERS) Makefile
		$(CC) $(CFLAGS) -o $(DIV) $(C_DIV) $(CLIBS)

install: $(PROGRAMS)
		@cp $(PROGRAMS) $(INSTALL_DIR)

clean:
		@rm -f *.o $(PROGRAMS)\
			$(INSTALL_DIR)/$(DCUT)\
			$(INSTALL_DIR)/$(IRCAT)\
			$(INSTALL_DIR)/$(SNR)\
			$(INSTALL_DIR)/$(DIV)
