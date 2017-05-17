#!/usr/bin/env bash

ROOT=/Users/saiheiyeung/git/serialization_demos
export PATH=$ROOT/install/flatbuffers/bin:$PATH
export PATH=$ROOT/install/protobuf-3.3.0/bin:$PATH


function g()
{
    grep $1 /Users/saiheiyeung/git/serialization_demos/commands.txt
}

function gadd()
{
    echo "$*" >> /Users/saiheiyeung/git/serialization_demos/commands.txt
}
