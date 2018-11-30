CC = g++
OBJ = program.o Calculator.o Date.o api_utils.o RecognitionAudio.o RecognitionConfig.o SpeechToText.o Timer.o TimerHandler.o tokenizer.o VolumeControl.o Weather.o
CFLAGS=-c
ODIR = obj

all: clean Program

Program: $(OBJ)
	$(CC) -o $@ $^ -Wno-psabi

program.o: program.cpp
	$(CC) $(CFLAGS) -o $@ $<

Calculator.o: ./Calculator/Calculator.cpp ./Calculator/Calculator.h
	$(CC) $(CFLAGS) -o $@ $<

Date.o: ./Date/Date.cpp ./Date/Date.h
	$(CC) $(CFLAGS) -o $@ $<

api_utils.o: ./Parser/api_utils.cpp ./Parser/api_utils.hpp
	$(CC) $(CFLAGS) -o $@ $<

RecognitionAudio.o: ./Parser/RecognitionAudio.cpp ./Parser/RecognitionAudio.hpp
	$(CC) $(CFLAGS) -o $@ $<

RecognitionConfig.o: ./Parser/RecognitionConfig.cpp ./Parser/RecognitionConfig.hpp
	$(CC) $(CFLAGS) -o $@ $<

SpeechToText.o: ./SpeechToText/SpeechToText.cpp ./SpeechToText/SpeechToText.hpp
	$(CC) $(CFLAGS) -o $@ $<

Timer.o: ./Timer/Timer.cpp ./Timer/Timer.h
	$(CC) $(CFLAGS) -o $@ $<

TimerHandler.o: ./Timer/TimerHandler.cpp ./Timer/TimerHandler.h
	$(CC) $(CFLAGS) -o $@ $<

tokenizer.o: ./Tokenizer/tokenizer.cpp ./Tokenizer/tokenizer.hpp
	$(CC) $(CFLAGS) -o $@ $<

VolumeControl.o: ./Volume/VolumeControl.cpp ./Volume/VolumeControl.h
	$(CC) $(CFLAGS) -o $@ $<

Weather.o: ./Weather/Weather.cpp ./Weather/Weather.h
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o Program