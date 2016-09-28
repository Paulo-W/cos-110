ofiles = main.o SubstitutionCipher.o OneTimePad.o Caesar.o TranspositionCipher.o
gpp_o = g++ -c -std=c++11 -static -g

main: $(ofiles)
	g++ -std=c++11 -static $(ofiles) -o main

main.o: main.cpp Cipher.h
	$(gpp_o) main.cpp

#~ CipherPipeline.o: CipherPipeline.cpp CipherPipeline.h Cipher.h
	#~ $(gpp_o) CipherPipeline.cpp


SubstitutionCipher.o: SubstitutionCipher.cpp SubstitutionCipher.h Cipher.h
	$(gpp_o) SubstitutionCipher.cpp

OneTimePad.o: OneTimePad.cpp OneTimePad.h SubstitutionCipher.h Caesar.h
	$(gpp_o) OneTimePad.cpp

Caesar.o: Caesar.cpp Caesar.h SubstitutionCipher.h
	$(gpp_o) Caesar.cpp

TranspositionCipher.o: TranspositionCipher.cpp TranspositionCipher.h Cipher.h
	$(gpp_o) TranspositionCipher.cpp

#~ RowsColumns.o: RowsColumns.cpp RowsColumns.h TranspositionCipher.h
	#~ $(gpp_o) RowsColumns.cpp

#~ ZigZag.o: ZigZag.cpp ZigZag.h TranspositionCipher.h
	#~ $(gpp_o) ZigZag.cpp

run: main
	./main

clean:
	rm *.o main *~
