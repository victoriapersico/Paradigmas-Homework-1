CC_GPP = g++
CC_CLANG = clang++
CFLAGS = -o dale
CFLAGS_CLANG = -std=c++17 -o dale

all: ejercicio1 ejercicio2 ejercicio3 ejercicio4

ejercicio1:
	$(CC_GPP) $(CFLAGS) Ejercicio_1/Ejercicio_1.cpp
	./dale

ejercicio2:
	$(CC_GPP) $(CFLAGS) Ejercicio_2/Ejercicio_2.cpp
	./dale

ejercicio3:
	$(CC_GPP) $(CFLAGS) Ejercicio_3/Ejercicio_3.cpp
	./dale

ejercicio4:
	$(CC_CLANG) $(CFLAGS_CLANG) Ejercicio_4/Ejercicio_4.cpp
	./dale

clean:
	rm -f dale
