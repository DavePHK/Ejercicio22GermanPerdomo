EDPSO.png : EDPSO.txt plot.py
	python plot.py

EDPSO.txt : EDPSO
	./EDPSO > EDPSO.txt

EDPSO : EDPSO.cpp
	c++ EDPSO.cpp -o EDPSO
