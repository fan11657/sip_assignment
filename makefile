all: main
main: main.o sipRetryClient.o sipUdpClient.o sipRequest.o utils.o
	g++ bin/main.o bin/sipRetryClient.o bin/sipUdpClient.o bin/sipRequest.o bin/utils.o -o bin/main
main.o: src/main.cpp
	g++ -c src/main.cpp -o bin/main.o
sipRetryClient.o: sipRequest.o
	g++ -c src/sipRetryClient.cpp -o bin/sipRetryClient.o
sipUdpClient.o: sipRequest.o
	g++ -c src/sipUdpClient.cpp -o bin/sipUdpClient.o
sipRequest.o:
	g++ -c src/sipRequest.cpp -o bin/sipRequest.o
utils.o:
	g++ -c src/utils.cpp -o bin/utils.o
clean:
	rm bin/*.o bin/main