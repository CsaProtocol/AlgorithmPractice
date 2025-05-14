FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Copy source code and Makefile
COPY . .

# Run make (you can override this at runtime too)
RUN make > output/output.txt 2>&1