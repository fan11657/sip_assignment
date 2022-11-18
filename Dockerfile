FROM debian:10 AS base
RUN apt update && apt install -y netcat

FROM base AS build
RUN apt install -y g++ make
COPY . ./workdir
RUN cd ./workdir && make

FROM base
COPY --from=build ./workdir/bin ./bin/sippingbin
RUN ln -s -f /bin/sippingbin/sipping /bin/sipping