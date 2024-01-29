compilo = g++

#cible principale (we put in order le plus profond). $^ will take all
banque.exe : main.cpp banque.o client.o compte.o operation.o pel.o livreta.o compteCourant.o compteBloque.o
	$(compilo) $^ -o banque.exe

#cible secondaires. $< will take the first one
banque.o : banque.cpp banque.hpp client.o
	$(compilo) -c $<

client.o : client.cpp client.hpp compte.o
	$(compilo) -c $<

compte.o : compte.cpp compte.hpp operation.o
	$(compilo) -c $<

operation.o : operation.cpp operation.hpp
	$(compilo) -c $<	

compteBloque.o : compteBloque.cpp compteBloque.hpp compteCourant.o
	$(compilo) -c $<

pel.o : pel.cpp pel.hpp compte.o
	$(compilo) -c $<

livreta.o : livreta.cpp livreta.hpp compte.o
	$(compilo) -c $<

compteCourant.o : compteCourant.cpp compteCourant.hpp compte.o
	$(compilo) -c $<

#cible fictive. 
MrProper:
	rm -rf *.o