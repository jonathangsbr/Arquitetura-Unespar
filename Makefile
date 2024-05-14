crun:
	g++ benchmark.cpp -o benchmark linkedList.cpp -lsfml-graphics -lsfml-window -lsfml-system && ./benchmark && rm benchmark