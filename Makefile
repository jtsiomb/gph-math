# build options
PREFIX ?= /usr/local
warn_flags = -pedantic -Wall
opt_flags = -O0
dbg_flags = -g
# -------------
name = gmath
so_major = 0
so_minor = 1

rootdir ?= .
ccsrc = $(wildcard $(rootdir)/src/*.cc)
obj = $(ccsrc:.cc=.o) $(csrc:.c=.o)
dep = $(obj:.o=.d)
def = -DGPH_NAMESPACE

CFLAGS = $(warn_flags) $(opt_flags) $(dbg_flags) $(pic) $(def)
CXXFLAGS = $(warn_flags) $(opt_flags) $(dbg_flags) $(pic) $(def)

sys = $(shell uname -s | sed 's/MINGW.*/MINGW/')
ifeq ($(sys), Darwin)
	alib = lib$(name).a
	solib = lib$(name).dylib
	shared = -dynamiclib

else ifeq ($(sys), MINGW)
	alib = $(name).lib
	solib = $(name).dll
	shared = -shared

else
	alib = lib$(name).a
	solib = lib$(name).so.$(so_major).$(so_minor)
	soname = lib$(name).so.$(so_major)
	ldname = lib$(name).so
	shared = -shared -Wl,-soname=$(soname)
	pic = -fPIC
endif

.PHONY: all
all: $(alib) $(solib)

$(alib): $(obj) Makefile
	$(AR) rcs $@ $(obj)

$(solib): $(obj) Makefile
	$(CXX) -o $@ $(shared) $(obj) $(LDFLAGS)
	[ -n "$(soname)" ] && \
		rm -f $(soname) $(ldname) && \
		ln -s $(solib) $(soname) && \
		ln -s $(soname) $(ldname) || true

-include $(dep)

%.d: %.c
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@

%.d: %.cc
	@$(CPP) $(CXXFLAGS) $< -MM -MT $(@:.d=.o) >$@

.PHONY: clean
clean:
	rm -f $(obj) $(alib) $(solib)

.PHONY: cleandep
cleandep:
	rm -f $(dep)

.PHONY: install
install: $(alib) $(solib)
	mkdir -p $(DESTDIR)$(PREFIX)/include/$(name) $(DESTDIR)$(PREFIX)/lib
	cp src/*.h src/*.inl $(DESTDIR)$(PREFIX)/include/$(name)/
	cp $(alib) $(DESTDIR)$(PREFIX)/lib/$(alib)
	cp $(solib) $(DESTDIR)$(PREFIX)/lib/$(solib)
	[ -n "$(soname)" ] && \
		rm -f $(DESTDIR)$(PREFIX)/lib/$(soname) $(DESTDIR)$(PREFIX)/lib/$(ldname) && \
		cp $(soname) $(DESTDIR)$(PREFIX)/lib/$(soname) && \
		cp $(ldname) $(DESTDIR)$(PREFIX)/lib/$(ldname) || true

.PHONY: uninstall
uninstall:
	rm -f $(DESTDIR)$(PREFIX)/include/$(name)/*.h $(DESTDIR)$(PREFIX)/include/$(name)/*.inl
	rm -f $(DESTDIR)$(PREFIX)/lib/$(solib)
	[ -n "$(soname)" ] && \
		rm -f $(DESTDIR)$(PREFIX)/lib/$(soname) && \
		rm -f $(DESTDIR)$(PREFIX)/lib/$(ldname) || true
