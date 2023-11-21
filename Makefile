target1:
	g++ -c Q1.cpp
	g++ -o Q1 Q1.o
	g++ -O3 -o optimize_file1 Q1.o 
	./Q1

	g++ -c Q2.cpp
	g++ -o Q2 Q2.o
	g++ -O3 -o optimize_file2 Q2.o 
	./Q2

	g++ -c Q3.cpp
	g++ -o Q3 Q3.o
	g++ -O3 -o optimize_file3 Q3.o 
	./Q3

	g++ -c Q4.cpp
	g++ -o Q4 Q4.o
	g++ -O3 -o optimize_file4 Q4.o 
	./Q4
