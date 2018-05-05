CXXFLAGS = -g -Wall -std=c++14 -Iinclude

bin/main: obj/main.o obj/data.o obj/errors.o obj/algorithms.o
	$(CXX) -o $@ $(LDFLAGS) $+ $(LDLIBS)

obj/main.o: src/main.cpp include/data.h include/errors.h include/algorithms.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<
obj/data.o: src/data.cpp include/data.h include/errors.h include/algorithms.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<
obj/errors.o: src/errors.cpp include/data.h include/errors.h include/algorithms.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<
obj/algorithms.o: src/algorithms.cpp include/data.h include/errors.h include/algorithms.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<
