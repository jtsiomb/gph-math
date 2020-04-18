PREFIX = /usr/local

src = $(wildcard src/*.cc)
obj = $(src:.cc=.o)
dep = $(obj:.o=.d)

so_major = 0
so_minor = 1

liba = libgmath.a
libso = libgmath.so.$(so_major).$(so_minor)
soname = libgmath.so.$(so_major)
ldname = libgmath.so

CXXFLAGS = -pedantic -Wall -g -O3 -ffast-math -fPIC
LDFLAGS = -lm

shared = -shared -Wl,-soname,$(soname)

.PHONY: all
all: $(libso) $(liba)

$(libso): $(obj)
	$(CC) -o $@ $(shared) $(obj) $(LDFLAGS)

$(liba): $(obj)
	$(AR) rcs $@ $(obj)

-include $(dep)

%.d: %.cc
	@echo depfile $@
	@$(CPP) $(CXXFLAGS) $< -MM -MT $(@:.d=.o) >$@

.PHONY: clean
clean:
	rm -f $(obj) $(libso) $(liba)

.PHONY: install
install: $(libso) $(liba)
	mkdir -p $(DESTDIR)$(PREFIX)/include/gmath
	mkdir -p $(DESTDIR)$(PREFIX)/lib
	cp src/*.h src/*.inl $(DESTDIR)$(PREFIX)/include/gmath/
	cp $(liba) $(DESTDIR)$(PREFIX)/lib/$(liba)
	cp $(libso) $(DESTDIR)$(PREFIX)/lib/$(libso)
	[ -n "$(soname)" ] && \
		cd $(DESTDIR)$(PREFIX)/lib && \
		rm -f $(soname) $(ldname) && \
		ln -s $(libso) $(soname) && \
		ln -s $(soname) $(ldname) || \
		true
