#!/bin/bash

echo "Building AssemblyWords Docker Image"
docker build --tag assemblywords .

test $? -eq 0 || { echo "AssemblyWords Docker image did not build."; exit 1; };

echo "Running AssemblyWords Docker Image"
docker run --interactive --tty --rm \
    --volume `pwd`:/AssemblyWords \
    --name AssemblyWords \
    assemblywords:latest
