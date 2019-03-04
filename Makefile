CC=g++
CFLAGS= -g --std=c++11

EXENAME=plasm
DEVNAME=plasm-dev

OBJPATH=obj
SRCPATH=src
BINPATH=bin
DATPATH=data

SRCFORM=$(SRCPATH)/%.cpp
OBJFORM=$(OBJPATH)/%.o

FILES=$(patsubst $(SRCPATH)/%.cpp, %, $(wildcard $(SRCPATH)/*.cpp))

#Main targets
all: $(patsubst %, $(OBJFORM), $(FILES))
	$(CC) -o $(BINPATH)/$(EXENAME) $(patsubst %, $(OBJPATH)/%.o, $(FILES)) $(CFLAGS) 
	
devel: $(patsubst %, $(OBJFORM), $(FILES))
	$(CC) -g -o $(BINPATH)/$(DEVNAME) $(patsubst %, $(OBJPATH)/%.o, $(FILES)) $(CFLAGS) 

print-%  : ; @echo $* = $($*)

#Objects
$(OBJFORM): $(SRCFORM)
	$(CC) -o $@ -c $< $(CFLAGS)

#Janitorial
clean:
	rm -f $(BINPATH)/$(EXENAME) 
	rm -f $(BINPATH)/$(DEVNAME)
	rm -f $(OBJPATH)/*.o
	rm -rf debwork
	
install:
	mkdir /usr/share/plasm
	mkdir /usr/share/plasm/core
	cp COPYING /usr/share/plasm/
	cp $(DATPATH)/*.cpu /usr/share/plasm/core/
	cp $(BINPATH)/$(EXENAME) /usr/bin/
	echo "Install complete."
	
update:
	cp $(DATPATH)/*.cpu /usr/share/plasm/core/
	cp $(BINPATH)/$(EXENAME) /usr/bin/
	echo "Updated binary/corefile."
	
debfile:
	mkdir debwork
	mkdir debwork/usr
	mkdir debwork/usr/share
	mkdir debwork/usr/bin
	mkdir debwork/usr/share/doc
	mkdir debwork/usr/share/plasm
	mkdir debwork/usr/share/plasm/core
	cp -r $(DATPATH)/DEBIAN debwork/
	cp $(DATPATH)/copyright debwork/usr/share/doc/
	cp COPYING debwork/usr/share/plasm/
	cp $(DATPATH)/*.cpu debwork/usr/share/plasm/core/
	cp $(BINPATH)/$(EXENAME) debwork/usr/bin/
	dpkg-deb --build debwork
	mv debwork.deb spasm.deb
	rm -r debwork
	echo "Debgen complete."

