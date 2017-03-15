CC = g++
CFLAGS = -std=c++11 -g -Wall -O0
PREFIX = ./src
APPNAME = DevsSlide

XDEVS_OBJS = ${PREFIX}/core/util/Constants.o \
             ${PREFIX}/core/modeling/Event.o \
             ${PREFIX}/core/modeling/Port.o \
             ${PREFIX}/core/modeling/Component.o \
             ${PREFIX}/core/modeling/Atomic.o \
             ${PREFIX}/core/modeling/Coupling.o \
             ${PREFIX}/core/modeling/Coupled.o \
             ${PREFIX}/core/simulation/SimulationClock.o \
             ${PREFIX}/core/simulation/AbstractSimulator.o \
             ${PREFIX}/core/simulation/Simulator.o \
             ${PREFIX}/core/simulation/Coordinator.o

# EDITABLE ------------------- OBJS
EXAMPLE_OBJS = ${PREFIX}/commons.o ${PREFIX}/DevsSlide.o ${PREFIX}/DevsJobsOffline.o ${PREFIX}/resourceManager/DevsAllocator.o ${PREFIX}/resourceManager/DevsResourceManager.o ${PREFIX}/test/DevsTransducer.o 
 
# EDITABLE ------------------- MAIN TARGET NAME
all: ${PREFIX}/main_xdevs.o ${XDEVS_OBJS} $(EXAMPLE_OBJS)
	${CC} ${CFLAGS} $^ -o ${APPNAME}

# EDITABLE ------------------- CLEAN
clean:
	rm -f *.o ${PREFIX}/core/util/*.o ${PREFIX}/core/modeling/*.o ${PREFIX}/core/simulation/*.o ${PREFIX}/test/*.o ${PREFIX}/resourceManager/*.o ../${APPNAME}

%.o: %.cpp
	${CC} -c ${CFLAGS} $< -o $@

# EDITABLE ------------------- EXAMPLE DEPENDENCIES
DevsSlide.o: ${PREFIX}/DevsSlide.cpp ${PREFIX}/DevsSlide.h
DevsJobsOffline.o: ${PREFIX}/DevsJobsOffline.cpp ${PREFIX}/DevsJobsOffline.h
DevsAllocator.o: ${PREFIX}/resourceManager/DevsAllocator.cpp ${PREFIX}/resourceManager/DevsAllocator.h
DevsTransducer.o: ${PREFIX}/test/DevsTransducer.cpp ${PREFIX}/test/DevsTransducer.h
DevsResourceManager.o: ${PREFIX}/resourceManager/DevsResourceManager.cpp ${PREFIX}/resourceManager/DevsResourceManager.h
commons.o: ${PREFIX}/commons.cpp ${PREFIX}/commons.h
main_xdevs.o: ${PREFIX}/main_xdevs.cpp

# XDEVS DEPENDENCIES
${PREFIX}/core/util/Constants.o: ${PREFIX}/core/util/Constants.cpp ${PREFIX}/core/util/Constants.h
${PREFIX}/core/modeling/Event.o: ${PREFIX}/core/modeling/Event.cpp ${PREFIX}/core/modeling/Event.h
${PREFIX}/core/modeling/Port.o: ${PREFIX}/core/modeling/Port.cpp ${PREFIX}/core/modeling/Port.h
${PREFIX}/core/modeling/Component.o: ${PREFIX}/core/modeling/Component.cpp ${PREFIX}/core/modeling/Component.h
${PREFIX}/core/modeling/Atomic.o: ${PREFIX}/core/modeling/Atomic.cpp ${PREFIX}/core/modeling/Atomic.h
${PREFIX}/core/modeling/Coupling.o: ${PREFIX}/core/modeling/Coupling.cpp ${PREFIX}/core/modeling/Coupling.h
${PREFIX}/core/modeling/Coupled.o: ${PREFIX}/core/modeling/Coupled.cpp ${PREFIX}/core/modeling/Coupled.h
${PREFIX}/core/simulation/SimulationClock.o: ${PREFIX}/core/simulation/SimulationClock.cpp ${PREFIX}/core/simulation/SimulationClock.h
${PREFIX}/core/simulation/AbstractSimulator.o: ${PREFIX}/core/simulation/AbstractSimulator.cpp ${PREFIX}/core/simulation/AbstractSimulator.h
${PREFIX}/core/simulation/Simulator.o: ${PREFIX}/core/simulation/Simulator.cpp ${PREFIX}/core/simulation/Simulator.h
${PREFIX}/core/simulation/Coordinator.o: ${PREFIX}/core/simulation/Coordinator.cpp ${PREFIX}/core/simulation/Coordinator.h
