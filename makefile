All: Compile Link Run

Compile:
	g++ -I "./include" -c ./src/Hucre.cpp -o ./lib/Hucre.o
	g++ -I "./include" -c ./src/Doku.cpp -o ./lib/Doku.o
	g++ -I "./include" -c ./src/Organ.cpp -o ./lib/Organ.o
	g++ -I "./include" -c ./src/Sistem.cpp -o ./lib/Sistem.o
	g++ -I "./include" -c ./src/Organizma.cpp -o ./lib/Organizma.o
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
	g++ -I "./include" -c ./src/queueNode.cpp -o ./lib/queueNode.o
	g++ -I "./include" -c ./src/Queue.cpp -o ./lib/Queue.o
	g++ -I "./include" -c ./src/IAANode.cpp -o ./lib/IAANode.o
	g++ -I "./include" -c ./src/IkiliAramaAgaci.cpp -o ./lib/IkiliAramaAgaci.o
	g++ -I "./include" -c ./src/ReadAdd.cpp -o ./lib/ReadAdd.o 
	g++ -I "./include" -c ./src/Radix.cpp -o ./lib/Radix.o
	g++ -I "./include" -c ./src/Kontrol.cpp -o ./lib/Kontrol.o
Link:
	g++ ./lib/Hucre.o ./lib/Doku.o ./lib/Organ.o ./lib/Sistem.o ./lib/Organizma.o ./lib/main.o ./lib/queueNode.o ./lib/Queue.o ./lib/IAANode.o ./lib/IkiliAramaAgaci.o ./lib/ReadAdd.o ./lib/Radix.o ./lib/Kontrol.o -o ./bin/program
Run:
	./bin/program.exe