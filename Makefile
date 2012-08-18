include param.mk

DEST=/home/luc/libs
VERSION=0.1

INCLUDES=/home/luc/includes
INCFILE=$(NAME).hpp
INCSDIR=$(INCLUDES)/$(NAME)

PCFILE=$(NAME).pc
PCDIR=/usr/lib/pkgconfig

all : $(LIB)

$(LIB) : $(OBJS)
	cd src && make

clean :
	cd src && make clean

rec : clean all

install : $(LIB)
	@cp -v $(LIB) $(DEST)
	@mkdir $(INCSDIR)
	@cp -v $(INCFILE) $(INCLUDES)
	@cp -v `ls src/*.hpp --ignore=$(INCFILE)` $(INCSDIR)
	@cp -v $(PCFILE) $(PCDIR)

uninstall : $(LIBS)
	@touch $(DEST)/$(LIB) $(INCLUDES)/$(INCFILE) $(PCDIR)/$(PCFILE) $(INCSDIR)
	@rm -v $(DEST)/$(LIB) $(INCLUDES)/$(INCFILE)
	@rm -rv $(INCSDIR)
	@rm -v $(PCDIR)/$(PCFILE)

mr-proper : uninstall clean

reinstall : uninstall rec install


