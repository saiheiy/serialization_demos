#!/usr/bin/env bash
set -x 
# MUST RUN INSIDE "[REPO ROOT]/flatbuffers/scripts" DIRECTORY, supply a sufficiently large input
if [ $# -eq 0 ]
then
    echo "No arguments supplied";
    exit 0;
fi

time ../cpp/msub $1 &
../cpp/mpub $1 &


set +x


