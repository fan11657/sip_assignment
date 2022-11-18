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

# How to run:
1. `.bin/sipping <ip> <port>`  
   e.g. `./bin/sipping "172.30.100.23" 5060`