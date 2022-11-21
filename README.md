# About this repo:
An assignment from CINNOX.

# Dev env:
1. Debian 10.
2. g++ 8.3.0
3. GNU Make 4.2.1
4. netcat v1.10

# How to build:
1. Clone this repo and cd into it.
2. Check if you have gcc installed by `g++ --version`. If it's not there, follow the steps below:  
   1. `sudo apt update`
   2. `sudo apt install build-essential`
3. Check if you have GNU Make installed by `make --version`. If it's not there, follow the steps below:  
   1. `sudo apt update`
   2. `sudo apt install make`
4. Check if you have netcat installed by `nc -h`. If it's not there, follow the steps below:  
   1. `sudo apt update`
   2. `sudo apt install net-tools`
5. `make`

# If Debian is not available for you:
1. cd into repo root.
2. `docker build -t sipping .`
3. (Optional) `docker image prune`
4. `docker run -it --rm sipping`

# How to run:
1. `./bin/sipping <ip> <port> <max_retry>` (or simply `sipping <ip> <port> <max_retry>` if you use Docker way).  
   e.g. `./bin/sipping "172.30.100.23" 5060 10`
2. You can test it by following two steps:
   1. `nc -ul -p 5060 -c 'echo SIP/2.0 200 OK' &`
   2. `./bin/sipping "0.0.0.0" 5060 10`