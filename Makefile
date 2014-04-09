LIBRARY := ./libs/libcec.jnilib
OBJFILES := src/main/cpp/LibCEC.o
INCLUDES := -Isrc/main/headers -I/usr/local/include/libcec -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/darwin
CXXFLAGS := $(INCLUDES)

$(LIBRARY): $(OBJFILES)
	$(CXX) -shared -lcec -o $@ $^

clean :
	rm $(OBJFILES) $(LIBRARY)
